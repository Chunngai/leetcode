//
// Created by neko on 2021/7/9.
//

#include <stdbool.h>
#include <stdio.h>
#include "../linked_list.h"
#include "../leetcode_utils.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
 * https://leetcode-cn.com/problems/linked-list-cycle/
 * cycle linked list.
 *
 * Iterate over the linked list and change the value of
 * each node to a specific number. When an altered node
 * is met again during the iteration, the linked list
 * has a cycle.
 * O(n), O(1).
 */
bool hasCycle141(struct ListNode *head) {
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

/*
 * https://leetcode-cn.com/problems/linked-list-cycle/
 * cycle; fast slow pointers.
 *
 * Use a slow ptr and a fast ptr. The slow ptr
 * moves 1 step each time and the fast ptr moves
 * two steps each time. If the linked list has no
 * cycle, the fast pts will become NULL at last.
 * Else it will meet the slow pts somewhere in the
 * cycle.
 * Note that `pFast = pFast->next->next` may cause
 * an error because after `pFast = pFast->next`, the
 * fast ptr may be NULL. Further check is needed.
 * And note that moving forward should be done before
 * checking if the slow ptr == the fast ptr because
 * their init vals are both the head node of the
 * linked list.
 * O(n), O(1).
 */
bool hasCycleFastSlowPointer141(struct ListNode *head) {
    struct ListNode *pSlow = head;
    struct ListNode *pFast = head;
    while (pFast != NULL) {
        // Moves forward.
        pSlow = pSlow->next;
        pFast = pFast->next;
        if (pFast) {
            pFast = pFast->next;
        } else {
            // pFast is NULL.
            return false;
        }

        // Check.
        if (pSlow == pFast) {
            return true;
        }
    }
    return false;
}

//int main() {
//    int vals[] = {3, 2, 0, -4};
////    int vals[] = {1, 2};
////    int vals[] = {1};
//
//    int valsSize = sizeof(vals) / sizeof(int);
//    struct ListNode *l = createLinkedListL(vals, valsSize);
//    // Ignores the head node.
//    l = removePseudoHeadNodeFromLinkedList(l);
//
//    l->next->next->next->next = l->next;  // Will lead to infinite loop.
////    l->next->next = l;
//
////    printLinkedList(l, 1);
//
//    bool result = hasCycleFastSlowPointer141(l);
//    printf("%d", result);
//}