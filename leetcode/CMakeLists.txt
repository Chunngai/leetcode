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
        "Todo - 82 - deleteDuplicates - linked list.c"
        "Todo - 83 - deleteDuplicates - linked list.c"
        "Todo - 86 - partition - linked list.c"
        "todo - 92 - reverseBetween - linked list.c"
        "141 - hasCycle - linked list.c"
        "142 - detectCycle - linked list.c" "Todo - 143 - reorderList - linked list.c" "Todo - 206 - reverseList - linked list.c" "Todo - 234 - isPalindrome - linked list.c" "2 - addTwoNumbers - linked list.c" queue.c queue.h "239 - maxSlidingWindow - queue.c" "1669 - mergeInBetween - linked list.c" "Todo - 23 - mergeKLists - linked list.c" stack.c stack.h "20 - isValid - stack.c" "496 - nextGreaterElement - stack.c" "739 - dailyTemperatures - stack.c" "503 - nextGreaterElements - stack.c" "1019 - nextLargerNodes - stack.c" "1475 - finalPrices - stack.c" "71 - simplifyPath - stack.c" "TODO - 150 - evalRPN - stack.c" "876 - middleNode  -linked list.c" "todo - 160 - getIntersectionNode - linked list.c" "19 - removeNthFromEnd - linked list.c" "203 - removeElements - linked list.c" "237 - deleteNode - linked list.c" "1290 - getDecimalValue - linked list.c" "1721 - swapNodes - linked list.c")

target_link_libraries(leetcode m)