//
// Created by Denisa on 2/28/2020.
//

#ifndef ASSIGNMENT1EXTRA_LISTS_H
#define ASSIGNMENT1EXTRA_LISTS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} NodeT;

void addLast(NodeT **first, NodeT **last, int x);

int sumOfNodes(NodeT *first, NodeT *last);
#endif //ASSIGNMENT1EXTRA_LISTS_H
