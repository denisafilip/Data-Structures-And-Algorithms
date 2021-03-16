//
// Created by Denisa on 3/7/2020.
//

#include "parsing.h"

void parseFromFile(char **nameOfFunction, int *key, char *line) {
    char *p = strtok(line, " \n");
    strcpy(*nameOfFunction, p);
    p = strtok(NULL, " \n");
    if (p != NULL) {
        sscanf(p, "%d", &(*key));
    } else {
        *key = 0;
    }
}

void callingTheFunctions(FILE *input, FILE *output, List *list) {
    int key = 0;
    char *nameOfFunction = (char *) malloc(MAX_LINE * sizeof(char));
    char *line = (char *) malloc(MAX_LINE * sizeof(char));
    while (fgets(line, MAX_LINE, input)) {
        parseFromFile(&nameOfFunction, &key, line);
        if (strcmp(nameOfFunction, "AF") == 0) {
            addFirst(list, key);
        } else if (strcmp(nameOfFunction, "AL") == 0) {
            addLast(list, key);
        } else if (strcmp(nameOfFunction, "DF") == 0) {
            deleteFirst(list);
        } else if (strcmp(nameOfFunction, "DL") == 0) {
            deleteLast(list);
        } else if (strcmp(nameOfFunction, "DOOM_THE_LIST") == 0) {
            removeList(list);
        } else if (strcmp(nameOfFunction, "DE") == 0) {
            deleteElement(list, key);
        } else if (strcmp(nameOfFunction, "PRINT_ALL") == 0) {
            printAll(output, list);
        } else if (strcmp(nameOfFunction, "PRINT_F") == 0) {
            printFirst(output, list, key);
        } else if (strcmp(nameOfFunction, "PRINT_L") == 0) {
            printLast(output, list, key);
        } else if (strcmp(nameOfFunction, "REVERSE") == 0) {
            reverseList(output, list);
        }
    }
}