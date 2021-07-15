//
// Created by neko on 2021/7/14.
//

#include <stdlib.h>
#include <malloc.h>
#include "leetcode_utils.h"

// char *tokens[] = {...};
// char tokens[][1] = {...};
// int tokensSize = sizeof(tokens) / sizeof(char *);

/*
 * https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/
 * basic ops.
 *
 * When the elem is an operand, push. When the elem
 * is an op, pop two operands and calculate. Push the
 * result into the stack.
 * When judging if the elem is an operand, ice the negative
 * numbers.
 * And notice the pushing order. The right operand is first
 * pushed, and then left operand is secondly pushed.
 * O(n), O(n).
 *
 * 1. TODO: char *tokens[] = { ... } and char tokens[][1] = { ... }
 * are different.
 * 2. TODO: For `char *tokens[]`, the arr size is `sizeof(tokens) / sizeof(char *)`.
 */
int evalRPN150(char **tokens, int tokensSize) {
    int *stack = malloc(sizeof(int) * tokensSize);
    int top = 0;

    for (int i = 0; i < tokensSize; i++) {
        int operand;
        if (tokens[i][0] == '-' && tokens[i][1] >= 48 && tokens[i][1] <= 57 ||
            tokens[i][0] >= 48 && tokens[i][0] <= 57) {
            operand = atoi(tokens[i]);
            stack[top++] = operand;
        } else {
            // First operand 2 then operand 1.
            int operand2 = stack[--top];
            int operand1 = stack[--top];
            int result = 0;
            if (tokens[i][0] == '+') {
                result = operand1 + operand2;
            } else if (tokens[i][0] == '-') {
                result = operand1 - operand2;
            } else if (tokens[i][0] == '*') {
                result = operand1 * operand2;
            } else if (tokens[i][0] == '/') {
                result = operand1 / operand2;
            }
            stack[top++] = result;
        }
    }

    return stack[top - 1];
}
//
//int main() {
////    char *tokens[] = {"2", "1", "+", "3", "*"};
////    char *tokens[] = {"4", "13", "5", "/", "+"};
//    char *tokens[] = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
//
//    int tokensSize = sizeof(tokens) / sizeof(char *);
//
//    printInt(evalRPN150((char **) tokens, tokensSize));
//}