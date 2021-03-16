#include "list.h"



nodeT * createNode(char * content)
{
    nodeT * n = (nodeT*) malloc(sizeof(nodeT));
    n->content = (char*) malloc((MAX_STRING_LENGTH + 1) * sizeof(char));
    strcpy(n->content, content);
    n->next = NULL;
    return n;
}

void addToList(listT *l, char * content) {

    nodeT *newNode = createNode(content);
    l->sizeOfList++;
    if (l->head == NULL) {
        l->head = newNode;
        l->tail = l->head;
   } else {
        l->tail->next = newNode;
   }
   l->tail = newNode;
}

void printList(listT l) {
    if (l.head == NULL) {
        printf("This bucket is empty! \n");
    } else {
        nodeT *temp = l.head;
        while(temp) {
            printf("%s ", temp->content);
            temp = temp->next;
        }
    }
}
