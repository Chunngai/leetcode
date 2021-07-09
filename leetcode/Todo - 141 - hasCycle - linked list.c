//
// Created by neko on 2021/7/9.
//

#include <stdbool.h>
#include <stdio.h>
#include "linked_list.h"
#include "leetcode_utils.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle141(struct ListNode *head) {  // O(n), O(1). TODO: the linked list may not be able to be modified. Another methods.
    int outOfVal = (int) 1e6;
    struct ListNode *p = head;

    while (p) {
        if (p->val >= outOfVal) {
            return true;
        }

        p->val = outOfVal;
        p = p->next;
    }

    return false;
}

//int main() {
////    int vals[] = {3, 2, 0, -4};
////    int vals[] = {1, 2};
//    int vals[] = {1};
//
//    int valsSize = sizeof(vals) / sizeof(int);
//    struct ListNode *l = createLinkedListL(vals, valsSize);
//    // Ignores the head node.
//    l = removeHeadNodeFromLinkedList(l);
//
////    l->next->next->next->next = l->next;  // Will lead to infinite loop.
////    l->next->next = l;
//
////    printLinkedList(l, 1);
//
//    bool result = hasCycle141(l);
//    printf("%d", result);
//}