//
// Created by Denisa on 3/7/2020.
//

#ifndef ASSIGNMENT2QUEUES_QUEUE_H
#define ASSIGNMENT2QUEUES_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMER_NAME 50
#define MAX_LINE 256
#define MAX_TIME 10

typedef struct customer {
    int rubles;
    int seconds;
} Customer;

typedef struct node {
    Customer c;
    struct node *next;
} NodeT;

typedef struct queue {
    NodeT *first;
    NodeT *last;
} Queue;

Customer createCustomer();

Queue createQueue();

void addCustomer(Queue *customersQueue, Customer customer);

void parseCustomerData(Queue *customersQueue, Customer *customer, FILE *input);

void printCustomers(Queue *customersQueue, FILE *output);

void parseTime(int * time, FILE *input, int *noOfTotalElements);

int computeRubles(int time, Queue *customersQueue);

#endif //ASSIGNMENT2QUEUES_QUEUE_H
