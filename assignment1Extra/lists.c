//
// Created by Denisa on 2/28/2020.
//

#include "lists.h"

void addLast(NodeT **first, NodeT **last, int x) {
    if (*first == NULL) {
        *first = (NodeT *) malloc(sizeof(NodeT));
        (*first)->next = NULL;
        (*first)->data = x;
        *last = *first;
    } else {
        NodeT *newElement = (NodeT *) malloc(sizeof(NodeT));
        (*last)->next = newElement;
        newElement->next = NULL;
        newElement->data = x;
        (*last) = newElement;
    }
}

int sumOfNodes(NodeT *first, NodeT *last) {
    int sum = 0;
    if (first == NULL || last == NULL) return 0;
    else {
        NodeT *currentElement = first;
        while (currentElement != NULL) {
            sum += currentElement->data;
            currentElement = currentElement->next;
        }
    }
    return sum;
}