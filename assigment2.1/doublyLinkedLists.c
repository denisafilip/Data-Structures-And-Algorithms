//
// Created by Denisa on 3/4/2020.
//
#include "doublyLinkedLists.h"

List createList() {
    List L;
    L.first = NULL;
    L.last = NULL;
    return L;
}

void addFirst(List *list, int x) {
    if (list->first == NULL) {
        list->first = (NodeT *) malloc(sizeof(NodeT));
        list->first->next = NULL;
        list->first->prev = NULL;
        list->first->data = x;
        list->last = list->first;
    } else {
        NodeT *newElement = (NodeT *) malloc(sizeof(NodeT));
        newElement->next = list->first;
        newElement->prev = NULL;
        newElement->data = x;
        list->first->prev = newElement;
        list->first = newElement;
    }
}

void addLast(List *list, int x) {
    if (list->first == NULL) {
        list->first = (NodeT *) malloc(sizeof(NodeT));
        list->first->next = NULL;
        list->first->prev = NULL;
        list->first->data = x;
        list->last = list->first;
    } else {
        NodeT *newElement = (NodeT *) malloc(sizeof(NodeT));
        newElement->prev = list->last;
        newElement->next = NULL;
        newElement->data = x;
        list->last->next = newElement;
        list->last = newElement;
    }
}

void deleteFirst(List *list) {
    NodeT *currentElement = list->first;
    if (currentElement != NULL) {
        list->first = list->first->next;
        free(currentElement);
        if (list->first == NULL) {
            list->last = NULL;
        } else {
            list->first->prev = NULL;
        }
    }
}

void deleteLast(List *list) {
    NodeT *currentElement = list->last;
    if (currentElement != NULL) {
        list->last = list->last->prev;
        if (list->last == NULL) {
            list->first = NULL;
        } else {
            list->last->next = NULL;
        }
        free(currentElement);
    }
}

void removeList(List *list) {
    NodeT *currentElement = list->first;
    while (currentElement != NULL) {
        list->first = list->first->next;
        free(currentElement);
        currentElement = list->first;
    }
    list->last = NULL;
    list->first = NULL;
}

void deleteElement(List *list, int x) {
    NodeT *currentElement = list->first;

    while (currentElement != NULL) {
        if (currentElement->data == x) {
            break;
        } else {
            currentElement = currentElement->next;
        }
    }

    if (currentElement != NULL) {
        if (currentElement == list->first) {
            deleteFirst(list);
        } else if (currentElement == list->last) {
            deleteLast(list);
        } else {
            currentElement->next->prev = currentElement->prev;
            currentElement->prev->next = currentElement->next;
            free(currentElement);
        }
    }
}

void printAll(FILE *output, List *list) {
    if (list->first == NULL) {
        fprintf(output, "The list is empty! \n");
    } else {
        NodeT *currentElement = list->first;
        while (currentElement != NULL) {
            fprintf(output, "%d ", currentElement->data);
            currentElement = currentElement->next;
        }
        fprintf(output, "\n");
    }
}

void printFirst(FILE *output, List *list, int x) {
    if (list->first == NULL) {
        fprintf(output, "The list is empty! \n");
    } else {
        NodeT *currentElement = list->first;
        for (int i = 0; i < x; i++) {
            if (currentElement != NULL) {
                fprintf(output, "%d ", currentElement->data);
                currentElement = currentElement->next;
            }
        }
        fprintf(output, "\n");
    }
}

void printLast(FILE *output, List *list, int x) {
    if (list->first == NULL) {
        fprintf(output, "The list is empty! \n");
    } else {
        NodeT *currentElement = list->last;
        for (int i = 0; i < x - 1; i++) {
            if (currentElement != NULL) {
                currentElement = currentElement->prev;
            }
        }
        for (int i = 0; i < x; i++) {
            if (currentElement != NULL) {
                fprintf(output, "%d ", currentElement->data);
                currentElement = currentElement->next;
            }
        }
        fprintf(output, "\n");
    }
}

void reverseList(FILE *output, List *list) {
    if (list->first == NULL) {
        fprintf(output, "The list is empty! \n");
    } else {
        NodeT *aux = list->first;
        list->first = list->last;
        list->last = aux;

        NodeT* head = list->first;

        while (head != NULL) {
            aux = head->next;
            head->next = head->prev;
            head->prev = aux;
            head = head->next;
        }

        printAll(output, list);
    }

}