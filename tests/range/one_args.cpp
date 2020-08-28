//
// Created by Ail on 11/08/2020.
//

#include "gtest/gtest.h"
#include "testes_helper.hpp"

TEST(range_one_args, basic_test)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    range r_src(src);

    // origin
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src));

    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src(0)));
    EXPECT_EQ("{2, 3, 4, 5, 6, 7}", Tests::str(r_src(1)));
    EXPECT_EQ("{3, 4, 5, 6, 7}", Tests::str(r_src(2)));
    EXPECT_EQ("{4, 5, 6, 7}", Tests::str(r_src(3)));
    EXPECT_EQ("{5, 6, 7}", Tests::str(r_src(4)));
    EXPECT_EQ("{6, 7}", Tests::str(r_src(5)));
    EXPECT_EQ("{7}", Tests::str(r_src(6)));
    EXPECT_EQ("{}", Tests::str(r_src(7)));
}

TEST(const_range_one_args, basic_test)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    const range r_src(src);

    // origin
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src));

    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src(0)));
    EXPECT_EQ("{2, 3, 4, 5, 6, 7}", Tests::str(r_src(1)));
    EXPECT_EQ("{3, 4, 5, 6, 7}", Tests::str(r_src(2)));
    EXPECT_EQ("{4, 5, 6, 7}", Tests::str(r_src(3)));
    EXPECT_EQ("{5, 6, 7}", Tests::str(r_src(4)));
    EXPECT_EQ("{6, 7}", Tests::str(r_src(5)));
    EXPECT_EQ("{7}", Tests::str(r_src(6)));
    EXPECT_EQ("{}", Tests::str(r_src(7)));
}

TEST(range_one_args, negitive_test)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    range r_src(src);

    // origin
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src));

    EXPECT_EQ("{7}", Tests::str(r_src(-1)));
    EXPECT_EQ("{6, 7}", Tests::str(r_src(-2)));
    EXPECT_EQ("{5, 6, 7}", Tests::str(r_src(-3)));
    EXPECT_EQ("{4, 5, 6, 7}", Tests::str(r_src(-4)));
    EXPECT_EQ("{3, 4, 5, 6, 7}", Tests::str(r_src(-5)));
    EXPECT_EQ("{2, 3, 4, 5, 6, 7}", Tests::str(r_src(-6)));
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src(-7)));
}

TEST(const_range_one_args, negitive_test)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    const range r_src(src);

    // origin
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src));

    EXPECT_EQ("{7}", Tests::str(r_src(-1)));
    EXPECT_EQ("{6, 7}", Tests::str(r_src(-2)));
    EXPECT_EQ("{5, 6, 7}", Tests::str(r_src(-3)));
    EXPECT_EQ("{4, 5, 6, 7}", Tests::str(r_src(-4)));
    EXPECT_EQ("{3, 4, 5, 6, 7}", Tests::str(r_src(-5)));
    EXPECT_EQ("{2, 3, 4, 5, 6, 7}", Tests::str(r_src(-6)));
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src(-7)));
}

TEST(range_one_args, multy_range_test)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    range r_src(src);

    // origin
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src));

    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src(0)(0)));
    EXPECT_EQ("{2, 3, 4, 5, 6, 7}", Tests::str(r_src(1)));
    EXPECT_EQ("{3, 4, 5, 6, 7}", Tests::str(r_src(1)(1)));
    EXPECT_EQ("{4, 5, 6, 7}", Tests::str(r_src(1)(1)(1)));
    EXPECT_EQ("{5, 6, 7}", Tests::str(r_src(1)(1)(1)(1)));
    EXPECT_EQ("{6, 7}", Tests::str(r_src(1)(1)(1)(1)(1)));
    EXPECT_EQ("{7}", Tests::str(r_src(1)(1)(1)(1)(1)(1)));
    EXPECT_EQ("{7}", Tests::str(r_src(1)(1)(2)(1)(1)));
    EXPECT_EQ("{}", Tests::str(r_src(1)(1)(1)(1)(1)(1)(1)));
}

TEST(const_range_one_args, multy_range_test)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    const range r_src(src);

    // origin
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src));

    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src(0)(0)));
    EXPECT_EQ("{2, 3, 4, 5, 6, 7}", Tests::str(r_src(1)));
    EXPECT_EQ("{3, 4, 5, 6, 7}", Tests::str(r_src(1)(1)));
    EXPECT_EQ("{4, 5, 6, 7}", Tests::str(r_src(1)(1)(1)));
    EXPECT_EQ("{5, 6, 7}", Tests::str(r_src(1)(1)(1)(1)));
    EXPECT_EQ("{6, 7}", Tests::str(r_src(1)(1)(1)(1)(1)));
    EXPECT_EQ("{7}", Tests::str(r_src(1)(1)(1)(1)(1)(1)));
    EXPECT_EQ("{7}", Tests::str(r_src(1)(1)(2)(1)(1)));
    EXPECT_EQ("{}", Tests::str(r_src(1)(1)(1)(1)(1)(1)(1)));
}

TEST(range_one_args, empty_test)
{
    std::vector<int> src = {};
    range r_src(src);

    // origin
    EXPECT_EQ("{}", Tests::str(r_src));

    EXPECT_EQ("{}", Tests::str(r_src(0)));
    EXPECT_EQ("{}", Tests::str(r_src(0)(0)));
    EXPECT_EQ("{}", Tests::str(r_src(0)(0)(0)));
    EXPECT_EQ("{}", Tests::str(r_src(0)(0)(0)(0)));
}

TEST(const_range_one_args, empty_test)
{
    std::vector<int> src = {};
    const range r_src(src);

    // origin
    EXPECT_EQ("{}", Tests::str(r_src));

    EXPECT_EQ("{}", Tests::str(r_src(0)));
    EXPECT_EQ("{}", Tests::str(r_src(0)(0)));
    EXPECT_EQ("{}", Tests::str(r_src(0)(0)(0)));
    EXPECT_EQ("{}", Tests::str(r_src(0)(0)(0)(0)));
}

TEST(range_one_args, exception_test)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    range r_src(src);
    range trash = r_src;

    EXPECT_THROW(trash = r_src(200), std::out_of_range);
    EXPECT_THROW(trash = r_src(8), std::out_of_range);
    EXPECT_THROW(trash = r_src(-8), std::out_of_range);
    EXPECT_THROW(trash = r_src(-200), std::out_of_range);

    src = {};
    r_src = range(src);
    EXPECT_THROW(trash = r_src(200), std::out_of_range);
    EXPECT_THROW(trash = r_src(1), std::out_of_range);
    EXPECT_THROW(trash = r_src(-1), std::out_of_range);
    EXPECT_THROW(trash = r_src(200), std::out_of_range);
}

TEST(const_range_one_args, exception_test)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    const range r_src(src);
    range<const std::vector<int>> trash(r_src);

    EXPECT_THROW(trash = r_src(200), std::out_of_range);
    EXPECT_THROW(trash = r_src(8), std::out_of_range);
    EXPECT_THROW(trash = r_src(-8), std::out_of_range);
    EXPECT_THROW(trash = r_src(-200), std::out_of_range);

    std::vector<int> src2 = {};
    const range r_src2 = range(src2);
    EXPECT_THROW(trash = r_src2(200), std::out_of_range);
    EXPECT_THROW(trash = r_src2(1), std::out_of_range);
    EXPECT_THROW(trash = r_src2(-1), std::out_of_range);
    EXPECT_THROW(trash = r_src2(200), std::out_of_range);
}