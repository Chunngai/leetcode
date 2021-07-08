cmake_minimum_required(VERSION 3.19)
project(leetcode C)

set(CMAKE_C_STANDARD 99)

add_executable(
        leetcode
        main.c

        linked_list.c
        linked_list.h

        "sample - twoSum.c"

        "21 - mergeTwoLists - linked list.c"
        leetcode_utils.c leetcode_utils.h "82 - deleteDuplicates - linked list.c")