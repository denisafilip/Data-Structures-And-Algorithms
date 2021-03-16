//
// Created by Denisa on 3/14/2020.
//

#ifndef ASSIGNMENT3_1_LIST_H
#define ASSIGNMENT3_1_LIST_H

#include "tree.h"

typedef struct nodeList {
    char *data;
    struct nodeList *prev, *next;
} NodeL;

NodeL *createNode();

void addNode(NodeL **first, NodeL **last, char *key);

NodeL *getListFromTree(NodeT *currentRoot);

NodeT *getTreeFromList(NodeL **head);

void traverseList(NodeL *head);

#endif //ASSIGNMENT3_1_LIST_H
