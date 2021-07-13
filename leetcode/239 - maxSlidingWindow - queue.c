//
// Created by neko on 2021/7/13.
//

#include <stdio.h>
#include <malloc.h>

/*
 * https://leetcode-cn.com/problems/sliding-window-maximum/submissions/
 * monotonic queue.
 *
 * Use a monotonic queue. Each time the window slices,
 * pushLast -> getMax -> popFirst.
 * Take care of the first few steps when the window is not full.
 * Note that when the subtraction op is needed in a circular queue,
 * it should be something like `(rare - 1 + maxSize) % maxSize`
 * rather than `(rare - 1) % maxSize`, since `rare - 1`
 * may result in a negative value.
 * Also note that the time complexity is O(n) though there is a
 * while loop in the push op because one elem will be pushed and
 * popped only once. The while loop only determines the direction
 * from which a certain elem is popped. if the elem has not been
 * popped in the while loop of the push op, it will be popped from
 * the head of the queue, the same as how a normal queue does. Else
 * it will be popped in the while for loop of the push op, which is
 * the special op of the monotonic queue.
 * O(n), O(k).
 */
struct MonotonicQueue239 {
    int maxSize;

    int *base;
    int front;
    int rare;
};

struct MonotonicQueue239 *initMonotonicQueue239(int maxSize) {
    struct MonotonicQueue239 *monotonicQueue = malloc(sizeof(struct MonotonicQueue239));

    monotonicQueue->maxSize = maxSize;
    monotonicQueue->base = malloc(sizeof(int) * monotonicQueue->maxSize);
    monotonicQueue->front = 0;
    monotonicQueue->rare = 0;

    return monotonicQueue;
}

void monotonicEnqueue239(struct MonotonicQueue239 *monotonicQueue, int val) {
    while (
            monotonicQueue->front != monotonicQueue->rare &&  // Ensures that the queue is not empty.
            // Maintains the monotonicity.
            monotonicQueue->base[(monotonicQueue->rare - 1 + monotonicQueue->maxSize) % monotonicQueue->maxSize] < val
            ) {
        monotonicQueue->rare = (monotonicQueue->rare - 1 + monotonicQueue->maxSize) % monotonicQueue->maxSize;
    }
    monotonicQueue->base[monotonicQueue->rare] = val;
    monotonicQueue->rare = (monotonicQueue->rare + 1) % monotonicQueue->maxSize;
}

void monotonicDequeue239(struct MonotonicQueue239 *monotonicQueue, int val) {
    if (monotonicQueue->front != monotonicQueue->rare && monotonicQueue->base[monotonicQueue->front] == val) {
        monotonicQueue->front = (monotonicQueue->front + 1) % monotonicQueue->maxSize;
    }
}

int monotonicMax239(struct MonotonicQueue239 *monotonicQueue) {
    return monotonicQueue->base[monotonicQueue->front];
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *maxSlidingWindow239(const int *nums, int numsSize, int k, int *returnSize) {
    *returnSize = numsSize - k + 1;
    int *maxVals = malloc(sizeof(int) * *returnSize);
    int maxValPos = 0;

    // Monotonic queue.
    struct MonotonicQueue239 *monotonicQueue = initMonotonicQueue239(k + 1);

    for (int i = 0; i < numsSize; i++) {
        // Push.
        monotonicEnqueue239(monotonicQueue, nums[i]);
        // The queue is not yet full now.
        if (i < k - 1) {
            continue;
        }

        // Get max.
        maxVals[maxValPos++] = monotonicMax239(monotonicQueue);

        // Pop.
        monotonicDequeue239(monotonicQueue, nums[i - k + 1]);
    }

    return maxVals;
}

//int main() {
////    int nums[] = {1, 3, -1, -3, 5, 3, 6, 7};
////    int numsSize = sizeof(nums) / sizeof(int);
////    int k = 3;
////    int returnSize = 0;
//
////    int nums[] = {1};
////    int numsSize = sizeof(nums) / sizeof(int);
////    int k = 1;
////    int returnSize = 0;
//
////    int nums[] = {1, -1};
////    int numsSize = sizeof(nums) / sizeof(int);
////    int k = 1;
////    int returnSize = 0;
//
////    int nums[] = {9, 11};
////    int numsSize = sizeof(nums) / sizeof(int);
////    int k = 2;
////    int returnSize = 0;
//
////    int nums[] = {4, -2};
////    int numsSize = sizeof(nums) / sizeof(int);
////    int k = 2;
////    int returnSize = 0;
//
////    int nums[] = {7238, 9932, -7015, 6020, 2596, 6189, -7315, 3176, -7751, 7995, 3970, 7008, 4059, 9310, -3655, -8628,
////                  3249, 6132, 9022, 8156, 8970, 7702, -8248, 9130, -1393, -6814, -8441, 9879, -2811, 3564, 6491, 8875,
////                  -200, 8698, -6756, -5946, 2006, 7604, 7379, -4675, 3323, -544, 544, 130, -1171, 6535, -6825, 4471,
////                  3580, -1876, -5201, 7337, -3992, -3277, -8251, 5427, 8989, 4481, -298, 5049, 9762, -4932, -7561,
////                  -8209, 1343, 2338, -8612, 5181, 95, 8312, 6140, 9449, 9283, 5812, 2348, -57, -5351, 4471, 3738, 5256,
////                  -1644, -8322, -4507, -6337, 821, 3626, 3804, 3957, 7675, 2195, 5933, 5699, 545, -3593, -760, 199,
////                  -7339, -6963, -8857, 5111, -2086, -4285, 5260, -6824, -7696, -3032, -1368, -6605, 2119, 5660, 850,
////                  4834, 3333, 7193, 6465, 1137, -7826, 3972, -4014, -8963, 6244, -5914, 7196, 8119, 4804, -1212, 4780,
////                  -5600, 8125, -5737, -2363, -5635, 3902, 4423, -3962, 7659, -2802, 9953, 6651, 3794, -7302, 5601,
////                  -6981, -9579, 6382, -1355, 6387, 8293, -4281, 393, 507, 3554, -85, 6148, 9009, 9994, 3835, -8033,
////                  -985, -9909, -2869, 1453, -1824, -7902, -5402, -4205, -187, -9707, 7666, 4167, 3762, -8791, -1256,
////                  9682, -9714, -597, 6671, -8381, -304, -4242, -5095, 6311, -7830, -1480, -6470, 6264, 8859, -4593,
////                  9514, 1430, 5248, 6556, 8422, -8424, -4742, -6497, -3416, -4005, -4213, -4945, 6129, 4473, -4092,
////                  -6352, 490, -5252, -2591, -5388, 9398, -8349, 3329, -5143, -5446, 9031, -6319, -4679, -7013, 867,
////                  -705, 7882, 5625, 6763, 954, 897, -2191, 4859, -4321, 4058, 2535, -1918, -9012, -2708, 500, -5448,
////                  -3478, -6758, -935, 7277, 979, -2030, -3152, 9066, -6420, 2590, -7793, -3197, 7510, 8948, -4362, 5464,
////                  -981, 4541, -6535, -4853, -8182, 4128, -4434, 8901, -1384, 1166, -5818, -5866, 3158, -9958, -5805,
////                  -959, 4945, -8665, -5298, 8831, 5525, 3577, -2783, 7743, 7145, -1839, -2936, -8183, 978, 2578, -6729,
////                  -7782, 135, 7508, 7847};
////    int numsSize = sizeof(nums) / sizeof(int);
////    int k = 19;
////    int returnSize = 0;
//
//    int nums[] = {-9361, -750, -8435, -5590, -5835, 2958, -3942, -8209, -8241, -9307, 7999, 9777, -6045, 1362, -4022,
//                  7045, -1351, 9610, -4192, -267, -2120, 6657, -9405, -7549, 8074, 3222, -5563, 204, 2999, 3961, -6798,
//                  -53, 2349, -6533, -223, 1033, 7369, -6896, -1756, -127, 6161, -7878, 9644, 2595, -1269, 8314, 8815,
//                  -7448, 9973, 9797, 1802, -6681, 6742, -2199, 795, 6579, 2676, 9505, -3383, -4465, 6993, 1317, 6608,
//                  -8496, -512, -100, 5136, 686, -2667, 1892, -2416, 4272, 1011, -6260, 5780, -2764, -7807, 3267, 833,
//                  -8811, -4751, 7541, -2562, 5043, -7245, -2427, -6331, 147, -2974, 759, -2200, -9467, 6092, 9013,
//                  -6563, 3810, -4710, -9420, -9173, -7326, 1120, -5794, 3928, 7327, 3017, -8873, 6524, -7972, -769,
//                  -1121, 3126, -1586, -2184, -6868, 6536, -3325, -9561, -7140, -9483, 2271, -6239, -128, 6595, -6159,
//                  3560, -6865, -8249, 1165, 5062, -7508, 3492, -1801, 9877, 4857, 6104, -7193, 9776};
//    int numsSize = sizeof(nums) / sizeof(int);
//    int k = 3;
//    int returnSize = 0;
//
//    int *result = maxSlidingWindow239(nums, numsSize, k, &returnSize);
//    for (int i = 0; i < returnSize; i++) {
//        printf("%d ", result[i]);
//    }
//}