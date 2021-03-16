//
// Created by Denisa on 4/4/2020.
//

#ifndef ASSIGNMENT5_GRAPHREPRESENTATION_H

#include "graph.h"
#include "list.h"

int getNumberOfVertices(FILE *input);

int **getAdjMatrix(int noOfVertices, FILE *input);

void printAdjMatrix(FILE *output, int noOfVertices, int **adjMatrix);

int getNumberOfNeighboursOfVertex(int noOfVertices, int **adjMatrix, int v);

int *getAllNeighboursOfVertex(int noOfVertices, int **adjMatrix, int v);

List *fromMatrixToList(int noOfVertices, int **adjMatrix);

void freeAdjMatrix(int noOfVertices, int **adjMatrix);

int **fromListToMatrix(int noOfVertices, List *adjList);

void computeInitializedMatrix(int noOfVertices, int **adjMatrix);

int **getAllocatedMatrix(int noOfVertices);

#define ASSIGNMENT5_GRAPHREPRESENTATION_H

#endif //ASSIGNMENT5_GRAPHREPRESENTATION_H
