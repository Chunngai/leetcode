//
// Created by neko on 2021/7/13.
//

#include"linked_list.h"
#include "leetcode_utils.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
 * https://leetcode-cn.com/problems/merge-in-between-linked-lists/
 * two lists?
 *
 * It's about merging two lists, but much easier than
 * q2 and q21. And the solution is diff from q2 and q21.
 * In l1, look for the node for merging the head of l2
 * and look for the node for merging the tail of l2 through
 * iteration. And alter the next node of the two nodes found.
 * O(max(m, n)), O(1).
 */
struct ListNode *mergeInBetween1669(struct ListNode *list1, int a, int b, struct ListNode *list2) {
    struct ListNode *pNodeA;
    struct ListNode *pNodeB;

    // For locating the two nodes.
    struct ListNode *p1 = list1;
    int pos = 0;
    // Gets the node before the first node to remove
    // and the node after the last node to remove.
    while (p1) {
        if (pos == a - 1) {
            pNodeA = p1;
        }
        if (pos == b) {
            pNodeB = p1->next;
            // No need to continue the iteration.
            break;
        }
        // Next node.
        p1 = p1->next;
        pos++;
    }

    // Merges the head of l2.
    pNodeA->next = list2;
    // Gets the tail of l2.
    struct ListNode *p2 = list2;
    while (p2->next) {
        p2 = p2->next;
    }
    // Merges the tail of l2.
    p2->next = pNodeB;

    return list1;
}

//int main() {
////    int vals1[] = {0, 1, 2, 3, 4, 5};
////    int vals2[] = {1000000, 1000001, 1000002};
////    int a = 3;
////    int b = 4;
//
////    int vals1[] = {0, 1, 2, 3, 4, 5, 6};
////    int vals2[] = {1000000, 1000001, 1000002, 1000003, 1000004};
////    int a = 2;
////    int b = 5;
//
//    int vals1Size = sizeof(vals1) / sizeof(int);
//    int vals2Size = sizeof(vals2) / sizeof(int);
//
//    struct ListNode *l1 = createLinkedListL(vals1, vals1Size);
//    struct ListNode *l2 = createLinkedListL(vals2, vals2Size);
//    // Ignores the head node.
//    l1 = removeHeadNodeFromLinkedList(l1);
//    l2 = removeHeadNodeFromLinkedList(l2);
//    printLinkedList(l1, 1);
//    printLinkedList(l2, 1);
//
//    struct ListNode *result = mergeInBetween1669(l1, a, b, l2);
//    printLinkedList(result, 1);
//}