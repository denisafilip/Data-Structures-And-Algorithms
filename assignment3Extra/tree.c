//
// Created by Denisa on 3/19/2020.
//

#include "tree.h"

NodeT *createTreeNode() {
    NodeT *t = (NodeT *) malloc(sizeof(NodeT));
    t->data = (char *) malloc(sizeof(char));
    t->right = NULL;
    t->left = NULL;
    return t;
}

NodeT *createBinTree(Queue *queue) {
    if (strcmp(queue->first->data, "&") == 0) {
        return NULL;
    }
    NodeT *currentNode = createTreeNode();
    strcpy(currentNode->data, queue->first->data);
    dequeue(queue);
    currentNode->left = createBinTree(queue);
    dequeue(queue);
    currentNode->right = createBinTree(queue);
    return currentNode;
}

void printTree(NodeT *currentRoot, int level) {
    if (currentRoot != NULL) {
        for (int i = 0; i < level; i++) {
            printf(" ");
        }
        printf("%s", currentRoot->data);
        printTree(currentRoot->left, level + 1);
        printTree(currentRoot->right, level + 1);
    }
}