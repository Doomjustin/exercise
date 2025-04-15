#ifndef EXERCISE_NONCOPYABLE_H
#define EXERCISE_NONCOPYABLE_H

namespace exercise {

class Noncopyable {
public:
    Noncopyable(Noncopyable&&) noexcept = default;
    Noncopyable& operator=(Noncopyable&&) noexcept = default;

    Noncopyable(const Noncopyable&) = delete;
    Noncopyable& operator=(const Noncopyable&) = delete;

protected:
    Noncopyable() = default;

    // 不能用Noncopyable的指针
    ~Noncopyable() = default;
};

} // namespace exercise

#endif // !EXERCISE_NONCOPYABLE_H