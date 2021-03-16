#include "hashTable.h"


listT* initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/3 of N)
    //! also the size variable has to be initialized
    sizeOfHashTable = N * INITIAL_HT_SIZE_FACTOR;
    hashTable = (listT *) malloc(sizeOfHashTable * sizeof(listT));
    for (int i = 0; i < sizeOfHashTable; i++) {
        hashTable[i].sizeOfList = 0;
        hashTable[i].head = NULL;
        hashTable[i].tail = NULL;
    }
    return hashTable;
}

void insertElement(char * element)
{
    //! insert an element
    int index = H3(element);
    addToList(&hashTable[index], element);
}

int H1(char *content)
{
    //! keep in mind, size in this case simply means the number of buckets
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++) {
        sum += content[k];
    }
    return sum % sizeOfHashTable;
}

int H0(char *content) {
    return content[0]%2;
}

int H2(char *content) {
    int hash = 5381;
    int i = 0;
    int length = strlen(content);
    for (i = 0; i < length; i++) {
        hash = ((hash << 5) + hash) + content[i];
    }

    return abs(hash) % sizeOfHashTable;
}

int H3(char *content) {
    long sum = 0, mul = 1, k;
    int length = strlen(content);
    for (k = 0; k < length; k++) {
        mul = (k % 4 == 0) ? 1 : mul * 256;
        sum += content[k]*mul;
    }
    return abs(sum) % sizeOfHashTable;
}

void computeDistributionsPerBucket(int N)
{
    //! computes the distribution of elements for each bucket
    //! the output should look something like:
    /**
        MAX = 'x' * 20

        B0: ********** (~50%)
        B1: ************ (~60%)
        B2: ****** (~30%)
        B3: ******* (~35%)
        .....


        hint : the bigger you choose X, the better approximation
        hint2: choose it somewhere between 20-40 such that it fits in one row in the console nicely
    */
    //int X = 30;
    for (int i = 0; i < sizeOfHashTable; i++) {
        float fraction = (float)hashTable[i].sizeOfList/N;
        float percentage = fraction*100;
        printf("B%d: ", i);
        printf("(~%.2f%%) \n", percentage);
    }
    printf("\n\n");

}

float computeStandardDeviation(int N) {
    float sum = 0.0, mean = 0.0, sigma = 0.0;
    for (int i = 0; i < sizeOfHashTable; i++) {
        sum += hashTable[i].sizeOfList;
    }
    mean = sum/sizeOfHashTable;
    sum = 0.0;
    for (int i = 0; i < sizeOfHashTable; i++) {
        sum += (hashTable[i].sizeOfList - mean)*(hashTable[i].sizeOfList - mean);
    }
    sigma = sqrt(sum/sizeOfHashTable);
    return sigma;
}

void freeArray(char **contents, int length) {
    for (int i = 0; i < length; i++) {
        free(contents[i]);
    }
    free(contents);
}
