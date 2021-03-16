//
// Created by Denisa on 4/13/2020.
//

#ifndef ASSIGNMENT5_GRAPHALGORITHMS_H

#include "graph.h"

void prim(FILE *output, int startNode, int noOfVertices, int **adjMatrix);
edgeT getMinEdgeForCurrentlyVisitedNodes(const int *visited, int noOfVertices, int **adjMatrix);
void printEdges(FILE *output, edgeT *edges, int n);

void dijkstra(FILE *output, int startNode, int noOfVertices, int **adjMatrix);
int getMinDistanceVertex(int noOfVertices, const int *distances, const int *visited);

void kruskal(FILE *output, int noOfVertices, int **adjMatrix);
int *initializeParentArray(int noOfVertices);
edgeT getMinimumEdgeForAdjacencyMatrix(int noOfVertices, int **adjMat, int *parent);
int getParent(const int *parent, int vertex);
int uni(int *parent, int i, int j);
int **getCopyOfAdjacencyMatrix(int noOfVertices, int **adjMatrix);

void bellmanFord(FILE *output, int startNode, int noOfVertices, int **adjMatrix);
int computeNoOfEdges(int noOfVertices, int **adjMatrix);
edgeT *getEdges(int noOfVertices, int **adjMatrix, int noOfEdges);
int checkIfNegativeCycles(const int *distances, int noOfEdges, edgeT *edges);
void printShortestPath(FILE *output, int noOfVertices, int startNode, const int *previous, const int *distances);

void vertexCover(FILE *output, int noOfVertices, int **adjMatrix);

void floydWarshall(FILE *output, int V, int **adjMatrix);
void printSolution(FILE *output, int **dist, int V);

#define ASSIGNMENT5_GRAPHALGORITHMS_H

#endif //ASSIGNMENT5_GRAPHALGORITHMS_H
