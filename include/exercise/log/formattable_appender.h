#ifndef EXERCISE_LOG_FORMATTABLE_APPENDER_H
#define EXERCISE_LOG_FORMATTABLE_APPENDER_H

#include "appender.h"
#include "formatter.h"

#include <memory>

namespace exercise::log {

class FormattableAppender: public Appender {
public:
    FormattableAppender(std::unique_ptr<Formatter> formatter);

    FormattableAppender(const FormattableAppender& other) = delete;
    FormattableAppender& operator=(const FormattableAppender& other) = delete;

    FormattableAppender(FormattableAppender&& other) noexcept = default;
    FormattableAppender& operator=(FormattableAppender&& other) noexcept = default;

    ~FormattableAppender() = default;

    void pattern(std::string_view value);

protected:
    std::string format(const Entry& entry) const;

private:
    std::unique_ptr<Formatter> formatter_;
    std::string pattern_;
};

} // namespace exercise::log

#endif // !EXERCISE_LOG_FORMATTABLE_APPENDER_H