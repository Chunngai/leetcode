//
// Created by neko on 2021/7/13.
//

#include <stdio.h>
#include <malloc.h>
#include "uthash/include/uthash.h"

/*
 * https://leetcode-cn.com/problems/next-greater-element-i/
 * monotonic stack.
 *
 * Example question of the monotonic stack.
 * First use the monotonic stack to get the greater elem
 * of each elem in nums2 and store the greater elems into
 * a hash table. Than construct the result according to
 * nums1 with the hash table.
 * O(max(m, n)), O(n).
 *
 * 1. for `struct HashTable { ...} *hashTable;`, remember
 * to init the hash table!!!.
 */
struct HashTable496 {
    int key;
    int val;
    UT_hash_handle hh;
} *hashTable;

void insert496(int iKey, int val) {
    struct HashTable496 *tmp = malloc(sizeof(struct HashTable496));
    tmp->key = iKey;
    tmp->val = val;
    HASH_ADD_INT(hashTable, key, tmp);
}

int find496(int iKey) {
    struct HashTable496 *tmp;
    HASH_FIND_INT(hashTable, &iKey, tmp);
    return tmp->val;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *nextGreaterElement496(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize) {
    hashTable = NULL;

    // Monotonic stack.
    int *stack = malloc(sizeof(int) * nums2Size);
    int top = 0;

    for (int i = nums2Size - 1; i >= 0; i--) {
        int val = nums2[i];
        while (top != 0 && stack[top - 1] <= val) {  // Not stack[top].
            // Pop.
            top--;
        }

        // Stores into the hash table.
        if (top != 0) {
            insert496(val, stack[top - 1]);
        } else {
            insert496(val, -1);
        }

        // Push.
        stack[top++] = val;
    }

    // Gets results from the hash table.
    *returnSize = nums1Size;
    int *result = malloc(sizeof(int) * nums1Size);
    for (int i = 0; i < nums1Size; i++) {
        result[i] = find496(nums1[i]);
    }
    return result;
}

int main() {
    int vals1[] = {4, 1, 2};
    int vals2[] = {1, 3, 4, 2};
//    int vals1[] = {2, 4};
//    int vals2[] = {1, 2, 3, 4};
//    int vals1[] = {1, 3, 5, 2, 4};
//    int vals2[] = {5, 4, 3, 2, 1};

    int vals1Size = sizeof(vals1) / sizeof(int);
    int vals2Size = sizeof(vals2) / sizeof(int);
    int returnSize = 0;

    int *result = nextGreaterElement496(vals1, vals1Size, vals2, vals2Size, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
}