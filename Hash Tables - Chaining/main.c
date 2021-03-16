#include "hashTable.h"
#include "files.h"


int main() {
    FILE *table = fopen("table.txt", "a");
    FILE *input = fopen("input.txt", "r");
    int N = _100000, j, i;

    float ISF;
    fprintf(table, "For the file %d.data:\n", N);
    fprintf(table, "hashFunction: H3\n");
    char ** content = readFromFile(N);
    for (j = 0; j < 6; j++) {
        fscanf(input, "%f", &ISF);
        INITIAL_HT_SIZE_FACTOR = ISF;
        fprintf(table, "For ISF %.2f: Standard Deviation ---------------------- ", INITIAL_HT_SIZE_FACTOR);
        hashTable = initHashTable(N);
        for (i = 0; i < N; i++) {
            insertElement(*(content + i));
        }
        computeDistributionsPerBucket(N);
        float SD = computeStandardDeviation(N);
        fprintf(table, "%.2f\n", SD);
    }
    fprintf(table, "\n\n");
    freeArray(content, N);
    fclose(input);
    fclose(table);
    return 0;
}
