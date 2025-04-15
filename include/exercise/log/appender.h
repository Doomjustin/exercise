#ifndef EXERCISE_LOG_APPENDER_H
#define EXERCISE_LOG_APPENDER_H

#include "entry.h"

namespace exercise::log {

struct Appender {
    Appender() = default;

    Appender(const Appender& other) = delete;
    Appender& operator=(const Appender& other) = delete;

    Appender(Appender&& other) noexcept = default;
    Appender& operator=(Appender&& other) noexcept = default;

    virtual ~Appender() = default;

    virtual void append(const Entry& entry) = 0;
};

} // namespace xin::log

#endif // EXERCISE_LOG_APPENDER_H