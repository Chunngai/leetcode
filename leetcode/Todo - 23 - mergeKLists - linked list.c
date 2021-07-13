//
// Created by neko on 2021/7/13.
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
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/solution/he-bing-kge-pai-xu-lian-biao-by-leetcode-solutio-2/
 * iteration; two lists.
 * TODO: better solutions with less complexity.
 *
 * A simple solution is to do "mergeTwoLists" for multiple times.
 * O((n1 + n2) + (n1 + n2 + n3) + ...)=O((k-1)n1 + (k-2) n2 + ...), O(1).
 * Assume that each list is of equal length, then the time complexity is
 * O((k-1)n + (k-2)n +. ... + (k-(k-1))n) = (\sum^{k-1}_{1} n) = O(k^2 n)
 */
struct ListNode *mergeKLists23(struct ListNode **lists, int listsSize) {
    if (!listsSize) {
        return NULL;
    }
    // No merging is needed for only one list.
    if (listsSize == 1) {
        return lists[0];
    }

    struct ListNode *pseudoHead;
    struct ListNode *p;
    for (int i = 1; i < listsSize; i++) {
        struct ListNode *p1;
        struct ListNode *p2;
        if (i == 1) {
            p1 = lists[0];
            p2 = lists[1];
        } else {
            // The newly merged list.
            p1 = pseudoHead->next;
            p2 = lists[i];
        }
        // A new pseudo head is needed for the current merging.
        pseudoHead = malloc(sizeof(struct ListNode));
        pseudoHead->val = 0;
        pseudoHead->next = NULL;
        p = pseudoHead;

        while (p1 && p2) {
            if (p1->val <= p2->val) {
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }

        if (p1) {
            p->next = p1;
        }
        if (p2) {
            p->next = p2;
        }
    }

    return pseudoHead->next;
}

//int main() {
//    int vals1[] = {1, 4, 5};
//    int vals2[] = {1, 3, 4};
//    int vals3[] = {2, 6};
//
////    int vals1[] = {};
//
//    int vals1Size = sizeof(vals1) / sizeof(int);
//    int vals2Size = sizeof(vals2) / sizeof(int);
//    int vals3Size = sizeof(vals3) / sizeof(int);
//
//    struct ListNode *l1 = createLinkedListL(vals1, vals1Size);
//    struct ListNode *l2 = createLinkedListL(vals2, vals2Size);
//    struct ListNode *l3 = createLinkedListL(vals3, vals3Size);
//    // Ignores the head node.
//    l1 = removeHeadNodeFromLinkedList(l1);
//    l2 = removeHeadNodeFromLinkedList(l2);
//    l3 = removeHeadNodeFromLinkedList(l3);
//    printLinkedList(l1, 1);
//    printLinkedList(l2, 1);
//    printLinkedList(l3, 1);
//
//    struct ListNode *lists[] = {l1, l2, l3};
////    struct ListNode *lists[] = {};
////    struct ListNode *lists[] = {l1};
//
//    struct ListNode *result = mergeKLists23(lists, 3);
//    printLinkedList(result, 1);
//}