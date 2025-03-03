/** @file
 * @brief Server configuration and startup for MPlex.
 *
 * Global application server configuration is stored within g_mplex_arg
 * which is initalised though parse_arg() at the time of application
 * initiation. The arg_type structure which g_mplex_arg references
 * contains all runtime configuration for the application server.
 */

#ifndef MPLEX_MPLEX_H
#define MPLEX_MPLEX_H

#include "color.h"
#include "essential.h"
#include "hook.h"
#include "network.h"
#include "protocol.h"
#include "queue.h"

#include <cstring>

namespace mplex
{

struct arg_type
{
    int nMotherPort;
    int nMudPort;
    char *pAddress;
    int g_bModeANSI;
    int g_bModeEcho;
    int g_bModeRedraw;
    int g_bModeTelnet;
    int g_bModeRawHTML;
    int bWebSockets;
    int bMudProtocol;
    int bForceAscii;
    bool g_bUseTLS;
};

#define Assert(a, b)                                                                                                                       \
    do                                                                                                                                     \
    {                                                                                                                                      \
        if (!(a))                                                                                                                          \
        {                                                                                                                                  \
            fprintf(stderr, "%s\n", b);                                                                                                    \
            assert(a);                                                                                                                     \
        }                                                                                                                                  \
    } while (0);

extern int g_bHadAlarm;
extern arg_type g_mplex_arg;
extern char g_mudname[50];

void parse_arg(int argc, char *argv[], arg_type *arg);
void bye_signal(int signal);
void alarm_signal(int sig);

} /* namespace mplex */

#endif /* MPLEX_MPLEX_H */
