//
// Created by Ail on 27/08/2020.
//

#include "gtest/gtest.h"
#include "testes_helper.hpp"

TEST(range_multiple, basic_test)
{
    std::vector src = {1, 2, 3, 4, 5, 6, 7};


    {
        range r_src = range(src)(1, -1);
        EXPECT_EQ("{2, 3, 4, 5, 6}", Tests::str(r_src));

        EXPECT_EQ("{4, 5, 6}", Tests::str(r_src(2)));

        EXPECT_EQ("{2, 3, 4}", Tests::str(r_src(0, -2)));

        EXPECT_EQ("{6, 5, 4, 3, 2}", Tests::str(r_src({}, {}, -1)));

        EXPECT_EQ("{6, 4}", Tests::str(r_src({}, 0, -2)));

        EXPECT_EQ("{6, 4, 2}", Tests::str(r_src({}, {}, -2)));

        EXPECT_EQ("{6, 4}", Tests::str(r_src({}, 1, -2)));
    }

    {
        range r_src = range(src)({}, {}, 2);
        EXPECT_EQ("{1, 3, 5, 7}", Tests::str(r_src));

        EXPECT_EQ("{5, 7}", Tests::str(r_src(2)));

        EXPECT_EQ("{1, 3}", Tests::str(r_src(0, -2)));

        EXPECT_EQ("{7, 5, 3, 1}", Tests::str(r_src({}, {}, -1)));

        EXPECT_EQ("{7, 3}", Tests::str(r_src({}, 0, -2)));

        EXPECT_EQ("{7, 3}", Tests::str(r_src({}, {}, -2)));

        EXPECT_EQ("{7}", Tests::str(r_src({}, 1, -2)));
    }

    {
        range r_src = range(src)({}, {}, -1);
        EXPECT_EQ("{7, 6, 5, 4, 3, 2, 1}", Tests::str(r_src));

        EXPECT_EQ("{5, 4, 3, 2, 1}", Tests::str(r_src(2)));

        EXPECT_EQ("{7, 6, 5, 4, 3}", Tests::str(r_src(0, -2)));

        EXPECT_EQ("{1, 2, 3, 4, 5, 6, 7}", Tests::str(r_src({}, {}, -1)));

        EXPECT_EQ("{1, 3, 5}", Tests::str(r_src({}, 0, -2)));

        EXPECT_EQ("{1, 3, 5, 7}", Tests::str(r_src({}, {}, -2)));

        EXPECT_EQ("{1, 3, 5}", Tests::str(r_src({}, 1, -2)));
    }
}