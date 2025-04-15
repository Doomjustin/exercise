#ifndef EXERCISE_LOG_H
#define EXERCISE_LOG_H

#include "noncopyable.h"

#include <fmt/core.h>

#include <source_location>
#include <string_view>


namespace exercise {

enum class LogLevel {
    Off,
    Fatal,
    Error,
    Warning,
    Info,
    Debug,
    Trace
};

struct Logger: Noncopyable {
    virtual ~Logger() = default;

    virtual void fatal(std::string_view message, std::source_location cur = std::source_location::current()) = 0;

    virtual void error(std::string_view message, std::source_location cur = std::source_location::current()) = 0;

    virtual void warning(std::string_view message, std::source_location cur = std::source_location::current()) = 0;

    virtual void info(std::string_view message, std::source_location cur = std::source_location::current()) = 0;

    virtual void debug(std::string_view message, std::source_location cur = std::source_location::current()) = 0;

    virtual void trace(std::string_view message, std::source_location cur = std::source_location::current()) = 0;

    virtual void pattern(std::string_view pattern) = 0;

    virtual constexpr LogLevel level() const noexcept = 0;

    virtual void level(LogLevel new_level) noexcept = 0;
};

Logger* default_logger() noexcept;

} // namespace exercise


#define LOG_FATAL(...) exercise::default_logger()->fatal(fmt::format(__VA_ARGS__));

#define LOG_ERROR(...) exercise::default_logger()->error(fmt::format(__VA_ARGS__));

#define LOG_WARNING(...) exercise::default_logger()->warning(fmt::format(__VA_ARGS__));

#define LOG_DEBUG(...) exercise::default_logger()->debug(fmt::format(__VA_ARGS__));

#define LOG_INFO(...) exercise::default_logger()->info(fmt::format(__VA_ARGS__));

#define LOG_TRACE(...) exercise::default_logger()->trace(fmt::format(__VA_ARGS__));

#endif // EXERCISE_LOG_H