//
// Created by Ail on 21/08/2020.
//

#ifndef RANGE_VECTOR_TESTES_HELPER_HPP
#define RANGE_VECTOR_TESTES_HELPER_HPP

#include "range.hpp"
#include <sstream>

class Tests {
public:
    template <typename container>
    static std::string str(const container &range, unsigned int limit=10) {
        std::stringstream stream;
        bool first = true;
        unsigned int cnt = 0;

        stream << '{';
        for (const auto &i : range) {
            if (first)
                first = false;
            else
                stream << ", ";
            stream << i;
            if (++cnt > limit) {
                stream << ", ::overflow(" << limit << ")";
                break;
            }
        }
        stream << '}';
        return stream.str();
    }

    template <typename container>
    static std::string str(container &&range, unsigned int limit=10) {
        std::stringstream stream;
        bool first = true;
        unsigned int cnt = 0;

        stream << '{';
        for (const auto &i : range) {
            if (first)
                first = false;
            else
                stream << ", ";
            stream << i;
            if (++cnt > limit) {
                stream << ", ::overflow(" << limit << ")";
                break;
            }
        }
        stream << '}';
        return stream.str();
    }
};

#endif //RANGE_VECTOR_TESTES_HELPER_HPP
