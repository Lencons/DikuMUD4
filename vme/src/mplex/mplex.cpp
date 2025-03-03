/** @file
 * @brief Server startup routines for MPlex.
 *
 * Helper routines for the initalisaion of the MPlex application server called
 * from the main() application entry point.
 */

#include "MUDConnector.h"
#include "essential.h"
#include "hook.h"
#include "mplex.h"
#include "network.h"
#include "slog.h"
#include "textutil.h"

#include <netdb.h>

#include <cassert>
#include <cctype>
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <iostream>

namespace mplex
{

char g_mudname[50] = "the MUD server (via DikuMUD Mplex)";
int g_bHadAlarm = FALSE;

/** Server configuration arguments for the MPlex instance. */
arg_type g_mplex_arg;


/******************************************************************************
 * @brief Signal handler for the termination of the application server.
 *
 * Signal handler which is assigned to SIGQUIT, SIGHUP, SIGINT and SIGTERM to
 * kill the MPlex application server.
 * 
 * The process is not exited gracefully with these signals, but execution is
 * just aborted with exit(). So no buffers are flushed and no memory management
 * is performed as part of the process killing. This is not a graceful exit of
 * the application server.
 * 
 * @param signal        The number of the signal that has called the handler.
 *****************************************************************************/
void bye_signal(int signal)
{

    slog(LOG_OFF, 0, "Received signal SIG%s.", sigabbrev_np(signal));
    slog(LOG_OFF, 0, "Server shutting down.....");

    slog(LOG_OFF, 0, "Closing CaptainHook.");
    g_CaptainHook.Close();

    slog(LOG_OFF, 0, "Server exiting.");
    exit(EXIT_FAILURE);
}


/******************************************************************************
 * @brief Signal handler for SIGALRM.
 *
 * Signal handler for the SIGALRM signal which is used as a watchdog style
 * monitor for the application server.
 * 
 * @param signal        The number of the signal that has called the handler.
 *****************************************************************************/
void alarm_signal(int signal)
{
    slog(LOG_OFF, 0, "Received alarm signal.");
    g_bHadAlarm = TRUE;

    // Reset the alarm signal.
    std::signal(SIGALRM, alarm_signal);
}


/******************************************************************************
 * @brief Display application usage help to the user.
 *
 * Display formated help information to the user on the command line syntax of
 * the application server and parameter options.
 * 
 * @param name          Name of the executed binary.
 *****************************************************************************/
void show_usage(const char *name)
{
    std::cout <<
        "Usage: " << name << " [-a] [-h] [-c] [-e] [-r] [-t] [-x] [-l <filename>] [-p <num>] [-d <path>] [-s <port>] [-a <address>]\n"
        "\n"
        "Parameters:\n"
        "  -h  This help screen.\n"
        "  -c  Deprecated. Always on. ANSI Colour when set, TTY when not.\n"
        "  -e  Echo mode (echo chars locally).\n"
        "  -r  Redraw prompt locally (usually only in -e mode).\n"
        "  -p  Player port number (default: 4242).\n"
        "  -a  Internet address of server (default: localhost).\n"
        "  -s  Internet port of server (default: 4999).\n"
        "  -l  Logfile file name for logging.\n"
        "  -x  Output raw HTML on telnet (nice for debugging).\n"
        "  -y  Strip away the HTML on websockets.\n"
        "  -w  Use Websockets.\n"
        "  -t  Use TLS (can only be used with Websockets).\n"
        "  -m  Use mud protocol (experimental).\n";

    exit(EXIT_SUCCESS);
}


/******************************************************************************
 * @brief Parse the command line arguments and set up initial server config.
 *
 * Perform the initial configuration of the MPlex application server through
 * first setting default values to all configuration values contained within
 * the provided arg structure, and then overriding those values with anything
 * provided on the command line.
 * 
 * The logging system is also initalised by assigning the required file pointer
 * to g_log_file_ptr. If a logfile is provided as a command line argument then
 * that file will be opened for writing, otherwise logging system output is
 * directed to STDERR by default.
 * 
 * Error Handling
 * --------------
 * As this function is performing the setup and configuration of the
 * application server, if an error is encounted a message is provided to the
 * user via STDERR and execution is exited. It is assumed that if there is an
 * error while trying to configure the server, then the server should not be
 * started.
 * 
 * @param argc          Number of argument tokens provided.
 * @param argv          Array of argument token strings.
 * @param arg           Structure of all application server configuration
 *                      values.
 *****************************************************************************/
void parse_arg(int argc, char *argv[], arg_type *arg)
{
    int i = 0;
    int n = 0;
    hostent *pHostInfo = nullptr;
    in_addr *pAddr = nullptr;
    char *c = nullptr;
    char *log_name = nullptr;

    arg->nMudPort = 4999;               // Default port
    arg->nMotherPort = 4242;            // Default port
    arg->pAddress = str_dup(DEF_SERVER_ADDR);
    arg->g_bUseTLS = false;

    arg->g_bModeANSI = TRUE;            // Deprication of support for TTY
    arg->g_bModeTelnet = TRUE;          // Deprication of support for TTY

    arg->g_bModeEcho = FALSE;
    arg->g_bModeRedraw = FALSE;
    arg->g_bModeRawHTML = FALSE;
    arg->bWebSockets = FALSE;
    arg->bMudProtocol = false;
    arg->bForceAscii = false;

    for (i = 1; i < argc; i++) {
        if (argv[i][0] != '-') {
            fprintf(stderr, "Illegal argument '%s'.\n", argv[i]);
            show_usage(argv[0]);
        }

        switch (argv[i][1]) {
            case 'h':
            case '?':
                show_usage(argv[0]);
                break;

            case 'x':
                arg->g_bModeRawHTML = TRUE;
                break;

            case 'c':
                fprintf(stderr, "-c is deprecated, it's always on.\n");
                arg->g_bModeANSI = TRUE;
                break;

            case 'e':
                arg->g_bModeEcho = TRUE;
                break;

            case 'r':
                arg->g_bModeRedraw = TRUE;
                break;

            case 'w':
                arg->bWebSockets = TRUE;
                break;

            case 't':
                arg->g_bUseTLS = true;
                break;

            case 'm':
                arg->bMudProtocol = true;
                break;

            case 'y':
                arg->bForceAscii = true;
                break;

            case 'l':
                i++;
                Assert(i < argc, "No argument to Mplex log.");
                Assert(log_name == nullptr, "Logfile set multiple times.");
                log_name = str_dup(argv[i]);
                break;
            case 'a':
                i++;
                Assert(i < argc, "No argument to internet address.");

                c = argv[i];

                if (!isdigit(c[0])) {
                    pHostInfo = gethostbyname(c);
                    Assert(pHostInfo != nullptr, "Could not lookup address.");
                    pAddr = (in_addr *)(pHostInfo->h_addr_list[0]);
                    c = inet_ntoa(*pAddr);
                    Assert(c != nullptr, "Error in address conversion");
                }

                arg->pAddress = str_dup(c);

                Assert(inet_addr(arg->pAddress) != (unsigned long)-1, "Illegal inet address");
                break;

            case 'p':
                i++;
                n = atoi(argv[i]);
                Assert(n > 1000, "Port number in reserved area.");
                arg->nMotherPort = n;
                break;

            case 's':
                i++;
                n = atoi(argv[i]);
                Assert(n > 1000, "Port number in reserved area.");
                arg->nMudPort = n;
                break;

            default:
                fprintf(stderr, "Illegal option.\n");
                show_usage(argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    // If a logfile name has been provided, then we will use it.
    if (log_name != nullptr) {
        g_log_file_ptr = fopen(log_name, "w");

        if (g_log_file_ptr == nullptr) {
            fprintf(stderr, "Failed to open Log file:  %s", log_name);
            exit(EXIT_FAILURE);
        }
        FREE(log_name);
    } else {
        // Log output to STDERR by default.
        g_log_file_ptr = stderr;
    }
}

} /* namespace mplex */
