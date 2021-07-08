//
// Created by neko on 2021/7/7.
//

#include<stdio.h>
#include<stdlib.h>
#include "linked_list.h"

struct ListNode *createNode(int val, struct ListNode *next) {
    struct ListNode *node = (struct ListNode *) malloc(sizeof(struct ListNode *));
    if (node == NULL) {
        printf("Failed to create a new node.\n");
        return NULL;
    }
    node->val = val;
    node->next = next;
    return node;
}

struct ListNode *initLinkedList() {
    struct ListNode *head = createNode(0, NULL);
    return head;
}

void printLinkedList(struct ListNode *linkedList, int printHead) {
    struct ListNode *p = NULL;
    if (printHead) {
        p = linkedList;
    } else {
        p = linkedList->next;
    }

    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

void insertNode(struct ListNode *linkedList, int pos, int val) {
    // 1 <= pos <= LENGTH + 1.

    int curPos = 0;
    struct ListNode *p = linkedList;

    while (p != NULL && curPos < pos - 1) {
        p = p->next;
        curPos++;
    }
    // Now curPos == pos - 1.
    if (p == NULL || curPos > pos - 1) {
        // curPos > pos - 1: pos < 1;
        // p == NULL: pos > LENGTH + 1.
        printf("Invalid pos %d: pos < 1 or pos > %d + 1.\n", pos, linkedList->val);
        return;
    }

    struct ListNode *nodeToInsert = createNode(val, p->next);
    p->next = nodeToInsert;

    linkedList->val += 1;
}

void removeNode(struct ListNode *linkedList, int pos) {
    // 1 <= pos <= LENGTH

    int curPos = 0;
    struct ListNode *p = linkedList;

    while (p->next != NULL && curPos < pos - 1) {
        p = p->next;
        curPos++;
    }
    // Now curPos == pos - 1.
    if (!p->next || curPos > pos - 1) {
        // curPos > pos - 1: pos < 1;
        // p->next == NULL: pos > LENGTH.
        printf("Invalid pos %d: pos < 1 or pos > %d.\n", pos, linkedList->val);
        return;
    }

    struct ListNode *nodeToRemove = p->next;
    p->next = nodeToRemove->next;
    free(nodeToRemove);

    linkedList->val -= 1;
}

struct ListNode *queryNode(struct ListNode *linkedList, int pos) {
    // 1 <= pos <= LENGTH.

    // Starts from the first node rather than the head node.
    int curPos = 1;
    struct ListNode *p = linkedList->next;

    while (p != NULL && curPos < pos) {
        p = p->next;
        curPos++;
    }
    // Now curPos == pos.
    if (p == NULL || curPos > pos) {
        // curPos > pos: pos < 1;
        // p == NULL: pos > LENGTH.
        printf("Invalid pos %d: pos < 1 or pos > %d.\n", pos, linkedList->val);
        return NULL;
    }

    return p;
}

struct ListNode *createLinkedListF(const int *vals, int valsSize) {
    struct ListNode *linkedList = initLinkedList();
    if (linkedList == NULL) {
        return linkedList;
    }

    linkedList->val = valsSize;  // The head node stores the length.
    for (int i = 0; i < valsSize; i++) {
        struct ListNode *newNode = createNode(vals[i], linkedList->next);
        if (newNode == NULL) {
            continue;
        }
        linkedList->next = newNode;
    }
    return linkedList;
}

struct ListNode *createLinkedListL(const int *vals, int valsSize) {
    struct ListNode *linkedList = initLinkedList();
    if (linkedList == NULL) {
        return linkedList;
    }

    struct ListNode *tail = linkedList;
    linkedList->val = valsSize;  // The head node stores the length.
    for (int i = 0; i < valsSize; i++) {
        struct ListNode *newNode = createNode(vals[i], NULL);
        if (newNode == NULL) {
            continue;
        }
        tail->next = newNode;
        tail = newNode;
    }
    return linkedList;
}

//int main() {
//    // Init.
//    printf("Initializing a linkedList.\n");
//    struct ListNode *linkedList = initLinkedList();
//    if (linkedList == NULL) {
//        exit(-1);
//    }
//
//    // Insert.
//    printf("Inserting val 1 to pos 1.\n");
//    insertNode(linkedList, 1, 1);
//    printf("Inserting val 2 to pos 2.\n");
//    insertNode(linkedList, 2, 2);
//
//    printf("The current linked list is: ");
//    printLinkedList(linkedList, 0);
//
//    // Query.
//    struct ListNode *node = queryNode(linkedList, 2);
//    printf("Querying the node at pos 2. The value is: %d.\n", node->val);
//
//    // Remove.
//    printf("Removing the node at pos 1.\n");
//    removeNode(linkedList, 1);
//
//    printf("The current linked list is: ");
//    printLinkedList(linkedList, 0);
//
//    int vals[] = {1, 2, 5};
//    int valsSize = sizeof(vals) / sizeof(int);
//
//    // Create F.
//    struct ListNode *linkedListF = createLinkedListF(vals, valsSize);
//    printf("The current linked list F is: ");
//    printLinkedList(linkedListF, 0);
//
//    // Creates L.
//    struct ListNode *linkedListL = createLinkedListL(vals, valsSize);
//    printf("The current linked list L is: ");
//    printLinkedList(linkedListL, 0);
//
//    return 0;
//}