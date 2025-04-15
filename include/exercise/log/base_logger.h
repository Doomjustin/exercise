#ifndef EXERCISE_LOG_BASE_LOGGER_H
#define EXERCISE_LOG_BASE_LOGGER_H

#include "entry.h"
#include "formattable_appender.h"

#include <string>
#include <source_location>
#include <vector>

namespace exercise::log {

class BaseLogger: public Logger {
public:
    explicit BaseLogger(std::string_view name);

    ~BaseLogger() = default;

    void fatal(std::string_view message, std::source_location cur) override;

    void error(std::string_view message, std::source_location cur) override;

    void warning(std::string_view message, std::source_location cur) override;

    void info(std::string_view message, std::source_location cur) override;

    void debug(std::string_view message, std::source_location cur) override;

    void trace(std::string_view message, std::source_location cur) override;

    void pattern(std::string_view pattern) override;

    constexpr LogLevel level() const noexcept override { return level_; }

    void level(LogLevel new_level) noexcept override { level_ = new_level; }

    void write(Entry entry) const;

    void add_appender(std::unique_ptr<FormattableAppender> appender) noexcept;

protected:
    std::string name_;
    LogLevel level_ = LogLevel::Debug;
    std::vector<std::unique_ptr<FormattableAppender>> appenders_;
};

} // namespace exercise::log

#endif // EXERCISE_LOG_BASE_LOGGER_H