cmake_minimum_required(VERSION 3.16)
project(Range-Vector)

# Pull or update all the sub module (see .gitmodules)
execute_process(COMMAND git submodule update --init --recursive)

add_subdirectory(tests)