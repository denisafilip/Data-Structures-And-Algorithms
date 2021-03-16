//
// Created by Denisa on 3/19/2020.
//

#ifndef ASSIGNMENT3EXTRA_TREE_H
#define ASSIGNMENT3EXTRA_TREE_H

#include "queue.h"

typedef struct nodeTree {
    char *data;
    struct nodeTree *left, *right;
} NodeT;

NodeT *createTreeNode();

NodeT *createBinTree(Queue *queue);

void printTree(NodeT *currentRoot, int level);

#endif //ASSIGNMENT3EXTRA_TREE_H
