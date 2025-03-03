/** @file
 * @mainpage Valhalla Mud Engine
 *
 * @section intro_sec Introduction
 *
 * This is the introduction.
 *
 * @authors All
 * @date 2004/09/18 19:52:56
 * @remark This text is located in main.cpp
 */

#include "comm.h"
#include "compile_defines.h"
#include "diku_exception.h"
#include "main_functions.h"
#include "pipe.h"
#include "slog.h"
#include "system.h"
#include "textutil.h"

#include <pthread.h>

#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define OPT_USEC 250000L /* time delay corresponding to 4 passes/sec */


/******************************************************************************
 * @brief Main entry point for the VME server.
 *
 * Entry point for the VME application server where basic runtime setup is
 * performed. Command line arguments are processed and the server is initalised
 * into its run loop.
 *
 * @param argc      Number of argument tokens provided.
 * @param argv      Array of argument token string.
 * @return          Program will exit with EXIT_SUCCESS (0) upon a managed
 *                  shutdown or with EXIT_FAILURE (1) on application error.
 *****************************************************************************/
int main(int argc, char **argv)
{
    char *srvcfg = nullptr;
    char *log_name = nullptr;
    int pos = 1;

    while ((pos < argc) && (*(argv[pos]) == '-')) {
        switch (*(argv[pos] + 1)) {
            case '?':
            case 'h':
                show_usage(argv[0]);
                exit(EXIT_SUCCESS);

            case 'c':
                slog(LOG_OFF, 0, "Converting player file mode.");
                g_player_convert = 1;
                break;

            case 'C':
                slog(LOG_OFF, 0, "Cleaning up player file mode.");
                g_player_convert = 2;
                break;

            case 'L':
                slog(LOG_OFF, 0, "Listing player file mode.");
                g_player_convert = 3;
                break;

            case 's':
                if (++pos < argc) {
                    srvcfg = strdup(argv[pos]);
                } else {
                    slog(LOG_OFF, 0, "Full path and file name for the config file expected.");
                    exit(EXIT_FAILURE);
                }
                break;

            case 'd':
                g_dumptables = true;
                break;

            case 'j':
                g_dump_json = true;
                break;

            case 'l':
                if (++pos < argc) {
                    log_name = str_dup(argv[pos]);
                } else {
                    slog(LOG_OFF, 0, "Full path and file name for the config file expected.");
                    exit(EXIT_FAILURE);
                }
                break;

            default:
                slog(LOG_OFF, 0, "Unknown option %s in argument string.", (argv[pos]));
                break;
        }
        pos++;
    }

    if (pos < argc) {
        if (!isdigit(*argv[pos])) {
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

    // If no server config file has been provided, look for defaults.
    if (srvcfg == nullptr) {
        srvcfg = getenv("VME_SERVER_CFG");
        if (srvcfg == nullptr) {
            srvcfg = strdup("./etc/server.cfg");
        }
    }

    try {
        type_validate_64();
        srandom(time(nullptr));
        run_the_game(srvcfg);
    }
    catch (const diku_exception &e) {
        std::cout << "DIKU EXCEPTION: " << e.what() << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << "EXCEPTION: " << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}
