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

        "linked list/21 - mergeTwoLists - linked list.c"
        "Todo - 82 - deleteDuplicates - linked list.c"
        "Todo - 83 - deleteDuplicates - linked list.c"
        "Todo - 86 - partition - linked list.c"
        "todo - 92 - reverseBetween - linked list.c"
        "linked list/141 - hasCycle - linked list.c"
        "linked list/142 - detectCycle - linked list.c" "Todo - 143 - reorderList - linked list.c" "Todo - 206 - reverseList - linked list.c" "Todo - 234 - isPalindrome - linked list.c" "linked list/2 - addTwoNumbers - linked list.c" queue.c queue.h "queue/239 - maxSlidingWindow - queue.c" "linked list/1669 - mergeInBetween - linked list.c" "Todo - 23 - mergeKLists - linked list.c" stack.c stack.h "stack/20 - isValid - stack.c" "stack/496 - nextGreaterElement - stack.c" "stack/739 - dailyTemperatures - stack.c" "stack/503 - nextGreaterElements - stack.c" "stack/1019 - nextLargerNodes - stack.c" "stack/1475 - finalPrices - stack.c" "stack/71 - simplifyPath - stack.c" "stack/150 - evalRPN - stack.c" "linked list/876 - middleNode  -linked list.c" "todo - 160 - getIntersectionNode - linked list.c" "linked list/19 - removeNthFromEnd - linked list.c" "linked list/203 - removeElements - linked list.c" "linked list/237 - deleteNode - linked list.c" "linked list/1290 - getDecimalValue - linked list.c" "linked list/1721 - swapNodes - linked list.c" "stack/682 - calPoints - stack.c" "stack/227 - calculate - stack.c")

target_link_libraries(leetcode m)