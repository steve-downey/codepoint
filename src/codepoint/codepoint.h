// codepoint.h                                                       -*-C++-*-
#ifndef INCLUDED_CODEPOINT
#define INCLUDED_CODEPOINT

#include <experimental/ranges/algorithm>
#include <experimental/ranges/iterator>

namespace ranges = std::experimental::ranges;

namespace unicode {

enum class codepoint : char32_t {
    min = 0,
    max = 0x10FFFF,
};

template <ranges::Integral I>
constexpr I to_integer(codepoint c) noexcept {
    return I(c);
}

} // namespace unicode

#endif
