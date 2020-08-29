//
// Created by Ail on 27/08/2020.
//

#include "gtest/gtest.h"
#include "testes_helper.hpp"
#include "range/xrange.hpp"

TEST(numeric_one_args, basic_test)
{
    EXPECT_FALSE((std::is_same<decltype(xrange(0)), decltype(xrange(0l))>::value));

    EXPECT_EQ("{}", Tests::str(xrange(0)));
    EXPECT_EQ("{0}", Tests::str(xrange(1)));
    EXPECT_EQ("{0, 1}", Tests::str(xrange(2)));
    EXPECT_EQ("{0, 1, 2}", Tests::str(xrange(3)));
    EXPECT_EQ("{0, 1, 2, 3}", Tests::str(xrange(4)));
}

TEST(numeric_one_args, negative_test)
{
    EXPECT_EQ("{}", Tests::str(xrange(-0))); // 0 == -0
    EXPECT_EQ("{0}", Tests::str(xrange(-1)));
    EXPECT_EQ("{0, -1}", Tests::str(xrange(-2)));
    EXPECT_EQ("{0, -1, -2}", Tests::str(xrange(-3)));
    EXPECT_EQ("{0, -1, -2, -3}", Tests::str(xrange(-4)));
}