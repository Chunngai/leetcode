//
// Created by neko on 2021/7/15.
//

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
 * https://leetcode-cn.com/problems/middle-of-the-linked-list/
 * =fast slow pointer.
 *
 * Use a fast pts and a slow ptr. When the fast pts
 * reaches the end of the list, the slow pts is
 * at the middle of the list.
 * O(n), O(1).
 */
struct ListNode *middleNode876(struct ListNode *head) {
    struct ListNode *pSlow = head;
    struct ListNode *pFast = head;

    while (pFast && pFast->next) {
//        pFast = pFast->next;  // pFast != NULL.
//        if (pFast) {  // pFast->next != NULL.
//            pFast = pFast->next;
//        } else {
//            return pSlow;
//        }
        pFast = pFast->next->next;
        pSlow = pSlow->next;
    }
    return pSlow;
}

//int main() {
//    int vals[] = {1, 2, 3, 4, 5};
////    int vals[] = {1, 2, 3, 4, 5, 6};
//
//    int valsSize = sizeof(vals) / sizeof(int);
//    struct ListNode *l = createLinkedListWoPseudoHeadNode(vals, valsSize, 1);
//    printLinkedList(l, 1);
//
//    struct ListNode *result = middleNode876(l);
//    printLinkedList(result, 1);
//}