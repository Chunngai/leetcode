//
// Created by neko on 2021/7/8.
//

#ifndef LEETCODE_LINKED_LIST_H
#define LEETCODE_LINKED_LIST_H

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *createNode(int val, struct ListNode *next);

struct ListNode *initLinkedList();

void printLinkedList(struct ListNode *linkedList, int printHead);

void insertNode(struct ListNode *linkedList, int pos, int val);

void removeNode(struct ListNode *linkedList, int pos);

struct ListNode *queryNode(struct ListNode *linkedList, int pos);

struct ListNode *createLinkedListF(const int *vals, int valsSize);

struct ListNode *createLinkedListL(const int *vals, int valsSize);

#endif //LEETCODE_LINKED_LIST_H
