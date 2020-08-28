//
// Created by Ail on 22/08/2020.
//

#include "gtest/gtest.h"
#include "testes_helper.hpp"


template <typename T, T ...values>
struct const_array {
    using type = T[sizeof...(values)];

    static constexpr const type value = {values...};

public:
    class iterator : public std::iterator<std::random_access_iterator_tag, T> {
        static constexpr const type &value = const_array::value;
        ptrdiff_t idx{};

    public:
        constexpr explicit iterator(ptrdiff_t idx) noexcept : idx(idx)  {}

    public:
        constexpr iterator()=default;
        constexpr iterator(const iterator&)=default;
        constexpr iterator(iterator&&)noexcept=default;

        constexpr inline iterator& operator++() noexcept
        {
            this->idx++;
            return *this;
        }

        constexpr inline iterator& operator--() noexcept
        {
            this->idx--;
            return *this;
        }

        constexpr inline iterator& operator+=(ptrdiff_t n) noexcept
        {
            this->idx += n;
            return *this;
        }

        constexpr inline iterator& operator-=(ptrdiff_t n) noexcept
        {
            this->idx -= n;
            return *this;
        }

        constexpr inline iterator operator+(ptrdiff_t n) const noexcept
        {
            return iterator{this->idx + n};
        }

        constexpr inline iterator operator-(ptrdiff_t n) const noexcept
        {
            return iterator{this->idx - n};
        }

        constexpr inline ptrdiff_t operator-(const iterator &other) const noexcept
        {
            return this->idx - other.idx;
        }

        constexpr inline T operator*() const noexcept
        {
            return this->value[idx];
        }

        constexpr inline T operator->() const noexcept
        {
            return this->value[idx];
        }

        constexpr inline T operator[](ptrdiff_t n) const noexcept
        {
            return this->value[idx + n];
        }

        constexpr inline bool operator==(const iterator &other) const noexcept
        {
            return this->idx == other.idx;
        }

        constexpr inline bool operator!=(const iterator &other) const noexcept
        {
            return this->idx != other.idx;
        }

        constexpr inline bool operator<(const iterator &other) const noexcept
        {
            return this->idx < other.idx;
        }

        constexpr inline bool operator>(const iterator &other) const noexcept
        {
            return this->idx > other.idx;
        }

        constexpr inline bool operator<=(const iterator &other) const noexcept
        {
            return this->idx <= other.idx;
        }

        constexpr inline bool operator>=(const iterator &other) const noexcept
        {
            return this->idx >= other.idx;
        }
    };

    [[nodiscard]] constexpr size_t size() const
    {
        return sizeof...(values);
    }

    [[nodiscard]] constexpr iterator begin()
    {
        return iterator(0);
    }

    [[nodiscard]] constexpr iterator begin() const
    {
        return iterator(0);
    }

    [[nodiscard]] constexpr iterator end()
    {
        return iterator(this->size());
    }

    [[nodiscard]] constexpr iterator end() const
    {
        return iterator(this->size());
    }
};


#define CONST_EVAL(...) (std::integral_constant<typename std::remove_reference<decltype(__VA_ARGS__)>::type, __VA_ARGS__>::value)


TEST(range_constexpr, basic_tests)
{
    constexpr const_array<int, 1, 2, 3, 4, 5, 6, 7> array{};
    constexpr range range1(array);
    constexpr range range2 = range1(1, -1);

    EXPECT_EQ(2, CONST_EVAL(*range2.begin()));
    EXPECT_EQ(3, CONST_EVAL(*(range2.begin() + 1)));
    EXPECT_EQ(6, CONST_EVAL(*(range2.begin() + 4)));
    EXPECT_EQ(7, CONST_EVAL(*(range2.begin() + 5))); // This one is a tricky one
    //EXPECT_EQ(7, CONST_EVAL(*(range2.begin() + 6))); // Can't compile
    EXPECT_EQ(1, CONST_EVAL(*(range2.begin() + -1))); // This one is a tricky one
    //EXPECT_EQ(1, CONST_EVAL(*(range2.begin() + -2))); // Can't compile
    EXPECT_EQ(4, CONST_EVAL(*range2(2, {}).begin()));
}

TEST(range_constexpr, c_str)
{
    constexpr range range1("salut");
    constexpr range range2 = range1(1, -1);
    constexpr range range3 = range(":salut")({}, 0, -1);

    constexpr const_array<char, *(range2.begin() + 0), *(range2.begin() + 1), *(range2.begin() + 2), *(range2.begin() + -1), *(range2.begin() + 3)> array{};

    EXPECT_EQ("alust", range(array).to<std::string>());

    EXPECT_EQ("tulas", range3.to<std::string>());

    constexpr range r_array = range(array);
    constexpr auto c_std_array = r_array.constexpr_to<std::array<char, r_array.size()>>();
    auto std_array = r_array.constexpr_to<std::array<char, r_array.size()>>();

    EXPECT_TRUE((std::is_same<const std::array<char, r_array.size()>, decltype(c_std_array)>::value));
    EXPECT_TRUE((std::is_same<std::array<char, r_array.size()>, decltype(std_array)>::value));
    EXPECT_TRUE(std::equal(std_array.begin(), std_array.end(), r_array.begin()));

    EXPECT_EQ('u', CONST_EVAL(c_std_array[2]));
}
