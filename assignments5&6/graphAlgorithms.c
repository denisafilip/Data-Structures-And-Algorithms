//
// Created by Denisa on 4/13/2020.
//

#include "graphAlgorithms.h"
#include "graphTraversals.h"

void prim(FILE *output, int startNode, int noOfVertices, int **adjMatrix) {
    fprintf(output, "\nPrim's algorithm started\n");

    int noOfVerticesVisited = 0, minCost = 0;
    int *visited = initializeArrayWithValues(noOfVertices, UNVISITED);

    edgeT *edges = (edgeT *) malloc(sizeof(edgeT) * (noOfVertices - 1));

    visited[startNode] = VISITED;

    while (noOfVerticesVisited < noOfVertices - 1) {
        edgeT minEdge = getMinEdgeForCurrentlyVisitedNodes(visited, noOfVertices, adjMatrix);
        visited[minEdge.destination] = VISITED;
        edges[noOfVerticesVisited++] = minEdge;
        minCost += minEdge.weight;
    }

    printEdges(output, edges, noOfVerticesVisited);
    fprintf(output, "Cost of MST by Prim's algorithm: %d\n", minCost);
    fprintf(output, "Prim's algorithm ended \n\n");
}

edgeT getMinEdgeForCurrentlyVisitedNodes(const int *visited, int noOfVertices, int **adjMatrix) {
    edgeT minEdge;
    minEdge.weight = MAX;

    for (int i = 0; i < noOfVertices; i++) {
        for (int j = 0; j < noOfVertices; j++) {
            if (visited[i] == VISITED && visited[j] == UNVISITED && adjMatrix[i][j] > 0) {
                if (adjMatrix[i][j] < minEdge.weight) {
                    minEdge.source = i;
                    minEdge.destination = j;
                    minEdge.weight = adjMatrix[i][j];
                }
            }
        }
    }
    return minEdge;
}

void printEdges(FILE *output, edgeT *edges, int n) {
    for (int i = 0; i < n; i++) {
        fprintf(output, "%c -> %c\t", edges[i].source + 'A', edges[i].destination + 'A');
    }
    fprintf(output, "\n");
}

void dijkstra(FILE *output, int startNode, int noOfVertices, int **adjMatrix) {
    fprintf(output, "Dijkstra's Algorithm started\n");

    int *distances = initializeArrayWithValues(noOfVertices, MAX);
    int *previous = initializeArrayWithValues(noOfVertices, UNDEFINED);
    int *visited = initializeArrayWithValues(noOfVertices, UNVISITED);
    int nrOfVerticesVisited = 0, i;
    distances[startNode] = 0;

    while (nrOfVerticesVisited < noOfVertices) {
        int u = getMinDistanceVertex(noOfVertices, distances, visited);
        visited[u] = VISITED;

        int noOfNeighbours = getNumberOfNeighboursOfVertex(noOfVertices, adjMatrix, u);
        int *neighbours = getAllNeighboursOfVertex(noOfVertices, adjMatrix, u);
        for (i = 0; i < noOfNeighbours; i++) {
            int w = neighbours[i];
            int alt = distances[u] + adjMatrix[u][w];
            if (alt < distances[w]) {
                distances[w] = alt;
                previous[w] = u;
            }
        }
        nrOfVerticesVisited++;
    }
    printShortestPath(output, noOfVertices, startNode, previous, distances);
    fprintf(output, "Dijkstra's Algorithm ended\n");
}

int getMinDistanceVertex(int noOfVertices, const int *distances, const int *visited) {
    int min = MAX, i;
    int minV = 0;
    for (i = 0; i < noOfVertices; i++) {
        if (distances[i] <= min && visited[i] == UNVISITED) {
            min = distances[i];
            minV = i;
        }
    }
    return minV;
}

//Kruskal algorithm, implemented with the help of the skeleton code

void kruskal(FILE *output, int noOfVertices, int **adjMatrix) {
    fprintf(output, "\nKruskal algorithm started:\n");
    int **adjMat = getCopyOfAdjacencyMatrix(noOfVertices, adjMatrix);
    edgeT *edges = (edgeT *) malloc(sizeof(edgeT) * (noOfVertices - 1));
    int *parent = initializeParentArray(noOfVertices);
    int minCost = 0, noOfEdges = 0;

    while (noOfEdges < noOfVertices - 1) {
        edgeT minEdge = getMinimumEdgeForAdjacencyMatrix(noOfVertices, adjMat, parent);
        if (uni(parent, minEdge.source, minEdge.destination)) {
            minCost += minEdge.weight;
            edges[noOfEdges++] = minEdge;
        }
    }
    printEdges(output, edges, noOfEdges);
    fprintf(output, "The cost of MST by Kruskal's Algorithm: %d", minCost);
    fprintf(output, "\nKruskal algorithm ended\n\n");
}

int *initializeParentArray(int noOfVertices) {
    int *parent = (int *) malloc(noOfVertices * sizeof(int));
    for (int i = 0; i < noOfVertices; i++) {
        parent[i] = 0;
    }
    return parent;
}

edgeT getMinimumEdgeForAdjacencyMatrix(int noOfVertices, int **adjMat, int *parent) {
    edgeT minEdge;
    minEdge.weight = MAX;

    for (int i = 0; i < noOfVertices; i++) {
        for (int j = 0; j < noOfVertices; j++) {
            if (adjMat[i][j] < minEdge.weight && adjMat[i][j] != 0 && getParent(parent, i) != getParent(parent, j)) {
                minEdge.weight = adjMat[i][j];
                minEdge.source = i;
                minEdge.destination = j;
            }
        }
    }
    adjMat[minEdge.source][minEdge.destination] = 0;
    adjMat[minEdge.destination][minEdge.source] = 0;
    return minEdge;
}

int **getCopyOfAdjacencyMatrix(int noOfVertices, int **adjMatrix) {
    int i, j;
    int **copyAdjMatrix = (int **) malloc(noOfVertices * sizeof(int *));
    for (i = 0; i < noOfVertices; i++) {
        *(copyAdjMatrix + i) = (int *) malloc(noOfVertices * sizeof(int));
        for (j = 0; j < noOfVertices; j++) {
            copyAdjMatrix[i][j] = adjMatrix[i][j];
        }
    }
    return copyAdjMatrix;
}

int getParent(const int *parent, int vertex) {
    while (parent[vertex]) {
        vertex = parent[vertex];
    }
    return vertex;
}

int uni(int *parent, int i, int j) {
    i = getParent(parent, i);
    j = getParent(parent, j);
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

//Bellman-Ford algorithm for directed graphs that can have a negative weights as well -- inspiration from geeksforgeeks

void bellmanFord(FILE *output, int startNode, int noOfVertices, int **adjMatrix) {
    fprintf(output, "Bellman-Ford algorithm started: \n");
    int *distances = initializeArrayWithValues(noOfVertices, MAX);
    int *previous = initializeArrayWithValues(noOfVertices, UNDEFINED);
    distances[startNode] = 0;
    int noOfEdges = computeNoOfEdges(noOfVertices, adjMatrix);
    edgeT *edges = getEdges(noOfVertices, adjMatrix, noOfEdges);

    for (int i = 0; i < noOfVertices; i++) {
        for (int j = 0; j < noOfEdges; j++) {
            int u = edges[j].source;
            int v = edges[j].destination;
            int alt = distances[u] + edges[j].weight;
            if (alt < distances[v]) {
                distances[v] = alt;
                previous[v] = u;
            }
        }
    }

    //if there is a negative cycle, print a message; otherwise, print the shortest paths with their respective costs
    if (checkIfNegativeCycles(distances, noOfEdges, edges) == 1) {
        fprintf(output, "The graph contains a negative weight cycle.\n");
    } else {
        printShortestPath(output, noOfVertices, startNode, previous, distances);
    }
    fprintf(output, "Bellman-Ford algorithm ended. \n");
}

void printShortestPath(FILE *output, int noOfVertices, int startNode, const int *previous, const int *distances) {
    for (int i = 0; i < noOfVertices; i++) {
        int u = i;
        if (i != startNode) {
            while (previous[u] != UNDEFINED) {
                push(u);
                u = previous[u];
            }
            fprintf(output, "Path from %c to %c is: %c", startNode + 'A', i + 'A', startNode + 'A');
            while (!isEmptyStack()) {
                fprintf(output, " -> %c", peekStack()->data + 'A');
                pop();
            }
            fprintf(output, ", with the cost %d.\n", distances[i]);
        }
    }
}

int computeNoOfEdges(int noOfVertices, int **adjMatrix) {
    int noOfEdges = 0, i, j;
    for (i = 0; i < noOfVertices; i++) {
        for (j = 0; j < noOfVertices; j++) {
            if (adjMatrix[i][j] != 0) {
                noOfEdges++;
            }
        }
    }
    return noOfEdges;
}

edgeT *getEdges(int noOfVertices, int **adjMatrix, int noOfEdges) {
    edgeT *edges = (edgeT *) malloc(sizeof(edgeT) * noOfEdges);
    int index = 0;
    for (int i = 0; i < noOfVertices; i++) {
        for (int j = 0; j < noOfVertices; j++) {
            if (adjMatrix[i][j] != 0) {
                edges[index].source = i;
                edges[index].destination = j;
                edges[index].weight = adjMatrix[i][j];
                index++;
            }
        }
    }
    return edges;
}

int checkIfNegativeCycles(const int *distances, int noOfEdges, edgeT *edges) {
    for (int i = 0; i < noOfEdges; i++) {
        int u = edges[i].source;
        int v = edges[i].destination;
        int alt = edges[i].weight + distances[u];
        if (alt < distances[v]) {
            return 1;
        }
    }
    return 0;
}

//approximation algorithm for vertex cover

void vertexCover(FILE *output, int noOfVertices, int **adjMatrix) {
    fprintf(output, "\nVertices covered by the approximation algorithm for vertex cover:\n");
    int *visited = initializeArrayWithValues(noOfVertices, UNVISITED);
    for (int i = 0; i < noOfVertices; i++) {
        if (visited[i] == UNVISITED) {
            int noOfNeighbours = getNumberOfNeighboursOfVertex(noOfVertices, adjMatrix, i);
            int *neighbours = getAllNeighboursOfVertex(noOfVertices, adjMatrix, i);
            for (int j = 0; j < noOfNeighbours; j++) {
                int w = neighbours[j];
                if (adjMatrix[i][w] > 0 && visited[w] == UNVISITED) {
                    visited[i] = VISITED;
                    visited[w] = VISITED;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < noOfVertices; i++) {
        if (visited[i] == VISITED) {
            fprintf(output, "%c ", 'A' + i);
        }
    }
    fprintf(output, "\nVertex cover approximation algorithm ended.\n");
}

///Floyd-Warshall algorithm (The All-Pairs Shortest Paths Problem)
void floydWarshall(FILE *output, int V, int **adjMatrix) {
    int **dist = (int **) malloc(sizeof(int *) * V);
    int i, j, k;
    for (i = 0; i < V; i++) {
        dist[i] = (int *) malloc(sizeof(int) * V);
        for (j = 0; j < V; j++) {
            dist[i][j] = adjMatrix[i][j];
        }
    }

    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    printSolution(output, dist, V);
}

void printSolution(FILE *output, int **dist, int V) {
    fprintf(output, "Floyd-Warshall algorithm:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == MAX) {
                fprintf(output, "INF");
            } else {
                fprintf(output, "%d", dist[i][j]);
            }
        }
        fprintf(output, "\n");
    }
}