//
// Created by neko on 2021/7/8.
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


struct ListNode* deleteDuplicates82(struct ListNode* head){  // O(n), O(1)
    // Empty list.
    if (!head) {
        return NULL;
    }

    struct ListNode *pseudoHead = (struct ListNode *) malloc(sizeof(struct ListNode));
    pseudoHead->val = 0;
    pseudoHead->next = head;

    struct ListNode *p = head;  // Iterates over the list.
    struct ListNode *pre = pseudoHead;  // For rolling back.
    struct ListNode *cur = head;

    // For 1, 1, 1 in 1, 1, 1, 2, 3.
    int duplicatedNumber = -200;

    while (p->next) {
        p = p->next;

        if (p->val == duplicatedNumber) {
            continue;
        }

        if (pre == cur) {
            // Modifies the pointer so that the duplicated numbers are ignored.
            pre->next = p;
            cur = p;
            continue;
        }

        if (cur->val != p->val) {
            pre = pre->next;
            cur = cur->next;
        } else {
            cur = pre;  // Rolls back.
            duplicatedNumber = p->val;
        }
    }
    /*
     * [1, 1]
     * [1, 2, 2]
     * Maybe for something like [..., 1, 1, 1, 1, 1]
     */
    if (pre == cur) {
        cur->next = NULL;
    }

    return pseudoHead->next;
}

//int main() {
//    int vals[] = {1, 2, 3, 3, 4, 4, 5};
//    int vals[] = {1, 1, 1, 2, 3};
//    int vals[] = {};
//    int vals[] = {1, 1};
//    int vals[] = {1, 2, 2};
//
//    int valsSize = sizeof(vals) / sizeof(int);
//    struct ListNode *l = createLinkedListL(vals, valsSize);
//    // Ignores the head node.
//    l = removeHeadNodeFromLinkedList(l);
//    printLinkedList(l, 1);
//
//    struct ListNode *rst = deleteDuplicates82(l);
//    printLinkedList(rst, 1);
//}