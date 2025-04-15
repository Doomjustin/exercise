#include "exercise/log.h"
#include "exercise/log/base_logger.h"
#include "exercise/log/simple_formatter.h"
#include "exercise/log/console_appender.h"

#include <memory>

namespace exercise {

// 一个默认实现的logger
std::unique_ptr<Logger> create(const std::string_view name) noexcept
{
    auto simple_formatter = std::make_unique<log::SimpleFormatter>("%c %n [%l] %P %t %s[line %#] %!: %v");
    auto console_appender = std::make_unique<log::ConsoleAppender>(std::move(simple_formatter));
    auto logger = std::make_unique<log::BaseLogger>(name);
    logger->add_appender(std::move(console_appender));
    return logger;
}

Logger* default_logger() noexcept
{
    static auto logger = create("xin");
    return logger.get();
}

} // namespace exercise