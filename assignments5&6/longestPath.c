//
// Created by Denisa on 4/5/2020.
//
#include "longestPath.h"

void longestPathUtility(FILE *output, List *adjList, int noOfVertices, int startNode, int destinationNode) {
    fprintf(output, "\nThe search for the longest path started:\n");
    int *visited = initializeArrayWithValues(noOfVertices, UNVISITED);
    List *longestPath = createList(1);
    List *currentPath = createList(1);

    addLast(currentPath, startNode, startNode, 0);  //adding the startNode
    longestSimplePathRec(adjList, longestPath, currentPath, startNode, destinationNode, visited);

    printPath(*longestPath, output);
    fprintf(output, "\nThe search for the longest path ended.\n");
}

//I use dfs (a bit modified) to search for the longest path. Looked everywhere on the internet for an alternative and faster solution, but to no avail. Found some interesting things for directed acyclic graphs, though
void longestSimplePathRec(List *adjList, List *longestPath, List *currentPath, int startNode, int destinationNode, int *visited) {
    if (startNode == destinationNode) {
        if (currentPath->noOfNodes > longestPath->noOfNodes) {    //if a longer path was found, then I update the longestPath list
            doomTheList(longestPath);   //deleting the previous contents of longestPath
            NodeL *currentElement = currentPath->first; //moving the contents of currentPath into longestPath
            while (currentElement != NULL) {
                addLast(longestPath, currentElement->start, currentElement->destination, 0);
                currentElement = currentElement->next;
            }
            longestPath->noOfNodes = currentPath->noOfNodes;  //updating the number of nodes of the longestPath
        }
    } else {
        visited[startNode] = VISITED;
        int *neighbours = adjList[startNode].first->neighbours;
        int noOfNeighbours = adjList[startNode].noOfNodes;
        for (int i = 0; i < noOfNeighbours; i++) {
            int w = neighbours[i];
            if (visited[w] == UNVISITED) {
                addLast(currentPath, startNode, w, 0);  //for the sake of simplicity, I ignore the weights here because I don't really need them
                longestSimplePathRec(adjList, longestPath, currentPath, w, destinationNode, visited);   //calling the recursive function again, now with the unvisited node w as the startNode
                deleteLast(currentPath);
            }
        }
        visited[startNode] = UNVISITED; //marking the startNode as unvisited, in case I will go through it when looking for another path
    }
}
