//
// Created by Denisa on 4/5/2020.
//

#ifndef ASSIGNMENT5_LONGESTPATH_H

#include "graphTraversals.h"

void longestPathUtility(FILE *output, List *adjList, int noOfVertices, int startNode, int destinationNode);

void longestSimplePathRec(List *adjList, List *longestPath, List *currentPath, int startNode, int destinationNode, int *visited);

#define ASSIGNMENT5_LONGESTPATH_H

#endif //ASSIGNMENT5_LONGESTPATH_H
