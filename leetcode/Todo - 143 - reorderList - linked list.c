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


void reorderList143(struct ListNode *head) {  // O(n), O(n). TODO: Better solution: O(n), O(1).
    if (!head) {
        return;
    }

    // For adding addrs into an arr.
    struct ListNode *addrs[(int) 10e4] = {};
    int i = 0;  // For appending elements into the arr.

    // Adds each addr to addrs.
    struct ListNode *p = head;
    while (p) {
        addrs[i++] = p;
        p = p->next;
    }
    i -= 1;  // Roll back by 1.

    // Re-link.

    int count = i + 1;

    // left -> right linking.
    for (int j = 0; j < count / 2; j++) {
        addrs[j]->next = addrs[count - j - 1];
//        printf("%d -> %d\n", j + 1, count - j);
    }

    addrs[count / 2]->next = NULL;
//    printf("%d -> NULL\n", count / 2 + 1);

    // left <- right linking.
    for (int j = count / 2 + 1; j < count; j++) {
        addrs[j]->next = addrs[count - j];
//        printf("%d -> %d\n", j + 1, count - j + 1);
    }
}

//int main() {
////    int vals[] = {1, 2, 3, 4};
//    int vals[] = {1, 2, 3, 4, 5};
//    int valsSize = sizeof(vals) / sizeof(int);
//    struct ListNode *l = createLinkedListL(vals, valsSize);
//    // Ignores the head node.
//    l = removeHeadNodeFromLinkedList(l);
//    printLinkedList(l, 1);
//
//    reorderList143(l);
//    printLinkedList(l, 1);
//}