cmake_minimum_required(VERSION 3.16)
project(Range-Vector_unit_test)

set(CMAKE_CXX_STANDARD 17)


if(UNIX)
    # Those are warning flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra")

    IF(CMAKE_BUILD_TYPE MATCHES Release)
        message("Build in Release mode...")

        # This is an optimisation flag
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

        # This is an optimisation flag (may include loss of precision, but doesn't affect ZipInt)
        #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Ofast")
    ENDIF(CMAKE_BUILD_TYPE MATCHES Release)

    IF(CMAKE_BUILD_TYPE MATCHES Coverage)
        message("Build in Coverage mode...")

        # This is compilation flags for coverage
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g3 --coverage -fprofile-arcs -fno-inline -fno-omit-frame-pointer -fno-optimize-sibling-calls -fprofile-generate")
        set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

        #--rc lcov_branch_coverage=1
    ENDIF(CMAKE_BUILD_TYPE MATCHES Coverage)

ENDIF(UNIX)


add_subdirectory(./lib/googletest-release-v1.10.x)


set(PATH_INCLUDES
    ./ ../
    ./lib/googletest-release-1.10.x/googletest/include
)

set(SOURCE_TEST
    range/one_args.cpp
    range/two_args.cpp
    range/three_args.cpp
    range/multiple.cpp
    range/conversion.cpp
    range/const_n_reverse_iterator.cpp
    range/constexpr.cpp

    range/iterator/operator.cpp

    vector/operator.cpp
    vector/constructor.cpp

    xrange/one_args.cpp
    xrange/two_args.cpp
    xrange/three_args.cpp
    xrange/const_n_reverse_iterator.cpp

    xrange/iterator/operator.cpp
)

include_directories(${PATH_INCLUDES})

add_executable(Range-Vector_unit_test ${SOURCE_TEST})

target_link_libraries(Range-Vector_unit_test gtest gtest_main)

