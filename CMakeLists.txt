cmake_minimum_required(VERSION 3.17)
project(leetcode C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(linked_list)

add_executable(reverse_single_linked_list linked_list/reverse.c)
add_executable(two_sum array/two_sum.c)
add_executable(three_sum array/three_sum.c)
add_executable(four_sum array/four_sum.c)

add_executable(full_permutation backtrack/full_permutation.c)

add_executable(traverse_bst
        tree/binary_search_tree.c
        tree/traverse_bst.c)
target_link_libraries(traverse_bst  m)
