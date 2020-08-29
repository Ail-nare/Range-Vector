//
// Created by Ail on 27/08/2020.
//

#include "gtest/gtest.h"
#include "testes_helper.hpp"
#include "range/xrange.hpp"

TEST(numeric_two_args, basic_test)
{
    EXPECT_EQ("{}", Tests::str(xrange(0, 0)));
    EXPECT_EQ("{0}", Tests::str(xrange(0, 1)));
    EXPECT_EQ("{0, 1}", Tests::str(xrange(0, 2)));
    EXPECT_EQ("{0, 1, 2}", Tests::str(xrange(0, 3)));
    EXPECT_EQ("{0, 1, 2, 3}", Tests::str(xrange(0, 4)));

    EXPECT_EQ("{0, 1, 2, 3}", Tests::str(xrange(0, 4)));
    EXPECT_EQ("{1, 2, 3}", Tests::str(xrange(1, 4)));
    EXPECT_EQ("{2, 3}", Tests::str(xrange(2, 4)));
    EXPECT_EQ("{3}", Tests::str(xrange(3, 4)));
    EXPECT_EQ("{}", Tests::str(xrange(4, 4)));

    EXPECT_EQ("{}", Tests::str(xrange(-2, -2)));
    EXPECT_EQ("{-2}", Tests::str(xrange(-2, -1)));
    EXPECT_EQ("{-2, -1}", Tests::str(xrange(-2, 0)));
    EXPECT_EQ("{-2, -1, 0}", Tests::str(xrange(-2, 1)));
    EXPECT_EQ("{-2, -1, 0, 1}", Tests::str(xrange(-2, 2)));

    EXPECT_EQ("{-2, -1, 0, 1}", Tests::str(xrange(-2, 2)));
    EXPECT_EQ("{-1, 0, 1}", Tests::str(xrange(-1, 2)));
    EXPECT_EQ("{0, 1}", Tests::str(xrange(0, 2)));
    EXPECT_EQ("{1}", Tests::str(xrange(1, 2)));
    EXPECT_EQ("{}", Tests::str(xrange(2, 2)));

}

TEST(numeric_two_args, inverted_test)
{
    EXPECT_EQ("{}", Tests::str(xrange(0, 0)));
    EXPECT_EQ("{1}", Tests::str(xrange(1, 0)));
    EXPECT_EQ("{2, 1}", Tests::str(xrange(2, 0)));
    EXPECT_EQ("{3, 2, 1}", Tests::str(xrange(3, 0)));
    EXPECT_EQ("{4, 3, 2, 1}", Tests::str(xrange(4, 0)));

    EXPECT_EQ("{4, 3, 2, 1}", Tests::str(xrange(4, 0)));
    EXPECT_EQ("{4, 3, 2}", Tests::str(xrange(4, 1)));
    EXPECT_EQ("{4, 3}", Tests::str(xrange(4, 2)));
    EXPECT_EQ("{4}", Tests::str(xrange(4, 3)));
    EXPECT_EQ("{}", Tests::str(xrange(4, 4)));

    EXPECT_EQ("{}", Tests::str(xrange(-2, -2)));
    EXPECT_EQ("{-1}", Tests::str(xrange(-1, -2)));
    EXPECT_EQ("{0, -1}", Tests::str(xrange(0, -2)));
    EXPECT_EQ("{1, 0, -1}", Tests::str(xrange(1, -2)));
    EXPECT_EQ("{2, 1, 0, -1}", Tests::str(xrange(2, -2)));

    EXPECT_EQ("{2, 1, 0, -1}", Tests::str(xrange(2, -2)));
    EXPECT_EQ("{2, 1, 0}", Tests::str(xrange(2, -1)));
    EXPECT_EQ("{2, 1}", Tests::str(xrange(2, 0)));
    EXPECT_EQ("{2}", Tests::str(xrange(2, 1)));
    EXPECT_EQ("{}", Tests::str(xrange(2, 2)));
}