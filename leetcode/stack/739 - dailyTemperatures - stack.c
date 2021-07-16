//
// Created by neko on 2021/7/13.
//

#include <stdio.h>
#include <malloc.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*
 * https://leetcode-cn.com/problems/daily-temperatures/
 * monotonic stack.
 *
 * Use a monotonic stack. However, the stack here stores
 * the index of a certain elem rather than the val of
 * the elem.
 * O(n), O(n).
 */
int *dailyTemperatures739(const int *temperatures, int temperaturesSize, int *returnSize) {
    *returnSize = temperaturesSize;
    int *result = malloc(sizeof(int) * temperaturesSize);

    int *stack = malloc(sizeof(int) * temperaturesSize);
    int top = 0;
    for (int i = temperaturesSize - 1; i >= 0; i--) {
        while (top != 0 && temperatures[stack[top - 1]] <= temperatures[i]) {
            // Pop.
            top--;
        }

        if (top == 0) {
            result[i] = 0;
        } else {
            result[i] = stack[top - 1] - i;
        }

        // Push.
        stack[top++] = i;
    }

    return result;
}

//int main() {
////    int vals1[] = {73, 74, 75, 71, 69, 72, 76, 73};
//    int vals1[] = {};
//
//    int vals1Size = sizeof(vals1) / sizeof(int);
//    int returnSize = 0;
//
//    int *result = dailyTemperatures739(vals1, vals1Size, &returnSize);
//    for (int i = 0; i < returnSize; i++) {
//        printf("%d ", result[i]);
//    }
//}