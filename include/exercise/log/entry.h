#ifndef XIN_LOG_ENTRY_H
#define XIN_LOG_ENTRY_H

#include "exercise/log.h"

#include <string>
#include <source_location>
#include <thread>
#include <ctime>


namespace exercise::log {

struct Entry {
    LogLevel level;
    std::string message;
    std::string logger_name;
    std::uint64_t process_id = 0;
    std::thread::id thread_id = std::this_thread::get_id();
    std::time_t occurred_time = std::time(nullptr);
    std::source_location source_location;

    Entry(const LogLevel level, const std::string_view message)
      : level{ level }, message{ message }
    {}
};

} // exercise::log

#endif // XIN_LOG_ENTRY_H