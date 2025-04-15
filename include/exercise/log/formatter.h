#ifndef EXERCISE_LOG_FORMATTER_H
#define EXERCISE_LOG_FORMATTER_H

#include "entry.h"

namespace exercise::log {

struct Formatter {
    Formatter() = default;

    Formatter(const Formatter& other) = delete;
    Formatter& operator=(const Formatter& other) = delete;

    Formatter(Formatter&& other) noexcept = default;
    Formatter& operator=(Formatter&& other) noexcept = default;

    virtual ~Formatter() = default;

    virtual std::string format(const Entry& entry) const = 0;
};

} // namespace exercise::log

#endif // EXERCISE_LOG_FORMATTER_H