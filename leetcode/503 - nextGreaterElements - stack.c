//
// Created by neko on 2021/7/13.
//

#include <stdio.h>
#include <malloc.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*
 * https://leetcode-cn.com/problems/next-greater-element-ii/
 * monotonic stack.
 *
 * Similar to q496, but the array here is circular,
 * so that each elem can see the whole list.
 * To simulate a circular list, double the length
 * of thr arr, i.e., iterate from `2 * n - 1`
 * instead of `n - 1`. And take care of the mod op.
 * Note that the circular arr simulation won't interrupt
 * the results of the elems which can get their greater
 * elements from a normal arr. For those elems, they get
 * their greater vals twice, first from the SECOND half
 * of the double length arr then from the FIRST half.
 * And the elems that cannot get their greater elem
 * from the normal arr also get their greater elems from the FIRST half.
 * For example, say that the arr is:
 * [ 1, 2, 3, 99, 98 ]
 * when doubled length:
 * [ 1, 2, 3, 99, 98, 1', 2', 3', 99', 98' ].
 * For 1 which can get its greater elem from the normal arr
 * before doubled, it first gets 2 from the second half of the
 * doubled arr since the iteration starts from the last.
 * Then it gets another and the same greater elem 2 from the first
 * half as the iteration goes. The latter greater elem covers
 * the old one. For 98 which gets its greater elem from the doubled
 * length arr, it gets 99 from the first half. It does not get its
 * greater elem from the second half.
 * O(n), O(n).
 */
int *nextGreaterElements503(const int *nums, int numsSize, int *returnSize) {
    *returnSize = numsSize;
    int *result = malloc(sizeof(int) * *returnSize);

    int *stack = malloc(sizeof(int) * *returnSize);
    int top = 0;

    for (int i = 2 * numsSize - 1; i >= 0; i--) {
        while (top != 0 && stack[top - 1] <= nums[i % numsSize]) {
            // Pop.
            top--;
        }

        if (top == 0) {
            result[i % numsSize] = -1;
        } else {
            result[i % numsSize] = stack[top - 1];
        }

        // Push.
        stack[top++] = nums[i % numsSize];
    }
    return result;
}

//int main() {
//    int vals1[] = {1, 2, 1};
//    int vals1Size = sizeof(vals1) / sizeof(int);
//    int returnSize = 0;
//
//    int *result = nextGreaterElements503(vals1, vals1Size, &returnSize);
//    for (int i = 0; i < returnSize; i++) {
//        printf("%d ", result[i]);
//    }
//}