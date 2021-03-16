//
// Created by Denisa on 4/4/2020.
//
#include "list.h"
#define MAX_NO_OF_NEIGHBOURS 20

List *createList(int noOfVertices) {
    //creates an array with the adjacency list of each node
    List *newList = (List *) malloc(noOfVertices * sizeof(List));
    for (int i = 0; i < noOfVertices; i++) {
        newList[i].noOfNodes = 0;
        newList[i].first = NULL;
        newList[i].last = NULL;
    }
    return newList;
}

NodeL *createNodeForList(int start, int destination, int weight) {
    NodeL *newNode = (NodeL *) malloc(sizeof(NodeL));
    newNode->start = start;
    newNode->destination = destination;
    newNode->weight = weight;
    newNode->neighbours = (int *) malloc(MAX_NO_OF_NEIGHBOURS * sizeof(int));
    newNode->next = NULL;
    return newNode;
}

void addLast(List *adjList, int start, int destination, int weight) {
    NodeL *newElement = createNodeForList(start, destination, weight);
    if (adjList->first == NULL) {
        adjList->first = newElement;
        adjList->last = adjList->first;
    } else {
        adjList->last->next = newElement;
    }
    adjList->first->neighbours[adjList->noOfNodes] = newElement->destination;
    adjList->last = newElement;
    adjList->noOfNodes++;

}

void deleteLast(List *adjList) {
    if (adjList->last != NULL) {
        NodeL *currentElement = adjList->first;
        NodeL *previousElement = adjList->first;
        if (currentElement) {
            while (currentElement != adjList->last) {
                previousElement = currentElement;
                currentElement = currentElement->next;
            }
            if (currentElement == adjList->first) {
                adjList->first = adjList->last = NULL;
            } else {
                previousElement->next = NULL;
            }
            adjList->last = previousElement;
            free(currentElement);
            adjList->noOfNodes--;
        }
    }
}

void doomTheList(List *adjList) {
    NodeL *currentElement = adjList->first;
    while (currentElement != NULL) {
        adjList->first = adjList->first->next;
        free(currentElement);
        currentElement = adjList->first;
    }
    adjList->first = NULL;
    adjList->last = NULL;
}

void printList(List adjList, FILE *output) {
    if (adjList.first == NULL) {
        fprintf(output, "This list is empty! \n");
    } else {
        NodeL *currentElement = adjList.first;
        fprintf(output, "%c: ", 'A' + currentElement->start);
        while (currentElement) {
            fprintf(output, "(%c, %d) ", 'A' + currentElement->destination, currentElement->weight);
            currentElement = currentElement->next;
        }
        fprintf(output, "\n");
    }
}

void printPath(List list, FILE *output) {
    if (list.first == NULL) {
        fprintf(output, "There is no path! \n");
    } else {
        NodeL *currentElement = list.first;
        while (currentElement) {
            fprintf(output, "%c ", 'A' + currentElement->destination);
            currentElement = currentElement->next;
        }
    }
}

void printEntireAdjList(FILE *output, List *adjList, int noOfVertices) {
    fprintf(output, "The adjacency list representation:\n");
    for (int i = 0; i < noOfVertices; i++) {
        printList(adjList[i], output);
    }
}