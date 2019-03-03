// scratch.h                                                       -*-C++-*-
#ifndef INCLUDED_SCRATCH
#define INCLUDED_SCRATCH

#include <experimental/ranges/algorithm>
#include <experimental/ranges/iterator>

namespace ranges = std::experimental::ranges;

namespace scratch {

class codepoint {
    char32_t value_;

  public:
    codepoint() = default;

    template<ranges::Integral I>
    constexpr codepoint(I i);

    template<ranges::Integral I>
    constexpr explicit operator I() const;

    codepoint& operator++();
    codepoint& operator--();
    codepoint operator++(int);
    codepoint operator--(int);

    template<ranges::Integral I>
    codepoint& operator +=(I b);

    template<ranges::Integral I>
    codepoint& operator -=(I b);

    friend constexpr bool operator==(codepoint l, codepoint r);
    friend constexpr bool operator!=(codepoint l, codepoint r);
    friend constexpr bool operator<(codepoint l, codepoint r);
    friend constexpr bool operator<=(codepoint l, codepoint r);
    friend constexpr bool operator>(codepoint l, codepoint r);
    friend constexpr bool operator>=(codepoint l, codepoint r);

    friend constexpr ptrdiff_t operator-(codepoint lhs, codepoint rhs);

};

template <ranges::Integral I>
constexpr codepoint::codepoint(I i) : value_(i) {}

template <ranges::Integral I>
constexpr codepoint::operator I() const {
    return value_;
}

codepoint& codepoint::operator++() {
    ++value_;
    return *this;
}
codepoint& codepoint::operator--() {
    --value_;
    return *this;
}
codepoint codepoint::operator++(int) {
    char32_t tmp = value_++;
    return tmp;
}
codepoint codepoint::operator--(int) {
    char32_t tmp = value_--;
    return tmp;
}

template <ranges::Integral I>
codepoint& codepoint::operator+=(I i) {
    value_ += i;
    return *this;
}

template <ranges::Integral I>
codepoint& codepoint::operator-=(I i) {
    value_ -= i;
    return *this;
}

constexpr bool operator==(codepoint l, codepoint r) {
    return l.value_ == r.value_;
}
constexpr bool operator!=(codepoint l, codepoint r) {
    return l.value_ != r.value_;
}
constexpr bool operator<(codepoint l, codepoint r) {
    return l.value_ < r.value_;
}
constexpr bool operator<=(codepoint l, codepoint r) {
    return l.value_ <= r.value_;
}
constexpr bool operator>(codepoint l, codepoint r) {
    return l.value_ > r.value_;
}
constexpr bool operator>=(codepoint l, codepoint r) {
    return l.value_ >= r.value_;
}

constexpr ptrdiff_t operator-(codepoint lhs, codepoint rhs) {
    return lhs.value_ - rhs.value_;
}

template< class CharT, class Traits >
std::basic_ostream<CharT,Traits>&
operator<<( std::basic_ostream<CharT,Traits>& os, codepoint c ) {
    return (os << static_cast<char32_t>(c));
}

} // namespace scratch

#endif
