//
// Created by neko on 2021/7/13.
//

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/*
 * https://leetcode-cn.com/problems/valid-parentheses/
 * basic op.
 *
 * Use a stack to match.
 * Note that if str len % 2 == 1,
 * the str must be invalid. And
 * checking if top == base at last
 * has the same effect.
 * Remember to check if the stack is empty
 * when popping.
 *
 * 1. When defining an arr wo init,
 * `ElemType arr[Var] is valid`.
 * 2. Remember to + 1 when creating a char arr.
 * 3. `*p != '\0'` is not equivalent to `p`.
 */
bool isValid20(char *s) {
//    char stack[(int) 1e4] = {};
    // From leetcode.
    int strLen = (int) strlen(s);
    if (strLen % 2 == 1) {
        return false;
    }
    char stack[strLen + 1];

    int top = 0;

    char *p = s;
    while (*p != '\0') {
        if (*p == '(' || *p == '[' || *p == '{') {
            // Push.
            stack[top++] = *p;
        }
        if (*p == ')' || *p == ']' || *p == '}') {
            // Pop.
            char topChar;
            /*
             * "]".
             * Needed when the length if not checked
             * using `strLen % 2 == 1`.
             */
            if (top != 0) {
                topChar = stack[--top];
            } else {
                // The stack is empty.
                return false;
            }

            if (topChar == '(' && *p != ')') {
                return false;
            }
            if (topChar == '[' && *p != ']') {
                return false;
            }
            if (topChar == '{' && *p != '}') {
                return false;
            }
        }
        p++;
    }

    if (top == 0) {
        return true;
    } else {
        return false;
    }
}

//int main() {
////    char s[] = "()";
////    char s[] = "()[]{}";
////    char s[] = "(]";
////    char s[] = "([}]";
////    char s[] = "{[]}";
//    char s[] = "]";
//
//    printf("%d", isValid20(s));
//}