/** @file
 * @mainpage Multiplexer
 *
 * @section intro_sec Introduction
 *
 * This is the introduction.
 *
 * @authors All
 * @date 2003/12/31 01:21:59
 * @remark This text is located in mplex/main.cpp
 */

#include "MUDConnector.h"
#include "compile_defines.h"
#include "echo_server.h"
#include "essential.h"
#include "hook.h"
#include "mplex.h"
#include "network.h"
#include "slog.h"
#include "translate.h"

#include <unistd.h>

#include <cassert>
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <thread>


/******************************************************************************
 * @brief Main entry point for the MPlex server.
 *
 * Entry point for the MPlex application server where basic runtime setup is
 * performed. Command line arguments are processed and the server is initalised
 * for Websocket or Telnet connections.
 *
 * @param argc      Number of argument tokens provided.
 * @param argv      Array of argument token string.
 * @return          Program will exit with EXIT_SUCCESS (0) upon a managed
 *                  shutdown or with EXIT_FAILURE (1) on application error.
 *****************************************************************************/
int main(int argc, char *argv[])
{
    int fd = -1;

#ifdef tPROFILE
    extern etext();
    monstartup((int)2, etext);
#endif /* tPROFILE */

    // If there is any error parsing the command line arguments, pasre_arg()
    // will not return, it will stop application execution.
    parse_arg(argc, argv, &mplex::g_mplex_arg);

    // Catch application termination signals and alarm.
    signal(SIGQUIT, mplex::bye_signal);
    signal(SIGHUP, mplex::bye_signal);
    signal(SIGINT, mplex::bye_signal);
    signal(SIGTERM, mplex::bye_signal);
    signal(SIGALRM, mplex::alarm_signal);

    /* MS2020 Websockets test hack */
    mplex::translate_init();

    slog(LOG_ALL, 0, "MPlex compiled with [%s]", get_compiled_hash_defines().c_str());
    slog(LOG_OFF, 0, "Opening mother connection on port %d.", mplex::g_mplex_arg.nMotherPort);

    if (mplex::g_mplex_arg.bWebSockets) {
        /* MS2020 Websockets test hack */
        std::thread t1(mplex::runechoserver);
        t1.detach();
    } else {
        fd = mplex::OpenMother(mplex::g_mplex_arg.nMotherPort);
        Assert(fd != -1, "NO MOTHER CONNECTION.");

        if (mplex::g_MotherHook.tfd() != -1)
        {
            slog(LOG_ALL, 0, "Hook() in main called with a non -1 fd.");
        }

        g_CaptainHook.Hook(fd, &mplex::g_MotherHook);
    }

    /* Subtract stdout, stdin, stderr, fdmud, fdmother and 2 to be safe. */
    mplex::g_nConnectionsLeft = getdtablesize() - 3 - 2 - 2;
    mplex::Control();

    mplex::g_MudHook.Unhook();
    mplex::g_MotherHook.Unhook();

    return EXIT_SUCCESS;
}
