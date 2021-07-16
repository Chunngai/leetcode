//
// Created by neko on 2021/7/15.
//

#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "../leetcode_utils.h"

// stack[top++] = stack[top - 1] * 2;

/*
 * https://leetcode-cn.com/problems/baseball-game/
 * basic ops.
 *
 * Use a stack to simulate the process.
 * Note that if the popping order is a, b,
 * the pushing order should be b, a.
 * O(n), O(n).
 */
int calPoints682(char **ops, int opsSize) {
    int *stack = malloc(sizeof(int) * (opsSize + 1));
    int top = 0;

    for (int i = 0; i < opsSize; i++) {
        char *elem = ops[i];
        if (strlen(elem) > 1 || (elem[0] >= '0' && elem[0] <= '9')) {
            stack[top++] = atoi(elem);
        } else if (elem[0] == '+') {
            int a = stack[--top];
            int b = stack[--top];
            stack[top++] = b;
            stack[top++] = a;
            stack[top++] = a + b;
        } else if (elem[0] == 'D') {
            stack[top] = stack[top - 1] * 2;
            top++;
        } else if (elem[0] == 'C') {
            top--;
        }
    }

    int result = 0;
    for (int i = 0; i < top; i++) {
        result += stack[i];
    }
    return result;
}

//int main() {
////    char *ops[] = {"5", "2", "C", "D", "+"};
////    char *ops[] = {"5", "-2", "4", "C", "D", "9", "+", "+"};
//    char *ops[] = {"1"};
//
//    int opsSize = sizeof(ops) / sizeof(char *);
//
//    printInt(calPoints682(ops, opsSize));
//}