//
// Created by Denisa on 5/5/2020.
//

#ifndef ASSIGNMENT8_IOFUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

#define ERROR_MESSAGE "The file you were looking for could not be found."

FILE *openFile(char *path, char *mode);
int* initializeArray(FILE *input, int length);
void printArrayToFile(FILE *output, int *array, int length);

#define ASSIGNMENT8_IOFUNCTIONS_H

#endif //ASSIGNMENT8_IOFUNCTIONS_H
