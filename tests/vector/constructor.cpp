//
// Created by Ail on 11/08/2020.
//

#include "gtest/gtest.h"
#include "testes_helper.hpp"
#include "range_vector.hpp"
#include <any>

TEST(vector_constructor, range_operator)
{
    {
        vector<int> src;
    }
    {
        vector<int> src((std::allocator<int>()));
    }
    {
        vector<int> src(5);
    }

    vector<int> src(5, 3);
    EXPECT_EQ("{3, 3, 3, 3, 3}", Tests::str(src));

    {
        vector<int> src2(src);
        EXPECT_EQ("{3, 3, 3, 3, 3}", Tests::str(src2));

        src = std::move(src2);
        EXPECT_EQ("{3, 3, 3, 3, 3}", Tests::str(src));
        EXPECT_EQ("{}", Tests::str(src2));
    }

    {
        vector<int> src2(std::move(src));
        EXPECT_EQ("{}", Tests::str(src));
        EXPECT_EQ("{3, 3, 3, 3, 3}", Tests::str(src2));

        src = src2;
        EXPECT_EQ("{3, 3, 3, 3, 3}", Tests::str(src));
        EXPECT_EQ("{3, 3, 3, 3, 3}", Tests::str(src2));
    }

    {
        vector<int> src2(src, std::allocator<int>());
        EXPECT_EQ("{3, 3, 3, 3, 3}", Tests::str(src2));
    }

    {
        vector<int> src2(std::move(src), std::allocator<int>());
        EXPECT_EQ("{}", Tests::str(src));
        EXPECT_EQ("{3, 3, 3, 3, 3}", Tests::str(src2));

        src = src2;
        EXPECT_EQ("{3, 3, 3, 3, 3}", Tests::str(src));
        EXPECT_EQ("{3, 3, 3, 3, 3}", Tests::str(src2));
    }
    {
        vector<int> src2(src.begin(), src.end());
        EXPECT_EQ("{3, 3, 3, 3, 3}", Tests::str(src2));

        src2 = {1, 2, 3};
        EXPECT_EQ("{1, 2, 3}", Tests::str(src2));
    }
}