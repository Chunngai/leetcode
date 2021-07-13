//
// Created by neko on 2021/7/13.
//

#ifndef LEETCODE_STACK_H
#define LEETCODE_STACK_H

#define MAXSIZE 100
struct Stack {
    int *base;
    int *top;
};

struct Stack *initStack();

int pushStack(struct Stack *stack, int val);

int popStack(struct Stack *stack, int *val);

void printStack(struct Stack *stack);

int stackLength(struct Stack *stack);

int stackHead(struct Stack *stack, int *val);

int isStackEmpty(struct Stack *stack);

int isStackFull(struct Stack *stack);

struct Stack *createStack(int vals[], int valsSize);

#endif //LEETCODE_STACK_H
