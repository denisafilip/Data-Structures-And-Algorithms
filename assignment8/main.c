#include "sortingAlgorithms.h"

#define INPUT_FILE_PATH "../input.txt"
#define OUTPUT_FILE_PATH "../output.txt"

int main() {
    FILE *input = openFile(INPUT_FILE_PATH, "r");
    FILE *output = openFile(OUTPUT_FILE_PATH, "w");

    int length;
    fscanf(input, "%d", &length);
    int *array = initializeArray(input, length), *temp;
    temp = initVars(array);
    bubbleSort(output, temp, length);
    temp = initVars(array);
    quickSortPrint(output, temp, 0, (length - 1), length);
    temp = initVars(array);
    countingSort(output, temp, length);
    temp = initVars(array);
    radixSort(output, temp, length);
    return 0;
}