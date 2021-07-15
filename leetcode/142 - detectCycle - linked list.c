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

/*
 * https://leetcode-cn.com/problems/linked-list-cycle-ii/
 * cycle linked list.
 *
 * Iterate over the linked list and store the accessed node
 * in an arr. Meeting a node in the arr means that the linked
 * list has a cycle.
 * O(n^2), O(n).
 * Time limit exceeded!
 */

const int maxNodeNum = (int) 10e4;

struct ListNode *getNode142(struct ListNode *addrs[], struct ListNode *p, int addrsSize) {
    for (int i = 1; i < addrsSize; i++) {
        if (addrs[i] == p) {
            return p;
        }
    }
    return NULL;
}

struct ListNode *detectCycle142(struct ListNode *head) {
    if (!head) {
        return NULL;
    }

    struct ListNode *addrs[(int) 10e4] = {0};
    int i = 1;

    struct ListNode *p = head;

    for (int j = 0; j < maxNodeNum + 1; j++) {
        struct ListNode *node = getNode142(addrs, p, i);
        if (node) {
            return node;
        }

        // Next node.
        addrs[i++] = p;
        p = p->next;
        if (!p) {
            break;
        }
    }
    return NULL;
}

// From leetcode.

/*
 * https://leetcode-cn.com/problems/linked-list-cycle-ii/
 * cycle linked list; hash table.
 *
 * The solution is similar to the one above, but use
 * a hash table to store the accessed nodes instead of
 * an arr.
 * O(n), O(n).
 */

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

/*
 * https://leetcode-cn.com/problems/linked-list-cycle-ii/
 * cycle; fast low pointers.
 *
 * Say that the part wo cycle is s1, that the slow ptr has
 * moved s2 in the cycle when the fast ptr meets the slow ptr,
 * and that there remains s3 to move for the slow ptr to complete
 * a cycle.
 * For the slow ptr, v_slow = (s1 + s2) / t;
 * for the fast pts, v_fast = (s1 + m(s2 + s3) + s2)) / t;
 * and v_fast = 2 v_slow.
 * Thus (m-1) (s2+s3) + s3 = s1. Therefore, if a detect ptr
 * starts to move from the head node when the slow pts meets
 * the fast pts in the cycle, the detect ptr can meet the slow
 * ptr at the entrance node of the cycle.
 * Note that check if the slow ptr == the detect ptr BEFORE start to
 * move the detect ptr since s1 may be 0, as in the second example.
 * O(n), O(1).
 */
struct ListNode *detectCycleFastSlowPointer142(struct ListNode *head) {
    struct ListNode *pSlow = head;
    struct ListNode *pFast = head;

    struct ListNode *pDetect = head;
    int isPDetectMoving = 0;

    while (pFast) {
        if (!isPDetectMoving) {
            // Forward.
            pSlow = pSlow->next;
            pFast = pFast->next;
            if (pFast) {
                pFast = pFast->next;
            } else {
                return NULL;
            }

            // Check.
            if (pSlow == pFast) {
                isPDetectMoving = 1;
                continue;
            }
        }

        if (isPDetectMoving) {
            // Check.
            if (pSlow == pDetect) {
                return pDetect;
            }
            // Forward.
            pSlow = pSlow->next;
            pDetect = pDetect->next;
        }
    }
    return NULL;
}

//int main() {
////    int vals[] = {3, 2, 0, -4};
////    int vals[] = {1, 2};
////    int vals[] = {1};
//    int vals[] = {};
//
//    int valsSize = sizeof(vals) / sizeof(int);
//    struct ListNode *l = createLinkedListL(vals, valsSize);
//    l = removePseudoHeadNodeFromLinkedList(l);
//
////    l->next->next->next->next = l->next;  // Will lead to infinite loop.
////    l->next->next = l;
//
//    struct ListNode *result = detectCycleFastSlowPointer142(l);
//    if (result) {
//        printf("%d", result->val);
//    } else {
//        printf("%s", NULL);
//    }
//}