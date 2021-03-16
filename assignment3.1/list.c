//
// Created by Denisa on 3/14/2020.
//
#include "list.h"

NodeL *createNode() {
    NodeL *node = (NodeL *) malloc(sizeof(NodeL));
    node->data = (char *) malloc(sizeof(char));
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void addNode(NodeL **first, NodeL **last, char *key) {
    if (*last == NULL) {
        *last = createNode();
        strcpy((*last)->data, key);
        (*last)->next = NULL;
        (*last)->prev = NULL;
        *first = *last;
    } else {
        NodeL *newElement = createNode();
        strcpy(newElement->data, key);
        newElement->next = NULL;
        newElement->prev = *last;
        (*last)->next = newElement;
        *last = newElement;
    }
}

NodeL *first = NULL, *last = NULL;

NodeL *getListFromTree(NodeT *currentRoot) {
    if (currentRoot == NULL) {
        addNode(&first, &last, "*");
    } else {
        addNode(&first, &last, currentRoot->id);
        last->prev = getListFromTree(currentRoot->left);
        last->prev = getListFromTree(currentRoot->right);
    }
    return first;
}

NodeT *getTreeFromList(NodeL **head) {
    char *aux = (char *) malloc(sizeof(char));
    if (head != NULL) {
        strcpy(aux, (*head)->data);
        *head = (*head)->next;
        if (strcmp(aux, "*") == 0) {
            return NULL;
        } else {
            NodeT *currentRoot = createTreeNode(aux);
            currentRoot->left = getTreeFromList(head);
            currentRoot->right = getTreeFromList(head);
            return currentRoot;
        }
    } else {
        return NULL;
    }
}

void traverseList(NodeL *head) {
    NodeL *currentNode = head;
    if (head == NULL) {
        printf("The list is empty! \n");
    } else {
        while (currentNode != NULL) {
            printf("%s ", currentNode->data);
            currentNode = currentNode->next;
        }
        printf("\n");
    }
}