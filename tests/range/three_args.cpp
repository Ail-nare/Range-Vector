//
// Created by Ail on 11/08/2020.
//

#include "gtest/gtest.h"
#include "testes_helper.hpp"

TEST(range_three_args, basic_test_step_1)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    range r_src(src);

    // origin
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src));
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src({}, {}, 1)));

    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src(0, {}, 1)));
    EXPECT_EQ("{2, 3, 4, 5, 6, 7}", Tests::str(r_src(1, {}, 1)));
    EXPECT_EQ("{3, 4, 5, 6, 7}", Tests::str(r_src(2, {}, 1)));
    EXPECT_EQ("{4, 5, 6, 7}", Tests::str(r_src(3, {}, 1)));
    EXPECT_EQ("{5, 6, 7}", Tests::str(r_src(4, {}, 1)));
    EXPECT_EQ("{6, 7}", Tests::str(r_src(5, {}, 1)));
    EXPECT_EQ("{7}", Tests::str(r_src(6, {}, 1)));
    EXPECT_EQ("{}", Tests::str(r_src(7, {}, 1)));

    EXPECT_EQ("{1, 2, 3, 4, 5, 6}", Tests::str(r_src(0, -1, 1)));
    EXPECT_EQ("{1, 2, 3, 4, 5, 6}", Tests::str(r_src(0, 6, 1)));
    EXPECT_EQ("{2, 3, 4, 5, 6}", Tests::str(r_src(1, -1, 1)));
    EXPECT_EQ("{3, 4, 5, 6}", Tests::str(r_src(2, -1, 1)));
    EXPECT_EQ("{4, 5, 6}", Tests::str(r_src(3, -1, 1)));
    EXPECT_EQ("{5, 6}", Tests::str(r_src(4, -1, 1)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, -1, 1)));
    EXPECT_EQ("{}", Tests::str(r_src(6, -1, 1)));

    EXPECT_EQ("{1, 2, 3, 4, 5}", Tests::str(r_src(0, -2, 1)));
    EXPECT_EQ("{2, 3, 4, 5}", Tests::str(r_src(1, -2, 1)));
    EXPECT_EQ("{2, 3, 4, 5}", Tests::str(r_src(1, 5, 1)));
    EXPECT_EQ("{3, 4, 5}", Tests::str(r_src(2, -2, 1)));
    EXPECT_EQ("{4, 5}", Tests::str(r_src(3, -2, 1)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, -2, 1)));
    EXPECT_EQ("{}", Tests::str(r_src(5, -2, 1)));

    EXPECT_EQ("{1, 2, 3, 4}", Tests::str(r_src(0, -3, 1)));
    EXPECT_EQ("{2, 3, 4}", Tests::str(r_src(1, -3, 1)));
    EXPECT_EQ("{3, 4}", Tests::str(r_src(2, -3, 1)));
    EXPECT_EQ("{3, 4}", Tests::str(r_src(2, 4, 1)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, -3, 1)));
    EXPECT_EQ("{}", Tests::str(r_src(4, -3, 1)));

    EXPECT_EQ("{1, 2, 3}", Tests::str(r_src(0, -4, 1)));
    EXPECT_EQ("{2, 3}", Tests::str(r_src(1, -4, 1)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, -4, 1)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 3, 1)));
    EXPECT_EQ("{}", Tests::str(r_src(3, -4, 1)));

    EXPECT_EQ("{1, 2}", Tests::str(r_src(0, -5, 1)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -5, 1)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, 2, 1)));
    EXPECT_EQ("{}", Tests::str(r_src(2, -5, 1)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -6, 1)));
    EXPECT_EQ("{1}", Tests::str(r_src(0, 1, 1)));
    EXPECT_EQ("{}", Tests::str(r_src(1, -6, 1)));

    EXPECT_EQ("{}", Tests::str(r_src(0, -7, 1)));
    EXPECT_EQ("{}", Tests::str(r_src(0, 0, 1)));
    EXPECT_EQ("{}", Tests::str(r_src(1, 1, 1)));
    EXPECT_EQ("{}", Tests::str(r_src(2, 2, 1)));
    EXPECT_EQ("{}", Tests::str(r_src(3, 3, 1)));
    EXPECT_EQ("{}", Tests::str(r_src(4, 4, 1)));
    EXPECT_EQ("{}", Tests::str(r_src(5, 5, 1)));
    EXPECT_EQ("{}", Tests::str(r_src(6, 6, 1)));
    EXPECT_EQ("{}", Tests::str(r_src(7, 7, 1)));
}

TEST(const_range_three_args, basic_test_step_1)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    const range r_src(src);

    // origin
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src));
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src({}, {}, 1)));

    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src(0, {}, 1)));
    EXPECT_EQ("{2, 3, 4, 5, 6, 7}", Tests::str(r_src(1, {}, 1)));
    EXPECT_EQ("{3, 4, 5, 6, 7}", Tests::str(r_src(2, {}, 1)));
    EXPECT_EQ("{4, 5, 6, 7}", Tests::str(r_src(3, {}, 1)));
    EXPECT_EQ("{5, 6, 7}", Tests::str(r_src(4, {}, 1)));
    EXPECT_EQ("{6, 7}", Tests::str(r_src(5, {}, 1)));
    EXPECT_EQ("{7}", Tests::str(r_src(6, {}, 1)));
    EXPECT_EQ("{}", Tests::str(r_src(7, {}, 1)));

    EXPECT_EQ("{1, 2, 3, 4, 5, 6}", Tests::str(r_src(0, -1, 1)));
    EXPECT_EQ("{1, 2, 3, 4, 5, 6}", Tests::str(r_src(0, 6, 1)));
    EXPECT_EQ("{2, 3, 4, 5, 6}", Tests::str(r_src(1, -1, 1)));
    EXPECT_EQ("{3, 4, 5, 6}", Tests::str(r_src(2, -1, 1)));
    EXPECT_EQ("{4, 5, 6}", Tests::str(r_src(3, -1, 1)));
    EXPECT_EQ("{5, 6}", Tests::str(r_src(4, -1, 1)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, -1, 1)));
    EXPECT_EQ("{}", Tests::str(r_src(6, -1, 1)));

    EXPECT_EQ("{1, 2, 3, 4, 5}", Tests::str(r_src(0, -2, 1)));
    EXPECT_EQ("{2, 3, 4, 5}", Tests::str(r_src(1, -2, 1)));
    EXPECT_EQ("{2, 3, 4, 5}", Tests::str(r_src(1, 5, 1)));
    EXPECT_EQ("{3, 4, 5}", Tests::str(r_src(2, -2, 1)));
    EXPECT_EQ("{4, 5}", Tests::str(r_src(3, -2, 1)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, -2, 1)));
    EXPECT_EQ("{}", Tests::str(r_src(5, -2, 1)));

    EXPECT_EQ("{1, 2, 3, 4}", Tests::str(r_src(0, -3, 1)));
    EXPECT_EQ("{2, 3, 4}", Tests::str(r_src(1, -3, 1)));
    EXPECT_EQ("{3, 4}", Tests::str(r_src(2, -3, 1)));
    EXPECT_EQ("{3, 4}", Tests::str(r_src(2, 4, 1)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, -3, 1)));
    EXPECT_EQ("{}", Tests::str(r_src(4, -3, 1)));

    EXPECT_EQ("{1, 2, 3}", Tests::str(r_src(0, -4, 1)));
    EXPECT_EQ("{2, 3}", Tests::str(r_src(1, -4, 1)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, -4, 1)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 3, 1)));
    EXPECT_EQ("{}", Tests::str(r_src(3, -4, 1)));

    EXPECT_EQ("{1, 2}", Tests::str(r_src(0, -5, 1)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -5, 1)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, 2, 1)));
    EXPECT_EQ("{}", Tests::str(r_src(2, -5, 1)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -6, 1)));
    EXPECT_EQ("{1}", Tests::str(r_src(0, 1, 1)));
    EXPECT_EQ("{}", Tests::str(r_src(1, -6, 1)));

    EXPECT_EQ("{}", Tests::str(r_src(0, -7, 1)));
    EXPECT_EQ("{}", Tests::str(r_src(0, 0, 1)));
    EXPECT_EQ("{}", Tests::str(r_src(1, 1, 1)));
    EXPECT_EQ("{}", Tests::str(r_src(2, 2, 1)));
    EXPECT_EQ("{}", Tests::str(r_src(3, 3, 1)));
    EXPECT_EQ("{}", Tests::str(r_src(4, 4, 1)));
    EXPECT_EQ("{}", Tests::str(r_src(5, 5, 1)));
    EXPECT_EQ("{}", Tests::str(r_src(6, 6, 1)));
    EXPECT_EQ("{}", Tests::str(r_src(7, 7, 1)));
}

TEST(range_three_args, basic_test_step_2)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    range r_src(src);

    // origin
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src));
    EXPECT_EQ("{1, 3, 5, 7}", Tests::str(r_src({}, {}, 2)));

    EXPECT_EQ("{1, 3, 5, 7}", Tests::str(r_src(0, {}, 2)));
    EXPECT_EQ("{2, 4, 6}", Tests::str(r_src(1, {}, 2)));
    EXPECT_EQ("{3, 5, 7}", Tests::str(r_src(2, {}, 2)));
    EXPECT_EQ("{4, 6}", Tests::str(r_src(3, {}, 2)));
    EXPECT_EQ("{5, 7}", Tests::str(r_src(4, {}, 2)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, {}, 2)));
    EXPECT_EQ("{7}", Tests::str(r_src(6, {}, 2)));
    EXPECT_EQ("{}", Tests::str(r_src(7, {}, 2)));

    EXPECT_EQ("{1, 3, 5}", Tests::str(r_src(0, -1, 2)));
    EXPECT_EQ("{1, 3, 5}", Tests::str(r_src(0, 6, 2)));
    EXPECT_EQ("{2, 4, 6}", Tests::str(r_src(1, -1, 2)));
    EXPECT_EQ("{3, 5}", Tests::str(r_src(2, -1, 2)));
    EXPECT_EQ("{4, 6}", Tests::str(r_src(3, -1, 2)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, -1, 2)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, -1, 2)));
    EXPECT_EQ("{}", Tests::str(r_src(6, -1, 2)));


    EXPECT_EQ("{1, 3, 5}", Tests::str(r_src(0, -2, 2)));
    EXPECT_EQ("{2, 4}", Tests::str(r_src(1, -2, 2)));
    EXPECT_EQ("{2, 4}", Tests::str(r_src(1, 5, 2)));
    EXPECT_EQ("{3, 5}", Tests::str(r_src(2, -2, 2)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, -2, 2)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, -2, 2)));
    EXPECT_EQ("{}", Tests::str(r_src(5, -2, 2)));

    EXPECT_EQ("{1, 3}", Tests::str(r_src(0, -3, 2)));
    EXPECT_EQ("{2, 4}", Tests::str(r_src(1, -3, 2)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, -3, 2)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 4, 2)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, -3, 2)));
    EXPECT_EQ("{}", Tests::str(r_src(4, -3, 2)));

    EXPECT_EQ("{1, 3}", Tests::str(r_src(0, -4, 2)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -4, 2)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, -4, 2)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 3, 2)));
    EXPECT_EQ("{}", Tests::str(r_src(3, -4, 2)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -5, 2)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -5, 2)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, 2, 2)));
    EXPECT_EQ("{}", Tests::str(r_src(2, -5, 2)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -6, 2)));
    EXPECT_EQ("{1}", Tests::str(r_src(0, 1, 2)));
    EXPECT_EQ("{}", Tests::str(r_src(1, -6, 2)));

    EXPECT_EQ("{}", Tests::str(r_src(0, -7, 2)));
    EXPECT_EQ("{}", Tests::str(r_src(0, 0, 2)));
    EXPECT_EQ("{}", Tests::str(r_src(1, 1, 2)));
    EXPECT_EQ("{}", Tests::str(r_src(2, 2, 2)));
    EXPECT_EQ("{}", Tests::str(r_src(3, 3, 2)));
    EXPECT_EQ("{}", Tests::str(r_src(4, 4, 2)));
    EXPECT_EQ("{}", Tests::str(r_src(5, 5, 2)));
    EXPECT_EQ("{}", Tests::str(r_src(6, 6, 2)));
    EXPECT_EQ("{}", Tests::str(r_src(7, 7, 2)));
}

TEST(const_range_three_args, basic_test_step_2)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    const range r_src(src);

    // origin
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src));
    EXPECT_EQ("{1, 3, 5, 7}", Tests::str(r_src({}, {}, 2)));

    EXPECT_EQ("{1, 3, 5, 7}", Tests::str(r_src(0, {}, 2)));
    EXPECT_EQ("{2, 4, 6}", Tests::str(r_src(1, {}, 2)));
    EXPECT_EQ("{3, 5, 7}", Tests::str(r_src(2, {}, 2)));
    EXPECT_EQ("{4, 6}", Tests::str(r_src(3, {}, 2)));
    EXPECT_EQ("{5, 7}", Tests::str(r_src(4, {}, 2)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, {}, 2)));
    EXPECT_EQ("{7}", Tests::str(r_src(6, {}, 2)));
    EXPECT_EQ("{}", Tests::str(r_src(7, {}, 2)));

    EXPECT_EQ("{1, 3, 5}", Tests::str(r_src(0, -1, 2)));
    EXPECT_EQ("{1, 3, 5}", Tests::str(r_src(0, 6, 2)));
    EXPECT_EQ("{2, 4, 6}", Tests::str(r_src(1, -1, 2)));
    EXPECT_EQ("{3, 5}", Tests::str(r_src(2, -1, 2)));
    EXPECT_EQ("{4, 6}", Tests::str(r_src(3, -1, 2)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, -1, 2)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, -1, 2)));
    EXPECT_EQ("{}", Tests::str(r_src(6, -1, 2)));


    EXPECT_EQ("{1, 3, 5}", Tests::str(r_src(0, -2, 2)));
    EXPECT_EQ("{2, 4}", Tests::str(r_src(1, -2, 2)));
    EXPECT_EQ("{2, 4}", Tests::str(r_src(1, 5, 2)));
    EXPECT_EQ("{3, 5}", Tests::str(r_src(2, -2, 2)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, -2, 2)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, -2, 2)));
    EXPECT_EQ("{}", Tests::str(r_src(5, -2, 2)));

    EXPECT_EQ("{1, 3}", Tests::str(r_src(0, -3, 2)));
    EXPECT_EQ("{2, 4}", Tests::str(r_src(1, -3, 2)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, -3, 2)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 4, 2)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, -3, 2)));
    EXPECT_EQ("{}", Tests::str(r_src(4, -3, 2)));

    EXPECT_EQ("{1, 3}", Tests::str(r_src(0, -4, 2)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -4, 2)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, -4, 2)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 3, 2)));
    EXPECT_EQ("{}", Tests::str(r_src(3, -4, 2)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -5, 2)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -5, 2)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, 2, 2)));
    EXPECT_EQ("{}", Tests::str(r_src(2, -5, 2)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -6, 2)));
    EXPECT_EQ("{1}", Tests::str(r_src(0, 1, 2)));
    EXPECT_EQ("{}", Tests::str(r_src(1, -6, 2)));

    EXPECT_EQ("{}", Tests::str(r_src(0, -7, 2)));
    EXPECT_EQ("{}", Tests::str(r_src(0, 0, 2)));
    EXPECT_EQ("{}", Tests::str(r_src(1, 1, 2)));
    EXPECT_EQ("{}", Tests::str(r_src(2, 2, 2)));
    EXPECT_EQ("{}", Tests::str(r_src(3, 3, 2)));
    EXPECT_EQ("{}", Tests::str(r_src(4, 4, 2)));
    EXPECT_EQ("{}", Tests::str(r_src(5, 5, 2)));
    EXPECT_EQ("{}", Tests::str(r_src(6, 6, 2)));
    EXPECT_EQ("{}", Tests::str(r_src(7, 7, 2)));
}

TEST(range_three_args, basic_test_step_3)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    range r_src(src);

    // origin
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src));
    EXPECT_EQ("{1, 4, 7}", Tests::str(r_src({}, {}, 3)));

    EXPECT_EQ("{1, 4, 7}", Tests::str(r_src(0, {}, 3)));
    EXPECT_EQ("{2, 5}", Tests::str(r_src(1, {}, 3)));
    EXPECT_EQ("{3, 6}", Tests::str(r_src(2, {}, 3)));
    EXPECT_EQ("{4, 7}", Tests::str(r_src(3, {}, 3)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, {}, 3)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, {}, 3)));
    EXPECT_EQ("{7}", Tests::str(r_src(6, {}, 3)));
    EXPECT_EQ("{}", Tests::str(r_src(7, {}, 3)));

    EXPECT_EQ("{1, 4}", Tests::str(r_src(0, -1, 3)));
    EXPECT_EQ("{1, 4}", Tests::str(r_src(0, 6, 3)));
    EXPECT_EQ("{2, 5}", Tests::str(r_src(1, -1, 3)));
    EXPECT_EQ("{3, 6}", Tests::str(r_src(2, -1, 3)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, -1, 3)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, -1, 3)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, -1, 3)));
    EXPECT_EQ("{}", Tests::str(r_src(6, -1, 3)));

    EXPECT_EQ("{1, 4}", Tests::str(r_src(0, -2, 3)));
    EXPECT_EQ("{2, 5}", Tests::str(r_src(1, -2, 3)));
    EXPECT_EQ("{2, 5}", Tests::str(r_src(1, 5, 3)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, -2, 3)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, -2, 3)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, -2, 3)));
    EXPECT_EQ("{}", Tests::str(r_src(5, -2, 3)));

    EXPECT_EQ("{1, 4}", Tests::str(r_src(0, -3, 3)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -3, 3)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, -3, 3)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 4, 3)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, -3, 3)));
    EXPECT_EQ("{}", Tests::str(r_src(4, -3, 3)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -4, 3)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -4, 3)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, -4, 3)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 3, 3)));
    EXPECT_EQ("{}", Tests::str(r_src(3, -4, 3)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -5, 3)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -5, 3)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, 2, 3)));
    EXPECT_EQ("{}", Tests::str(r_src(2, -5, 3)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -6, 3)));
    EXPECT_EQ("{1}", Tests::str(r_src(0, 1, 3)));
    EXPECT_EQ("{}", Tests::str(r_src(1, -6, 3)));

    EXPECT_EQ("{}", Tests::str(r_src(0, -7, 3)));
    EXPECT_EQ("{}", Tests::str(r_src(0, 0, 3)));
    EXPECT_EQ("{}", Tests::str(r_src(1, 1, 3)));
    EXPECT_EQ("{}", Tests::str(r_src(2, 2, 3)));
    EXPECT_EQ("{}", Tests::str(r_src(3, 3, 3)));
    EXPECT_EQ("{}", Tests::str(r_src(4, 4, 3)));
    EXPECT_EQ("{}", Tests::str(r_src(5, 5, 3)));
    EXPECT_EQ("{}", Tests::str(r_src(6, 6, 3)));
    EXPECT_EQ("{}", Tests::str(r_src(7, 7, 3)));
}

TEST(const_range_three_args, basic_test_step_3)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    const range r_src(src);

    // origin
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src));
    EXPECT_EQ("{1, 4, 7}", Tests::str(r_src({}, {}, 3)));

    EXPECT_EQ("{1, 4, 7}", Tests::str(r_src(0, {}, 3)));
    EXPECT_EQ("{2, 5}", Tests::str(r_src(1, {}, 3)));
    EXPECT_EQ("{3, 6}", Tests::str(r_src(2, {}, 3)));
    EXPECT_EQ("{4, 7}", Tests::str(r_src(3, {}, 3)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, {}, 3)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, {}, 3)));
    EXPECT_EQ("{7}", Tests::str(r_src(6, {}, 3)));
    EXPECT_EQ("{}", Tests::str(r_src(7, {}, 3)));

    EXPECT_EQ("{1, 4}", Tests::str(r_src(0, -1, 3)));
    EXPECT_EQ("{1, 4}", Tests::str(r_src(0, 6, 3)));
    EXPECT_EQ("{2, 5}", Tests::str(r_src(1, -1, 3)));
    EXPECT_EQ("{3, 6}", Tests::str(r_src(2, -1, 3)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, -1, 3)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, -1, 3)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, -1, 3)));
    EXPECT_EQ("{}", Tests::str(r_src(6, -1, 3)));

    EXPECT_EQ("{1, 4}", Tests::str(r_src(0, -2, 3)));
    EXPECT_EQ("{2, 5}", Tests::str(r_src(1, -2, 3)));
    EXPECT_EQ("{2, 5}", Tests::str(r_src(1, 5, 3)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, -2, 3)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, -2, 3)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, -2, 3)));
    EXPECT_EQ("{}", Tests::str(r_src(5, -2, 3)));

    EXPECT_EQ("{1, 4}", Tests::str(r_src(0, -3, 3)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -3, 3)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, -3, 3)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 4, 3)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, -3, 3)));
    EXPECT_EQ("{}", Tests::str(r_src(4, -3, 3)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -4, 3)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -4, 3)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, -4, 3)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 3, 3)));
    EXPECT_EQ("{}", Tests::str(r_src(3, -4, 3)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -5, 3)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -5, 3)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, 2, 3)));
    EXPECT_EQ("{}", Tests::str(r_src(2, -5, 3)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -6, 3)));
    EXPECT_EQ("{1}", Tests::str(r_src(0, 1, 3)));
    EXPECT_EQ("{}", Tests::str(r_src(1, -6, 3)));

    EXPECT_EQ("{}", Tests::str(r_src(0, -7, 3)));
    EXPECT_EQ("{}", Tests::str(r_src(0, 0, 3)));
    EXPECT_EQ("{}", Tests::str(r_src(1, 1, 3)));
    EXPECT_EQ("{}", Tests::str(r_src(2, 2, 3)));
    EXPECT_EQ("{}", Tests::str(r_src(3, 3, 3)));
    EXPECT_EQ("{}", Tests::str(r_src(4, 4, 3)));
    EXPECT_EQ("{}", Tests::str(r_src(5, 5, 3)));
    EXPECT_EQ("{}", Tests::str(r_src(6, 6, 3)));
    EXPECT_EQ("{}", Tests::str(r_src(7, 7, 3)));
}

TEST(range_three_args, basic_test_step_6)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    range r_src(src);

    // origin
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src));
    EXPECT_EQ("{1, 7}", Tests::str(r_src({}, {}, 6)));

    EXPECT_EQ("{1, 7}", Tests::str(r_src(0, {}, 6)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, {}, 6)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, {}, 6)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, {}, 6)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, {}, 6)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, {}, 6)));
    EXPECT_EQ("{7}", Tests::str(r_src(6, {}, 6)));
    EXPECT_EQ("{}", Tests::str(r_src(7, {}, 6)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -1, 6)));
    EXPECT_EQ("{1}", Tests::str(r_src(0, 6, 6)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -1, 6)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, -1, 6)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, -1, 6)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, -1, 6)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, -1, 6)));
    EXPECT_EQ("{}", Tests::str(r_src(6, -1, 6)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -2, 6)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -2, 6)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, 5, 6)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, -2, 6)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, -2, 6)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, -2, 6)));
    EXPECT_EQ("{}", Tests::str(r_src(5, -2, 6)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -3, 6)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -3, 6)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, -3, 6)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 4, 6)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, -3, 6)));
    EXPECT_EQ("{}", Tests::str(r_src(4, -3, 6)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -4, 6)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -4, 6)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, -4, 6)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 3, 6)));
    EXPECT_EQ("{}", Tests::str(r_src(3, -4, 6)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -5, 6)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -5, 6)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, 2, 6)));
    EXPECT_EQ("{}", Tests::str(r_src(2, -5, 6)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -6, 6)));
    EXPECT_EQ("{1}", Tests::str(r_src(0, 1, 6)));
    EXPECT_EQ("{}", Tests::str(r_src(1, -6, 6)));

    EXPECT_EQ("{}", Tests::str(r_src(0, -7, 6)));
    EXPECT_EQ("{}", Tests::str(r_src(0, 0, 6)));
    EXPECT_EQ("{}", Tests::str(r_src(1, 1, 6)));
    EXPECT_EQ("{}", Tests::str(r_src(2, 2, 6)));
    EXPECT_EQ("{}", Tests::str(r_src(3, 3, 6)));
    EXPECT_EQ("{}", Tests::str(r_src(4, 4, 6)));
    EXPECT_EQ("{}", Tests::str(r_src(5, 5, 6)));
    EXPECT_EQ("{}", Tests::str(r_src(6, 6, 6)));
    EXPECT_EQ("{}", Tests::str(r_src(7, 7, 6)));
}

TEST(const_range_three_args, basic_test_step_6)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    const range r_src(src);

    // origin
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src));
    EXPECT_EQ("{1, 7}", Tests::str(r_src({}, {}, 6)));

    EXPECT_EQ("{1, 7}", Tests::str(r_src(0, {}, 6)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, {}, 6)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, {}, 6)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, {}, 6)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, {}, 6)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, {}, 6)));
    EXPECT_EQ("{7}", Tests::str(r_src(6, {}, 6)));
    EXPECT_EQ("{}", Tests::str(r_src(7, {}, 6)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -1, 6)));
    EXPECT_EQ("{1}", Tests::str(r_src(0, 6, 6)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -1, 6)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, -1, 6)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, -1, 6)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, -1, 6)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, -1, 6)));
    EXPECT_EQ("{}", Tests::str(r_src(6, -1, 6)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -2, 6)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -2, 6)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, 5, 6)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, -2, 6)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, -2, 6)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, -2, 6)));
    EXPECT_EQ("{}", Tests::str(r_src(5, -2, 6)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -3, 6)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -3, 6)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, -3, 6)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 4, 6)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, -3, 6)));
    EXPECT_EQ("{}", Tests::str(r_src(4, -3, 6)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -4, 6)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -4, 6)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, -4, 6)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 3, 6)));
    EXPECT_EQ("{}", Tests::str(r_src(3, -4, 6)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -5, 6)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -5, 6)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, 2, 6)));
    EXPECT_EQ("{}", Tests::str(r_src(2, -5, 6)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -6, 6)));
    EXPECT_EQ("{1}", Tests::str(r_src(0, 1, 6)));
    EXPECT_EQ("{}", Tests::str(r_src(1, -6, 6)));

    EXPECT_EQ("{}", Tests::str(r_src(0, -7, 6)));
    EXPECT_EQ("{}", Tests::str(r_src(0, 0, 6)));
    EXPECT_EQ("{}", Tests::str(r_src(1, 1, 6)));
    EXPECT_EQ("{}", Tests::str(r_src(2, 2, 6)));
    EXPECT_EQ("{}", Tests::str(r_src(3, 3, 6)));
    EXPECT_EQ("{}", Tests::str(r_src(4, 4, 6)));
    EXPECT_EQ("{}", Tests::str(r_src(5, 5, 6)));
    EXPECT_EQ("{}", Tests::str(r_src(6, 6, 6)));
    EXPECT_EQ("{}", Tests::str(r_src(7, 7, 6)));
}

TEST(range_three_args, basic_test_step_7)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    range r_src(src);

    // origin
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src));
    EXPECT_EQ("{1}", Tests::str(r_src({}, {}, 7)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, {}, 7)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, {}, 7)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, {}, 7)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, {}, 7)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, {}, 7)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, {}, 7)));
    EXPECT_EQ("{7}", Tests::str(r_src(6, {}, 7)));
    EXPECT_EQ("{}", Tests::str(r_src(7, {}, 7)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -1, 7)));
    EXPECT_EQ("{1}", Tests::str(r_src(0, 6, 7)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -1, 7)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, -1, 7)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, -1, 7)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, -1, 7)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, -1, 7)));
    EXPECT_EQ("{}", Tests::str(r_src(6, -1, 7)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -2, 7)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -2, 7)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, 5, 7)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, -2, 7)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, -2, 7)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, -2, 7)));
    EXPECT_EQ("{}", Tests::str(r_src(5, -2, 7)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -3, 7)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -3, 7)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, -3, 7)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 4, 7)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, -3, 7)));
    EXPECT_EQ("{}", Tests::str(r_src(4, -3, 7)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -4, 7)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -4, 7)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, -4, 7)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 3, 7)));
    EXPECT_EQ("{}", Tests::str(r_src(3, -4, 7)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -5, 7)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -5, 7)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, 2, 7)));
    EXPECT_EQ("{}", Tests::str(r_src(2, -5, 7)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -6, 7)));
    EXPECT_EQ("{1}", Tests::str(r_src(0, 1, 7)));
    EXPECT_EQ("{}", Tests::str(r_src(1, -6, 7)));

    EXPECT_EQ("{}", Tests::str(r_src(0, -7, 7)));
    EXPECT_EQ("{}", Tests::str(r_src(0, 0, 7)));
    EXPECT_EQ("{}", Tests::str(r_src(1, 1, 7)));
    EXPECT_EQ("{}", Tests::str(r_src(2, 2, 7)));
    EXPECT_EQ("{}", Tests::str(r_src(3, 3, 7)));
    EXPECT_EQ("{}", Tests::str(r_src(4, 4, 7)));
    EXPECT_EQ("{}", Tests::str(r_src(5, 5, 7)));
    EXPECT_EQ("{}", Tests::str(r_src(6, 6, 7)));
    EXPECT_EQ("{}", Tests::str(r_src(7, 7, 7)));
}

TEST(const_range_three_args, basic_test_step_7)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    const range r_src(src);

    // origin
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src));
    EXPECT_EQ("{1}", Tests::str(r_src({}, {}, 7)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, {}, 7)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, {}, 7)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, {}, 7)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, {}, 7)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, {}, 7)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, {}, 7)));
    EXPECT_EQ("{7}", Tests::str(r_src(6, {}, 7)));
    EXPECT_EQ("{}", Tests::str(r_src(7, {}, 7)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -1, 7)));
    EXPECT_EQ("{1}", Tests::str(r_src(0, 6, 7)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -1, 7)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, -1, 7)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, -1, 7)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, -1, 7)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, -1, 7)));
    EXPECT_EQ("{}", Tests::str(r_src(6, -1, 7)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -2, 7)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -2, 7)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, 5, 7)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, -2, 7)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, -2, 7)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, -2, 7)));
    EXPECT_EQ("{}", Tests::str(r_src(5, -2, 7)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -3, 7)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -3, 7)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, -3, 7)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 4, 7)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, -3, 7)));
    EXPECT_EQ("{}", Tests::str(r_src(4, -3, 7)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -4, 7)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -4, 7)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, -4, 7)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 3, 7)));
    EXPECT_EQ("{}", Tests::str(r_src(3, -4, 7)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -5, 7)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -5, 7)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, 2, 7)));
    EXPECT_EQ("{}", Tests::str(r_src(2, -5, 7)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -6, 7)));
    EXPECT_EQ("{1}", Tests::str(r_src(0, 1, 7)));
    EXPECT_EQ("{}", Tests::str(r_src(1, -6, 7)));

    EXPECT_EQ("{}", Tests::str(r_src(0, -7, 7)));
    EXPECT_EQ("{}", Tests::str(r_src(0, 0, 7)));
    EXPECT_EQ("{}", Tests::str(r_src(1, 1, 7)));
    EXPECT_EQ("{}", Tests::str(r_src(2, 2, 7)));
    EXPECT_EQ("{}", Tests::str(r_src(3, 3, 7)));
    EXPECT_EQ("{}", Tests::str(r_src(4, 4, 7)));
    EXPECT_EQ("{}", Tests::str(r_src(5, 5, 7)));
    EXPECT_EQ("{}", Tests::str(r_src(6, 6, 7)));
    EXPECT_EQ("{}", Tests::str(r_src(7, 7, 7)));
}

TEST(range_three_args, basic_test_step_8)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    range r_src(src);

    // origin
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src));
    EXPECT_EQ("{1}", Tests::str(r_src({}, {}, 8)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, {}, 8)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, {}, 8)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, {}, 8)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, {}, 8)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, {}, 8)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, {}, 8)));
    EXPECT_EQ("{7}", Tests::str(r_src(6, {}, 8)));
    EXPECT_EQ("{}", Tests::str(r_src(7, {}, 8)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -1, 8)));
    EXPECT_EQ("{1}", Tests::str(r_src(0, 6, 8)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -1, 8)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, -1, 8)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, -1, 8)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, -1, 8)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, -1, 8)));
    EXPECT_EQ("{}", Tests::str(r_src(6, -1, 8)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -2, 8)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -2, 8)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, 5, 8)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, -2, 8)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, -2, 8)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, -2, 8)));
    EXPECT_EQ("{}", Tests::str(r_src(5, -2, 8)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -3, 8)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -3, 8)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, -3, 8)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 4, 8)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, -3, 8)));
    EXPECT_EQ("{}", Tests::str(r_src(4, -3, 8)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -4, 8)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -4, 8)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, -4, 8)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 3, 8)));
    EXPECT_EQ("{}", Tests::str(r_src(3, -4, 8)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -5, 8)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -5, 8)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, 2, 8)));
    EXPECT_EQ("{}", Tests::str(r_src(2, -5, 8)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -6, 8)));
    EXPECT_EQ("{1}", Tests::str(r_src(0, 1, 8)));
    EXPECT_EQ("{}", Tests::str(r_src(1, -6, 8)));

    EXPECT_EQ("{}", Tests::str(r_src(0, -7, 8)));
    EXPECT_EQ("{}", Tests::str(r_src(0, 0, 8)));
    EXPECT_EQ("{}", Tests::str(r_src(1, 1, 8)));
    EXPECT_EQ("{}", Tests::str(r_src(2, 2, 8)));
    EXPECT_EQ("{}", Tests::str(r_src(3, 3, 8)));
    EXPECT_EQ("{}", Tests::str(r_src(4, 4, 8)));
    EXPECT_EQ("{}", Tests::str(r_src(5, 5, 8)));
    EXPECT_EQ("{}", Tests::str(r_src(6, 6, 8)));
    EXPECT_EQ("{}", Tests::str(r_src(7, 7, 8)));
}

TEST(const_range_three_args, basic_test_step_8)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    const range r_src(src);

    // origin
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src));
    EXPECT_EQ("{1}", Tests::str(r_src({}, {}, 8)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, {}, 8)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, {}, 8)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, {}, 8)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, {}, 8)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, {}, 8)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, {}, 8)));
    EXPECT_EQ("{7}", Tests::str(r_src(6, {}, 8)));
    EXPECT_EQ("{}", Tests::str(r_src(7, {}, 8)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -1, 8)));
    EXPECT_EQ("{1}", Tests::str(r_src(0, 6, 8)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -1, 8)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, -1, 8)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, -1, 8)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, -1, 8)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, -1, 8)));
    EXPECT_EQ("{}", Tests::str(r_src(6, -1, 8)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -2, 8)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -2, 8)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, 5, 8)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, -2, 8)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, -2, 8)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, -2, 8)));
    EXPECT_EQ("{}", Tests::str(r_src(5, -2, 8)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -3, 8)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -3, 8)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, -3, 8)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 4, 8)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, -3, 8)));
    EXPECT_EQ("{}", Tests::str(r_src(4, -3, 8)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -4, 8)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -4, 8)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, -4, 8)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 3, 8)));
    EXPECT_EQ("{}", Tests::str(r_src(3, -4, 8)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -5, 8)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, -5, 8)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, 2, 8)));
    EXPECT_EQ("{}", Tests::str(r_src(2, -5, 8)));

    EXPECT_EQ("{1}", Tests::str(r_src(0, -6, 8)));
    EXPECT_EQ("{1}", Tests::str(r_src(0, 1, 8)));
    EXPECT_EQ("{}", Tests::str(r_src(1, -6, 8)));

    EXPECT_EQ("{}", Tests::str(r_src(0, -7, 8)));
    EXPECT_EQ("{}", Tests::str(r_src(0, 0, 8)));
    EXPECT_EQ("{}", Tests::str(r_src(1, 1, 8)));
    EXPECT_EQ("{}", Tests::str(r_src(2, 2, 8)));
    EXPECT_EQ("{}", Tests::str(r_src(3, 3, 8)));
    EXPECT_EQ("{}", Tests::str(r_src(4, 4, 8)));
    EXPECT_EQ("{}", Tests::str(r_src(5, 5, 8)));
    EXPECT_EQ("{}", Tests::str(r_src(6, 6, 8)));
    EXPECT_EQ("{}", Tests::str(r_src(7, 7, 8)));
}

TEST(range_three_args, step_nagative_test_2nd_default)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    range r_src(src);

    // origin
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src));
    EXPECT_EQ("{7, 6, 5, 4, 3, 2, 1}", Tests::str(r_src({}, {}, -1)));

    EXPECT_EQ("{7, 6, 5, 4, 3, 2, 1}", Tests::str(r_src(6, {}, -1)));
    EXPECT_EQ("{6, 5, 4, 3, 2, 1}", Tests::str(r_src(5, {}, -1)));
    EXPECT_EQ("{5, 4, 3, 2, 1}", Tests::str(r_src(4, {}, -1)));
    EXPECT_EQ("{4, 3, 2, 1}", Tests::str(r_src(3, {}, -1)));
    EXPECT_EQ("{3, 2, 1}", Tests::str(r_src(2, {}, -1)));
    EXPECT_EQ("{2, 1}", Tests::str(r_src(1, {}, -1)));
    EXPECT_EQ("{1}", Tests::str(r_src(0, {}, -1)));


    EXPECT_EQ("{7, 5, 3, 1}", Tests::str(r_src(6, {}, -2)));
    EXPECT_EQ("{6, 4, 2}", Tests::str(r_src(5, {}, -2)));
    EXPECT_EQ("{5, 3, 1}", Tests::str(r_src(4, {}, -2)));
    EXPECT_EQ("{4, 2}", Tests::str(r_src(3, {}, -2)));
    EXPECT_EQ("{3, 1}", Tests::str(r_src(2, {}, -2)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, {}, -2)));
    EXPECT_EQ("{1}", Tests::str(r_src(0, {}, -2)));


    EXPECT_EQ("{7, 4, 1}", Tests::str(r_src(6, {}, -3)));
    EXPECT_EQ("{6, 3}", Tests::str(r_src(5, {}, -3)));
    EXPECT_EQ("{5, 2}", Tests::str(r_src(4, {}, -3)));
    EXPECT_EQ("{4, 1}", Tests::str(r_src(3, {}, -3)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, {}, -3)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, {}, -3)));
    EXPECT_EQ("{1}", Tests::str(r_src(0, {}, -3)));

    EXPECT_EQ("{7, 3}", Tests::str(r_src(6, {}, -4)));
    EXPECT_EQ("{6, 2}", Tests::str(r_src(5, {}, -4)));
    EXPECT_EQ("{5, 1}", Tests::str(r_src(4, {}, -4)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, {}, -4)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, {}, -4)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, {}, -4)));
    EXPECT_EQ("{1}", Tests::str(r_src(0, {}, -4)));

    EXPECT_EQ("{7, 2}", Tests::str(r_src(6, {}, -5)));
    EXPECT_EQ("{6, 1}", Tests::str(r_src(5, {}, -5)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, {}, -5)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, {}, -5)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, {}, -5)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, {}, -5)));
    EXPECT_EQ("{1}", Tests::str(r_src(0, {}, -5)));

    EXPECT_EQ("{7, 1}", Tests::str(r_src(6, {}, -6)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, {}, -6)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, {}, -6)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, {}, -6)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, {}, -6)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, {}, -6)));
    EXPECT_EQ("{1}", Tests::str(r_src(0, {}, -6)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, {}, -7)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, {}, -7)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, {}, -7)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, {}, -7)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, {}, -7)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, {}, -7)));
    EXPECT_EQ("{1}", Tests::str(r_src(0, {}, -7)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, {}, -8)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, {}, -8)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, {}, -8)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, {}, -8)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, {}, -8)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, {}, -8)));
    EXPECT_EQ("{1}", Tests::str(r_src(0, {}, -8)));

    // Over
    EXPECT_EQ("{7}", Tests::str(r_src(6, {}, -200)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, {}, -200)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, {}, -200)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, {}, -200)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, {}, -200)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, {}, -200)));
    EXPECT_EQ("{1}", Tests::str(r_src(0, {}, -200)));
}

TEST(const_range_three_args, step_nagative_test_2nd_default)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    const range r_src(src);

    // origin
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src));
    EXPECT_EQ("{7, 6, 5, 4, 3, 2, 1}", Tests::str(r_src({}, {}, -1)));

    EXPECT_EQ("{7, 6, 5, 4, 3, 2, 1}", Tests::str(r_src(6, {}, -1)));
    EXPECT_EQ("{6, 5, 4, 3, 2, 1}", Tests::str(r_src(5, {}, -1)));
    EXPECT_EQ("{5, 4, 3, 2, 1}", Tests::str(r_src(4, {}, -1)));
    EXPECT_EQ("{4, 3, 2, 1}", Tests::str(r_src(3, {}, -1)));
    EXPECT_EQ("{3, 2, 1}", Tests::str(r_src(2, {}, -1)));
    EXPECT_EQ("{2, 1}", Tests::str(r_src(1, {}, -1)));
    EXPECT_EQ("{1}", Tests::str(r_src(0, {}, -1)));


    EXPECT_EQ("{7, 5, 3, 1}", Tests::str(r_src(6, {}, -2)));
    EXPECT_EQ("{6, 4, 2}", Tests::str(r_src(5, {}, -2)));
    EXPECT_EQ("{5, 3, 1}", Tests::str(r_src(4, {}, -2)));
    EXPECT_EQ("{4, 2}", Tests::str(r_src(3, {}, -2)));
    EXPECT_EQ("{3, 1}", Tests::str(r_src(2, {}, -2)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, {}, -2)));
    EXPECT_EQ("{1}", Tests::str(r_src(0, {}, -2)));


    EXPECT_EQ("{7, 4, 1}", Tests::str(r_src(6, {}, -3)));
    EXPECT_EQ("{6, 3}", Tests::str(r_src(5, {}, -3)));
    EXPECT_EQ("{5, 2}", Tests::str(r_src(4, {}, -3)));
    EXPECT_EQ("{4, 1}", Tests::str(r_src(3, {}, -3)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, {}, -3)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, {}, -3)));
    EXPECT_EQ("{1}", Tests::str(r_src(0, {}, -3)));

    EXPECT_EQ("{7, 3}", Tests::str(r_src(6, {}, -4)));
    EXPECT_EQ("{6, 2}", Tests::str(r_src(5, {}, -4)));
    EXPECT_EQ("{5, 1}", Tests::str(r_src(4, {}, -4)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, {}, -4)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, {}, -4)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, {}, -4)));
    EXPECT_EQ("{1}", Tests::str(r_src(0, {}, -4)));

    EXPECT_EQ("{7, 2}", Tests::str(r_src(6, {}, -5)));
    EXPECT_EQ("{6, 1}", Tests::str(r_src(5, {}, -5)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, {}, -5)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, {}, -5)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, {}, -5)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, {}, -5)));
    EXPECT_EQ("{1}", Tests::str(r_src(0, {}, -5)));

    EXPECT_EQ("{7, 1}", Tests::str(r_src(6, {}, -6)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, {}, -6)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, {}, -6)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, {}, -6)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, {}, -6)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, {}, -6)));
    EXPECT_EQ("{1}", Tests::str(r_src(0, {}, -6)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, {}, -7)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, {}, -7)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, {}, -7)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, {}, -7)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, {}, -7)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, {}, -7)));
    EXPECT_EQ("{1}", Tests::str(r_src(0, {}, -7)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, {}, -8)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, {}, -8)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, {}, -8)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, {}, -8)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, {}, -8)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, {}, -8)));
    EXPECT_EQ("{1}", Tests::str(r_src(0, {}, -8)));

    // Over
    EXPECT_EQ("{7}", Tests::str(r_src(6, {}, -200)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, {}, -200)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, {}, -200)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, {}, -200)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, {}, -200)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, {}, -200)));
    EXPECT_EQ("{1}", Tests::str(r_src(0, {}, -200)));
}

TEST(range_three_args, step_nagative_test_step_1_with_end)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    range r_src(src);

    // origin
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src));
    EXPECT_EQ("{7, 6, 5, 4, 3, 2, 1}", Tests::str(r_src({}, {}, -1)));

    EXPECT_EQ("{7, 6, 5, 4, 3, 2}", Tests::str(r_src(6, 0, -1)));
    EXPECT_EQ("{6, 5, 4, 3, 2}", Tests::str(r_src(5, 0, -1)));
    EXPECT_EQ("{5, 4, 3, 2}", Tests::str(r_src(4, 0, -1)));
    EXPECT_EQ("{4, 3, 2}", Tests::str(r_src(3, 0, -1)));
    EXPECT_EQ("{3, 2}", Tests::str(r_src(2, 0, -1)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, 0, -1)));
    EXPECT_EQ("{}", Tests::str(r_src(0, 0, -1)));

    EXPECT_EQ("{7, 6, 5, 4, 3}", Tests::str(r_src(6, 1, -1)));
    EXPECT_EQ("{6, 5, 4, 3}", Tests::str(r_src(5, 1, -1)));
    EXPECT_EQ("{5, 4, 3}", Tests::str(r_src(4, 1, -1)));
    EXPECT_EQ("{4, 3}", Tests::str(r_src(3, 1, -1)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 1, -1)));
    EXPECT_EQ("{}", Tests::str(r_src(1, 1, -1)));

    EXPECT_EQ("{7, 6, 5, 4}", Tests::str(r_src(6, 2, -1)));
    EXPECT_EQ("{6, 5, 4}", Tests::str(r_src(5, 2, -1)));
    EXPECT_EQ("{5, 4}", Tests::str(r_src(4, 2, -1)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, 2, -1)));
    EXPECT_EQ("{}", Tests::str(r_src(2, 2, -1)));

    EXPECT_EQ("{7, 6, 5}", Tests::str(r_src(6, 3, -1)));
    EXPECT_EQ("{6, 5}", Tests::str(r_src(5, 3, -1)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 3, -1)));
    EXPECT_EQ("{}", Tests::str(r_src(3, 3, -1)));

    EXPECT_EQ("{7, 6}", Tests::str(r_src(6, 4, -1)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 4, -1)));
    EXPECT_EQ("{}", Tests::str(r_src(4, 4, -1)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 5, -1)));
    EXPECT_EQ("{}", Tests::str(r_src(5, 5, -1)));

    EXPECT_EQ("{}", Tests::str(r_src(6, 6, -1)));
}

TEST(const_range_three_args, step_nagative_test_step_1_with_end)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    const range r_src(src);

    // origin
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src));
    EXPECT_EQ("{7, 6, 5, 4, 3, 2, 1}", Tests::str(r_src({}, {}, -1)));

    EXPECT_EQ("{7, 6, 5, 4, 3, 2}", Tests::str(r_src(6, 0, -1)));
    EXPECT_EQ("{6, 5, 4, 3, 2}", Tests::str(r_src(5, 0, -1)));
    EXPECT_EQ("{5, 4, 3, 2}", Tests::str(r_src(4, 0, -1)));
    EXPECT_EQ("{4, 3, 2}", Tests::str(r_src(3, 0, -1)));
    EXPECT_EQ("{3, 2}", Tests::str(r_src(2, 0, -1)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, 0, -1)));
    EXPECT_EQ("{}", Tests::str(r_src(0, 0, -1)));

    EXPECT_EQ("{7, 6, 5, 4, 3}", Tests::str(r_src(6, 1, -1)));
    EXPECT_EQ("{6, 5, 4, 3}", Tests::str(r_src(5, 1, -1)));
    EXPECT_EQ("{5, 4, 3}", Tests::str(r_src(4, 1, -1)));
    EXPECT_EQ("{4, 3}", Tests::str(r_src(3, 1, -1)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 1, -1)));
    EXPECT_EQ("{}", Tests::str(r_src(1, 1, -1)));

    EXPECT_EQ("{7, 6, 5, 4}", Tests::str(r_src(6, 2, -1)));
    EXPECT_EQ("{6, 5, 4}", Tests::str(r_src(5, 2, -1)));
    EXPECT_EQ("{5, 4}", Tests::str(r_src(4, 2, -1)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, 2, -1)));
    EXPECT_EQ("{}", Tests::str(r_src(2, 2, -1)));

    EXPECT_EQ("{7, 6, 5}", Tests::str(r_src(6, 3, -1)));
    EXPECT_EQ("{6, 5}", Tests::str(r_src(5, 3, -1)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 3, -1)));
    EXPECT_EQ("{}", Tests::str(r_src(3, 3, -1)));

    EXPECT_EQ("{7, 6}", Tests::str(r_src(6, 4, -1)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 4, -1)));
    EXPECT_EQ("{}", Tests::str(r_src(4, 4, -1)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 5, -1)));
    EXPECT_EQ("{}", Tests::str(r_src(5, 5, -1)));

    EXPECT_EQ("{}", Tests::str(r_src(6, 6, -1)));
}

TEST(range_three_args, step_nagative_test_step_2_with_end)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    range r_src(src);

    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src));
    EXPECT_EQ("{7, 5, 3, 1}", Tests::str(r_src({}, {}, -2)));

    EXPECT_EQ("{7, 5, 3}", Tests::str(r_src(6, 0, -2)));
    EXPECT_EQ("{6, 4, 2}", Tests::str(r_src(5, 0, -2)));
    EXPECT_EQ("{5, 3}", Tests::str(r_src(4, 0, -2)));
    EXPECT_EQ("{4, 2}", Tests::str(r_src(3, 0, -2)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 0, -2)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, 0, -2)));
    EXPECT_EQ("{}", Tests::str(r_src(0, 0, -2)));

    EXPECT_EQ("{7, 5, 3}", Tests::str(r_src(6, 1, -2)));
    EXPECT_EQ("{6, 4}", Tests::str(r_src(5, 1, -2)));
    EXPECT_EQ("{5, 3}", Tests::str(r_src(4, 1, -2)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, 1, -2)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 1, -2)));
    EXPECT_EQ("{}", Tests::str(r_src(1, 1, -2)));

    EXPECT_EQ("{7, 5}", Tests::str(r_src(6, 2, -2)));
    EXPECT_EQ("{6, 4}", Tests::str(r_src(5, 2, -2)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 2, -2)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, 2, -2)));
    EXPECT_EQ("{}", Tests::str(r_src(2, 2, -2)));

    EXPECT_EQ("{7, 5}", Tests::str(r_src(6, 3, -2)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 3, -2)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 3, -2)));
    EXPECT_EQ("{}", Tests::str(r_src(3, 3, -2)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 4, -2)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 4, -2)));
    EXPECT_EQ("{}", Tests::str(r_src(4, 4, -2)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 5, -2)));
    EXPECT_EQ("{}", Tests::str(r_src(5, 5, -2)));

    EXPECT_EQ("{}", Tests::str(r_src(6, 6, -2)));
}

TEST(const_range_three_args, step_nagative_test_step_2_with_end)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    const range r_src(src);

    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src));
    EXPECT_EQ("{7, 5, 3, 1}", Tests::str(r_src({}, {}, -2)));

    EXPECT_EQ("{7, 5, 3}", Tests::str(r_src(6, 0, -2)));
    EXPECT_EQ("{6, 4, 2}", Tests::str(r_src(5, 0, -2)));
    EXPECT_EQ("{5, 3}", Tests::str(r_src(4, 0, -2)));
    EXPECT_EQ("{4, 2}", Tests::str(r_src(3, 0, -2)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 0, -2)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, 0, -2)));
    EXPECT_EQ("{}", Tests::str(r_src(0, 0, -2)));

    EXPECT_EQ("{7, 5, 3}", Tests::str(r_src(6, 1, -2)));
    EXPECT_EQ("{6, 4}", Tests::str(r_src(5, 1, -2)));
    EXPECT_EQ("{5, 3}", Tests::str(r_src(4, 1, -2)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, 1, -2)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 1, -2)));
    EXPECT_EQ("{}", Tests::str(r_src(1, 1, -2)));

    EXPECT_EQ("{7, 5}", Tests::str(r_src(6, 2, -2)));
    EXPECT_EQ("{6, 4}", Tests::str(r_src(5, 2, -2)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 2, -2)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, 2, -2)));
    EXPECT_EQ("{}", Tests::str(r_src(2, 2, -2)));

    EXPECT_EQ("{7, 5}", Tests::str(r_src(6, 3, -2)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 3, -2)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 3, -2)));
    EXPECT_EQ("{}", Tests::str(r_src(3, 3, -2)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 4, -2)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 4, -2)));
    EXPECT_EQ("{}", Tests::str(r_src(4, 4, -2)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 5, -2)));
    EXPECT_EQ("{}", Tests::str(r_src(5, 5, -2)));

    EXPECT_EQ("{}", Tests::str(r_src(6, 6, -2)));
}

TEST(range_three_args, step_nagative_test_step_3_with_end)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    range r_src(src);

    // origin
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src));
    EXPECT_EQ("{7, 4, 1}", Tests::str(r_src({}, {}, -3)));


    EXPECT_EQ("{7, 4}", Tests::str(r_src(6, 0, -3)));
    EXPECT_EQ("{6, 3}", Tests::str(r_src(5, 0, -3)));
    EXPECT_EQ("{5, 2}", Tests::str(r_src(4, 0, -3)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, 0, -3)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 0, -3)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, 0, -3)));
    EXPECT_EQ("{}", Tests::str(r_src(0, 0, -3)));

    EXPECT_EQ("{7, 4}", Tests::str(r_src(6, 1, -3)));
    EXPECT_EQ("{6, 3}", Tests::str(r_src(5, 1, -3)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 1, -3)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, 1, -3)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 1, -3)));
    EXPECT_EQ("{}", Tests::str(r_src(1, 1, -3)));

    EXPECT_EQ("{7, 4}", Tests::str(r_src(6, 2, -3)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 2, -3)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 2, -3)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, 2, -3)));
    EXPECT_EQ("{}", Tests::str(r_src(2, 2, -3)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 3, -3)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 3, -3)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 3, -3)));
    EXPECT_EQ("{}", Tests::str(r_src(3, 3, -3)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 4, -3)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 4, -3)));
    EXPECT_EQ("{}", Tests::str(r_src(4, 4, -3)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 5, -3)));
    EXPECT_EQ("{}", Tests::str(r_src(5, 5, -3)));

    EXPECT_EQ("{}", Tests::str(r_src(6, 6, -3)));
}

TEST(const_range_three_args, step_nagative_test_step_3_with_end)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    const range r_src(src);

    // origin
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src));
    EXPECT_EQ("{7, 4, 1}", Tests::str(r_src({}, {}, -3)));


    EXPECT_EQ("{7, 4}", Tests::str(r_src(6, 0, -3)));
    EXPECT_EQ("{6, 3}", Tests::str(r_src(5, 0, -3)));
    EXPECT_EQ("{5, 2}", Tests::str(r_src(4, 0, -3)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, 0, -3)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 0, -3)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, 0, -3)));
    EXPECT_EQ("{}", Tests::str(r_src(0, 0, -3)));

    EXPECT_EQ("{7, 4}", Tests::str(r_src(6, 1, -3)));
    EXPECT_EQ("{6, 3}", Tests::str(r_src(5, 1, -3)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 1, -3)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, 1, -3)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 1, -3)));
    EXPECT_EQ("{}", Tests::str(r_src(1, 1, -3)));

    EXPECT_EQ("{7, 4}", Tests::str(r_src(6, 2, -3)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 2, -3)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 2, -3)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, 2, -3)));
    EXPECT_EQ("{}", Tests::str(r_src(2, 2, -3)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 3, -3)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 3, -3)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 3, -3)));
    EXPECT_EQ("{}", Tests::str(r_src(3, 3, -3)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 4, -3)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 4, -3)));
    EXPECT_EQ("{}", Tests::str(r_src(4, 4, -3)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 5, -3)));
    EXPECT_EQ("{}", Tests::str(r_src(5, 5, -3)));

    EXPECT_EQ("{}", Tests::str(r_src(6, 6, -3)));
}

TEST(range_three_args, step_nagative_test_step_6_with_end)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    range r_src(src);

    // origin
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src));
    EXPECT_EQ("{7, 1}", Tests::str(r_src({}, {}, -6)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 0, -6)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 0, -6)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 0, -6)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, 0, -6)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 0, -6)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, 0, -6)));
    EXPECT_EQ("{}", Tests::str(r_src(0, 0, -6)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 1, -6)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 1, -6)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 1, -6)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, 1, -6)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 1, -6)));
    EXPECT_EQ("{}", Tests::str(r_src(1, 1, -6)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 2, -6)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 2, -6)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 2, -6)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, 2, -6)));
    EXPECT_EQ("{}", Tests::str(r_src(2, 2, -6)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 3, -6)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 3, -6)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 3, -6)));
    EXPECT_EQ("{}", Tests::str(r_src(3, 3, -6)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 4, -6)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 4, -6)));
    EXPECT_EQ("{}", Tests::str(r_src(4, 4, -6)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 5, -6)));
    EXPECT_EQ("{}", Tests::str(r_src(5, 5, -6)));

    EXPECT_EQ("{}", Tests::str(r_src(6, 6, -6)));
}

TEST(const_range_three_args, step_nagative_test_step_6_with_end)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    const range r_src(src);

    // origin
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src));
    EXPECT_EQ("{7, 1}", Tests::str(r_src({}, {}, -6)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 0, -6)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 0, -6)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 0, -6)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, 0, -6)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 0, -6)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, 0, -6)));
    EXPECT_EQ("{}", Tests::str(r_src(0, 0, -6)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 1, -6)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 1, -6)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 1, -6)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, 1, -6)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 1, -6)));
    EXPECT_EQ("{}", Tests::str(r_src(1, 1, -6)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 2, -6)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 2, -6)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 2, -6)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, 2, -6)));
    EXPECT_EQ("{}", Tests::str(r_src(2, 2, -6)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 3, -6)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 3, -6)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 3, -6)));
    EXPECT_EQ("{}", Tests::str(r_src(3, 3, -6)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 4, -6)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 4, -6)));
    EXPECT_EQ("{}", Tests::str(r_src(4, 4, -6)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 5, -6)));
    EXPECT_EQ("{}", Tests::str(r_src(5, 5, -6)));

    EXPECT_EQ("{}", Tests::str(r_src(6, 6, -6)));
}

TEST(range_three_args, step_nagative_test_step_7_with_end)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    range r_src(src);

    // origin
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src));
    EXPECT_EQ("{7}", Tests::str(r_src({}, {}, -7)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 0, -7)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 0, -7)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 0, -7)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, 0, -7)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 0, -7)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, 0, -7)));
    EXPECT_EQ("{}", Tests::str(r_src(0, 0, -7)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 1, -7)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 1, -7)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 1, -7)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, 1, -7)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 1, -7)));
    EXPECT_EQ("{}", Tests::str(r_src(1, 1, -7)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 2, -7)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 2, -7)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 2, -7)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, 2, -7)));
    EXPECT_EQ("{}", Tests::str(r_src(2, 2, -7)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 3, -7)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 3, -7)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 3, -7)));
    EXPECT_EQ("{}", Tests::str(r_src(3, 3, -7)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 4, -7)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 4, -7)));
    EXPECT_EQ("{}", Tests::str(r_src(4, 4, -7)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 5, -7)));
    EXPECT_EQ("{}", Tests::str(r_src(5, 5, -7)));

    EXPECT_EQ("{}", Tests::str(r_src(6, 6, -7)));
}

TEST(const_range_three_args, step_nagative_test_step_7_with_end)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    const range r_src(src);

    // origin
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src));
    EXPECT_EQ("{7}", Tests::str(r_src({}, {}, -7)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 0, -7)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 0, -7)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 0, -7)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, 0, -7)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 0, -7)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, 0, -7)));
    EXPECT_EQ("{}", Tests::str(r_src(0, 0, -7)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 1, -7)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 1, -7)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 1, -7)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, 1, -7)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 1, -7)));
    EXPECT_EQ("{}", Tests::str(r_src(1, 1, -7)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 2, -7)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 2, -7)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 2, -7)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, 2, -7)));
    EXPECT_EQ("{}", Tests::str(r_src(2, 2, -7)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 3, -7)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 3, -7)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 3, -7)));
    EXPECT_EQ("{}", Tests::str(r_src(3, 3, -7)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 4, -7)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 4, -7)));
    EXPECT_EQ("{}", Tests::str(r_src(4, 4, -7)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 5, -7)));
    EXPECT_EQ("{}", Tests::str(r_src(5, 5, -7)));

    EXPECT_EQ("{}", Tests::str(r_src(6, 6, -7)));
}

TEST(range_three_args, step_nagative_test_step_8_with_end)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    range r_src(src);

    // origin
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src));
    EXPECT_EQ("{7}", Tests::str(r_src({}, {}, -8)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 0, -8)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 0, -8)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 0, -8)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, 0, -8)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 0, -8)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, 0, -8)));
    EXPECT_EQ("{}", Tests::str(r_src(0, 0, -8)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 1, -8)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 1, -8)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 1, -8)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, 1, -8)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 1, -8)));
    EXPECT_EQ("{}", Tests::str(r_src(1, 1, -8)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 2, -8)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 2, -8)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 2, -8)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, 2, -8)));
    EXPECT_EQ("{}", Tests::str(r_src(2, 2, -8)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 3, -8)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 3, -8)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 3, -8)));
    EXPECT_EQ("{}", Tests::str(r_src(3, 3, -8)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 4, -8)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 4, -8)));
    EXPECT_EQ("{}", Tests::str(r_src(4, 4, -8)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 5, -8)));
    EXPECT_EQ("{}", Tests::str(r_src(5, 5, -8)));

    EXPECT_EQ("{}", Tests::str(r_src(6, 6, -8)));
}

TEST(const_range_three_args, step_nagative_test_step_8_with_end)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    const range r_src(src);

    // origin
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src));
    EXPECT_EQ("{7}", Tests::str(r_src({}, {}, -8)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 0, -8)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 0, -8)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 0, -8)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, 0, -8)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 0, -8)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, 0, -8)));
    EXPECT_EQ("{}", Tests::str(r_src(0, 0, -8)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 1, -8)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 1, -8)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 1, -8)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, 1, -8)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 1, -8)));
    EXPECT_EQ("{}", Tests::str(r_src(1, 1, -8)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 2, -8)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 2, -8)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 2, -8)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, 2, -8)));
    EXPECT_EQ("{}", Tests::str(r_src(2, 2, -8)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 3, -8)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 3, -8)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 3, -8)));
    EXPECT_EQ("{}", Tests::str(r_src(3, 3, -8)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 4, -8)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 4, -8)));
    EXPECT_EQ("{}", Tests::str(r_src(4, 4, -8)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 5, -8)));
    EXPECT_EQ("{}", Tests::str(r_src(5, 5, -8)));

    EXPECT_EQ("{}", Tests::str(r_src(6, 6, -8)));
}

TEST(range_three_args, step_nagative_test_step_200_with_end)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    range r_src(src);

    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src));
    EXPECT_EQ("{7}", Tests::str(r_src({}, {}, -200)));


    EXPECT_EQ("{7}", Tests::str(r_src(6, 0, -200)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 0, -200)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 0, -200)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, 0, -200)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 0, -200)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, 0, -200)));
    EXPECT_EQ("{}", Tests::str(r_src(0, 0, -200)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 1, -200)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 1, -200)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 1, -200)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, 1, -200)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 1, -200)));
    EXPECT_EQ("{}", Tests::str(r_src(1, 1, -200)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 2, -200)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 2, -200)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 2, -200)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, 2, -200)));
    EXPECT_EQ("{}", Tests::str(r_src(2, 2, -200)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 3, -200)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 3, -200)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 3, -200)));
    EXPECT_EQ("{}", Tests::str(r_src(3, 3, -200)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 4, -200)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 4, -200)));
    EXPECT_EQ("{}", Tests::str(r_src(4, 4, -200)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 5, -200)));
    EXPECT_EQ("{}", Tests::str(r_src(5, 5, -200)));

    EXPECT_EQ("{}", Tests::str(r_src(6, 6, -200)));
}

TEST(const_range_three_args, step_nagative_test_step_200_with_end)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    const range r_src(src);

    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src));
    EXPECT_EQ("{7}", Tests::str(r_src({}, {}, -200)));


    EXPECT_EQ("{7}", Tests::str(r_src(6, 0, -200)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 0, -200)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 0, -200)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, 0, -200)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 0, -200)));
    EXPECT_EQ("{2}", Tests::str(r_src(1, 0, -200)));
    EXPECT_EQ("{}", Tests::str(r_src(0, 0, -200)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 1, -200)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 1, -200)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 1, -200)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, 1, -200)));
    EXPECT_EQ("{3}", Tests::str(r_src(2, 1, -200)));
    EXPECT_EQ("{}", Tests::str(r_src(1, 1, -200)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 2, -200)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 2, -200)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 2, -200)));
    EXPECT_EQ("{4}", Tests::str(r_src(3, 2, -200)));
    EXPECT_EQ("{}", Tests::str(r_src(2, 2, -200)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 3, -200)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 3, -200)));
    EXPECT_EQ("{5}", Tests::str(r_src(4, 3, -200)));
    EXPECT_EQ("{}", Tests::str(r_src(3, 3, -200)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 4, -200)));
    EXPECT_EQ("{6}", Tests::str(r_src(5, 4, -200)));
    EXPECT_EQ("{}", Tests::str(r_src(4, 4, -200)));

    EXPECT_EQ("{7}", Tests::str(r_src(6, 5, -200)));
    EXPECT_EQ("{}", Tests::str(r_src(5, 5, -200)));

    EXPECT_EQ("{}", Tests::str(r_src(6, 6, -200)));
}

TEST(range_three_args, exception_test)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    range r_src(src);
    range trash = r_src;

    // step == 0
    EXPECT_THROW(trash = r_src({}, {}, 0), std::overflow_error);


    // inverted start and end from step
    EXPECT_THROW(trash = r_src(5, 2, 1), std::out_of_range);
    EXPECT_THROW(trash = r_src(2, 5, -1), std::out_of_range);


    // edge
    EXPECT_THROW(trash = r_src(200, {}, 1), std::out_of_range);
    EXPECT_THROW(trash = r_src(8, {}, 1), std::out_of_range);
    EXPECT_THROW(trash = r_src(-8, {}, 1), std::out_of_range);
    EXPECT_THROW(trash = r_src(-200, {}, 1), std::out_of_range);

    EXPECT_THROW(trash = r_src({}, 200, 1), std::out_of_range);
    EXPECT_THROW(trash = r_src({}, 8, 1), std::out_of_range);
    EXPECT_THROW(trash = r_src({}, -8, 1), std::out_of_range);
    EXPECT_THROW(trash = r_src({}, 200, 1), std::out_of_range);



    // empty
    src = {};
    r_src = range(src);

    // step == 0
    EXPECT_THROW(trash = r_src({}, {}, 0), std::overflow_error);


    // inverted start and end from step
    EXPECT_THROW(trash = r_src(5, 2, 1), std::out_of_range);
    EXPECT_THROW(trash = r_src(2, 5, -1), std::out_of_range);


    // edge
    EXPECT_THROW(trash = r_src(200, {}, 1), std::out_of_range);
    EXPECT_THROW(trash = r_src(1, {}, 1), std::out_of_range);
    EXPECT_THROW(trash = r_src(-1, {}, 1), std::out_of_range);
    EXPECT_THROW(trash = r_src(200, {}, 1), std::out_of_range);

    EXPECT_THROW(trash = r_src({}, 200, 1), std::out_of_range);
    EXPECT_THROW(trash = r_src({}, 1, 1), std::out_of_range);
    EXPECT_THROW(trash = r_src({}, -1, 1), std::out_of_range);
    EXPECT_THROW(trash = r_src({}, 200, 1), std::out_of_range);

    EXPECT_THROW(trash = r_src(200, {}, -1), std::out_of_range);
    EXPECT_THROW(trash = r_src(1, {}, -1), std::out_of_range);
    EXPECT_THROW(trash = r_src(-1, {}, -1), std::out_of_range);
    EXPECT_THROW(trash = r_src(200, {}, -1), std::out_of_range);

    EXPECT_THROW(trash = r_src({}, 200, -1), std::out_of_range);
    EXPECT_THROW(trash = r_src({}, 1, -1), std::out_of_range);
    EXPECT_THROW(trash = r_src({}, -1, -1), std::out_of_range);
    EXPECT_THROW(trash = r_src({}, 200, -1), std::out_of_range);
}

TEST(const_range_three_args, exception_test)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    const range r_src(src);
    range<const std::vector<int>> trash = r_src;

    // step == 0
    EXPECT_THROW(trash = r_src({}, {}, 0), std::overflow_error);


    // inverted start and end from step
    EXPECT_THROW(trash = r_src(5, 2, 1), std::out_of_range);
    EXPECT_THROW(trash = r_src(2, 5, -1), std::out_of_range);


    // edge
    EXPECT_THROW(trash = r_src(200, {}, 1), std::out_of_range);
    EXPECT_THROW(trash = r_src(8, {}, 1), std::out_of_range);
    EXPECT_THROW(trash = r_src(-8, {}, 1), std::out_of_range);
    EXPECT_THROW(trash = r_src(-200, {}, 1), std::out_of_range);

    EXPECT_THROW(trash = r_src({}, 200, 1), std::out_of_range);
    EXPECT_THROW(trash = r_src({}, 8, 1), std::out_of_range);
    EXPECT_THROW(trash = r_src({}, -8, 1), std::out_of_range);
    EXPECT_THROW(trash = r_src({}, 200, 1), std::out_of_range);



    // empty
    src = {};
    const range r_src2(src);

    // step == 0
    EXPECT_THROW(trash = r_src2({}, {}, 0), std::overflow_error);


    // inverted start and end from step
    EXPECT_THROW(trash = r_src2(5, 2, 1), std::out_of_range);
    EXPECT_THROW(trash = r_src2(2, 5, -1), std::out_of_range);


    // edge
    EXPECT_THROW(trash = r_src2(200, {}, 1), std::out_of_range);
    EXPECT_THROW(trash = r_src2(1, {}, 1), std::out_of_range);
    EXPECT_THROW(trash = r_src2(-1, {}, 1), std::out_of_range);
    EXPECT_THROW(trash = r_src2(200, {}, 1), std::out_of_range);

    EXPECT_THROW(trash = r_src2({}, 200, 1), std::out_of_range);
    EXPECT_THROW(trash = r_src2({}, 1, 1), std::out_of_range);
    EXPECT_THROW(trash = r_src2({}, -1, 1), std::out_of_range);
    EXPECT_THROW(trash = r_src2({}, 200, 1), std::out_of_range);

    EXPECT_THROW(trash = r_src2(200, {}, -1), std::out_of_range);
    EXPECT_THROW(trash = r_src2(1, {}, -1), std::out_of_range);
    EXPECT_THROW(trash = r_src2(-1, {}, -1), std::out_of_range);
    EXPECT_THROW(trash = r_src2(200, {}, -1), std::out_of_range);

    EXPECT_THROW(trash = r_src2({}, 200, -1), std::out_of_range);
    EXPECT_THROW(trash = r_src2({}, 1, -1), std::out_of_range);
    EXPECT_THROW(trash = r_src2({}, -1, -1), std::out_of_range);
    EXPECT_THROW(trash = r_src2({}, 200, -1), std::out_of_range);
}
