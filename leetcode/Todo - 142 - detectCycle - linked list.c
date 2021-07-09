//
// Created by neko on 2021/7/9.
//

#include <stdio.h>
#include "linked_list.h"
#include "leetcode_utils.h"
#include "uthash/include/uthash.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//const int maxNodeNum = (int) 10e4;
//
//struct ListNode *getNode142(struct ListNode *addrs[], struct ListNode *p, int addrsSize) {  // O(n^2), O(n). TODO: Better solutions: O(n), O(n) or O(n), O(1).
//    for (int i = 1; i < addrsSize; i++) {
//        if (addrs[i] == p) {
//            return p;
//        }
//    }
//    return NULL;
//}
//
//struct ListNode *detectCycle142(struct ListNode *head) {
//    if (!head) {
//        return NULL;
//    }
//
//    struct ListNode *addrs[(int) 10e4] = {0};
//    int i = 1;
//
//    struct ListNode *p = head;
//
//    for (int j = 0; j < maxNodeNum + 1; j++) {
//        struct ListNode *node = getNode142(addrs, p, i);
//        if (node) {
//            return node;
//        }
//
//        // Next node.
//        addrs[i++] = p;
//        p = p->next;
//        if (!p) {
//            break;
//        }
//    }
//    return NULL;
//}

// TODO: from leetcode solution

struct HashTable142 {
    struct ListNode *key;
    UT_hash_handle hh;
} *hashTable;  // hashTable should be defined outside.

struct HashTable142 *find142(struct ListNode *iKey) {
    struct HashTable142 *tmp;
    HASH_FIND_PTR(hashTable, &iKey, tmp);
    return tmp;
}

void insert142(struct ListNode *iKey) {
    struct HashTable142 *tmp = malloc(sizeof(struct HashTable142));
    tmp->key = iKey;
    HASH_ADD_PTR(hashTable, key, tmp);
}

struct ListNode *detectCycleWithHash142(struct ListNode *head) {
    while (head) {
        if (find142(head)) {
            return head;
        }
        insert142(head);
        // Next node.
        head = head->next;
    }
    return NULL;
}

//int main() {
//    int vals[] = {3, 2, 0, -4};
////    int vals[] = {1, 2};
////    int vals[] = {1};
////    int vals[] = {};
//
//    int valsSize = sizeof(vals) / sizeof(int);
//    struct ListNode *l = createLinkedListL(vals, valsSize);
//    // Ignores the head node.
//    l = removeHeadNodeFromLinkedList(l);
//
//    l->next->next->next->next = l->next;  // Will lead to infinite loop.
////    l->next->next = l;
//
////    printLinkedList(l, 1);
//
//    struct ListNode *result = detectCycleWithHash142(l);
//    if (result) {
//        printf("%d", result->val);
//    } else {
//        printf("%s", NULL);
//    }
//}

/*
 * Diff solution in leetcode official.
 */