//
// Created by neko on 2021/7/9.
//

#include <stdbool.h>
#include <stdio.h>
#include "linked_list.h"
#include "leetcode_utils.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome234(struct ListNode *head) {  // O(n), O(n). TODO: Better solutions: O(n), O(1).
    int vals[(int) 10e4] = {};
    int count = 0;
    while (head) {
        vals[count++] = head->val;
        head = head->next;
    }

    for (int j = 0; j <= count / 2; j++) {
        if (vals[j] != vals[count - j - 1]) {
            return false;
        }
    }
    return true;
}

//int main() {
//    int vals[] = {1, 2, 2, 1};
////    int vals[] = {1, 2};
////    int vals[] = {};
//    int valsSize = sizeof(vals) / sizeof(int);
//    struct ListNode *l = createLinkedListL(vals, valsSize);
//    // Ignores the head node.
//    l = removePseudoHeadNodeFromLinkedList(l);
//    printLinkedList(l, 1);
//
//    bool result = isPalindrome234(l);
//    printf("%d", result);
//}