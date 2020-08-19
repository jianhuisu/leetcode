cmake_minimum_required(VERSION 3.17)
project(leetcode C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(linked_list)

add_executable(reverse_single_linked_list linked_list/reverse.c)
add_executable(leetcode linked_list/reverse.c)
