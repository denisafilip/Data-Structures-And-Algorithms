#include "list.h"

float INITIAL_HT_SIZE_FACTOR;

listT * hashTable;
int sizeOfHashTable;


int H1(char * content);

int H0(char * content);

int H2(char * content);

int H3(char *content);

void freeArray(char **contents, int length);

listT* initHashTable(int N);

void insertElement(char * element);

void computeDistributionsPerBucket(int N);

float computeStandardDeviation(int N);


