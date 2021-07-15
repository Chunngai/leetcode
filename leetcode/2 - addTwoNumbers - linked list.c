//
// Created by neko on 2021/7/11.
//

#include <malloc.h>
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
 * https://leetcode-cn.com/problems/add-two-numbers/
 * two lists.
 *
 * The solution is similar to "21 - mergeTwoLists - linked list".
 * Use p1 for l1, p2 for l2, and p for the new list.
 * Take care of the digit carrying and remember to
 * process the remaining part of the longer list.
 * If there remains a 1 to carry at last, new a new node
 * and store the 1.
 * Note that the solution below changes the given linked list,
 * which may not be permitted. If it's not permitted,
 * new a node each time instead.
 * O(max(m, n)), O(1).
 *
 * 1. Remember to add a pseudo node (for two lists problems).
 * 2. Use another ptr p to construct the new list (for two lists problems)
 * instead of use l1 or l2. That's because the lengths of the two
 * lists may be different and use l1 or l2 directly may require
 * additional efforts to code.
 */
struct ListNode *addTwoNumbers2(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *p1 = l1;
    struct ListNode *p2 = l2;

    struct ListNode *pseudoHead = malloc(sizeof(struct ListNode));
    pseudoHead->val = 0;
    pseudoHead->next = l1;

    // Tracks the new list.
    struct ListNode *p = pseudoHead;

    int shouldCarry = 0;

    while (p1 && p2) {
        int sum = p1->val + p2->val + shouldCarry;

        // Takes care of the digit carrying.
        if (sum >= 10) {
            sum -= 10;
            shouldCarry = 1;
        } else {
            shouldCarry = 0;
        }

        // Constructs the new list.
        p->next = p1;
        p = p->next;
        p->val = sum;
        /* If the given linked list cannot be altered:
         * p->next = malloc(sizeof(struct ListNode));
         * p = p->next;
         * p->val = sum;
         * p->next = NULL;
         */

        p1 = p1->next;
        p2 = p2->next;
    }

    while (p1) {
        int sum = p1->val + shouldCarry;

        if (sum >= 10) {
            sum -= 10;
            shouldCarry = 1;
        } else {
            shouldCarry = 0;
        }

        p->next = p1;
        p = p->next;
        p->val = sum;

        p1 = p1->next;
    }
    while (p2) {
        int sum = p2->val + shouldCarry;

        if (sum >= 10) {
            sum -= 10;
            shouldCarry = 1;
        } else {
            shouldCarry = 0;
        }

        p->next = p2;
        p = p->next;
        p->val = sum;

        p2 = p2->next;
    }

    // A new node is needed to store the carried 1.
    if (shouldCarry) {
        struct ListNode *newNode = malloc(sizeof(struct ListNode));
        newNode->val = 1;
        newNode->next = NULL;

        p->next = newNode;
    }

    return pseudoHead->next;
}

//int main() {
////    int vals1[] = {2, 4, 3};
////    int vals2[] = {5, 6, 4};
//
////    int vals1[] = {0};
////    int vals2[] = {0};
//
////    int vals1[] = {9, 9, 9, 9, 9, 9, 9};
////    int vals2[] = {9, 9, 9, 9};
//
////    int vals1[] = {9, 9, 9, 9};
////    int vals2[] = {9, 9, 9, 9, 9, 9, 9};
//
//    int vals1[] = {2, 4, 9};
//    int vals2[] = {5, 6, 4, 9};
//
//    int vals1Size = sizeof(vals1) / sizeof(int);
//    int vals2Size = sizeof(vals2) / sizeof(int);
//
//    struct ListNode *l1 = createLinkedListL(vals1, vals1Size);
//    struct ListNode *l2 = createLinkedListL(vals2, vals2Size);
//    // Ignores the head node.
//    l1 = removePseudoHeadNodeFromLinkedList(l1);
//    l2 = removePseudoHeadNodeFromLinkedList(l2);
//    printLinkedList(l1, 1);
//    printLinkedList(l2, 1);
//
//    struct ListNode *result = addTwoNumbers2(l1, l2);
//    printLinkedList(result, 1);
//}