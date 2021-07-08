//
// Created by neko on 2021/7/8.
//

#include "linked_list.h"
#include "leetcode_utils.h"

struct ListNode *removeHeadNodeFromLinkedList(struct ListNode *linkedList) {
    return linkedList->next;
}