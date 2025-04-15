#include "exercise/log/console_appender.h"

#include <fmt/base.h>


namespace exercise::log {

ConsoleAppender::ConsoleAppender(std::unique_ptr<Formatter> formatter)
  : FormattableAppender{ std::move(formatter) }
{}

void ConsoleAppender::append(const Entry& entry)
{
    fmt::println("{}", format(entry));
}

} // namespace exercise::log
