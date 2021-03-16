//
// Created by Denisa on 4/4/2020.
//

#ifndef ASSIGNMENT5_GRAPHTRAVERSALS_H

#include "graphRepresentation.h"

int *initializeArrayWithValues(int noOfVertices, int value);

void bfsMatrix(FILE *output, int startNode, int noOfVertices, int **adjMatrix);

void bfsList(FILE *output, int startNode, int noOfVertices, List *adjList);

int BFS(int source, int dest, int noOfVertices, int **adjMatrix);

void dfsRecMatrix(FILE *output, int v, int *visited, int noOfVertices, int **adjMatrix);

void dfsRecUtilityMatrix(FILE *output, int startNode, int noOfVertices, int **adjMatrix);

void dfsRecList(FILE *output, int v, int *visited, int noOfVertices, List *adjList);

void dfsRecUtilityList(FILE *output, int startNode, int noOfVertices, List *adjList);
#define ASSIGNMENT5_GRAPHTRAVERSALS_H

#endif //ASSIGNMENT5_GRAPHTRAVERSALS_H
