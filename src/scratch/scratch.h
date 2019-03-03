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
    constexpr codepoint(I i) : value_(i) {}

    template<ranges::Integral I>
    constexpr operator I() const {return  value_;}

    codepoint& operator++();
    codepoint& operator--();
    codepoint operator++(int);
    codepoint operator--(int);

    friend constexpr bool operator==(codepoint l, codepoint r);
    friend constexpr bool operator!=(codepoint l, codepoint r);
    friend constexpr bool operator<(codepoint l, codepoint r);
    friend constexpr bool operator<=(codepoint l, codepoint r);
    friend constexpr bool operator>(codepoint l, codepoint r);
    friend constexpr bool operator>=(codepoint l, codepoint r);

    friend constexpr ptrdiff_t operator-(codepoint lhs, codepoint rhs);
};

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
} // namespace scratch

#endif
