//
// Created by Denisa on 4/4/2020.
//

#ifndef ASSIGNMENT5_LIST_H

#include "node.h"

typedef struct nodeList {
    int start, destination, weight; //the start node, destination node and weight for each edge
    int *neighbours;    //an array that stores the neighbours of each node of the adjacency list -> using it for traversals
    struct nodeList *next;
} NodeL;

typedef struct adjList {
    int noOfNodes;  //the number of nodes for each adjacency list
    NodeL *first, *last;
} List;

List *createList(int noOfVertices);

NodeL *createNodeForList(int start, int destination, int weight);

void addLast(List *adjList, int start, int destination, int weight);

void deleteLast(List *adjList);

void doomTheList(List *adjList);

void printList(List adjList, FILE *output);

void printPath(List list, FILE *output);

void printEntireAdjList(FILE *output, List *adjList, int noOfVertices);

#define ASSIGNMENT5_LIST_H

#endif //ASSIGNMENT5_LIST_H
