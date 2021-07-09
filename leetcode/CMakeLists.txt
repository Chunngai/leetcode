cmake_minimum_required(VERSION 3.19)
project(leetcode C)

set(CMAKE_C_STANDARD 99)

add_executable(
        leetcode
        main.c

        linked_list.c
        linked_list.h

        "sample - twoSum.c"

        leetcode_utils.c leetcode_utils.h

        "21 - mergeTwoLists - linked list.c"
        "82 - deleteDuplicates - linked list.c"
        "83 - deleteDuplicates - linked list.c"
        "Todo - 86 - partition - linked list.c"
        "todo - 92 - reverseBetween - linked list.c"
        "Todo - 141 - hasCycle - linked list.c"
        "Todo - 142 - detectCycle - linked list.c" "Todo - 143 - reorderList - linked list.c" "206 - reverseList - linked list.c" "Todo - 234 - isPalindrome - linked list.c")