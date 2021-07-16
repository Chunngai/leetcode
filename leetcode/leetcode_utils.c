//
// Created by neko on 2021/7/8.
//

#include <stdio.h>
#include "linked_list.h"
#include "leetcode_utils.h"

void printNULL() {
    printf("%s \n", NULL);
}

void printInt(int val) {
    printf("%d\n", val);
}

void printChar(char val) {
    printf("%c\n", val);
}

// Linked list utils.

        struct ListNode *removePseudoHeadNodeFromLinkedList(struct ListNode *linkedList) {
    return linkedList->next;
}

struct ListNode *createLinkedListWoPseudoHeadNode(const int *vals, int valsSize, int printToCheck) {
    struct ListNode *l = createLinkedListL(vals, valsSize);
    l = removePseudoHeadNodeFromLinkedList(l);
    if (printToCheck) {
        printLinkedList(l, 1);
    }
    return l;
}

// Array utils.

void printIntArray(int *arr, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printCharArray(char *arr, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

void printString(char *val) {
    printf("%s\n", val);
}