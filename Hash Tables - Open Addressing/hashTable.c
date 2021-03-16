#include "hashTable.h"


void initHashTable(int N) {
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/4 of N)
    size = N * INITIAL_HT_SIZE_FACTOR;
    hashTable = (char **) malloc(size * sizeof(char*));
    for (int i = 0; i < size; i++) {
        hashTable[i] = NULL;
    }
    noOfResizes = 0;
}

float getFillFactor() {
    //! return the fill factor of the hash table
    float fillFactor;
    int i, noOfElements = 0;
    for (i = 0; i < size; i++) {
        if (hashTable[i] != NULL) {
            noOfElements = noOfElements + 1;
       }
    }
    fillFactor = (float) noOfElements/(float) size;    //the number of elements inserted in the hash tabled divided by the number of buckets
    return fillFactor;
}

void resizeHashTable() {
    //! reconstruct the hash table by (usually) doubling its size
    //! only call this when the current fill factor of your hash table > MAX_FILL_FACTOR

    //! careful, when resizing, the 'size' variable should be changed as well such that the 'hashFunction's distribution will work
    //! be double careful! all the elements which are already in the hash table have to  be RE-hashed! (explanation @ lab)

    noOfResizes++;
    char **prevHashTable = hashTable;
    int prevSize = size;
    size = size*2;
    int i, j;
    //resizing and initializing the new hash table
    hashTable = (char **) malloc(size * sizeof(char*));
    for (i = 0; i < size; i++) {
        hashTable[i] = NULL;
    }
    for (j = 0; j < prevSize; j++) {
        if (prevHashTable[j] != NULL) {
            insertElement(prevHashTable[j]);
            free(prevHashTable[j]);
        }
    }
    free(prevHashTable);
}

void freeArray(char **contents, int length) {
    for (int i = 0; i < length; i++) {
        free(contents[i]);
    }
    free(contents);
}

int insertElement(char * element) {
    //! insert an element
    //! returns the number of collisions which occurred before the element was inserted
    int len = strlen(element);
    int index, i = 0;
    float fillFactor = 0;
    bool isInserted = false;
    while (isInserted == false) {
        index = H1(element, i);
        if (hashTable[index] == NULL) {
            hashTable[index] = (char *) malloc((len + 1) * sizeof(char));
            strcpy(hashTable[index], element);
            fillFactor = getFillFactor();   //resizing if the current fill factor is greater than the max one
            if (fillFactor > MAX_FILL_FACTOR) {
                resizeHashTable();
            }
            isInserted = true;
            return i;
        }
        i++;
    }
}

int hashFunction(char * content, int i) {
    return i % size;
}

int H1(char * content, int i) {
    int length = strlen(content);
    int k, sum;
    for (sum = 0, k = 0; k < length; k++)
    {
        sum += content[k];
    }
    return (sum + i) % size;
}

int H2(char *content, int i) {
    int j;
    const int p = 89, m = 1e9 + 9;
    long long sum = 0;
    long long power = 1;
    int length = strlen(content);
    for (j = 0; j < length; j++) {
        sum +=  (content[j]*power)%m;
        power = (power*p)%m;
    }
    return (sum + i) % size;
}

int H3(char *content, int i) {
    int hash = 5381;
    int j;
    int length = strlen(content);
    for (j = 0; j < length; j++) {
        hash = ((hash << 5) + hash) + content[j];
    }

    return (abs(hash) + i) % size;
}

