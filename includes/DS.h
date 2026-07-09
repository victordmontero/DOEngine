#pragma once

#include <functional>
#include <cstdint>
#include <compare>
#include <iostream>
#include <limits>
#include <stdexcept>


namespace doengine::DS
{

template <typename T>
struct BinaryTree
{
    BinaryTree* left;
    BinaryTree* right;
    T value;
    BinaryTree() : value{0}, left{nullptr}, right{nullptr}
    {
    }

    void set_value(T va)
    {
        value = va;
    }
    BinaryTree(T start) : value{start}, left{nullptr}, right{nullptr}
    {
    }

    BinaryTree<T> visitFromLeft(std::function<void(T)> visitor)
    {

        if (left)
        {
            left->visitFromLeft(visitor);
        }
        if (right)
        {
            right->visitFromLeft(visitor);
        }
        visitor(value);
    }

    BinaryTree<T> insert(T value)
    {
        if (value == this->value)
            return *this;
        if (value < this->value)
        {
            if (left)
            {
                left->insert(value);
            }
            else
            {
                left = new BinaryTree<T>(value);
            }
        }
        else
        {
            if (right)
            {
                right->insert(value);
            }
            else
            {
                right = new BinaryTree<T>(value);
            }
        }
        return *this;
    }
};

template<int32_t Initial, int32_t MaxValue = std::numeric_limits<int32_t>::max()>
class CircularInteger
{
    static_assert(Initial <= MaxValue,
                  "Initial must be less than or equal to MaxValue.");

public:
    static constexpr int32_t min_value = Initial;
    static constexpr int32_t max_value = MaxValue;
    static constexpr int32_t range_size = MaxValue - Initial + 1;

    constexpr CircularInteger() noexcept = default;

    constexpr explicit CircularInteger(int32_t value) noexcept
        : current_value(normalize(value))
    {
    }

    constexpr CircularInteger(const CircularInteger&) noexcept = default;
    constexpr CircularInteger(CircularInteger&&) noexcept = default;
    constexpr CircularInteger& operator=(const CircularInteger&) noexcept = default;
    constexpr CircularInteger& operator=(CircularInteger&&) noexcept = default;

    constexpr CircularInteger& operator=(int32_t value) noexcept
    {
        current_value = normalize(value);
        return *this;
    }

    constexpr CircularInteger& operator++() noexcept
    {
        current_value = normalize(current_value + 1);
        return *this;
    }

    constexpr CircularInteger operator++(int) noexcept
    {
        CircularInteger tmp(*this);
        ++(*this);
        return tmp;
    }

    constexpr CircularInteger& operator--() noexcept
    {
        current_value = normalize(current_value - 1);
        return *this;
    }

    constexpr CircularInteger operator--(int) noexcept
    {
        CircularInteger tmp(*this);
        --(*this);
        return tmp;
    }

    constexpr CircularInteger& operator+=(int32_t n) noexcept
    {
        current_value = normalize(current_value + n);
        return *this;
    }

    constexpr CircularInteger& operator-=(int32_t n) noexcept
    {
        current_value = normalize(current_value - n);
        return *this;
    }

    friend constexpr CircularInteger operator+(CircularInteger lhs, int32_t rhs) noexcept
    {
        lhs += rhs;
        return lhs;
    }

    friend constexpr CircularInteger operator+(int32_t lhs, CircularInteger rhs) noexcept
    {
        rhs += lhs;
        return rhs;
    }

    friend constexpr CircularInteger operator-(CircularInteger lhs, int32_t rhs) noexcept
    {
        lhs -= rhs;
        return lhs;
    }

    friend constexpr int32_t operator-(CircularInteger lhs,
                                       CircularInteger rhs) noexcept
    {
        return lhs.current_value - rhs.current_value;
    }

    constexpr auto operator<=>(const CircularInteger&) const noexcept = default;

    constexpr operator int32_t() const noexcept
    {
        return current_value;
    }

    [[nodiscard]]
    constexpr int32_t value() const noexcept
    {
        return current_value;
    }

    constexpr void reset() noexcept
    {
        current_value = Initial;
    }

    [[nodiscard]]
    constexpr bool atMin() const noexcept
    {
        return current_value == Initial;
    }

    [[nodiscard]]
    constexpr bool atMax() const noexcept
    {
        return current_value == MaxValue;
    }

    [[nodiscard]]
    static constexpr int32_t min() noexcept
    {
        return Initial;
    }

    [[nodiscard]]
    static constexpr int32_t max() noexcept
    {
        return MaxValue;
    }

    [[nodiscard]]
    static constexpr int32_t range() noexcept
    {
        return range_size;
    }

    friend std::ostream& operator<<(std::ostream& os,
                                    const CircularInteger& value)
    {
        return os << value.current_value;
    }

private:
    [[nodiscard]]
    static constexpr int32_t normalize(int64_t value) noexcept
    {
        constexpr int64_t r = static_cast<int64_t>(range_size);

        value -= Initial;
        value %= r;

        if (value < 0)
            value += r;

        return static_cast<int32_t>(value + Initial);
    }

    int32_t current_value = Initial;
};

 



class LimitInteger
{
public:
    constexpr LimitInteger() = default;

    constexpr LimitInteger(int32_t minimum,
                           int32_t maximum,
                           int32_t value = 0)
        : min_value_(minimum),
          max_value_(maximum)
    {
        if (minimum > maximum)
            throw std::invalid_argument("minimum must be <= maximum");

        current_value_ = normalize(value);
    }

    LimitInteger& setLimits(int32_t minimum, int32_t maximum)
    {
        if (minimum > maximum)
            throw std::invalid_argument("minimum must be <= maximum");

        min_value_ = minimum;
        max_value_ = maximum;
        current_value_ = normalize(current_value_);
        return *this;
    }

    constexpr int32_t min() const noexcept
    {
        return min_value_;
    }

    constexpr int32_t max() const noexcept
    {
        return max_value_;
    }

    constexpr int32_t range() const noexcept
    {
        return max_value_ - min_value_ + 1;
    }

    constexpr int32_t value() const noexcept
    {
        return current_value_;
    }

    LimitInteger&  reset() noexcept
    {
        current_value_ = min_value_;
        return *this;
    }

    bool atMin() const noexcept
    {
        return current_value_ == min_value_;
    }

    bool atMax() const noexcept
    {
        return current_value_ == max_value_;
    }

    LimitInteger& operator=(int32_t value)
    {
        current_value_ = normalize(value);
        return *this;
    }

    LimitInteger& operator++()
    {
        current_value_ = normalize(current_value_ + 1);
        return *this;
    }

    LimitInteger operator++(int)
    {
        LimitInteger tmp(*this);
        ++(*this);
        return tmp;
    }

    LimitInteger& operator--()
    {
        current_value_ = normalize(current_value_ - 1);
        return *this;
    }

    LimitInteger operator--(int)
    {
        LimitInteger tmp(*this);
        --(*this);
        return tmp;
    }

    LimitInteger& operator+=(int32_t n)
    {
        current_value_ = normalize(static_cast<int64_t>(current_value_) + n);
        return *this;
    }

    LimitInteger& operator-=(int32_t n)
    {
        current_value_ = normalize(static_cast<int64_t>(current_value_) - n);
        return *this;
    }

    friend LimitInteger operator+(LimitInteger lhs, int32_t rhs)
    {
        lhs += rhs;
        return lhs;
    }

    friend LimitInteger operator-(LimitInteger lhs, int32_t rhs)
    {
        lhs -= rhs;
        return lhs;
    }

    /// auto operator<=>(const LimitInteger&) const = default;

    operator int32_t() const noexcept
    {
        return current_value_;
    }

    friend std::ostream& operator<<(std::ostream& os,
                                    const LimitInteger& value)
    {
        return os << value.current_value_;
    }

private:
    int32_t normalize(int64_t value) const noexcept
    {
        const int64_t r = static_cast<int64_t>(range());

        value -= min_value_;
        value %= r;

        if (value < 0)
            value += r;

        return static_cast<int32_t>(value + min_value_);
    }

    int32_t min_value_ = 0;
    int32_t max_value_ = INT32_MAX;
    int32_t current_value_ = 0;
};

}; // namespace doengine::DS