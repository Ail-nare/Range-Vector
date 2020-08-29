//
// Created by Ail on 27/08/2020.
//

#include "gtest/gtest.h"
#include "testes_helper.hpp"
#include "range/xrange.hpp"

TEST(numeric_three_args, basic_test)
{
    EXPECT_EQ("{}", Tests::str(xrange(0, 0, 1)));
    EXPECT_EQ("{0}", Tests::str(xrange(0, 1, 1)));
    EXPECT_EQ("{0, 1}", Tests::str(xrange(0, 2, 1)));
    EXPECT_EQ("{0, 1, 2}", Tests::str(xrange(0, 3, 1)));
    EXPECT_EQ("{0, 1, 2, 3}", Tests::str(xrange(0, 4, 1)));

    EXPECT_EQ("{0, 1, 2, 3}", Tests::str(xrange(0, 4, 1)));
    EXPECT_EQ("{1, 2, 3}", Tests::str(xrange(1, 4, 1)));
    EXPECT_EQ("{2, 3}", Tests::str(xrange(2, 4, 1)));
    EXPECT_EQ("{3}", Tests::str(xrange(3, 4, 1)));
    EXPECT_EQ("{}", Tests::str(xrange(4, 4, 1)));

    EXPECT_EQ("{}", Tests::str(xrange(-2, -2, 1)));
    EXPECT_EQ("{-2}", Tests::str(xrange(-2, -1, 1)));
    EXPECT_EQ("{-2, -1}", Tests::str(xrange(-2, 0, 1)));
    EXPECT_EQ("{-2, -1, 0}", Tests::str(xrange(-2, 1, 1)));
    EXPECT_EQ("{-2, -1, 0, 1}", Tests::str(xrange(-2, 2, 1)));

    EXPECT_EQ("{-2, -1, 0, 1}", Tests::str(xrange(-2, 2, 1)));
    EXPECT_EQ("{-1, 0, 1}", Tests::str(xrange(-1, 2, 1)));
    EXPECT_EQ("{0, 1}", Tests::str(xrange(0, 2, 1)));
    EXPECT_EQ("{1}", Tests::str(xrange(1, 2, 1)));
    EXPECT_EQ("{}", Tests::str(xrange(2, 2, 1)));


    EXPECT_EQ("{}", Tests::str(xrange(0, 0, 2)));
    EXPECT_EQ("{0}", Tests::str(xrange(0, 1, 2)));
    EXPECT_EQ("{0}", Tests::str(xrange(0, 2, 2)));
    EXPECT_EQ("{0, 2}", Tests::str(xrange(0, 3, 2)));
    EXPECT_EQ("{0, 2}", Tests::str(xrange(0, 4, 2)));
    EXPECT_EQ("{0, 2, 4}", Tests::str(xrange(0, 5, 2)));
    EXPECT_EQ("{0, 2, 4}", Tests::str(xrange(0, 6, 2)));
    EXPECT_EQ("{0, 2, 4, 6}", Tests::str(xrange(0, 7, 2)));

    EXPECT_EQ("{0, 2, 4, 6}", Tests::str(xrange(0, 7, 2)));
    EXPECT_EQ("{1, 3, 5}", Tests::str(xrange(1, 7, 2)));
    EXPECT_EQ("{2, 4, 6}", Tests::str(xrange(2, 7, 2)));
    EXPECT_EQ("{3, 5}", Tests::str(xrange(3, 7, 2)));
    EXPECT_EQ("{4, 6}", Tests::str(xrange(4, 7, 2)));
    EXPECT_EQ("{5}", Tests::str(xrange(5, 7, 2)));
    EXPECT_EQ("{6}", Tests::str(xrange(6, 7, 2)));
    EXPECT_EQ("{}", Tests::str(xrange(7, 7, 2)));

    EXPECT_EQ("{}", Tests::str(xrange(-2, -2, 2)));
    EXPECT_EQ("{-2}", Tests::str(xrange(-2, -1, 2)));
    EXPECT_EQ("{-2}", Tests::str(xrange(-2, 0, 2)));
    EXPECT_EQ("{-2, 0}", Tests::str(xrange(-2, 1, 2)));
    EXPECT_EQ("{-2, 0}", Tests::str(xrange(-2, 2, 2)));
    EXPECT_EQ("{-2, 0, 2}", Tests::str(xrange(-2, 3, 2)));
    EXPECT_EQ("{-2, 0, 2}", Tests::str(xrange(-2, 4, 2)));
    EXPECT_EQ("{-2, 0, 2, 4}", Tests::str(xrange(-2, 5, 2)));

    EXPECT_EQ("{-2, 0, 2, 4}", Tests::str(xrange(-2, 5, 2)));
    EXPECT_EQ("{-1, 1, 3}", Tests::str(xrange(-1, 5, 2)));
    EXPECT_EQ("{0, 2, 4}", Tests::str(xrange(0, 5, 2)));
    EXPECT_EQ("{1, 3}", Tests::str(xrange(1, 5, 2)));
    EXPECT_EQ("{2, 4}", Tests::str(xrange(2, 5, 2)));
    EXPECT_EQ("{3}", Tests::str(xrange(3, 5, 2)));
    EXPECT_EQ("{4}", Tests::str(xrange(4, 5, 2)));
    EXPECT_EQ("{}", Tests::str(xrange(5, 5, 2)));

}

TEST(numeric_three_args, negative_step_test)
{
    EXPECT_EQ("{}", Tests::str(xrange(0, 0, -1)));
    EXPECT_EQ("{1}", Tests::str(xrange(1, 0, -1)));
    EXPECT_EQ("{2, 1}", Tests::str(xrange(2, 0, -1)));
    EXPECT_EQ("{3, 2, 1}", Tests::str(xrange(3, 0, -1)));
    EXPECT_EQ("{4, 3, 2, 1}", Tests::str(xrange(4, 0, -1)));

    EXPECT_EQ("{4, 3, 2, 1}", Tests::str(xrange(4, 0, -1)));
    EXPECT_EQ("{4, 3, 2}", Tests::str(xrange(4, 1, -1)));
    EXPECT_EQ("{4, 3}", Tests::str(xrange(4, 2, -1)));
    EXPECT_EQ("{4}", Tests::str(xrange(4, 3, -1)));
    EXPECT_EQ("{}", Tests::str(xrange(4, 4, -1)));

    EXPECT_EQ("{}", Tests::str(xrange(-2, -2, -1)));
    EXPECT_EQ("{-1}", Tests::str(xrange(-1, -2, -1)));
    EXPECT_EQ("{0, -1}", Tests::str(xrange(0, -2, -1)));
    EXPECT_EQ("{1, 0, -1}", Tests::str(xrange(1, -2, -1)));
    EXPECT_EQ("{2, 1, 0, -1}", Tests::str(xrange(2, -2, -1)));

    EXPECT_EQ("{2, 1, 0, -1}", Tests::str(xrange(2, -2, -1)));
    EXPECT_EQ("{2, 1, 0}", Tests::str(xrange(2, -1, -1)));
    EXPECT_EQ("{2, 1}", Tests::str(xrange(2, 0, -1)));
    EXPECT_EQ("{2}", Tests::str(xrange(2, 1, -1)));
    EXPECT_EQ("{}", Tests::str(xrange(2, 2, -1)));


    EXPECT_EQ("{}", Tests::str(xrange(0, 0, -2)));
    EXPECT_EQ("{1}", Tests::str(xrange(1, 0, -2)));
    EXPECT_EQ("{2}", Tests::str(xrange(2, 0, -2)));
    EXPECT_EQ("{3, 1}", Tests::str(xrange(3, 0, -2)));
    EXPECT_EQ("{4, 2}", Tests::str(xrange(4, 0, -2)));
    EXPECT_EQ("{5, 3, 1}", Tests::str(xrange(5, 0, -2)));
    EXPECT_EQ("{6, 4, 2}", Tests::str(xrange(6, 0, -2)));
    EXPECT_EQ("{7, 5, 3, 1}", Tests::str(xrange(7, 0, -2)));

    EXPECT_EQ("{7, 5, 3, 1}", Tests::str(xrange(7, 0, -2)));
    EXPECT_EQ("{7, 5, 3}", Tests::str(xrange(7, 1, -2)));
    EXPECT_EQ("{7, 5, 3}", Tests::str(xrange(7, 2, -2)));
    EXPECT_EQ("{7, 5}", Tests::str(xrange(7, 3, -2)));
    EXPECT_EQ("{7, 5}", Tests::str(xrange(7, 4, -2)));
    EXPECT_EQ("{7}", Tests::str(xrange(7, 5, -2)));
    EXPECT_EQ("{7}", Tests::str(xrange(7, 6, -2)));
    EXPECT_EQ("{}", Tests::str(xrange(7, 7, -2)));


    EXPECT_EQ("{}", Tests::str(xrange(-2, -2, -2)));
    EXPECT_EQ("{-1}", Tests::str(xrange(-1, -2, -2)));
    EXPECT_EQ("{0}", Tests::str(xrange(0, -2, -2)));
    EXPECT_EQ("{1, -1}", Tests::str(xrange(1, -2, -2)));
    EXPECT_EQ("{2, 0}", Tests::str(xrange(2, -2, -2)));
    EXPECT_EQ("{3, 1, -1}", Tests::str(xrange(3, -2, -2)));
    EXPECT_EQ("{4, 2, 0}", Tests::str(xrange(4, -2, -2)));
    EXPECT_EQ("{5, 3, 1, -1}", Tests::str(xrange(5, -2, -2)));

    EXPECT_EQ("{5, 3, 1, -1}", Tests::str(xrange(5, -2, -2)));
    EXPECT_EQ("{5, 3, 1}", Tests::str(xrange(5, -1, -2)));
    EXPECT_EQ("{5, 3, 1}", Tests::str(xrange(5, 0, -2)));
    EXPECT_EQ("{5, 3}", Tests::str(xrange(5, 1, -2)));
    EXPECT_EQ("{5, 3}", Tests::str(xrange(5, 2, -2)));
    EXPECT_EQ("{5}", Tests::str(xrange(5, 3, -2)));
    EXPECT_EQ("{5}", Tests::str(xrange(5, 4, -2)));
    EXPECT_EQ("{}", Tests::str(xrange(5, 5, -2)));
}

TEST(xrange_three_args, exception_tests)
{
    xrange<int> trash{0};

    // step 0
    EXPECT_THROW(trash = xrange({}, {}, 0), std::overflow_error);

    // inverted start and end from step
    EXPECT_THROW(trash = xrange(5, 2, 1), std::out_of_range);
    EXPECT_THROW(trash = xrange(2, 5, -1), std::out_of_range);
}

TEST(xrange_three_args, reverse)
{
    constexpr xrange range1 = xrange(0, 8, 2).reverse();
    EXPECT_EQ("{6, 4, 2, 0}", Tests::str(range1));

    xrange range2 = xrange(0, 8, 2);

    range2 = range2.reverse();
    EXPECT_EQ("{6, 4, 2, 0}", Tests::str(range2));
}

TEST(xrange_three_args, size)
{
    EXPECT_EQ(0, xrange(0, 0, 2).size());
    EXPECT_EQ(1, xrange(0, 1, 2).size());
    EXPECT_EQ(1, xrange(0, 2, 2).size());
    EXPECT_EQ(2, xrange(0, 3, 2).size());

    EXPECT_EQ(1, xrange(0, 3, 3).size());
    EXPECT_EQ(2, xrange(0, 4, 3).size());

    constexpr size_t constexpr_int = xrange(0, 100, 2).size();

    EXPECT_EQ(50, constexpr_int);

    EXPECT_EQ(3, xrange(0, 4, 3)[1]);
}