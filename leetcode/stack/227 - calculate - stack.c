//
// Created by neko on 2021/7/16.
//

#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "../leetcode_utils.h"

/*
 * https://leetcode-cn.com/problems/basic-calculator-ii/
 * math expression.
 *
 * Convert the infix expr to the postfix expr
 * then calculate using the postfix expr. It's slow
 * and requires a lot of code.
 * O(n), O(n).
 *
 * 1. For int -> str and char -> str,
 * when creating the arr,
 * `ElemType arr[Size] = {0}` does not work,
 * but `ElemType *arr = malloc(sizeof(ElemType) * Size)` does.
 */
int isoperator227(char chr) {
    switch (chr) {
        case '+':
        case '-':
        case '*':
        case '/':
            return 1;
        default:
            return 0;
    }
}

int priority227(char chr) {
    switch (chr) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

char *int2string227(int val) {
    char *s = malloc(sizeof(char) * 11);  // Should malloc each time.
    sprintf(s, "%d", val);
    return s;
}

char *char2string227(char val) {
    char *s = malloc(sizeof(char) * 2);  // Should malloc each time.
    sprintf(s, "%c", val);
    return s;
}

int calculateAfterInfixToPostfix227(char *s) {
    int strLen = (int) strlen(s);

    char *operatorStack = malloc(sizeof(char) * strLen);
    int operatorStackTop = 0;

    char **postfixRepr = malloc(sizeof(char *) * strLen);
    int postfixReprTop = 0;

    /*
     * 0
     */
    int hasNumBuffer = 0;
    int numBuffer = 0;  // An int may have multiple digits.
    for (int i = 0; i < strLen; i++) {
        char chr = s[i];

        // ignores spaces.
        if (chr == ' ') {
            continue;
        }

        if (isdigit(chr)) {
            numBuffer = 10 * numBuffer + atoi(char2string227(chr));
            hasNumBuffer = 1;
        } else {
            if (hasNumBuffer) {
                postfixRepr[postfixReprTop++] = int2string227(numBuffer);
                numBuffer = 0;
                hasNumBuffer = 0;
            }

            if (isoperator227(chr)) {
                while (operatorStackTop - 1 >= 0 &&
                       priority227(operatorStack[operatorStackTop - 1]) >= priority227(chr)) {
                    postfixRepr[postfixReprTop++] = char2string227(operatorStack[--operatorStackTop]);
                }
                operatorStack[operatorStackTop++] = chr;
            } else if (chr == '(') {
                operatorStack[operatorStackTop++] = chr;
            } else if (chr == ')') {
                while (operatorStack[operatorStackTop - 1] != '(') {
                    postfixRepr[postfixReprTop++] = char2string227(operatorStack[--operatorStackTop]);
                }
                operatorStackTop--;
            }
        }
    }
    if (hasNumBuffer) {
        postfixRepr[postfixReprTop++] = int2string227(numBuffer);
    }
    while (operatorStackTop > 0) {
        postfixRepr[postfixReprTop++] = char2string227(operatorStack[--operatorStackTop]);
    }

    int postfixReprLen = postfixReprTop;

    int *evalRPNstack = malloc(sizeof(int) * (postfixReprLen + 1));
    int evalRPNTop = 0;
    for (int i = 0; i < postfixReprLen; i++) {
        char *elem = postfixRepr[i];
        if (isdigit(elem[0])) {
            int number = atoi(elem);
            evalRPNstack[evalRPNTop++] = number;
        } else {
            int rightOperand = evalRPNstack[--evalRPNTop];
            int leftOperand = evalRPNstack[--evalRPNTop];
            int result;
            switch (elem[0]) {
                case '+':
                    result = leftOperand + rightOperand;
                    break;;
                case '-':
                    result = leftOperand - rightOperand;
                    break;
                case '*':
                    result = leftOperand * rightOperand;
                    break;
                case '/':
                    result = leftOperand / rightOperand;
                    break;
            }
            evalRPNstack[evalRPNTop++] = result;
        }
    }

    return evalRPNstack[0];
}

void cal(int *operandStack, int *operandStackTop, char *operatorStack, int *operatorStackTop) {
    int rightOperand = operandStack[--*operandStackTop];
    int leftOperand = operandStack[--*operandStackTop];
    char operator = operatorStack[--*operatorStackTop];

    int result;
    switch (operator) {
        case '+':
            result = leftOperand + rightOperand;
            break;
        case '-':
            result = leftOperand - rightOperand;
            break;
        case '*':
            result = leftOperand * rightOperand;
            break;
        case '/':
            result = leftOperand / rightOperand;
            break;
    }
    operandStack[(*operandStackTop)++] = result;
}

/*
 * https://leetcode-cn.com/problems/basic-calculator-ii/
 * math expression.
 *
 * The solution is similar to the one above, but
 * calculate at the same time of implicitly converting
 * the infix expr to the postfix expr.
 * O(n), O(n).
 */
int calculateDuringInfixToPostfix227(char *s) {
    int strLen = (int) strlen(s);

    int *operandStack = malloc(sizeof(int) * strLen);
    int operandStackTop = 0;

    char *operatorStack = malloc(sizeof(char) * strLen);
    int operatorStackTop = 0;

    for (int i = 0; i < strLen; i++) {
        char chr = s[i];
        if (chr == ' ') {
            continue;
        }
        if (isdigit(chr)) {
            int number = 0;
            while (1) {
                number = number * 10 + (int) (chr - '0');
                // Next chr.
                i++;
                chr = s[i];
                if (!isdigit(chr)) {
                    i--;
                    break;
                }
            }
            operandStack[operandStackTop++] = number;
        } else if (isoperator227(chr)) {
            while (operatorStackTop > 0 && priority227(operatorStack[operatorStackTop - 1]) >= priority227(chr)) {
                // Pops two numbers from the operand stack,
                // and pops one operator from the operator stack,
                // then calculate and pushes the result to the operand stack.
                cal(operandStack, &operandStackTop, operatorStack, &operatorStackTop);
            }
            operatorStack[operatorStackTop++] = chr;
        } else if (chr == '(') {
            operatorStack[operatorStackTop++] = chr;
        } else if (chr == ')') {
            while (operatorStackTop - 1 >= 0 && operatorStack[operatorStackTop - 1] != '(') {
                cal(operandStack, &operandStackTop, operatorStack, &operatorStackTop);
            }
            operatorStackTop--;
        }
    }
    while (operatorStackTop > 0) {
        cal(operandStack, &operandStackTop, operatorStack, &operatorStackTop);
    }

    return operandStack[0];
}

//int main() {
//    char *strings[10] = {
//            "3+2*2",
//            " 3/2 ",
//            " 3+5 / 2 ",
//            " 233 + 666    ",
//            " 1 - 1 + 1 ",
//            "9 + (3 - 1) * 3 + 10 / 2",  // 9 3 1 - 3 * + 10 2 / +
//            "1 + 2 * 3 + ( 4 * 5 + 6 ) * 7",  // 1 2 3 * + 4 5 * 6 + 7 * +
//            "1 + ((2 + 3) * 4) - 5",  // 1 2 3 + 4 * + 5 -
//            "12 + ( 1 * 2 + 3 * 4 )",  // 12 1 2 * 3 4 * + +
//            "0"
//    };
//    for (int i = 0; i < 10; i++) {
//        printInt(calculateDuringInfixToPostfix227(strings[i]));
//    }
//}