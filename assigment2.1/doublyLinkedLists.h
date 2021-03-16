//
// Created by Denisa on 3/4/2020.
//

#ifndef ASSIGMENT2EXERCISE1_DOUBLYLINKEDLISTS_H
#define ASSIGMENT2EXERCISE1_DOUBLYLINKEDLISTS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} NodeT;

typedef struct list {
    NodeT *first;
    NodeT *last;
} List;

List createList();

void addFirst(List *list, int x);

void addLast(List *list, int x);

void deleteFirst(List *list);

void deleteLast(List *list);

void removeList(List *list); //DOOM_THE_LIST

void deleteElement(List *list, int x);

void printAll(FILE *output, List *list);

void printFirst(FILE *output, List *list, int x);

void printLast(FILE *output, List *list, int x);

void reverseList(FILE *output, List *list);

#endif //ASSIGMENT2EXERCISE1_DOUBLYLINKEDLISTS_H
