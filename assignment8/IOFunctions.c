//
// Created by Denisa on 5/5/2020.
//
#include "IOFunctions.h"

int* initializeArray(FILE *input, int length) {
    int *array = (int *) malloc(sizeof(int) * length);
    int i;
    for (i = 0; i < length; i++) {
        fscanf(input, "%d", &array[i]);
    }
    return array;
}

void printArrayToFile(FILE *output, int *array, int length) {
    int i;
    for (i = 0; i < length; i++) {
        fprintf(output, "%d ", array[i]);
    }
    fprintf(output, "\n");
}

FILE *openFile(char *path, char *mode) {
    FILE *file = fopen(path, mode);
    if (file == NULL) {
        perror(ERROR_MESSAGE);
        exit(EXIT_FAILURE);
    }
    return file;
}