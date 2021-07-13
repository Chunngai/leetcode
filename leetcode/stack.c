//
// Created by neko on 2021/7/13.
//

#include <malloc.h>
#include <stdlib.h>
#include "stack.h"

struct Stack *initStack() {
    struct Stack *stack = malloc(sizeof(struct Stack));
    if (!stack) {
        printf("Failed to allocate memory for the stack.\n");
        return NULL;
    }

    stack->base = malloc(sizeof(int) * MAXSIZE);
    if (!stack->base) {
        printf("Failed to allocate memory for stack->base.\n");
        return NULL;
    }
    stack->top = stack->base;
    return stack;
}

int pushStack(struct Stack *stack, int val) {
    if (isStackFull(stack)) {
        printf("The stack is full!\n");
        return 0;
    }
    *stack->top++ = val;
    return 1;
}

int popStack(struct Stack *stack, int *val) {
    if (isStackEmpty(stack)) {
        printf("The stack is empty!\n");
        return 0;
    }

    *val = *--stack->top;
    return 1;
}

void printStack(struct Stack *stack) {
    int *p = stack->base;
    while (p != stack->top) {
        printf("%d ", *p);
        p++;
    }
    printf("\n");
}

int stackLength(struct Stack *stack) {
    return (int) (stack->top - stack->base);
}

int stackHead(struct Stack *stack, int *val) {
    if (isStackEmpty(stack)) {
        printf("The stack is empty!\n");
        return 0;
    }

    *val = *(stack->top - 1);
    return 1;
}

int isStackEmpty(struct Stack *stack) {
    return stack->top == stack->base;
}

int isStackFull(struct Stack *stack) {
    return stack->top - stack->base == MAXSIZE;
}

struct Stack *createStack(int vals[], int valsSize) {
    struct Stack *stack = initStack();
    for (int i = 0; i < valsSize; i++) {
        pushStack(stack, vals[i]);
    }
    return stack;
}

//int main() {
//    // Init.
//    printf("Initializing a stack.\n");
//    struct Stack *stack = initStack();
//    if (stack == NULL) {
//        exit(-1);
//    }
//
//    int val = 0;
//    int returnVal;
//
//    // Push.
//    printf("Pushing 1.\n");
//    pushStack(stack, 1);
//    printf("Pushing 2.\n");
//    pushStack(stack, 2);
//    printf("Pushing 5.\n");
//    pushStack(stack, 5);
//
//    // Prints the stack.
//    printf("The current stack is: ");
//    printStack(stack);
//    // Stack length.
//    printf("The current stack length is: %d\n", stackLength(stack));
//    // Stack head.
//    returnVal = stackHead(stack, &val);
//    if (returnVal) {
//        printf("The stack head is: %d.\n", val);
//    }
//
//    // Pop.
//    popStack(stack, &val);
//    printf("Popping. Got %d.\n", val);
//    popStack(stack, &val);
//    printf("Popping. Got %d.\n", val);
//    popStack(stack, &val);
//    printf("Popping. Got %d.\n", val);
//
//    // Prints the stack.
//    printf("The current stack is: ");
//    printStack(stack);
//    // Stack length.
//    printf("The current stack length is: %d\n", stackLength(stack));
//    // Stack head.
//    returnVal = stackHead(stack, &val);
//    if (returnVal) {
//        printf("The stack head is: %d.\n", val);
//    }
//
//    // Creates a stack.
//    printf("Creating stack: 1, 2, ..., 10.\n");
//    int moreVals[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    int moreValsSize = sizeof(moreVals) / sizeof(int);
//    struct Stack *anotherStack = createStack(moreVals, moreValsSize);
//    printf("The current stack is: ");
//    printStack(anotherStack);
//}