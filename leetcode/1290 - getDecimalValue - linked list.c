//
// Created by neko on 2021/7/15.
//

#include <stddef.h>
#include <math.h>
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
 * https://leetcode-cn.com/problems/convert-binary-number-in-a-linked-list-to-integer/
 * reverse.
 *
 * Reverse the list and dec -> bin.
 * O(n), O(1).
 */
int getDecimalValue1290(struct ListNode *head) {
    // Reverses the list.
    struct ListNode *pre = NULL;
    struct ListNode *cur = head;
    struct ListNode *tmp = NULL;
    while (cur) {
        tmp = cur->next;
        cur->next = pre;

        pre = cur;
        cur = tmp;
    }

    // Dec -> bin.
    int exp = 0;
    int result = 0;
    struct ListNode *p = pre;
    while (p) {
        result += (int) pow(2, exp++) * p->val;
        p = p->next;
    }
    return result;
}

//int main() {
////    int vals[] = {1, 0, 1};
//    int vals[] = {1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0};
//
//    int valsSize = sizeof(vals) / sizeof(int);
//    struct ListNode *l = createLinkedListWoPseudoHeadNode(vals, valsSize, 1);
//
//    printInt(getDecimalValue1290(l));
//}