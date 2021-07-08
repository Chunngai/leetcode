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


struct ListNode* partition86(struct ListNode* head, int x){
    if (!head) {
        return NULL;
    }

    struct ListNode * pseudoHead = malloc (sizeof(struct ListNode));
    pseudoHead->val = 0;
    pseudoHead->next = head;

    // For storing the nodes at which no node points at.
    // The nodes will be accessed again
    // after accessing all nodes whose vals are less than x.
    // Note that the vals of the nodes in ptrs
    // may also be less than x.
    struct ListNode *ptrs[201] = {};
    int i = 0;

    struct ListNode *p = head;
    struct ListNode *cur = pseudoHead;
    while (p) {
        if (p->val < x) {
            // Stores the next node so that
            // we can access their val later.
            ptrs[i++] = cur->next;

            cur->next = p;
            cur = p;
        }
        p = p->next;
    }
    /*
     * int vals[] = {1, 4, 3, 0, 5, 2};
     * int x = 2;
     */
    if (cur->next) {
        ptrs[i++] = cur->next;
    }

    for (int j = 0; j < i; j++) {
        p = ptrs[j];
        while (p && p->val >= x) {  // p should not be null. (p may run away and be null).
            cur->next = p;
            cur = p;
            p = p->next;
        }
    }
    cur->next = NULL;

    return pseudoHead->next;
}

//int main() {
////    int vals[] = {1, 4, 3, 2, 5, 2};
////    int x = 3;
//
////    int vals[] = {2, 1};
////    int x = 2;
//
//    int vals[] = {1, 4, 3, 0, 5, 2};
//    int x = 2;
//
////    int vals[] = {};
////    int x = 300;
//
//    int valsSize = sizeof(vals) / sizeof(int);
//    struct ListNode *l = createLinkedListL(vals, valsSize);
//    // Ignores the head node.
//    l = removeHeadNodeFromLinkedList(l);
//    printLinkedList(l, 1);
//
//    struct ListNode *rst = partition86(l, x);
//    printLinkedList(rst, 1);
//}

/*
 * Diff solution in leetcode official.
 */