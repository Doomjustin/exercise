#include "exercise/log/base_logger.h"

#include <algorithm>

#ifdef _WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
#endif

namespace exercise::log {

BaseLogger::BaseLogger(std::string_view name)
  : name_{ name }
{}

void BaseLogger::fatal(std::string_view message, std::source_location cur)
{
    Entry entry{ LogLevel::Fatal, message };
    entry.source_location = std::move(cur);
    write(std::move(entry));
}

void BaseLogger::error(std::string_view message, std::source_location cur )
{
    Entry entry{ LogLevel::Error, message };
    entry.source_location = std::move(cur);
    write(std::move(entry));
}

void BaseLogger::warning(std::string_view message, std::source_location cur)
{
    Entry entry{ LogLevel::Warning, message };
    entry.source_location = std::move(cur);
    write(std::move(entry));
}

void BaseLogger::info(std::string_view message, std::source_location cur)
{
    Entry entry{ LogLevel::Debug, message };
    entry.source_location = std::move(cur);
    entry.source_location = cur;
    write(std::move(entry));
}

void BaseLogger::debug(std::string_view message, std::source_location cur)
{
    Entry entry{ LogLevel::Info, message };
    entry.source_location = std::move(cur);
    write(std::move(entry));
}

void BaseLogger::trace(std::string_view message, std::source_location cur)
{
    Entry entry{ LogLevel::Trace, message };
    entry.source_location = std::move(cur);
    write(std::move(entry));
}

void BaseLogger::pattern(std::string_view value)
{
    std::ranges::for_each(appenders_, [&value] (auto& appender) { appender->pattern(value); });
}

void BaseLogger::add_appender(std::unique_ptr<FormattableAppender> appender) noexcept
{
    appenders_.push_back(std::move(appender));
}

void BaseLogger::write(Entry entry) const
{
    if (entry.level > level_) return;

    #ifdef _WIN32
        entry.process_id = GetCurrentProcessId(); 
    #else
        entry.process_id = ::getpid();
    #endif

    entry.logger_name = name_;
    
    std::ranges::for_each(appenders_, 
                    [&entry] (const auto& appender) { appender->append(entry); });
}

} // namespace exercise::log
