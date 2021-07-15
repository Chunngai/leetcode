//
// Created by neko on 2021/7/9.
//

#include <stddef.h>
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


struct ListNode* reverseBetween92(struct ListNode* head, int left, int right){  // O(n), O(1). TODO: Another methods.
    if (!head) {
        return NULL;
    }

    struct ListNode *pseudoHead = malloc(sizeof(struct ListNode));
    pseudoHead->val = 0;
    pseudoHead->next = head;

    struct ListNode *pre = pseudoHead;
    struct ListNode *cur = head;

    /*
     * [3,5]
     * 1
     * 2
     */
    int preIndex = 0;
    int curIndex = 1;

    // For linking the left part, the reversed part and the right part.
    struct ListNode *pBeforeLeft = NULL;
    struct ListNode *pLeft = NULL;

    int isReversing = 0;

    // For recording the "next node" when reversing.
    struct ListNode *pCurNext = NULL;

    while (pre) {
        if (isReversing) {
            if (preIndex == right) {  // Reaches the upper bound.
                pBeforeLeft->next = pre;
                pLeft->next = cur;
                break;
            }

            // Reverse.
            pCurNext = cur->next;
            cur->next = pre;

            // Next node.
            pre = cur;
            cur = pCurNext;
            preIndex++;
            curIndex++;
        } else {
            if (curIndex == left) {  // Reaches the lower bound.
                pBeforeLeft = pre;
                pLeft = cur;
                isReversing = 1;
            }

            // Next node.
            pre = cur;
            cur = cur->next;
            preIndex++;
            curIndex++;
        }
    }

    return pseudoHead->next;
}

//int main() {
////    int vals[] = {1, 2, 3, 4, 5};
////    int left = 2;
////    int right = 4;
//
////    int vals[] = {5};
////    int left = 1;
////    int right = 1;
//
//    int vals[] = {3, 5};
//    int left = 1;
//    int right = 2;
//
//    int valsSize = sizeof(vals) / sizeof(int);
//    struct ListNode *l = createLinkedListL(vals, valsSize);
//    // Ignores the head node.
//    l = removePseudoHeadNodeFromLinkedList(l);
//    printLinkedList(l, 1);
//
//    struct ListNode *rst = reverseBetween92(l, left, right);
//    printLinkedList(rst, 1);
//}