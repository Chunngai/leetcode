//
// Created by neko on 2021/7/8.
//

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


struct ListNode *mergeTwoLists21(struct ListNode *l1, struct ListNode *l2) {
    // Empty list.
    if (!l1) {
        return l2;
    }
    if (!l2) {
        return l1;
    }

    struct ListNode *mergedList;
    struct ListNode *pTail;

    // Finds the first node of the merged list
    // from the first nodes of the two lists.
    if (l1->val <= l2->val) {
        mergedList = l1;
        pTail = l1;
        // l1 moves forward.
        // Then the first node of l1 will not be evaluated.
        l1 = l1->next;
    } else {
        mergedList = l2;
        pTail = l2;
        // l2 moves forward.
        // Then the first node of l2 will not be evaluated.
        l2 = l2->next;
    }

    while (l1 && l2) {
        // Should pTail move to l1 or l2?

        if (l1->val <= l2->val) {
            pTail->next = l1;

            pTail = l1;
            l1 = l1->next;
        } else {
            pTail->next = l2;

            pTail = l2;
            l2 = l2->next;
        }
    }

    // Concats the remaining.
    if (l1) {
        pTail->next = l1;
    }
    if (l2) {
        pTail->next = l2;
    }

    return mergedList;
}

/*
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/
 * iteration, two lists.
 *
 * Use pa to points at la, pb to points at lb.
 * The next node of the merged list should be the smaller one
 * of la->val and lb->val.
 * Don't forget to merge to longer part of the two lists.
 * O(m+n), O(1)
 */
struct ListNode *mergeTwoListsWithHeadNode21(struct ListNode *l1, struct ListNode *l2) {
    // Head node.
    struct ListNode *pHead = (struct ListNode *) malloc(sizeof(struct ListNode));
    pHead->val = 0;
    pHead->next = NULL;

    struct ListNode *pTail = pHead;

    while (l1 && l2) {
        // Should pTail move to l1 or l2?

        if (l1->val <= l2->val) {
            pTail->next = l1;

            pTail = l1;
            l1 = l1->next;
        } else {
            pTail->next = l2;

            pTail = l2;
            l2 = l2->next;
        }
    }

    // Concats the remaining.
    if (l1) {
        pTail->next = l1;
    }
    if (l2) {
        pTail->next = l2;
    }

    return pHead->next;  // Remember to ignore the pHead node.
}

//int main() {
//    int vals1[] = {1, 2, 4};
////    int vals1[] = {};
////    int vals1[] = {};
//
//    int vals1Size = sizeof(vals1) / sizeof(int);
//    struct ListNode *l1 = createLinkedListL(vals1, vals1Size);
//    // Ignores the head node.
//    l1 = removeHeadNodeFromLinkedList(l1);
//    printLinkedList(l1, 1);
//
//    int vals2[] = {1, 3, 4};
////    int vals2[] = {};
////    int vals2[] = {0};
//
//    int vals2Size = sizeof(vals1) / sizeof(int);
//    struct ListNode *l2 = createLinkedListL(vals2, vals2Size);
//    // Ignores the head node.
//    l2 = removeHeadNodeFromLinkedList(l2);
//    printLinkedList(l2, 1);
//
////    struct ListNode *mergedList = mergeTwoLists21(l1, l2);
//    struct ListNode *mergedList = mergeTwoListsWithHeadNode21(l1, l2);
//    printLinkedList(mergedList, 1);
//}

/*
 * struct ListNode *pHead = (struct ListNode *) malloc(sizeof(struct ListNode));  // not sizeof(struct ListNode *)
 * Error:
    =================================================================
    ==42==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x602000000118 at pc 0x558b3b30b218 bp 0x7ffce1c64250 sp 0x7ffce1c64240
    WRITE of size 8 at 0x602000000118 thread T0
        #2 0x7fe64bea50b2 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
    0x602000000118 is located 0 bytes to the right of 8-byte region [0x602000000110,0x602000000118)
    allocated by thread T0 here:
        #0 0x7fe64caeabc8 in malloc (/lib/x86_64-linux-gnu/libasan.so.5+0x10dbc8)
        #3 0x7fe64bea50b2 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
    Shadow bytes around the buggy address:
      0x0c047fff7fd0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
      0x0c047fff7fe0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
      0x0c047fff7ff0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
      0x0c047fff8000: fa fa fd fa fa fa 00 00 fa fa 00 00 fa fa 00 00
      0x0c047fff8010: fa fa fd fa fa fa 00 00 fa fa 00 00 fa fa 00 00
    =>0x0c047fff8020: fa fa 00[fa]fa fa fa fa fa fa fa fa fa fa fa fa
      0x0c047fff8030: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
      0x0c047fff8040: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
      0x0c047fff8050: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
      0x0c047fff8060: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
      0x0c047fff8070: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
    Shadow byte legend (one shadow byte represents 8 application bytes):
      Addressable:           00
      Partially addressable: 01 02 03 04 05 06 07
      Heap left redzone:       fa
      Freed heap region:       fd
      Stack left redzone:      f1
      Stack mid redzone:       f2
      Stack right redzone:     f3
      Stack after return:      f5
      Stack use after scope:   f8
      Global redzone:          f9
      Global init order:       f6
      Poisoned by user:        f7
      Container overflow:      fc
      Array cookie:            ac
      Intra object redzone:    bb
      ASan internal:           fe
      Left alloca redzone:     ca
      Right alloca redzone:    cb
      Shadow gap:              cc
    ==42==ABORTING
 */

/*
 *  // On Leetcode, should init pHead whose memory is allocated via malloc.
    pHead->val = 0;
    pHead->next = NULL;
 * Error:
    Line 70: Char 15: runtime error: member access within misaligned address 0xbebebebebebebebe for type 'struct ListNode', which requires 8 byte alignment [ListNode.c]
    0xbebebebebebebebe: note: pointer points here
    <memory cannot be printed>
 */