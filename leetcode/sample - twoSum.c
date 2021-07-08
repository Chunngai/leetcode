//
// Created by neko on 2021/7/7.
//

#include <stdio.h>
#include <malloc.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                int *result = malloc(sizeof(int) * 2);
                result[0] = i;
                result[1] = j;

                *returnSize = 2;
                return result;
            }
        }
    }

    *returnSize = 0;
    return NULL;
}

//int main() {
//    int nums[] = {2, 7, 11, 15};
//    int target = 9;
//    int returnSize = 0;
//
//    int numSize = sizeof(nums) / sizeof(int);
//    int *result = twoSum(nums, numSize, target, &returnSize);
//
//    for (int i = 0; i < returnSize; i++) {
//        printf("%d ", result[i]);
//    }
//
//    free(result);
//
//    return 0;
//}