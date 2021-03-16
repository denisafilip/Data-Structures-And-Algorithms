#include "io.h"

float INITIAL_HT_SIZE_FACTOR;
float MAX_FILL_FACTOR;

char ** hashTable;
int size;
int noOfResizes;

void freeArray(char **contents, int length);
int hashFunction(char * content, int i);
int H1(char * content, int i);
int H2(char *content, int i);
int H3(char *content, int i);
void initHashTable(int N);
float getFillFactor();
void resizeHashTable();
int insertElement(char * element);



