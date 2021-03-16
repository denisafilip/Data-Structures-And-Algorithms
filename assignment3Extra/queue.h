//
// Created by Denisa on 3/19/2020.
//

#ifndef ASSIGNMENT3EXTRA_QUEUE_H
#define ASSIGNMENT3EXTRA_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
    char *data;
    struct node *next;
} NodeQ;

typedef struct list {
    NodeQ *first;
    NodeQ *last;
} Queue;

NodeQ *createNode();

Queue createQueue();

void enqueue(Queue *queue, char *value);

void checkIfOperandOrOperator(Queue *queue, char *value);

void dequeue(Queue *queue);

Queue parseMathematicalExpression(FILE *input, Queue *queue);
#endif //ASSIGNMENT3EXTRA_QUEUE_H
