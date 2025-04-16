#include "exercise/log.h"
#include "exercise/log/spdlog_logger.h"

#include <memory>

namespace exercise {

std::unique_ptr<Logger> create(const std::string_view name) noexcept
{
    auto logger = std::make_unique<SpdLogLogger>(name);
    logger->pattern("%Y-%m-%d %T.%e.%f %n %^%l%$ %t %P %v");
    logger->level(LogLevel::Debug);
    return logger;
}

Logger* default_logger() noexcept
{
    static auto logger = create("exercise");
    return logger.get();
}

} // namespace exercise