//
// Created by Denisa on 3/19/2020.
//

#include "queue.h"

NodeQ *createNode() {
    NodeQ *node = (NodeQ *) malloc(sizeof(NodeQ));
    node->data = (char *) malloc(sizeof(char));
    node->next = NULL;
    return node;
}

Queue createQueue() {
    Queue queue;
    queue.first = NULL;
    queue.last = NULL;
    return queue;
}

void enqueue(Queue *queue, char *value) {
    if (queue->first == NULL) {
        queue->first = createNode();
        strcpy(queue->first->data, value);
        queue->last = queue->first;
    } else {
        NodeQ *newElement = createNode();
        strcpy(newElement->data, value);
        queue->last->next = newElement;
        queue->last = newElement;
    }
}

void dequeue(Queue *queue) {
    NodeQ *currentElement = queue->first;
    if (currentElement != NULL) {
        queue->first = queue->first->next;
        free(currentElement);
        if (queue->first == NULL) {
            queue->last = NULL;
        }
    }
}

void checkIfOperandOrOperator(Queue *queue, char *value) {
    // if the value is an operand, it will be a leaf of the newly created tree, so I need to insert the "&" character to represent NULL
    if (isdigit(value[0]) || isdigit(value[1])) { //a number can be negative as well -> the first two chars of the operand must be checked
        enqueue(queue, value);
        enqueue(queue, "&");
        enqueue(queue, "&");
    } else {
        enqueue(queue, value);
    }
}

Queue parseMathematicalExpression(FILE *input, Queue *queue) {
    *queue = createQueue();
    while (!feof(input)) {
        char *value = (char *) malloc(sizeof(char));
        fscanf(input, "%s", value);
        checkIfOperandOrOperator(queue, value);
        free(value);
    }
    return *queue;
}