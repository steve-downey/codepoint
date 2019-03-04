// codepoint.h                                                       -*-C++-*-
#ifndef INCLUDED_CODEPOINT
#define INCLUDED_CODEPOINT

#include <experimental/ranges/algorithm>
#include <experimental/ranges/iterator>

namespace ranges = std::experimental::ranges;

namespace unicode {

class codepoint {
    char32_t value_;

  public:
    codepoint() noexcept = default;

    template <ranges::Integral I>
    constexpr codepoint(I i) noexcept;

    template <ranges::Integral I>
    constexpr explicit operator I() const noexcept;

    constexpr codepoint& operator++() noexcept;
    constexpr codepoint& operator--() noexcept;
    constexpr codepoint  operator++(int) noexcept;
    constexpr codepoint  operator--(int) noexcept;

    template <ranges::Integral I>
    constexpr codepoint& operator+=(I b) noexcept;

    template <ranges::Integral I>
    constexpr codepoint& operator-=(I b) noexcept;

    template <ranges::Integral I>
    friend constexpr codepoint operator+(codepoint lhs, I rhs) noexcept {
        lhs += rhs;
        return lhs;
    }

    template <ranges::Integral I>
    friend constexpr codepoint operator-(codepoint lhs, I rhs) noexcept {
        lhs -= rhs;
        return lhs;
    }

    template <ranges::Integral I>
    friend constexpr codepoint operator+(I lhs, codepoint rhs) noexcept {
        lhs += static_cast<I>(rhs);
        return lhs;
    }

    template <ranges::Integral I>
    friend constexpr codepoint operator-(I lhs, codepoint rhs) noexcept {
        lhs -= static_cast<I>(rhs);
        return lhs;
    }

    //  auto constexpr operator<=>(codepoint) = default;
    friend constexpr bool operator==(codepoint l, codepoint r) noexcept{
        return l.value_ == r.value_;
    }

    friend constexpr bool operator!=(codepoint l, codepoint r) noexcept{
        return l.value_ != r.value_;
    }

    friend constexpr bool operator<(codepoint l, codepoint r) noexcept{
        return l.value_ < r.value_;
    }

    friend constexpr bool operator<=(codepoint l, codepoint r) noexcept{
        return l.value_ <= r.value_;
    }

    friend constexpr bool operator>(codepoint l, codepoint r) noexcept{
        return l.value_ > r.value_;
    }

    friend constexpr bool operator>=(codepoint l, codepoint r) noexcept{
        return l.value_ >= r.value_;
    }

    friend constexpr ptrdiff_t operator-(codepoint lhs,
                                         codepoint rhs) noexcept{
        return lhs.value_ - rhs.value_;
    }
};

template <class CharT, class Traits>
inline std::basic_ostream<CharT, Traits>&
operator<<(std::basic_ostream<CharT, Traits>& os, codepoint c) noexcept {
    return (os << static_cast<char32_t>(c));
}

// IMPLEMENTATIONS
template <ranges::Integral I>
inline constexpr codepoint::codepoint(I i) noexcept : value_(i) {}

template <ranges::Integral I>
inline constexpr codepoint::operator I() const noexcept {
    return value_;
}

inline constexpr codepoint& codepoint::operator++() noexcept {
    ++value_;
    return *this;
}

inline constexpr codepoint& codepoint::operator--() noexcept {
    --value_;
    return *this;
}

inline constexpr codepoint codepoint::operator++(int) noexcept {
    char32_t tmp = value_++;
    return tmp;
}

inline constexpr codepoint codepoint::operator--(int) noexcept {
    char32_t tmp = value_--;
    return tmp;
}

template <ranges::Integral I>
inline constexpr codepoint& codepoint::operator+=(I i) noexcept {
    value_ += i;
    return *this;
}

template <ranges::Integral I>
inline constexpr codepoint& codepoint::operator-=(I i) noexcept {
    value_ -= i;
    return *this;
}


} // namespace unicode

#endif
