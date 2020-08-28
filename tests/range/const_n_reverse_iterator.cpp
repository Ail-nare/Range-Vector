//
// Created by Ail on 22/08/2020.
//

#include "gtest/gtest.h"
#include "testes_helper.hpp"
#include <list>

TEST(const_n_reverse_iterator, test)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    const range r1(src);

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