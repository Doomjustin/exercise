#include "exercise/log/spdlog_logger.h"

#include <fmt/format.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/daily_file_sink.h>

namespace exercise {

SpdLogLogger::SpdLogLogger(std::string_view name)
{
    sinks_.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
    sinks_.push_back(std::make_shared<spdlog::sinks::daily_file_sink_mt>("logs/log.txt", 0, 0));
    logger_ = std::make_shared<spdlog::logger>(name.data(), std::begin(sinks_), std::end(sinks_));
}

void SpdLogLogger::fatal(std::string_view message, std::source_location cur)
{
    logger_->critical(make_message(message, cur));
}

void SpdLogLogger::error(std::string_view message, std::source_location cur)
{
    logger_->error(make_message(message, cur));
}

void SpdLogLogger::warning(std::string_view message, std::source_location cur)
{
    logger_->warn(make_message(message, cur));
}

void SpdLogLogger::info(std::string_view message, std::source_location cur)
{
    logger_->info(make_message(message, cur));
}

void SpdLogLogger::debug(std::string_view message, std::source_location cur)
{
    logger_->debug(make_message(message, cur));
}

void SpdLogLogger::trace(std::string_view message, std::source_location cur)
{
    logger_->trace(make_message(message, cur));
}

void SpdLogLogger::pattern(std::string_view pattern)
{
    logger_->set_pattern(std::string{ pattern });
}

constexpr LogLevel SpdLogLogger::level() const noexcept
{
    switch (logger_->level()) {
    case spdlog::level::critical:
        return LogLevel::Fatal;
    case spdlog::level::err:
        return LogLevel::Error;
    case spdlog::level::warn:
        return LogLevel::Warning;
    case spdlog::level::info:
        return LogLevel::Info;
    case spdlog::level::debug:
        return LogLevel::Debug;
    case spdlog::level::trace:
        return LogLevel::Trace;
    default:
        return LogLevel::Off;
    }
}

void SpdLogLogger::level(LogLevel new_level) noexcept
{
    switch (new_level) {
    case LogLevel::Fatal:
        new_level = static_cast<LogLevel>(spdlog::level::critical);
        return;
    case LogLevel::Error:
        new_level = static_cast<LogLevel>(spdlog::level::err);
        return;
    case LogLevel::Warning:
        new_level = static_cast<LogLevel>(spdlog::level::warn);
        return;
    case LogLevel::Info:
        new_level = static_cast<LogLevel>(spdlog::level::info);
        return;
    case LogLevel::Debug:
        new_level = static_cast<LogLevel>(spdlog::level::debug);
        return;
    case LogLevel::Trace:
        new_level = static_cast<LogLevel>(spdlog::level::trace);
        return;
    case LogLevel::Off:
        new_level = static_cast<LogLevel>(spdlog::level::off);
        return;
    }
}

std::string SpdLogLogger::make_message(std::string_view message, std::source_location cur)
{
    return fmt::format("{}: {}", cur.function_name(), message);
}

} // namespace exercise
