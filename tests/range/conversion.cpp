//
// Created by Ail on 22/08/2020.
//

#include "gtest/gtest.h"
#include "testes_helper.hpp"

#include <stack>

TEST(range_conversion, const)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};

    const range c_r1(src); // from: src
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(c_r1));

    range<const std::vector<int>> rc_1(c_r1); // from: const range
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(rc_1));

    const range c_r2(c_r1); // from: const range
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(c_r2));

    range<const std::vector<int>> rc_2(rc_1); // from: range<const>
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(rc_2));

    //const range<std::vector<int>> rc_3(rc_1); // from: range<const> // shouldn't compile compile
    //EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(rc_3));

    range<std::vector<int>> r1(c_r1); // from: const range
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r1));

    rc_2 = rc_2;
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(rc_2));

    r1 = std::move(c_r1);
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r1));

    rc_2 = std::move(rc_1);
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(rc_2));

    range c_r3(std::move(r1));
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(c_r3));

    range rc_3(std::move(rc_1));
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(rc_3));
}

TEST(range_conversion, back_to_original_reserve)
{
    const std::vector src = {1, 2, 3, 4, 5, 6, 7};
    auto new_vector = std::vector<int>(range(src)({}, {}, 2));

    EXPECT_EQ("{1, 3, 5, 7}", Tests::str(new_vector));

    new_vector = std::vector<int>(range(src)(1, -2, 2));
    EXPECT_EQ("{2, 4}", Tests::str(new_vector));
}

TEST(range_conversion, from_iterator)
{
    const std::vector src = {1, 2, 3, 4, 5, 6, 7};
    range<const std::vector<int>> range1(src.begin(), src.end());

    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(range1));
}

TEST(range_conversion, to)
{
    // Use of the small overload on the constructor
    constexpr range range1("1234567");

    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(range1));
    EXPECT_EQ("1234567", range1.to<std::string>());
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(range1.to<std::vector<char>>()));

    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(range1.constexpr_to<std::array<char, range1.size()>>()));
    {
        constexpr range range2 = range1(1, -1);
        // constexpr
        EXPECT_EQ("{2, 3, 4, 5, 6}", Tests::str(range2.constexpr_to<std::array<char, range2.size()>>()));
        EXPECT_EQ("{2, 3, 4, 5, 6}", Tests::str(range2.constexpr_to<std::array<char, range2.size()>>()));

        // not constexpr
        EXPECT_EQ("{2, 3, 4, 5, 6}", Tests::str(range2.to<std::array<char, range2.size()>>()));
        EXPECT_EQ("{2, 3, 4, 5, 6}", Tests::str(range2.to<std::array<char, range2.size()>>()));
    }

    { // Test for container with push_back() but no reserve(size_t)
        class my_stack : public std::stack<char> {
        public:
            void push_back(char c) {
                this->push(c);
            }
        };
        auto stack = range1.to<my_stack>();
        range range_inv = range1.reverse();

        for (; range_inv.size(); range_inv = range_inv(1), stack.pop())
            EXPECT_EQ(range_inv[0], stack.top());
    }
}

TEST(range_conversion, to_lambda)
{
    // Use of the small overload on the constructor
    constexpr range range1("1234567");

    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(range1));

    // convert constexpr char[N] to vector<int>
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(range1.to<std::vector<int>>([] (char c) constexpr noexcept -> int { return c - '0'; })));

    // convert constexpr char[N] to constexpr std::array<int, N>
    constexpr auto array = range1.constexpr_to<std::array<int, range1.size()>>([] (char c) constexpr noexcept -> int { return c - '0'; });
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(array));

    // convert constexpr char[N] to std::array<int, N>
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(range1.to<std::array<int, range1.size()>>([] (char c) constexpr noexcept -> int { return c - '0'; })));
}

TEST(range_conversion, to_container_lambda)
{
    // Use of the small overload on the constructor
    constexpr range range1("456");

    {
        std::vector<char> vector = {'1', '2', '3'};
        EXPECT_EQ("{1, 2, 3}", Tests::str(vector));

        range1.to(vector);
        EXPECT_EQ("{1, 2, 3, 4, 5, 6}", Tests::str(vector));
    }

    {
        std::vector<int> vector = {1, 2, 3};

        EXPECT_EQ("{1, 2, 3}", Tests::str(vector));

        range1.to(vector, [] (char c) constexpr noexcept -> int { return c - '0'; });
        EXPECT_EQ("{1, 2, 3, 4, 5, 6}", Tests::str(vector));
    }
}