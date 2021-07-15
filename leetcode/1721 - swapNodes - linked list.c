//
// Created by neko on 2021/7/15.
//

#include <stddef.h>
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
 * https://leetcode-cn.com/problems/swapping-nodes-in-a-linked-list/
 * fast slow pointers.
 *
 * Iterate over the list to get the k-th node.
 * And use the slow fast pointers to get the k-th
 * node from end. Then swap the vals of the two nodes.
 * O(n), O(1).
 */
struct ListNode *swapNodes1721(struct ListNode *head, int k) {
    struct ListNode *p = head;
    struct ListNode *pSlow = head;
    struct ListNode *pFast = head;
    int count = 1;

    // Gets the two nodes for swapping.
    for (int i = 0; i < k - 1; i++) {
        pFast = pFast->next;
    }
    while (pFast->next) {
        pSlow = pSlow->next;
        pFast = pFast->next;

        /*
         * [100, 90]
         * 2
         *
         * If put the code block below
         * in the current while loop,
         * it should also be put in the for loop
         * above. That is, p should more together
         * with pFast until `count < k`.
         */
//        if (count < k) {
//            p = p->next;
//            count++;
//        }
    }
    while (count < k) {
        p = p->next;
        count++;
    }

    // Swaps the values.
    int tmp = pSlow->val;
    pSlow->val = p->val;
    p->val = tmp;

    return head;
}

//int main() {
////    int vals[] = {1, 2, 3, 4, 5};
////    int k = 2;
//
////    int vals[] = {7, 9, 6, 6, 7, 8, 3, 0, 9, 5};
////    int k = 5;
//
////    int vals[] = {1};
////    int k = 1;
//
////    int vals[] = {1, 2};
////    int k = 1;
//
////    int vals[] = {1, 2, 3};
////    int k = 2;
//
//    int vals[] = {100, 90};
//    int k = 2;
//
//    int valsSize = sizeof(vals) / sizeof(int);
//    struct ListNode *l = createLinkedListWoPseudoHeadNode(vals, valsSize, 1);
//
//    struct ListNode *result = swapNodes1721(l, k);
//    printLinkedList(result, 1);
//}