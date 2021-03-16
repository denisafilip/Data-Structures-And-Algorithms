#include "graphTraversals.h"
#include "graphAlgorithms.h"
#include "longestPath.h"
#include "heap.h"

#define INPUT_FILE_PATH "../input.txt"
#define OUTPUT_FILE_PATH "../output.txt"
#define ERROR_FILE_MESSAGE "Sorry, the file you were looking for could not be found"

FILE *openFile(char *filePath, char *mode);

int main() {
    FILE *input = openFile(INPUT_FILE_PATH, "r");
    FILE *output = openFile(OUTPUT_FILE_PATH, "w");

    int noOfVertices = getNumberOfVertices(input);
    int **adjMatrix = getAdjMatrix(noOfVertices, input);
    printAdjMatrix(output, noOfVertices, adjMatrix);

    bfsMatrix(output, 'G' - 'A', noOfVertices, adjMatrix);
    dfsRecUtilityMatrix(output, 'G' - 'A', noOfVertices, adjMatrix);

    List *adjList = fromMatrixToList(noOfVertices, adjMatrix);
    printEntireAdjList(output, adjList, noOfVertices);

    bfsList(output, 'G' - 'A', noOfVertices, adjList);
    dfsRecUtilityList(output, 'G'- 'A', noOfVertices, adjList);

    longestPathUtility(output, adjList, noOfVertices, 'B' - 'A', 'D' - 'A');

    adjMatrix = fromListToMatrix(noOfVertices, adjList);
    printAdjMatrix(output, noOfVertices, adjMatrix);

    prim(output, 'E' - 'A', noOfVertices, adjMatrix);
    dijkstra(output, 'E' - 'A', noOfVertices, adjMatrix);
    kruskal(output, noOfVertices, adjMatrix);
    bellmanFord(output, 'E' - 'A', noOfVertices, adjMatrix);
    vertexCover(output, noOfVertices, adjMatrix);

    BinHeapT *h = createBinHeap(12);
    insertBinHeap(h, 1);
    insertBinHeap(h, 3);
    insertBinHeap(h, 2);
    insertBinHeap(h, 4);
    insertBinHeap(h, 5);
    insertBinHeap(h, 1);
    insertBinHeap(h, 7);
    insertBinHeap(h, 5);
    printHeap(h);
    fclose(output);
    return 0;
}

FILE *openFile(char *filePath, char *mode) {
    FILE *file = fopen(filePath, mode);
    if (file == NULL) {
        perror(ERROR_FILE_MESSAGE);
        exit(EXIT_FAILURE);
    }
}

