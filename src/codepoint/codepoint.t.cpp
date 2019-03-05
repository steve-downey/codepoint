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
    codepoint cp7 = codepoint(c32);
    cp1 = cp2;
    ASSERT_EQ(cp1, codepoint(0));
    cp1 = codepoint(c32);
    ASSERT_EQ(cp1, codepoint(0x1234));

    codepoint a = codepoint('a');
    ASSERT_EQ(a, codepoint('a'));

    codepoint a8 = codepoint(u8'a');
    ASSERT_EQ(a8, codepoint('a'));

}

TEST(CodepointTest, IntegralCompare) {
    constexpr codepoint cp1{1};

    ASSERT_EQ(codepoint(1), cp1);
    ASSERT_NE(codepoint(2), cp1);
    ASSERT_EQ(cp1, codepoint(1));
    ASSERT_NE(cp1, codepoint(2));
}

TEST(CodepointTest, IntegralAssign) {
    constexpr codepoint cp1{1};
    int i;
    i = int(cp1);
    ASSERT_EQ(1, i);
}

// TEST(CodepointTest, AddSubAssign) {
//     codepoint cp1{1};
//     codepoint cp2 = (cp1 += 1);
//     ASSERT_EQ(cp1, 2);
//     ASSERT_EQ(cp2, cp1);
//     codepoint cp3 = (cp2 -= 2);
//     ASSERT_EQ(cp3, 0);
//     ASSERT_EQ(cp3, cp2);

//     codepoint cp4 = 0;
//     (cp4 += 1) += 2;
//     ASSERT_EQ(cp4, 3);
// }

// TEST(CodepointTest, ConstExprAddSubAssign) {
//     constexpr codepoint cp2 = (codepoint{1} += 1);
//     ASSERT_EQ(cp2, 2);
//     constexpr codepoint cp3 = (codepoint{2} -= 2);
//     ASSERT_EQ(cp3, 0);
// }

TEST(CodepointTest, AddSub) {
    codepoint cp1{1};
    codepoint cp2 = codepoint(to_integer<int>(cp1) + 1);
    ASSERT_EQ(cp1, codepoint(1));
    ASSERT_EQ(cp2, codepoint(2));
    codepoint cp3 = codepoint(char32_t(cp2) - 2);
    ASSERT_EQ(cp3, codepoint(0));
    ASSERT_EQ(cp2, codepoint(2));

    codepoint cp4 = codepoint((to_integer<char32_t>(cp3) + 2) + 1);
    ASSERT_EQ(cp4, codepoint(3));

    codepoint cp5 = codepoint(1 + to_integer<int>(cp1));
    ASSERT_EQ(cp5, codepoint(2));

    codepoint cp6 = codepoint(1 - to_integer<int>(cp1));
    ASSERT_EQ(cp6, codepoint(0));
}

TEST(CodepointTest, ConstExprAddSub) {
    constexpr codepoint cp1{1};
    constexpr codepoint cp2 = codepoint(to_integer<int>(cp1) + 1);
    ASSERT_EQ(cp1, codepoint(1));
    ASSERT_EQ(cp2, codepoint(2));
    constexpr codepoint cp3 = codepoint(to_integer<int>(cp2) - 2);
    ASSERT_EQ(cp3, codepoint(0));
    ASSERT_EQ(cp2, codepoint(2));

    constexpr codepoint cp4 = codepoint((to_integer<int>(cp3) + 2) + 1);
    ASSERT_EQ(cp4, codepoint(3));
}

// TEST(CodepointTest, IncDec) {
//     codepoint cp1;
//     cp1 = 1;
//     codepoint t1 = cp1++;
//     ASSERT_EQ(t1, 1);
//     ASSERT_EQ(cp1, 2);

//     codepoint t2 = ++cp1;
//     ASSERT_EQ(t2, 3);
//     ASSERT_EQ(cp1, 3);

//     codepoint t3 = cp1--;
//     ASSERT_EQ(t3, 3);
//     ASSERT_EQ(cp1, 2);

//     codepoint t4 = --cp1;
//     ASSERT_EQ(t4, 1);
//     ASSERT_EQ(cp1, 1);

//     codepoint& r1 = ++cp1;
//     codepoint& r2 = --cp1;
// }

// TEST(CodepointTest, ConstExprIncDec) {
//     constexpr codepoint t1 = codepoint{4}++;
//     ASSERT_EQ(t1, 4);

//     constexpr codepoint t2 = ++codepoint{4};
//     ASSERT_EQ(t2, 5);

//     constexpr codepoint t3 = codepoint{4}--;
//     ASSERT_EQ(t3, 4);

//     constexpr codepoint t4 = --codepoint{4};
//     ASSERT_EQ(t4, 3);
// }

TEST(CodepointTest, Diff) {
    constexpr codepoint cp1{1};
    constexpr codepoint cp2{3};
    constexpr ptrdiff_t diff = (char32_t(cp2) - char32_t(cp1));
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
    stream << char32_t(cp1);
    //   ASSERT_EQ(stream.str(), "b");
    ASSERT_EQ(stream.str(), "98");
}
