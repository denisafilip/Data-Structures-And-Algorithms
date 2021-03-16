#include "queue.h"

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

    int *time = (int *) malloc(MAX_TIME * sizeof(int));
    int noOfTotalElements = 0;

    parseTime(time, input, &noOfTotalElements);

    Customer customer = createCustomer();

    Queue customersQueue = createQueue();

    parseCustomerData(&customersQueue, &customer, input);

    for (int i = 0; i < noOfTotalElements; i++) {
        fprintf(output, "After %d seconds: %d\n", time[i], computeRubles(time[i], &customersQueue));
    }

    fclose(input);
    fclose(output);
    return 0;
}