#include "hashTable.h"
#include "files.h"

int main()
{
    FILE *table = fopen("table", "a");
    FILE *input = fopen("input.txt", "r");
    int N = _100;
    float ISF, MFF;
    fprintf(table, "For the file %d.data:\n", N);
    fprintf(table, "hashFunction: H1\nMax Collisions ------------------------------------ NoOfResizes\n");
    char **content = readFromFile(N);
    for (int j = 0; j < 6; j++) {
        fscanf(input, "%f %f", &ISF, &MFF);
        INITIAL_HT_SIZE_FACTOR = ISF;
        MAX_FILL_FACTOR = MFF;
        fprintf(table, "for ISF %.2f & MFF %.2f\n", INITIAL_HT_SIZE_FACTOR, MAX_FILL_FACTOR);
        int maxCollisions = 0, collisions = 0;
        initHashTable(N);
        for (int i = 0; i < N; i++) {
            collisions = insertElement(content[i]);
            if (maxCollisions < collisions) {
                maxCollisions = collisions;
            }
        }
        fprintf(table, "      %d       ------------------------------------       %d\n", maxCollisions, noOfResizes);

    }
    fprintf(table, "\n\n");
    freeArray(hashTable, size);
    freeArray(content, N);
    fclose(input);
    fclose(table);
    return 0;
}
