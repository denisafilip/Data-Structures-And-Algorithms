//
// Created by Denisa on 3/26/2020.
//

#ifndef ASSIGNMENT4_1_TREE_H
#define ASSIGNMENT4_1_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define COUNT 10

typedef struct node {
    int key;
    struct node *left, *right;
    int height;
} NodeT;

NodeT *createNode(int key);

void prettyPrintUtil(NodeT *currentRoot, int space);

void prettyPrint(NodeT *currentRoot);

int height(NodeT *currentNode);

int getHeight(NodeT *currentNode);

int getMaximum(int a, int b);

int computeBalance(NodeT *currentNode);

NodeT *rightRotate(NodeT *leftRoot);

NodeT *leftRotate(NodeT *currentRoot);

void mirror(NodeT *root);

NodeT *transformIntoBalancedTree(NodeT *currentRoot, int key);

NodeT *insert(NodeT *currentRoot, int key);

bool find(NodeT *currentRoot, int key);

void findWithPrint(NodeT *currentRoot, int key);

NodeT *getSuccessor(NodeT *node);

NodeT *delete(NodeT *currentRoot, int key);

int hasPathSum(NodeT *root, int sum);

void doubleTree(NodeT *root);

void inorder(NodeT *currentRoot);

void printArray(int *arr, int len);

void printPaths(NodeT *root, int *path,int pathLength);
#endif //ASSIGNMENT4_1_TREE_H
