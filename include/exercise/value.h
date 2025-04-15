#ifndef EXERCISE_VALUE_H
#define EXERCISE_VALUE_H

#include "noncopyable.h"

#include <gsl/gsl>

#include <typeindex>


namespace exercise {

class BaseValue: Noncopyable {
public:
    virtual ~BaseValue() = default;

    template<typename T>
    const T& get_value() const noexcept
    {
        Expects(type_ == typeid(T));
        return *static_cast<T*>(bridge_);
    }

    template<typename T>
    void set_value(T value) noexcept
    {
        // TODO: 是否允许设置成不同类型的新值
        Expects(type_ == typeid(T));
        *static_cast<T*>(bridge_) = value;
    }

    std::type_index get_type() const noexcept
    {
        return type_;
    }

protected:
    void* bridge_ = nullptr;
    std::type_index type_;

    template<typename T>
    explicit BaseValue(T)
      : bridge_{ nullptr },
        type_{ typeid(T) }
    {}
};


template<typename T>
struct Value: public BaseValue {
    T value;
    
    Value(T v)
      : BaseValue{ v },
        value{ std::move(v) }
    {
        bridge_ = &value;
    }

    ~Value() = default;
};

} // namespace exercise

#endif // EXERCISE_VALUE_H