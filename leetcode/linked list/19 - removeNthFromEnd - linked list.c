//
// Created by neko on 2021/7/15.
//

#include <stddef.h>
#include <stdio.h>
#include <malloc.h>
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
 * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
 * fast slow pointers.
 *
 * The solution here requires two iterations.
 * First find out the middle node of the list.
 * Then look for the node before the node to delete
 * with some basic maths. In this process, we should
 * determine if the node to delete is on the first
 * or second half of the list according to the given
 * n. If it is on the first half, iterate from the head
 * node to delete it, else iterate from the slow ptr
 * to delete it.
 * O(n), O(1).
 */
struct ListNode *removeNthFromEnd19(struct ListNode *head, int n) {
    struct ListNode *pSlow = head;
    struct ListNode *pFast = head;
    int length = 0;

    while (pFast) {
        pFast = pFast->next;
        length++;
        if (pFast) {
            pFast = pFast->next;
            length++;
        } else {
            break;
        }
        pSlow = pSlow->next;
    }
    // Now if length % 2 == 1,
    // pSlow is at the middle of the list,
    // i.e., 1 2 3 (pSlow) 4 5.
    // If length % 2 == 0,
    // pSlow is at the second pos of the middle
    // of the list,
    // i.e., 1 2 3 4 (pSlow) 5 6.

    int secondHalfLen;
    if (length % 2 == 0) {
        secondHalfLen = length / 2 - 1;
    } else {
        secondHalfLen = length / 2;
    }
    int stepsToMove;
    struct ListNode *pBeforeNodeToRemove = NULL;
    if (secondHalfLen >= n) {
        // A node on the second half is to delete.
        stepsToMove = secondHalfLen - (length - (length - n + 1));
        pBeforeNodeToRemove = pSlow;
    } else {
        // A node on the first half is to delete.
        stepsToMove = length / 2 - (n - secondHalfLen - 1);
        if (stepsToMove == 0) {
            // Removes the head node.
            head = head->next;
            pBeforeNodeToRemove = NULL;
        } else {
            // The node to delete is after the head node.
            pBeforeNodeToRemove = head;
        }
    }
    int stepCount = 0;
    while (stepCount < stepsToMove - 1) {
        stepCount++;
        pBeforeNodeToRemove = pBeforeNodeToRemove->next;
    }
    if (pBeforeNodeToRemove) {
        if (pBeforeNodeToRemove->next->next) {
            pBeforeNodeToRemove->next = pBeforeNodeToRemove->next->next;
        } else {
            pBeforeNodeToRemove->next = NULL;
        }
    }

    return head;
}

/*
 * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
 * fast slow pointers.
 *
 * Use a slow ptr and a fast ptr.
 * First the fast ptr moves n steps.
 * Then the slow ptr and the fast ptr
 * move together at the same speed.
 * When the next node of the fast ptr
 * is NULL, the slow ptr points at
 * before the node to delete.
 * Here the fast ptr is fast because
 * it moves n steps further than the
 * slow ptr.
 * Add a pseudo head because the head
 * node may be deleted.
 * O(n), O(1).
 */
struct ListNode *removeNthFromEndFastSlowPointers19(struct ListNode *head, int n) {
    // Adds a pseudo node since the head node may be deleted.
    struct ListNode *pseudoNode = malloc(sizeof(struct ListNode));
    pseudoNode->val = 0;
    pseudoNode->next = head;

    struct ListNode *pSlow = pseudoNode;
    struct ListNode *pFast = pseudoNode;
    for (int i = 0; i < n; i++) {
        pFast = pFast->next;
    }

    while (pFast->next) {
        pSlow = pSlow->next;
        pFast = pFast->next;
    }
    pSlow->next = pSlow->next->next ? pSlow->next->next : NULL;

    return pseudoNode->next;
}

//int main() {
//    int vals[] = {1, 2, 3, 4, 5};  // n = 3
//    int n = 1;
//
////    int vals[] = {1, 2, 3, 4, 5, 6};  // n = 3
////    int n = 6;
//
////    int vals[] = {1};
////    int n = 1;
//
////    int vals[] = {1, 2};
////    int n = 1;
//
//    int valsSize = sizeof(vals) / sizeof(int);
//    struct ListNode *l = createLinkedListWoPseudoHeadNode(vals, valsSize, 1);
//
//    struct ListNode *result = removeNthFromEndFastSlowPointers19(l, n);
//    if (result) {
//        printLinkedList(result, 1);
//    } else {
//        printNULL();
//    }
//}