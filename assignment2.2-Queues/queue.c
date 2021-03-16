//
// Created by Denisa on 3/7/2020.
//

#include "queue.h"

Queue createQueue() {
    Queue q;
    q.first = NULL;
    q.last = NULL;
    return q;
}

Customer createCustomer() {
    Customer c;
    c.rubles = 0;
    c.seconds = 0;
    return c;
}

void addCustomer(Queue *customersQueue, Customer customer) {
    if (customersQueue->first == NULL) {
        customersQueue->first = (NodeT *) malloc(sizeof(NodeT));
        customersQueue->first->c = customer;
        customersQueue->first->next = NULL;
        customersQueue->last = customersQueue->first;
    } else {
        NodeT *newCustomer = (NodeT *) malloc(sizeof(NodeT));
        newCustomer->c = customer;
        customersQueue->last->next = newCustomer;
        customersQueue->last = newCustomer;
    }
}

void parseCustomerData(Queue *customersQueue, Customer *customer, FILE *input) {
    char *name = (char *) malloc(MAX_CUSTOMER_NAME * sizeof(char));
    while (!feof(input)) {
        fscanf(input, "%s %d %d", name, &customer->rubles, &customer->seconds);
        addCustomer(customersQueue, *customer);
    }
    free(name);
}

void printCustomers(Queue *customersQueue, FILE *output) {
    if (customersQueue->first == NULL) {
        fprintf(output, "The list is empty! \n");
    } else {
        NodeT *currentElement = customersQueue->first;
        while (currentElement != NULL) {
            fprintf(output, "%d %d \n", currentElement->c.rubles, currentElement->c.seconds);
            currentElement = currentElement->next;
        }
    }
}

void parseTime(int * time, FILE *input, int *noOfTotalElements) {
    char *line = (char *) malloc(MAX_LINE * sizeof(char));
    int index = 0;
    *noOfTotalElements = 0;
    fgets(line, MAX_LINE, input);
    char *delim = strtok(line, " ");
    while (delim != NULL) {
        time[index] = atoi(delim);
        *noOfTotalElements = ++index;
        delim = strtok(NULL, " ");
    }
    free(line);
}

int computeRubles(int time, Queue *customersQueue) {
    NodeT *currentElement = customersQueue->first;
    int sumOfRubles = 0;
    while (time > 0 && currentElement != NULL) {
        time -= currentElement->c.seconds;
        if (time >= 0) sumOfRubles += currentElement->c.rubles;
        currentElement = currentElement->next;
    }
    return sumOfRubles;
}