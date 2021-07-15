//
// Created by neko on 2021/7/15.
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
 * https://leetcode-cn.com/problems/delete-node-in-a-linked-list/
 * basic ops.
 *
 * Repeatedly alter the nodes
 * after the node to delete.
 * O(n), O(1).
 */
void deleteNode237(struct ListNode *node) {
    struct ListNode *p = node;
    while (p->next->next) {
        p->val = p->next->val;
        p = p->next;
    }
    p->val = p->next->val;
    p->next = NULL;
}

// From leetcode.

/*
 * https://leetcode-cn.com/problems/delete-node-in-a-linked-list/
 * basic ops.
 *
 * Two lines are enough.
 */
void deleteNodeTwoLines237(struct ListNode *node) {
    node->val = node->next->val;
    node->next = node->next->next;
}

//int main() {
//    int vals[] = {4, 5, 1, 9};
//
//    int valsSize = sizeof(vals) / sizeof(int);
//    struct ListNode *l = createLinkedListWoPseudoHeadNode(vals, valsSize, 1);
//
////    struct ListNode *node = l->next;
//    struct ListNode *node = l->next->next;
//
//    deleteNodeTwoLines237(node);
//    printLinkedList(l, 1);
//}