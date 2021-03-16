//
// Created by Denisa on 4/4/2020.
//

#include "node.h"

NodeT *createNode(int data) {
    NodeT *newNode;
    newNode = (NodeT *) malloc(sizeof(int));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Queue createQueue() {
    Queue newList;
    newList.first = NULL;
    newList.last = NULL;
    return newList;
}