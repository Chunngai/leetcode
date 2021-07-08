//
// Created by neko on 2021/7/8.
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


struct ListNode* deleteDuplicates83(struct ListNode* head){
    if (head == NULL) {
        return NULL;
    }

    struct ListNode *pseudoHead = malloc (sizeof(struct ListNode));
    pseudoHead->val = 0;
    pseudoHead->next = head;

    struct ListNode *pre = head;
    struct ListNode *p = head;  // For iterating over the list.
    while (p) {
        if (pre->val != p->val) {
            // i-1 points at i.
            pre->next = p;

            pre = p;
        }
        p = p->next;
    }

    // Wo the below statement, 1 1 2 3 3 outputs 1 2 3 3.
    pre->next = NULL;

    return pseudoHead->next;
}

//int main() {
//    int vals[] = {1, 1, 2};
////    int vals[] = {1, 1, 2, 3, 3};
////    int vals[] = {};
//    int valsSize = sizeof(vals) / sizeof(int);
//    struct ListNode *l = createLinkedListL(vals, valsSize);
//    // Ignores the head node.
//    l = removeHeadNodeFromLinkedList(l);
//    printLinkedList(l, 1);
//
//    struct ListNode *rst = deleteDuplicates83(l);
//    printLinkedList(rst, 1);
//}