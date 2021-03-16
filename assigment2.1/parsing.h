//
// Created by Denisa on 3/7/2020.
//

#ifndef ASSIGMENT2EXERCISE1_PARSING_H
#define ASSIGMENT2EXERCISE1_PARSING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doublyLinkedLists.h"

#define MAX_LINE 100

void parseFromFile(char **nameOfFunction, int *key, char *line);

void callingTheFunctions(FILE *input, FILE *output, List *list);

#endif //ASSIGMENT2EXERCISE1_PARSING_H
