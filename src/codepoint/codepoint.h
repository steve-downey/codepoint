// codepoint.h                                                       -*-C++-*-
#ifndef INCLUDED_CODEPOINT
#define INCLUDED_CODEPOINT

#include <optional>

namespace unicode {

inline constexpr struct {
} assume_valid = {};

constexpr auto first_surrogate = 0xD800;
constexpr auto last_surrogate  = 0xDFFF;
constexpr auto last_code_point = 0x10FFFF;

class codepoint {
  public:
    codepoint() = delete;

    friend constexpr std::optional<codepoint>
    as_codepoint(std::uint32_t value) noexcept;

    friend constexpr codepoint as_codepoint(std::uint32_t value,
                                            decltype(assume_valid)) noexcept;

    explicit constexpr operator std::uint32_t() const noexcept {
        return value_;
    }

    //  auto constexpr operator<=>(codepoint) = default;
    friend constexpr bool operator==(codepoint l, codepoint r) noexcept {
        return l.value_ == r.value_;
    }

    friend constexpr bool operator!=(codepoint l, codepoint r) noexcept {
        return l.value_ != r.value_;
    }

    friend constexpr bool operator<(codepoint l, codepoint r) noexcept {
        return l.value_ < r.value_;
    }

    friend constexpr bool operator<=(codepoint l, codepoint r) noexcept {
        return l.value_ <= r.value_;
    }

    friend constexpr bool operator>(codepoint l, codepoint r) noexcept {
        return l.value_ > r.value_;
    }

    friend constexpr bool operator>=(codepoint l, codepoint r) noexcept {
        return l.value_ >= r.value_;
    }

    friend constexpr int_least32_t operator-(codepoint lhs,
                                             codepoint rhs) noexcept {
        return lhs.value_ - rhs.value_;
    }

    friend constexpr bool operator==(std::uint32_t l, codepoint r) noexcept {
        return l == r.value_;
    }

    friend constexpr bool operator==(codepoint l, std::uint32_t r) noexcept {
        return l.value_ == r;
    }

    friend constexpr bool operator!=(std::uint32_t l, codepoint r) noexcept {
        return l != r.value_;
    }

    friend constexpr bool operator!=(codepoint l, std::uint32_t r) noexcept {
        return l.value_ != r;
    }

    template <class CharT, class Traits>
    friend inline std::basic_ostream<CharT, Traits>&
    operator<<(std::basic_ostream<CharT, Traits>& os, codepoint c) noexcept {
        return (os << static_cast<uint32_t>(c));
    }

  private:
    constexpr codepoint(std::uint32_t v) : value_(v) {}
    std::uint32_t value_;
};


constexpr std::optional<codepoint> as_codepoint(std::uint32_t value) noexcept {
    if ((value >= first_surrogate && value <= last_surrogate) ||
        value > last_code_point) {
        return std::nullopt;
    } else {
        return codepoint{value};
    }
}

constexpr codepoint as_codepoint(std::uint32_t value,
                                 decltype(assume_valid)) noexcept {
    return codepoint{value};
}

} // namespace unicode

#endif
