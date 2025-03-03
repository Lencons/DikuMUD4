/** @file
 * @brief Internal functions for the logging system.
 *
 * The logging system provides a central capability to generate standard
 * messages and output them in the form of log files or an internal buffer
 * which can be accessed within the game engine itself.
 * 
 * Output File Descriptor
 * ----------------------
 * The global variable g_log_file_ptr is used as the file descriptor to
 * write log entries to. This file descriptor is expected to have been
 * initalised as part of the application start process. As check is performed
 * by the logging function slog_raw() to verify that g_log_file_ptr is a
 * valid descriptor, otherwise log entries will be dumped to STDERR as a
 * fallback.
 * 
 * Application Log Buffer
 * ----------------------
 * There is a internal logging buffer which at this stage is assumed can
 * be accessed in-game by wizards?
 */

 #include <iostream>

 #include "slog.h"

#include "formatter.h"
#include "utility.h"

/** Maximum number of characters which will be written as a log entry. */
#define MAX_LOG_SIZE    320


/******************************************************************************
 * @brief Backend function to write out a system log entry.
 *
 * This function is generally expected to be called via slog() within the
 * application and perform the backend process of generating the correct
 * message format of the log entry and managing any internal application
 * actions associated with the log entry.
 * 
 * A maximum log entry message size is defined by MAX_LOG_SIZE which will
 * truncate the log message to the set number of characters. The message that
 * will actually be recorded within the log will be larger that this as only
 * the message content is truncated, this excludes timestamp and other detail
 * which may be added to the truncated message.
 *
 * @param level         Set the log level type (from log_level enum).
 * @param wizinv_level  Set the Wizard level for the log entry.
 * @param msg           Formatted log message string.
 *****************************************************************************/
void slog_raw(log_level level, ubit8 wizinv_level, const std::string &msg)
{
    char timestamp[20];
    std::string log_msg;

    // Global log buffer index
    static uint8_t idx = 0;

    // Generate timestamp information for log entry.
    std::time_t tm = std::time(nullptr);
    std::tm *local_time = std::localtime(&tm);
    if (strftime(timestamp, 20, "%F %T", local_time) == 0) {
        // The timestamp buffer isn't big enough for the time/date string.
        std::cerr << "FATAL: Failed to create log entry timestamp!!!\n";
        std::cerr << "     : Incresae the buffer size in slog_raw()\n";

        // This is a discraceful exit, but we are effectively crashing.
        exit(EXIT_FAILURE); 
    }

    // Ensure that we haven't been given a crazy large log entry.
    if (msg.length() > MAX_LOG_SIZE) {
        // Complain that we have received a large log entry, this is a bug.
        slog(LOG_OFF, 0,
             "A crazy large log entry has been requested, %d characters!!",
            msg.length());

        // Truncate the message and write it out anyway.
        log_msg = msg.substr(0, MAX_LOG_SIZE) + "...<snip>";
    } else {
        log_msg = msg;
    }

    // Add a Wizard tag if a level has been provided.
    if (wizinv_level > 0) {
        log_msg.insert(0, diku::format_to_str("(%d) ", wizinv_level));
    }

    // Write out the formated log entry.
    if (g_log_file_ptr != NULL) {
        fprintf(g_log_file_ptr, "%s :: %s\n", timestamp, log_msg.c_str());
        fflush(g_log_file_ptr);
    } else {
        // For whatever reason, we don't have an initalised file pointer.
        std::cerr << "CRITICAL: File descriptor for loging not initalsed!!\n";
        std::cerr << log_msg;
    }

    if (level > LOG_OFF) {
        g_log_buf[idx].setLevel(level);
        g_log_buf[idx].setWizInvLevel(wizinv_level);
        g_log_buf[idx].setString(log_msg);

        // Move the index to the next log entry.
        idx++;
        idx %= MAXLOG;
        g_log_buf[idx].clearString();
    }
}
