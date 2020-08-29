//
// Created by Ail on 22/08/2020.
//

#include "gtest/gtest.h"
#include "testes_helper.hpp"
#include <list>
#include "range/xrange.hpp"

TEST(const_n_reverse_xiterator, test)
{
    const xrange r1(1, 8);

    int cnt = 0;

    std::for_each(r1.cbegin(), r1.cend(), [&cnt] (const auto &i) {
        EXPECT_EQ(++cnt, i);
    });

    EXPECT_EQ(cnt, 7);

    std::for_each(r1.rbegin(), r1.rend(), [&cnt] (const auto &i) {
        EXPECT_EQ(cnt--, i);
    });

    EXPECT_EQ(cnt, 0);
}