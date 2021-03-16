#include "io.h"

typedef struct node
{
    char * content;
    struct node * next;
} nodeT;

typedef struct list
{
    nodeT * head;
    nodeT * tail;
    int sizeOfList;
} listT;

void addToList(listT *l, char * content);

void printList(listT l);
