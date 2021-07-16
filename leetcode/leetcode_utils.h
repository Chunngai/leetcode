//
// Created by neko on 2021/7/8.
//

#ifndef LEETCODE_LEETCODE_UTILS_H
#define LEETCODE_LEETCODE_UTILS_H

void printNULL();

void printInt(int val);

void printChar(char val);

// Linked list utils.

struct ListNode *removePseudoHeadNodeFromLinkedList(struct ListNode *linkedList);

struct ListNode *createLinkedListWoPseudoHeadNode(const int *vals, int valsSize, int printToCheck);

// Array utils.

void printIntArray(int *arr, int arrSize);

void printCharArray(char *arr, int arrSize);

void printString(char *val);

#endif //LEETCODE_LEETCODE_UTILS_H
