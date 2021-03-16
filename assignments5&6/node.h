//
// Created by Denisa on 4/4/2020.
//

#ifndef ASSIGNMENT5_NODE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} NodeT;

typedef struct list {
    NodeT *first;
    NodeT *last;
} Queue;

NodeT *createNode(int data);

Queue createQueue();

#define ASSIGNMENT5_NODE_H

#endif //ASSIGNMENT5_NODE_H
