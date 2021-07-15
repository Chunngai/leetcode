//
// Created by neko on 2021/7/9.
//

#include "linked_list.h"
#include "leetcode_utils.h"
#include <stddef.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode *reverseList206(struct ListNode *head) {  // O(n), O(1)
    if (!head) {
        return head;
    }

    // The two statements below require an
    // additional statement to remove the
    // cycle generated when reversing.
//    struct ListNode *pre = head;
//    struct ListNode *cur = head->next;

    struct ListNode *pre = NULL;
    struct ListNode *cur = head;

    while (cur) {
        struct ListNode *curNext = cur->next;
        // Reverse.
        cur->next = pre;

        // Forward.
        pre = cur;
        cur = curNext;
    }

    // Removes the cycle.
//        head->next = NULL;

    return pre;
}

//int main() {
//    int vals[] = {1, 2, 3, 4, 5};
////    int vals[] = {1, 2};
////    int vals[] = {};
//    int valsSize = sizeof(vals) / sizeof(int);
//    struct ListNode *l = createLinkedListL(vals, valsSize);
//    // Ignores the head node.
//    l = removePseudoHeadNodeFromLinkedList(l);
//    printLinkedList(l, 1);
//
//    struct ListNode *result = reverseList206(l);
//    printLinkedList(result, 1);
//}

/*
 * Note that when using a pseudoHead and
    struct ListNode *pre = head;
    struct ListNode *cur = head->next;
 * A cycle will be generated. (pseudoHead <--> first node).
 *
 * And setting `pseudoHead` to NULL cannot result in NULL <- first node
 * because `pseudoHead` is a ptr that points to the memory,
 * not the allocated memory itself.
 *
 * And free(pseudoHead) does not work neither.
 * Should explicitly mod the ptr of the first node,
 * i.e. head->next = NULL;
 */