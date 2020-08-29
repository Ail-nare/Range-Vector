//
// Created by Ail on 29/08/2020.
//

#ifndef RANGE_VECTOR_XRANGE_HPP
#define RANGE_VECTOR_XRANGE_HPP

#include <type_traits>
#include <iterator>

template <typename intxx_t=int32_t, typename std::enable_if<std::is_integral<intxx_t>::value, int>::type=0>
class [[nodiscard]] xrange {
    class iterator : public std::iterator<std::random_access_iterator_tag, intxx_t> {
        intxx_t _it{};
        intxx_t _step{};

    public:
        [[maybe_unused]] constexpr iterator(intxx_t it, ptrdiff_t step)
            : _it(it), _step(step)
        {}

        [[maybe_unused]] constexpr iterator()=default;
        [[maybe_unused]] constexpr iterator(const iterator &)=default;
        [[maybe_unused]] constexpr iterator(iterator &&) noexcept=default;

        [[maybe_unused]] constexpr iterator& operator=(const iterator &)=default;
        [[maybe_unused]] constexpr iterator& operator=(iterator &&) noexcept=default;


        [[maybe_unused]] [[nodiscard]] constexpr inline intxx_t operator*() const
        {
            return this->_it;
        }

        [[maybe_unused]] [[nodiscard]] constexpr inline intxx_t operator->() const
        {
            return this->_it;
        }


        [[maybe_unused]] constexpr inline iterator& operator++()
        {
            this->_it += this->_step;
            return *this;
        }

        [[maybe_unused]] constexpr inline iterator& operator--()
        {
            this->_it -= this->_step;
            return *this;
        }

        [[maybe_unused]] constexpr inline iterator operator++(int)
        {
            iterator tmp = *this;
            this->_it += this->_step;
            return tmp;
        }

        [[maybe_unused]] constexpr inline iterator operator--(int)
        {
            iterator tmp = *this;
            this->_it -= this->_step;
            return tmp;
        }

        [[maybe_unused]] constexpr inline iterator& operator+=(ptrdiff_t n)
        {
            this->_it += (this->_step * n);
            return *this;
        }

        [[maybe_unused]] constexpr inline iterator& operator-=(ptrdiff_t n)
        {
            this->_it -= (this->_step * n);
            return *this;
        }


        [[maybe_unused]] [[nodiscard]] constexpr inline iterator operator+(ptrdiff_t n) const
        {
            iterator new_it = *this;

            new_it._it += new_it._step * n;
            return new_it;
        }

        [[maybe_unused]] [[nodiscard]] constexpr inline iterator operator-(ptrdiff_t n) const
        {
            iterator new_it = *this;

            new_it._it -= new_it._step * n;
            return new_it;
        }


        [[maybe_unused]] [[nodiscard]] constexpr inline ptrdiff_t operator-(const iterator &other) const
        {
            return ((this->_step > 0) ? (this->_it - other._it) : (other._it - this->_it)) / this->_step;
        }


        [[maybe_unused]] [[nodiscard]] constexpr inline intxx_t operator[](ptrdiff_t n) const
        {
            return *(*this + n);
        }


        [[maybe_unused]] [[nodiscard]] constexpr inline bool operator<(const iterator &other) const
        {
            return (_step > 0) ?  (this->_it < other._it) : (other._it < this->_it);
        }

        [[maybe_unused]] [[nodiscard]] constexpr inline bool operator>(const iterator &other) const
        {
            return other < *this;
        }

        [[maybe_unused]] [[nodiscard]] constexpr inline bool operator<=(const iterator &other) const
        {
            return (_step > 0) ?  (this->_it <= other._it) : (other._it <= this->_it);
        }

        [[maybe_unused]] [[nodiscard]] constexpr inline bool operator>=(const iterator &other) const
        {
            return other <= *this;
        }


        [[maybe_unused]] [[nodiscard]] constexpr inline bool operator==(const iterator &other) const
        {
            return this->_it == other._it;
        }

        [[maybe_unused]] [[nodiscard]] constexpr inline bool operator!=(const iterator &other) const
        {
            return this->_it != other._it;
        }


        [[maybe_unused]] [[nodiscard]] constexpr inline iterator reverse() const
        {
            return {this->_it - this->_step, -this->_step};
        }
    };

protected:
    intxx_t _start;
    intxx_t _end;
    intxx_t _step;

public:
    xrange()=delete;
    constexpr xrange(const xrange&)noexcept=default;
    constexpr xrange(xrange&&)noexcept=default;

    constexpr xrange& operator=(const xrange&)noexcept=default;
    constexpr xrange& operator=(xrange&&)noexcept=default;


    [[maybe_unused]] constexpr xrange(intxx_t end) noexcept
        : _start(0), _end(end), _step((end >= 0) ? 1 : -1)
    {}

    [[maybe_unused]] constexpr xrange(intxx_t start, intxx_t end) noexcept
        : _start(start), _end(end), _step((start <= end) ? 1 : -1)
    {}

    [[maybe_unused]] constexpr xrange(intxx_t start, intxx_t end, intxx_t step)
        : _start(start), _end(end), _step(step)
    {
        if (step == 0) {
            throw std::overflow_error("xrange<integral>::xrange(start, end, step): the step can't be 0");
        } else if (step > 0) {
            if (start > end)
                throw std::out_of_range("xrange<integral>::xrange(start, end, step): step is positive but start superior than end");

            const ptrdiff_t diff = (step - ((end - start) % step)) % step;

            this->_end += diff;
        } else {
            if (start < end)
                throw std::out_of_range("xrange<integral>::xrange(start, end, step): step is positive but start inferior than end");

            const ptrdiff_t n_step = -step;
            const ptrdiff_t diff = (n_step - ((start - end) % n_step)) % n_step;

            this->_end -= diff;
        }
    }


protected:
    [[maybe_unused]] [[nodiscard]] constexpr inline ptrdiff_t diff() const
    {
        return ((this->_step > 0) ? this->_start - this->_end : this->_end - this->_start) / this->_step;
    }

public:
    [[maybe_unused]] [[nodiscard]] constexpr inline size_t size() const
    {
        const ptrdiff_t diff = this->diff();

        return (diff >= 0) ? diff : -diff;
    }

    [[maybe_unused]] [[nodiscard]] constexpr inline xrange reverse() const
    {
        return {this->_end - this->_step, this->_start - this->_step, -this->_step};
    }


    [[maybe_unused]] [[nodiscard]] constexpr inline iterator begin() const
    {
        return {this->_start, this->_step};
    }

    [[maybe_unused]] [[nodiscard]] constexpr inline iterator end() const
    {
        return {this->_end, this->_step};
    }

    [[maybe_unused]] [[nodiscard]] constexpr inline iterator cbegin() const
    {
        return this->begin();
    }

    [[maybe_unused]] [[nodiscard]] constexpr inline iterator cend() const
    {
        return this->end();
    }

    [[maybe_unused]] [[nodiscard]] constexpr inline iterator rbegin() const
    {
        return {this->_end - this->_step, - this->_step};
    }

    [[maybe_unused]] [[nodiscard]] constexpr inline iterator rend() const
    {
        return {this->_start - this->_step, - this->_step};
    }

    [[maybe_unused]] [[nodiscard]] constexpr inline intxx_t operator[](size_t n) const
    {
        return *(this->begin() + n);
    }
};

#endif //RANGE_VECTOR_XRANGE_HPP
