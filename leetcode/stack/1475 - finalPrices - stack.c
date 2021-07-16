//
// Created by neko on 2021/7/14.
//

#include <malloc.h>
#include "../leetcode_utils.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*
 * https://leetcode-cn.com/problems/final-prices-with-a-special-discount-in-a-shop/
 * monotonic stack.
 *
 * The solution is similar to q496. But it's
 * a problem for obtaining the next less or equal elements
 * rather than the next greater elements.
 * O(n), O(n).
 */
int *finalPrices1475(int *prices, int pricesSize, int *returnSize) {
    int *nextLessElements = malloc(sizeof(int) * pricesSize);

    int *stack = malloc(sizeof(int) * pricesSize);
    int top = 0;

    for (int i = pricesSize - 1; i >= 0; i--) {
        while (top != 0 && stack[top - 1] > prices[i]) {
            // Pop.
            top--;
        }

        if (top == 0) {
            nextLessElements[i] = 0;
        } else {
            nextLessElements[i] = stack[top - 1];
        }

        // Push.
        stack[top++] = prices[i];
    }

    *returnSize = pricesSize;
    for (int i = 0; i < *returnSize; i++) {
        prices[i] -= nextLessElements[i];
    }
    return prices;
}

//int main() {
////    int vals1[] = {8, 4, 6, 2, 3};
////    int vals1[] = {1, 2, 3, 4, 5};
//    int vals1[] = {10, 1, 1, 6};
//
//    int vals1Size = sizeof(vals1) / sizeof(int);
//
//    int returnSize = 0;
//
//    int *result = finalPrices1475(vals1, vals1Size, &returnSize);
//    printIntArray(result, returnSize);
//}