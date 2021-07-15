//
// Created by neko on 2021/7/13.
//

#include <stdio.h>
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*
 * https://leetcode-cn.com/problems/next-greater-node-in-linked-list/
 * monotonic stack.
 *
 * The solution is similar to q496, but should first
 * get the size of the linked list and store
 * the vals of the linked list in an arr.
 * O(n), O(n).
 */
int *nextLargerNodes1019(struct ListNode *head, int *returnSize) {
    // Gets num size.
    int numSize = 0;
    struct ListNode *p = head;
    while (p) {
        numSize++;
        p = p->next;
    }

    // Gets nums.
    int *nums = malloc(sizeof(int) * numSize);
    int pos = 0;
    p = head;
    while (p) {
        nums[pos++] = p->val;
        p = p->next;
    }

    *returnSize = numSize;
    int *result = malloc(sizeof(int) * numSize);

    int *stack = malloc(sizeof(int) * numSize);
    int top = 0;
    for (int i = numSize - 1; i >= 0; i--) {
        while (top != 0 && stack[top - 1] <= nums[i]) {
            // Pop.
            top--;
        }

        if (top == 0) {
            result[i] = 0;
        } else {
            result[i] = stack[top - 1];
        }

        stack[top++] = nums[i];
    }
    return result;
}

//int main() {
////    int vals[] = {2, 1, 5};
//    int vals[] = {2, 7, 4, 3, 5};
////    int vals[] = {1, 7, 5, 1, 9, 2, 5, 1};
//
//    int valsSize = sizeof(vals) / sizeof(int);
//    struct ListNode *l = createLinkedListL(vals, valsSize);
//    // Ignores the head node.
//    l = removePseudoHeadNodeFromLinkedList(l);
//    printLinkedList(l, 1);
//
//    int returnSize = 0;
//
//    int *result = nextLargerNodes1019(l, &returnSize);
//    for (int i = 0; i < returnSize; i++) {
//        printf("%d ", result[i]);
//    }
//}