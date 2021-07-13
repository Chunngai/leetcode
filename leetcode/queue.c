//
// Created by neko on 2021/7/12.
//

#include <malloc.h>
#include <stdlib.h>
#include "queue.h"

struct Queue *initQueue() {
    struct Queue *queue = malloc(sizeof(struct Queue));
    if (!queue) {
        printf("Failed to allocate memory for the queue.\n");
        return NULL;
    }

    queue->base = malloc(sizeof(int) * MAXSIZE);
    if (!queue->base) {
        printf("Failed to allocate memory for queue->base.\n");
        return NULL;
    }
    queue->front = 0;
    queue->rear = 0;
    return queue;
}

int enQueue(struct Queue *queue, int val) {
//    // Uni-directional queue.
//    if (queue->rear == MAXSIZE) {
//        printf("The queue is full!\n");
//        return 0;
//    }

    // Circular queue.
    // The last pos is not allowed to store a val
    // so that when queue->rear == queue->front,
    // or, (queue->rear) % MAXSIZE == queue->front
    // the queue is empty,
    // when (queue->rear + 1) % MAXSIZE == queue->front,
    // the queue is full.
    if (isQueueFull(queue)) {
        printf("The queue is full!\n");
        return 0;
    }

    queue->base[queue->rear] = val;
    queue->rear = (queue->rear + 1) % MAXSIZE;
    return 1;
}

int deQueue(struct Queue *queue, int *val) {
    if (isQueueEmpty(queue)) {
        printf("The queue is empty!\n");
        return 0;
    }

    *val = queue->base[queue->front];
    queue->front = (queue->front + 1) % MAXSIZE;
    return 1;
}

void printQueue(struct Queue *queue) {
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->base[i]);
        i = (i + 1) % MAXSIZE;
    }
    printf("\n");
}

int queueLength(struct Queue *queue) {
    return (queue->rear - queue->front + MAXSIZE) % MAXSIZE;
}

int queueHead(struct Queue *queue, int *val) {
    if (isQueueEmpty(queue)) {
        printf("The queue is empty!\n");
        return 0;
    }

    *val = queue->base[queue->front];
    return 1;
}

int isQueueEmpty(struct Queue *queue) {
    return queue->front == queue->rear;
}

int isQueueFull(struct Queue *queue) {
    return (queue->rear + 1) % MAXSIZE == queue->front;
}

struct Queue *createQueue(int vals[], int valsSize) {
    struct Queue *queue = initQueue();
    for (int i = 0; i < valsSize; i++) {
        enQueue(queue, vals[i]);
    }
    return queue;
}

//int main() {
//    // Init.
//    printf("Initializing a queue.\n");
//    struct Queue *queue = initQueue();
//    if (queue == NULL) {
//        exit(-1);
//    }
//
//    int val = 0;
//    int returnVal;
//
//    // Enqueue.
//    printf("Enqueueing 1.\n");
//    enQueue(queue, 1);
//    printf("Enqueueing 2.\n");
//    enQueue(queue, 2);
//    printf("Enqueueing 5.\n");
//    enQueue(queue, 5);
//
//    // Prints the queue.
//    printf("The current queue is: ");
//    printQueue(queue);
//    // Queue length.
//    printf("The current queue length is: %d\n", queueLength(queue));
//    // Queue head.
//    returnVal = queueHead(queue, &val);
//    if (returnVal) {
//        printf("The queue head is: %d.\n", val);
//    }
//
//    // Dequeue.
//    deQueue(queue, &val);
//    printf("Dequeueing. Got %d.\n", val);
//    deQueue(queue, &val);
//    printf("Dequeueing. Got %d.\n", val);
//    deQueue(queue, &val);
//    printf("Dequeueing. Got %d.\n", val);
//
//    // Prints the queue.
//    printf("The current queue is: ");
//    printQueue(queue);
//    // Queue length.
//    printf("The current queue length is: %d\n", queueLength(queue));
//    // Queue head.
//    returnVal = queueHead(queue, &val);
//    if (returnVal) {
//        printf("The queue head is: %d.\n", val);
//    }
//
//    // Creates a queue.
//    printf("Creating queue: 1, 2, ..., 10.\n");
//    int moreVals[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    int moreValsSize = sizeof(moreVals) / sizeof(int);
//    struct Queue *anotherQueue = createQueue(moreVals, moreValsSize);
//    printf("The current queue is: ");
//    printQueue(anotherQueue);
//}