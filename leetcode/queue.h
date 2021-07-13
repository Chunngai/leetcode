//
// Created by neko on 2021/7/12.
//

#ifndef LEETCODE_QUEUE_H
#define LEETCODE_QUEUE_H

#define MAXSIZE 100
struct Queue {
    int *base;
    int front;
    int rear;
};

struct Queue *initQueue();

int enQueue(struct Queue *queue, int val);

int deQueue(struct Queue *queue, int *val);

void printQueue(struct Queue *queue);

int queueLength(struct Queue *queue);

int queueHead(struct Queue *queue, int *val);

int isQueueEmpty(struct Queue *queue);

int isQueueFull(struct Queue *queue);

struct Queue *createQueue(int vals[], int valsSize);

#endif //LEETCODE_QUEUE_H
