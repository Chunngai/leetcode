//
// Created by neko on 2021/7/15.
//

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
 * https://leetcode-cn.com/problems/remove-linked-list-elements/
 * basic ops.
 *
 * Iterates over the list the delete
 * the nodes whose val is the given val.
 * Notice that p moves forward only if
 * the val of its next node is not
 * the given val (the inner while loop
 * in the code).
 * O(n), O(1).
 */
struct ListNode *removeElements203(struct ListNode *head, int val) {
    struct ListNode *pseudoHead = malloc(sizeof(struct ListNode));
    pseudoHead->val = 0;
    pseudoHead->next = head;

    struct ListNode *p = pseudoHead;
    while (p) {
        while (p->next && p->next->val == val) {
            p->next = p->next->next ? p->next->next : NULL;
        }
        p = p->next;
    }
    return pseudoHead->next;
}

//int main() {
//    int vals[] = {1, 2, 6, 3, 4, 5, 6};
//    int val = 6;
//
////    int vals[] = {};
////    int val = 1;
//
////    int vals[] = {7, 7, 7, 7};
////    int val = 7;
//
//    int valsSize = sizeof(vals) / sizeof(int);
//    struct ListNode *l = createLinkedListWoPseudoHeadNode(vals, valsSize, 1);
//
//    struct ListNode *result = removeElements203(l, val);
//    printLinkedList(result, 1);
//}