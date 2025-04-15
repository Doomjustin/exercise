#ifndef EXERCISE_MATH_H
#define EXERCISE_MATH_H

#include <concepts>
#include <cstddef>

namespace exercise {

template<std::unsigned_integral T>
[[nodiscard]]
constexpr bool is_odd(T value)
{
    return value % 2 == 1;
}

[[nodiscard]]
constexpr bool is_odd(std::size_t value)
{
    return value % 2 == 1;
}


template<std::unsigned_integral T>
[[nodiscard]]
constexpr bool is_even(T value)
{
    return value % 2 == 0;
}

[[nodiscard]]
constexpr bool is_even(std::size_t value)
{
    return value % 2 == 0;
}


template<std::unsigned_integral T>
[[nodiscard]]
constexpr bool is_prime(T value)
{
    for (std::size_t d = 2; d <= value/2; ++d) {
        if (value % d == 0)
            return false;
    }

    return true;
}

constexpr bool is_prime(std::size_t value)
{
    for (std::size_t d = 2; d <= value/2; ++d) {
        if (value % d == 0)
            return false;
    }

    return true;
}

} // namespace exercise


#endif // EXERCISE_MATH_H