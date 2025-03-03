/** @file
 * @brief Logging system interface.
 *
 * The interface to the logging system is through slog() which provides a
 * standard printf() style string formatting mechanisim to generate log
 * entries.
 */

#ifndef VME_SLOG_H
#define VME_SLOG_H

#include <string>

#include "essential.h"
#include "formatter.h"
#include "OutputCapture.h"

void slog_raw(log_level level, ubit8 wizinv_level, const std::string &msg);


/******************************************************************************
 * Generate a system log entry.
 *
 * Logging system function to create log entries within the application. The
 * logging level identifies the type of log entry to create.
 * 
 * For log entries which are not to be buffered within the applications
 * internal log that can be accessed via in-game characters, a log level of
 * LOG_OFF should be used.
 * 
 * If a Wizard level of 1 or greater is proved, then the log entry is prefixed
 * with a tag for entry filtering based on character Wizard level.
 *
 * @tparam              ParamPack Type of the remaining function parameters.
 * @param level         Set the log level type (from log_level enum).
 * @param wizinv_level  Set the Wizard level for the log entry.
 * @param fmt           Printf style format string for the log entry message.
 * @param pack          Parameter pack of all the arguments.
 *****************************************************************************/
template<typename... ParamPack>
void slog(log_level level, ubit8 wizinv_level, const std::string &fmt, ParamPack &&...pack)
{
    std::string log_msg, wiz_tag;

    if constexpr (sizeof...(pack) != 0) {
        log_msg = diku::format_to_str(fmt.c_str(), pack...);
    } else {
        log_msg = fmt;
    }

    slog_raw(level, wizinv_level, log_msg);

    // If a unit test is being run, send results there too
    unit_tests::OutputCapture::slog(level, wizinv_level, fmt, log_msg);
}

#endif /* VME_SLOG_H */
