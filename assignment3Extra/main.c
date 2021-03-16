#include "tree.h"

#define INPUT_FILE_PATH "../input.dat"
#define ERROR_MESSAGE "Sorry, the file could not be found"

FILE *openFile (char *name, char *mode);

int main() {
    FILE *input = openFile(INPUT_FILE_PATH, "r");
    Queue myQueue = parseMathematicalExpression(input, &myQueue);
    NodeT *root = createBinTree(&myQueue);
    printTree(root, 0);
    fclose(input);
    return 0;
}

FILE *openFile (char *name, char *mode) {
    FILE *newFile = fopen(name, mode);
    if (newFile == NULL) {
       perror(ERROR_MESSAGE);
       exit(EXIT_FAILURE);
    }
}