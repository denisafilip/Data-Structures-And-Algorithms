#include "doublyLinkedLists.h"
#include "parsing.h"

#define FILE_PATH_INPUT "../input.dat"
#define FILE_PATH_OUTPUT "../output.dat"
#define FILE_ERROR "sorry, the file could not be found"

int main() {
    FILE *input = fopen(FILE_PATH_INPUT, "r");
    if (input == NULL) {
        perror(FILE_ERROR);
        exit(EXIT_FAILURE);
    }
    FILE *output = fopen(FILE_PATH_OUTPUT, "w");
    if (output == NULL) {
        perror(FILE_ERROR);
        exit(EXIT_FAILURE);
    }

    List list = createList();

    callingTheFunctions(input, output, &list);
    return 0;
}