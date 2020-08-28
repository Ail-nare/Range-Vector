//
// Created by Ail on 11/08/2020.
//

#include "gtest/gtest.h"
#include "testes_helper.hpp"

TEST(range_two_args, basic_test)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    range r_src(src);

    // origin
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src));
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src({}, {})));

    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src(0, {})));
    EXPECT_EQ("{2, 3, 4, 5, 6, 7}", Tests::str(r_src(1, {})));
    EXPECT_EQ("{3, 4, 5, 6, 7}", Tests::str(r_src(2, {})));
    EXPECT_EQ("{4, 5, 6, 7}", Tests::str(r_src(3, {})));
    EXPECT_EQ("{5, 6, 7}", Tests::str(r_src(4, {})));
    EXPECT_EQ("{6, 7}", Tests::str(r_src(5, {})));
    EXPECT_EQ("{7}", Tests::str(r_src(6, {})));
    EXPECT_EQ("{}", Tests::str(r_src(7, {})));

    EXPECT_EQ("{1, 2, 3, 4, 5, 6}", Tests::str(r_src(0, -1)));
    EXPECT_EQ("{1, 2, 3, 4, 5, 6}", Tests::str(r_src(0, 6)));
    EXPECT_EQ("{2, 3, 4, 5, 6}", Tests::str(r_src(1, -1)));
    EXPECT_EQ("{3, 4, 5, 6}", Tests::str(r_src(2, -1)));
    EXPECT_EQ("{4, 5, 6}", Tests::str(r_src(3, -1)));
    EXPECT_EQ("{5, 6}", Tests::str(r_src(4, -1)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, -1)));
    EXPECT_EQ("{}", Tests::str(r_src(6, -1)));

    EXPECT_EQ("{1, 2, 3, 4, 5}", Tests::str(r_src(0, -2)));
    EXPECT_EQ("{2, 3, 4, 5}", Tests::str(r_src(1, -2)));
    EXPECT_EQ("{2, 3, 4, 5}", Tests::str(r_src(1, 5)));
    EXPECT_EQ("{3, 4, 5}", Tests::str(r_src(2, -2)));
    EXPECT_EQ("{4, 5}", Tests::str(r_src(3, -2)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, -2)));
    EXPECT_EQ("{}", Tests::str(r_src(5, -2)));

    EXPECT_EQ("{1, 2, 3, 4}", Tests::str(r_src(0, -3)));
    EXPECT_EQ("{2, 3, 4}", Tests::str(r_src(1, -3)));
    EXPECT_EQ("{3, 4}", Tests::str(r_src(2, -3)));
    EXPECT_EQ("{3, 4}", Tests::str(r_src(2, 4)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, -3)));
    EXPECT_EQ("{}", Tests::str(r_src(4, -3)));

    EXPECT_EQ("{1, 2, 3}", Tests::str(r_src(0, -4)));
    EXPECT_EQ("{2, 3}", Tests::str(r_src(1, -4)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, -4)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 3)));
    EXPECT_EQ("{}", Tests::str(r_src(3, -4)));

    EXPECT_EQ("{1, 2}", Tests::str(r_src(0, -5)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -5)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, 2)));
    EXPECT_EQ("{}", Tests::str(r_src(2, -5)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -6)));
    EXPECT_EQ("{1}", Tests::str(r_src(0, 1)));
    EXPECT_EQ("{}", Tests::str(r_src(1, -6)));

    EXPECT_EQ("{}", Tests::str(r_src(0, -7)));
    EXPECT_EQ("{}", Tests::str(r_src(0, 0)));
    EXPECT_EQ("{}", Tests::str(r_src(1, 1)));
    EXPECT_EQ("{}", Tests::str(r_src(2, 2)));
    EXPECT_EQ("{}", Tests::str(r_src(3, 3)));
    EXPECT_EQ("{}", Tests::str(r_src(4, 4)));
    EXPECT_EQ("{}", Tests::str(r_src(5, 5)));
    EXPECT_EQ("{}", Tests::str(r_src(6, 6)));
    EXPECT_EQ("{}", Tests::str(r_src(7, 7)));
}

TEST(const_range_two_args, basic_test)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    const range r_src(src);

    // origin
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src));
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src({}, {})));

    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src(0, {})));
    EXPECT_EQ("{2, 3, 4, 5, 6, 7}", Tests::str(r_src(1, {})));
    EXPECT_EQ("{3, 4, 5, 6, 7}", Tests::str(r_src(2, {})));
    EXPECT_EQ("{4, 5, 6, 7}", Tests::str(r_src(3, {})));
    EXPECT_EQ("{5, 6, 7}", Tests::str(r_src(4, {})));
    EXPECT_EQ("{6, 7}", Tests::str(r_src(5, {})));
    EXPECT_EQ("{7}", Tests::str(r_src(6, {})));
    EXPECT_EQ("{}", Tests::str(r_src(7, {})));

    EXPECT_EQ("{1, 2, 3, 4, 5, 6}", Tests::str(r_src(0, -1)));
    EXPECT_EQ("{1, 2, 3, 4, 5, 6}", Tests::str(r_src(0, 6)));
    EXPECT_EQ("{2, 3, 4, 5, 6}", Tests::str(r_src(1, -1)));
    EXPECT_EQ("{3, 4, 5, 6}", Tests::str(r_src(2, -1)));
    EXPECT_EQ("{4, 5, 6}", Tests::str(r_src(3, -1)));
    EXPECT_EQ("{5, 6}", Tests::str(r_src(4, -1)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, -1)));
    EXPECT_EQ("{}", Tests::str(r_src(6, -1)));

    EXPECT_EQ("{1, 2, 3, 4, 5}", Tests::str(r_src(0, -2)));
    EXPECT_EQ("{2, 3, 4, 5}", Tests::str(r_src(1, -2)));
    EXPECT_EQ("{2, 3, 4, 5}", Tests::str(r_src(1, 5)));
    EXPECT_EQ("{3, 4, 5}", Tests::str(r_src(2, -2)));
    EXPECT_EQ("{4, 5}", Tests::str(r_src(3, -2)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, -2)));
    EXPECT_EQ("{}", Tests::str(r_src(5, -2)));

    EXPECT_EQ("{1, 2, 3, 4}", Tests::str(r_src(0, -3)));
    EXPECT_EQ("{2, 3, 4}", Tests::str(r_src(1, -3)));
    EXPECT_EQ("{3, 4}", Tests::str(r_src(2, -3)));
    EXPECT_EQ("{3, 4}", Tests::str(r_src(2, 4)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, -3)));
    EXPECT_EQ("{}", Tests::str(r_src(4, -3)));

    EXPECT_EQ("{1, 2, 3}", Tests::str(r_src(0, -4)));
    EXPECT_EQ("{2, 3}", Tests::str(r_src(1, -4)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, -4)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 3)));
    EXPECT_EQ("{}", Tests::str(r_src(3, -4)));

    EXPECT_EQ("{1, 2}", Tests::str(r_src(0, -5)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -5)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, 2)));
    EXPECT_EQ("{}", Tests::str(r_src(2, -5)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -6)));
    EXPECT_EQ("{1}", Tests::str(r_src(0, 1)));
    EXPECT_EQ("{}", Tests::str(r_src(1, -6)));

    EXPECT_EQ("{}", Tests::str(r_src(0, -7)));
    EXPECT_EQ("{}", Tests::str(r_src(0, 0)));
    EXPECT_EQ("{}", Tests::str(r_src(1, 1)));
    EXPECT_EQ("{}", Tests::str(r_src(2, 2)));
    EXPECT_EQ("{}", Tests::str(r_src(3, 3)));
    EXPECT_EQ("{}", Tests::str(r_src(4, 4)));
    EXPECT_EQ("{}", Tests::str(r_src(5, 5)));
    EXPECT_EQ("{}", Tests::str(r_src(6, 6)));
    EXPECT_EQ("{}", Tests::str(r_src(7, 7)));
}

TEST(range_two_args, inverted_test)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    range r_src(src);

    // origin
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src));

    EXPECT_EQ("{7, 6, 5, 4, 3, 2}", Tests::str(r_src(-1, 0)));
    EXPECT_EQ("{7, 6, 5, 4, 3}", Tests::str(r_src(-1, 1)));
    EXPECT_EQ("{7, 6, 5, 4}", Tests::str(r_src(-1, 2)));
    EXPECT_EQ("{7, 6, 5}", Tests::str(r_src(-1, 3)));
    EXPECT_EQ("{7, 6}", Tests::str(r_src(-1, 4)));
    EXPECT_EQ("{7}", Tests::str(r_src(-1, 5)));
    EXPECT_EQ("{}", Tests::str(r_src(-1, 6)));

    EXPECT_EQ("{7, 6, 5, 4, 3, 2}", Tests::str(r_src(-1, 0)));
    EXPECT_EQ("{6, 5, 4, 3, 2}", Tests::str(r_src(-2, 0)));
    EXPECT_EQ("{5, 4, 3, 2}", Tests::str(r_src(-3, 0)));
    EXPECT_EQ("{4, 3, 2}", Tests::str(r_src(-4, 0)));
    EXPECT_EQ("{3, 2}", Tests::str(r_src(-5, 0)));
    EXPECT_EQ("{2}", Tests::str(r_src(-6, 0)));
    EXPECT_EQ("{}", Tests::str(r_src(-7, 0)));

    EXPECT_EQ("{7, 6, 5, 4, 3}", Tests::str(r_src(-1, 1)));
    EXPECT_EQ("{6, 5, 4, 3}", Tests::str(r_src(-2, 1)));
    EXPECT_EQ("{5, 4, 3}", Tests::str(r_src(-3, 1)));
    EXPECT_EQ("{4, 3}", Tests::str(r_src(-4, 1)));
    EXPECT_EQ("{3}", Tests::str(r_src(-5, 1)));

    EXPECT_EQ("{7, 6, 5, 4}", Tests::str(r_src(-1, 2)));
    EXPECT_EQ("{6, 5, 4}", Tests::str(r_src(-2, 2)));
    EXPECT_EQ("{5, 4}", Tests::str(r_src(-3, 2)));
    EXPECT_EQ("{4}", Tests::str(r_src(-4, 2)));
    EXPECT_EQ("{}", Tests::str(r_src(-5, 2)));
}

TEST(const_range_two_args, inverted_test)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    const range r_src(src);

    // origin
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src));

    EXPECT_EQ("{7, 6, 5, 4, 3, 2}", Tests::str(r_src(-1, 0)));
    EXPECT_EQ("{7, 6, 5, 4, 3}", Tests::str(r_src(-1, 1)));
    EXPECT_EQ("{7, 6, 5, 4}", Tests::str(r_src(-1, 2)));
    EXPECT_EQ("{7, 6, 5}", Tests::str(r_src(-1, 3)));
    EXPECT_EQ("{7, 6}", Tests::str(r_src(-1, 4)));
    EXPECT_EQ("{7}", Tests::str(r_src(-1, 5)));
    EXPECT_EQ("{}", Tests::str(r_src(-1, 6)));

    EXPECT_EQ("{7, 6, 5, 4, 3, 2}", Tests::str(r_src(-1, 0)));
    EXPECT_EQ("{6, 5, 4, 3, 2}", Tests::str(r_src(-2, 0)));
    EXPECT_EQ("{5, 4, 3, 2}", Tests::str(r_src(-3, 0)));
    EXPECT_EQ("{4, 3, 2}", Tests::str(r_src(-4, 0)));
    EXPECT_EQ("{3, 2}", Tests::str(r_src(-5, 0)));
    EXPECT_EQ("{2}", Tests::str(r_src(-6, 0)));
    EXPECT_EQ("{}", Tests::str(r_src(-7, 0)));

    EXPECT_EQ("{7, 6, 5, 4, 3}", Tests::str(r_src(-1, 1)));
    EXPECT_EQ("{6, 5, 4, 3}", Tests::str(r_src(-2, 1)));
    EXPECT_EQ("{5, 4, 3}", Tests::str(r_src(-3, 1)));
    EXPECT_EQ("{4, 3}", Tests::str(r_src(-4, 1)));
    EXPECT_EQ("{3}", Tests::str(r_src(-5, 1)));

    EXPECT_EQ("{7, 6, 5, 4}", Tests::str(r_src(-1, 2)));
    EXPECT_EQ("{6, 5, 4}", Tests::str(r_src(-2, 2)));
    EXPECT_EQ("{5, 4}", Tests::str(r_src(-3, 2)));
    EXPECT_EQ("{4}", Tests::str(r_src(-4, 2)));
    EXPECT_EQ("{}", Tests::str(r_src(-5, 2)));
}

TEST(range_two_args, empty_test)
{
    std::vector<int> src = {};
    range r_src(src);

    // origin
    EXPECT_EQ("{}", Tests::str(r_src));

    EXPECT_EQ("{}", Tests::str(r_src(0, 0)));
    EXPECT_EQ("{}", Tests::str(r_src(0, 0)(0, 0)));
    EXPECT_EQ("{}", Tests::str(r_src(0, 0)(0, 0)(0, {})));
    EXPECT_EQ("{}", Tests::str(r_src(0, 0)(0, {})(0, 0)(0, 0)));
}

TEST(const_range_two_args, empty_test)
{
    std::vector<int> src = {};
    const range r_src(src);

    // origin
    EXPECT_EQ("{}", Tests::str(r_src));

    EXPECT_EQ("{}", Tests::str(r_src(0, 0)));
    EXPECT_EQ("{}", Tests::str(r_src(0, 0)(0, 0)));
    EXPECT_EQ("{}", Tests::str(r_src(0, 0)(0, 0)(0, {})));
    EXPECT_EQ("{}", Tests::str(r_src(0, 0)(0, {})(0, 0)(0, 0)));
}

TEST(range_two_args, exception_test)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    range r_src(src);
    range trash = r_src;

    EXPECT_THROW(trash = r_src(200, {}), std::out_of_range);
    EXPECT_THROW(trash = r_src(8, {}), std::out_of_range);
    EXPECT_THROW(trash = r_src(-8, {}), std::out_of_range);
    EXPECT_THROW(trash = r_src(-200, {}), std::out_of_range);

    EXPECT_THROW(trash = r_src({}, 200), std::out_of_range);
    EXPECT_THROW(trash = r_src({}, 8), std::out_of_range);
    EXPECT_THROW(trash = r_src({}, -8), std::out_of_range);
    EXPECT_THROW(trash = r_src({}, 200), std::out_of_range);

    src = {};
    r_src = range(src);
    EXPECT_THROW(trash = r_src(200, {}), std::out_of_range);
    EXPECT_THROW(trash = r_src(1, {}), std::out_of_range);
    EXPECT_THROW(trash = r_src(-1, {}), std::out_of_range);
    EXPECT_THROW(trash = r_src(200, {}), std::out_of_range);

    EXPECT_THROW(trash = r_src({}, 200), std::out_of_range);
    EXPECT_THROW(trash = r_src({}, 1), std::out_of_range);
    EXPECT_THROW(trash = r_src({}, -1), std::out_of_range);
    EXPECT_THROW(trash = r_src({}, 200), std::out_of_range);
}

TEST(const_range_two_args, exception_test)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    const range r_src(src);
    range<const std::vector<int>> trash = r_src;
    const range trash2(trash);

    EXPECT_THROW(trash = r_src(200, {}), std::out_of_range);
    EXPECT_THROW(trash = r_src(8, {}), std::out_of_range);
    EXPECT_THROW(trash = r_src(-8, {}), std::out_of_range);
    EXPECT_THROW(trash = r_src(-200, {}), std::out_of_range);

    EXPECT_THROW(trash = r_src({}, 200), std::out_of_range);
    EXPECT_THROW(trash = r_src({}, 8), std::out_of_range);
    EXPECT_THROW(trash = r_src({}, -8), std::out_of_range);
    EXPECT_THROW(trash = r_src({}, 200), std::out_of_range);

    std::vector<int> src2 = {};
    const range r_src2(src2);
    [[maybe_unused]] range<const std::vector<int>> r_src3 = range(r_src2);
    EXPECT_THROW(trash = r_src2(200, {}), std::out_of_range);
    EXPECT_THROW(trash = r_src2(1, {}), std::out_of_range);
    EXPECT_THROW(trash = r_src2(-1, {}), std::out_of_range);
    EXPECT_THROW(trash = r_src2(200, {}), std::out_of_range);

    EXPECT_THROW(trash = r_src2({}, 200), std::out_of_range);
    EXPECT_THROW(trash = r_src2({}, 1), std::out_of_range);
    EXPECT_THROW(trash = r_src2({}, -1), std::out_of_range);
    EXPECT_THROW(trash = r_src2({}, 200), std::out_of_range);
}