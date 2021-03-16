//
// Created by Denisa on 4/4/2020.
//

#include "queue.h"

void enQueue(Queue *queue, int data) {
    NodeT *newElement = createNode(data);
    if (queue->last == NULL) {
        queue->first = newElement;
    } else {
        queue->last->next = newElement;
    }
    queue->last = newElement;
}

void deQueue(Queue *queue) {
    if (queue->first) {
        NodeT *aux = queue->first;
        if (queue->first == queue->last) {
            queue->first = queue->last = NULL;
        } else {
            queue->first = queue->first->next;
        }
        free(aux);
    }
}

int isEmptyQueue(Queue *queue) {
    return (queue->first == NULL);
}