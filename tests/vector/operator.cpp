//
// Created by Ail on 11/08/2020.
//

#include "gtest/gtest.h"
#include "testes_helper.hpp"
#include "range/vector.hpp"

TEST(vector_operator, range_operator)
{
    vector<int> src {1, 2, 3, 4, 5, 6, 7};

    // origin
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(src));

    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(src(0)));
    EXPECT_EQ("{2, 3, 4, 5, 6, 7}", Tests::str(src(1)));
    EXPECT_EQ("{7}", Tests::str(src(6)));
    EXPECT_EQ("{}", Tests::str(src(7)));

    EXPECT_EQ("{7}", Tests::str(src(-1)));
    EXPECT_EQ("{6, 7}", Tests::str(src(-2)));
    EXPECT_EQ("{2, 3, 4, 5, 6, 7}", Tests::str(src(-6)));
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(src(-7)));

    EXPECT_EQ("{2, 3, 4, 5, 6}", Tests::str(src(1, -1)));

    EXPECT_EQ("{6, 4, 2}", Tests::str(src(-2, 0, -2)));
}

TEST(const_vector_operator, range_operator)
{
    const vector<int> src {1, 2, 3, 4, 5, 6, 7};

    // origin
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(src));

    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(src(0)));
    EXPECT_EQ("{2, 3, 4, 5, 6, 7}", Tests::str(src(1)));
    EXPECT_EQ("{7}", Tests::str(src(6)));
    EXPECT_EQ("{}", Tests::str(src(7)));

    EXPECT_EQ("{7}", Tests::str(src(-1)));
    EXPECT_EQ("{6, 7}", Tests::str(src(-2)));
    EXPECT_EQ("{2, 3, 4, 5, 6, 7}", Tests::str(src(-6)));
    EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(src(-7)));

    EXPECT_EQ("{2, 3, 4, 5, 6}", Tests::str(src(1, -1)));

    EXPECT_EQ("{6, 4, 2}", Tests::str(src(-2, 0, -2)));
}

TEST(vector_operator, operator_bracket)
{
    vector<int> src {1, 2, 3, 4, 5, 6, 7};

    EXPECT_EQ(1, src[0]);
    EXPECT_EQ(2, src[1]);
    EXPECT_EQ(6, src[5]);
    EXPECT_EQ(7, src[6]);

    EXPECT_EQ(7, src[-1]);
    EXPECT_EQ(6, src[-2]);
}

TEST(const_vector_operator, operator_bracket)
{
    const vector<int> src {1, 2, 3, 4, 5, 6, 7};

    EXPECT_EQ(1, src[0]);
    EXPECT_EQ(2, src[1]);
    EXPECT_EQ(6, src[5]);
    EXPECT_EQ(7, src[6]);

    EXPECT_EQ(7, src[-1]);
    EXPECT_EQ(6, src[-2]);
}