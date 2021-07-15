//
// Created by neko on 2021/7/15.
//

#include <stddef.h>
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

/*
 * https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
 * cycle; fast low pointers; reverse.
 * TODO: Another solution with the same complexity.
 *
 * The solution is to convert the problem to the
 * detectCycle (q142) by reversing one of the list and
 * concatenating the heads of the two lists.
 * Don't forget to reverse back the reversed list after
 * obtaining the intersection node.
 * O(n), O(1).
 */
struct ListNode *getIntersectionNode160(struct ListNode *headA, struct ListNode *headB) {
    if (!headA || !headB) {
        return NULL;
    }

    // Reverses l1.
    struct ListNode *pre = NULL;
    struct ListNode *cur = headA;
    struct ListNode *tmp = NULL;
    while (cur) {
        tmp = cur->next;
        // Reverses.
        cur->next = pre;
        // Forward.
        pre = cur;
        cur = tmp;
    }
    struct ListNode *l1PTail = pre;

    // Makes a cycle.
    headA->next = headB;

    // Looks for the intersection node.

    struct ListNode *pSlow = l1PTail;
    struct ListNode *pFast = l1PTail;

    struct ListNode *pDetect = l1PTail;
    int isPDetectMoving = 0;

    struct ListNode *pIntersection = NULL;
    while (pFast) {
        if (!isPDetectMoving) {
            pSlow = pSlow->next;
            pFast = pFast->next;
            if (pFast) {
                pFast = pFast->next;
            } else {
                pIntersection = NULL;
            }

            if (pSlow == pFast) {
                isPDetectMoving = 1;
                continue;
            }
        } else {
            if (pSlow == pDetect) {
                pIntersection = pDetect;
                break;
            }
            pSlow = pSlow->next;
            pDetect = pDetect->next;
        }
    }

    // Removes the cycle.
    headA->next = NULL;

    // Reverses l1 back.
    pre = NULL;
    cur = l1PTail;
    tmp = NULL;
    while (cur) {
        tmp = cur->next;
        // Reverses.
        cur->next = pre;
        // Forward.
        pre = cur;
        cur = tmp;
    }

    return pIntersection;
}

//int main() {
//    int vals1[] = {4, 1, 8, 4, 5};
//    int vals2[] = {5, 0, 1, 8, 4, 5};
//
////    int vals1[] = {0, 9, 1, 2, 4};
////    int vals2[] = {3, 2, 4};
////
////    int vals1[] = {2, 6, 4};
////    int vals2[] = {1, 5};
//
////    int vals1[] = {};
////    int vals2[] = {1, 2};
//
////    int vals1[] = {1, 2};
////    int vals2[] = {};
//
////    int vals1[] = {};
////    int vals2[] = {};
//
//    int vals1Size = sizeof(vals1) / sizeof(int);
//    int vals2Size = sizeof(vals2) / sizeof(int);
//    struct ListNode *l1 = createLinkedListWoPseudoHeadNode(vals1, vals1Size, 1);
//    struct ListNode *l2 = createLinkedListWoPseudoHeadNode(vals2, vals2Size, 1);
//
//    // Shares the intersection node.
////    l2->next->next->next = l1->next->next;
////    l2->next = l1->next->next->next;
//
//    struct ListNode *result = getIntersectionNode160(l1, l2);
//    if (result) {
//        printLinkedList(result, 1);
//    } else {
//        printf("%s \n", NULL);
//    }
//
//    printLinkedList(l1, 1);
//    printLinkedList(l2, 1);
//}