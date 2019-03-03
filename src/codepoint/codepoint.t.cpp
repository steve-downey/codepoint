#include <codepoint/codepoint.h>

#include <gtest/gtest.h>

#include <sstream>

using namespace unicode;

TEST(CodepointTest, TestGTest) {
    ASSERT_EQ(1, 1);
}

TEST(CodepointTest, Breathing) {
    codepoint cp1;
    codepoint cp2{0};
    codepoint cp3{cp2};

    codepoint cp4 = codepoint{};
    codepoint cp5 = codepoint{1};

    char32_t c32 = 0x1234;
    codepoint cp6{c32};
    codepoint cp7 = c32;
    cp1 = cp2;
    ASSERT_EQ(cp1, 0);
    cp1 = c32;
    ASSERT_EQ(cp1, 0x1234);

    codepoint a = 'a';
    ASSERT_EQ(a, 'a');

    codepoint a8 = u8'a';
    ASSERT_EQ(a8, 'a');

}

TEST(CodepointTest, IntegralCompare) {
    constexpr codepoint cp1{1};

    ASSERT_EQ(1, cp1);
    ASSERT_NE(2, cp1);
    ASSERT_EQ(cp1, 1);
    ASSERT_NE(cp1, 2);
}

TEST(CodepointTest, IntegralAssign) {
    constexpr codepoint cp1{1};
    int i;
    i = int(cp1);
    ASSERT_EQ(1, i);
}

TEST(CodepointTest, AddSubAssign) {
    codepoint cp1{1};
    codepoint cp2 = (cp1 += 1);
    ASSERT_EQ(cp1, 2);
    ASSERT_EQ(cp2, cp1);
    codepoint cp3 = (cp2 -= 2);
    ASSERT_EQ(cp3, 0);
    ASSERT_EQ(cp3, cp2);

    codepoint cp4 = 0;
    (cp4 += 1) += 2;
    ASSERT_EQ(cp4, 3);

}

TEST(CodepointTest, AddSub) {
    codepoint cp1{1};
    codepoint cp2 = (cp1 + 1);
    ASSERT_EQ(cp1, 1);
    ASSERT_EQ(cp2, 2);
    codepoint cp3 = (cp2 - 2);
    ASSERT_EQ(cp3, 0);
    ASSERT_EQ(cp2, 2);

    codepoint cp4 = (cp3 + 2) + 1;
    ASSERT_EQ(cp3, 3);
}

TEST(CodepointTest, IncDec) {
    codepoint cp1;
    cp1 = 1;
    codepoint t1 = cp1++;
    ASSERT_EQ(t1, 1);
    ASSERT_EQ(cp1, 2);

    codepoint t2 = ++cp1;
    ASSERT_EQ(t2, 3);
    ASSERT_EQ(cp1, 3);

    codepoint t3 = cp1--;
    ASSERT_EQ(t3, 3);
    ASSERT_EQ(cp1, 2);

    codepoint t4 = --cp1;
    ASSERT_EQ(t4, 1);
    ASSERT_EQ(cp1, 1);

    codepoint& r1 = ++cp1;
    codepoint& r2 = --cp1;
}

TEST(CodepointTest, Diff) {
    constexpr codepoint cp1{1};
    constexpr codepoint cp2{3};
    constexpr ptrdiff_t diff = (cp2 - cp1);
    ASSERT_EQ(diff, 2);
}

TEST(CodepointTest, Compare) {
    constexpr codepoint cp1{1};
    constexpr codepoint cp2{3};

    ASSERT_TRUE((cp1 == cp1));
    ASSERT_TRUE((cp1 != cp2));
    ASSERT_TRUE((cp1 < cp2));
    ASSERT_TRUE((cp1 <= cp1));
    ASSERT_TRUE((cp2 > cp1));
    ASSERT_TRUE((cp2 >= cp2));
}

TEST(CodepointTest, Stream) {
    std::ostringstream stream;
    constexpr codepoint cp1{'b'};
    stream << cp1;
    //   ASSERT_EQ(stream.str(), "b");
    ASSERT_EQ(stream.str(), "98");
}
