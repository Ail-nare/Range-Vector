//
// Created by Ail on 11/08/2020.
//

#include "gtest/gtest.h"
#include "testes_helper.hpp"
#include "range_vector.hpp"
#include <any>

TEST(iterator_operator, basic_tests)
{
    vector<int> src {1, 2, 3, 4, 5, 6, 7};
    auto r_src = range(src)(1, -1, 2);
    auto it = r_src.begin();

    EXPECT_EQ(2, *it);
    EXPECT_EQ(2, it.operator->());
    EXPECT_EQ(4, *(++it));
    EXPECT_EQ(4, *(it++));
    EXPECT_EQ(4, *(--it));
    EXPECT_EQ(4, *(it--));
    EXPECT_EQ(2, *it);
    EXPECT_EQ(6, it[2]);
    it += 2;
    EXPECT_EQ(6, *it);
    it -= 1;
    EXPECT_EQ(4, *it);
}

TEST(const_iterator_operator, basic_tests)
{
    vector<int> src {1, 2, 3, 4, 5, 6, 7};
    auto r_src = range(src)(1, -1, 2);

    {
        const auto it = r_src.begin();

        EXPECT_EQ(2, *it);
        EXPECT_EQ(2, it.operator->());
        EXPECT_EQ(4, *(it + 1));

        const auto it2 = it + 1;
        EXPECT_EQ(2, *(it2 - 1));

        EXPECT_EQ(6, it[2]);
    }

    const auto it = r_src.begin() + 1;

    {
        EXPECT_EQ(1, it - r_src.begin());

        EXPECT_EQ(false, it < r_src.begin());
        EXPECT_EQ(true, it > r_src.begin());
        EXPECT_EQ(true, r_src.begin() < it);
        EXPECT_EQ(false, r_src.begin() > it);

        EXPECT_EQ(false, it < it);
        EXPECT_EQ(false, it > it);
        EXPECT_EQ(false, it < it);
        EXPECT_EQ(false, it > it);

        EXPECT_EQ(false, it <= r_src.begin());
        EXPECT_EQ(true, it >= r_src.begin());
        EXPECT_EQ(true, r_src.begin() <= it);
        EXPECT_EQ(false, r_src.begin() >= it);

        EXPECT_EQ(true, it <= it);
        EXPECT_EQ(true, it >= it);
        EXPECT_EQ(true, it <= it);
        EXPECT_EQ(true, it >= it);

        EXPECT_EQ(true, it == it);
        EXPECT_EQ(false, it == r_src.begin());

        EXPECT_EQ(false, it != it);
        EXPECT_EQ(true, it != r_src.begin());
    }

    auto rit = it.reverse();
    ++rit;
    EXPECT_EQ(true, rit.reverse() == r_src.begin());
}