//
// Created by Denisa on 3/14/2020.
//

#ifndef ASSIGNMENT3_1_TREE_H
#define ASSIGNMENT3_1_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *id;
    struct node *right, *left;
} NodeT;

NodeT *createTreeNode(char *c);

NodeT *createBinTree();

void prettyPrint(NodeT *currentRoot, int level);

int getMaxDepth(NodeT *root);

void postorder(NodeT *root);

void inorder(NodeT *currentRoot);

void preorder(NodeT *root);

int search(NodeT *root, char *content);


#endif //ASSIGNMENT3_1_TREE_H
