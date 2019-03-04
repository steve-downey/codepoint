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

    codepoint& operator++() noexcept;
    codepoint& operator--() noexcept;
    codepoint  operator++(int) noexcept;
    codepoint  operator--(int) noexcept;

    template <ranges::Integral I>
    codepoint& operator+=(I b) noexcept;

    template <ranges::Integral I>
    codepoint& operator-=(I b) noexcept;

    template <ranges::Integral I>
    friend codepoint operator+(codepoint lhs, I rhs) noexcept {
        lhs += rhs;
        return lhs;
    }

    template <ranges::Integral I>
    friend codepoint operator-(codepoint lhs, I rhs) noexcept {
        lhs -= rhs;
        return lhs;
    }

    //  auto constexpr operator<=>(codepoint) = default;
    friend constexpr bool operator==(codepoint l, codepoint r) noexcept;
    friend constexpr bool operator!=(codepoint l, codepoint r) noexcept;
    friend constexpr bool operator<(codepoint l, codepoint r) noexcept;
    friend constexpr bool operator<=(codepoint l, codepoint r) noexcept;
    friend constexpr bool operator>(codepoint l, codepoint r) noexcept;
    friend constexpr bool operator>=(codepoint l, codepoint r) noexcept;

    friend constexpr ptrdiff_t operator-(codepoint lhs,
                                         codepoint rhs) noexcept;
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

inline codepoint& codepoint::operator++() noexcept {
    ++value_;
    return *this;
}

inline codepoint& codepoint::operator--() noexcept {
    --value_;
    return *this;
}

inline codepoint codepoint::operator++(int) noexcept {
    char32_t tmp = value_++;
    return tmp;
}

inline codepoint codepoint::operator--(int) noexcept {
    char32_t tmp = value_--;
    return tmp;
}

template <ranges::Integral I>
inline codepoint& codepoint::operator+=(I i) noexcept {
    value_ += i;
    return *this;
}

template <ranges::Integral I>
inline codepoint& codepoint::operator-=(I i) noexcept {
    value_ -= i;
    return *this;
}

inline constexpr bool operator==(codepoint l, codepoint r) noexcept {
    return l.value_ == r.value_;
}

inline constexpr bool operator!=(codepoint l, codepoint r) noexcept {
    return l.value_ != r.value_;
}

inline constexpr bool operator<(codepoint l, codepoint r) noexcept {
    return l.value_ < r.value_;
}

inline constexpr bool operator<=(codepoint l, codepoint r) noexcept {
    return l.value_ <= r.value_;
}

inline constexpr bool operator>(codepoint l, codepoint r) noexcept {
    return l.value_ > r.value_;
}

inline constexpr bool operator>=(codepoint l, codepoint r) noexcept {
    return l.value_ >= r.value_;
}

inline constexpr ptrdiff_t operator-(codepoint lhs, codepoint rhs) noexcept {
    return lhs.value_ - rhs.value_;
}

} // namespace unicode

#endif
