//
// Created by Denisa on 4/4/2020.
//


#include "graphRepresentation.h"

int getNumberOfVertices(FILE *input) {
    int noOfVertices;
    fscanf(input, "%d", &noOfVertices);
    return noOfVertices;
}

int **getAdjMatrix(int noOfVertices, FILE *input) {
    int **adjMatrix = getAllocatedMatrix(noOfVertices);
    for (int i = 0; i < noOfVertices; i++) {
        for (int j = 0; j < noOfVertices; j++) {
            fscanf(input, "%3d", &adjMatrix[i][j]);
        }
    }
    fclose(input);
    return adjMatrix;
}

void printAdjMatrix(FILE *output, int noOfVertices, int **adjMatrix) {
    fprintf(output, "\nThe matrix is:\n");
    fprintf(output, "    ");
    for (int i = 0; i < noOfVertices; i++) {
        fprintf(output, "%c   ", 'A' + i);
    }
    fprintf(output, "\n");
    for (int i = 0; i < noOfVertices; i++) {
        fprintf(output, "%c ", 'A' + i);
        for (int j = 0; j < noOfVertices; j++) {
            fprintf(output, "%3d ", adjMatrix[i][j]);
        }
        fprintf(output, "\n");
    }
}

int getNumberOfNeighboursOfVertex(int noOfVertices, int **adjMatrix, int v) {
    if (v < noOfVertices) {
        int noOfNeighbours = 0;
        for (int i = 0; i < noOfVertices; i++) {
            if (adjMatrix[v][i] > 0 && i != v) {
                noOfNeighbours++;
            }
        }
        return noOfNeighbours;
    } else {
        return 0;
    }
}

int *getAllNeighboursOfVertex(int noOfVertices, int **adjMatrix, int v) {
    if (v < noOfVertices) {
        int noOfNeighbours = getNumberOfNeighboursOfVertex(noOfVertices, adjMatrix, v);
        int *neighbours = (int *) malloc(noOfNeighbours * sizeof(int));
        int j = 0, i;
        for (i = 0; i < noOfVertices; i++) {
            if (adjMatrix[v][i] > 0 && i != v) {
                neighbours[j] = i;
                j++;
            }
        }
        return neighbours;
    } else {
        return NULL;
    }
}

List *fromMatrixToList(int noOfVertices, int **adjMatrix) {
    List *adjList = createList(noOfVertices);
    for (int i = 0; i < noOfVertices; i++) {
        for (int j = 0; j < noOfVertices; j++) {
            if (adjMatrix[i][j]) {
                addLast(&adjList[i], i, j, adjMatrix[i][j]);
            }
        }
    }
    freeAdjMatrix(noOfVertices, adjMatrix);
    return adjList;
}

void freeAdjMatrix(int noOfVertices, int **adjMatrix) {
    for (int i = 0; i < noOfVertices; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
}

void computeInitializedMatrix(int noOfVertices, int **adjMatrix) {
    //initializes the entire matrix with 0, to avoid random values in the positions where there isn't a node
    for (int i = 0; i < noOfVertices; i++) {
        for (int j = 0; j < noOfVertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

int **getAllocatedMatrix(int noOfVertices) {
    int **adjMatrix = (int **) malloc(noOfVertices * sizeof(int *));
    for (int i = 0; i < noOfVertices; i++) {
        adjMatrix[i] = (int *) malloc(noOfVertices * sizeof(int));
    }
    return adjMatrix;
}

int **fromListToMatrix(int noOfVertices, List *adjList) {
    int **adjMatrix = getAllocatedMatrix(noOfVertices);
    computeInitializedMatrix(noOfVertices, adjMatrix);
    for (int i = 0; i < noOfVertices; i++) {
        NodeL *currentElement = adjList[i].first;
        for (int j = 0; j < noOfVertices && currentElement != NULL; j++) {
            if (j == currentElement->destination) {
                adjMatrix[i][j] = currentElement->weight;
                currentElement = currentElement->next;
            } else {
                adjMatrix[i][j] = 0;
            }
        }
    }
    free(adjList);
    return adjMatrix;
}