//
// Created by Denisa on 6/11/2020.
//

#include "heap.h"

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

unsigned int parent(unsigned int i) {
    return (i - 1) * 2;
}

unsigned int leftChild(unsigned int i) {
    return 2 * i + 1;
}

unsigned int rightChild(unsigned int i) {
    return 2 * i + 2;
}

BinHeapT *createBinHeap(unsigned int size) {
    BinHeapT *h = malloc(sizeof(BinHeapT));
    if (h) {
        // successful allocation of header
        h->size = (size > base_size) ? size : base_size; // size will be base_size if < base_size
        h->count = 0; // no elements stored yet
        h->data = malloc(sizeof(int) * h->size);
        if (!h->data) {
            //allocation unsuccessful
            exit(1);
        }
    } else {
        exit(1); //allocation failed
    }
    return h;
}

void insertBinHeap(BinHeapT *h, int value) {
    unsigned int index, p;
    if (h->count == h->size) {
       // h->size = h->size * 2;
       // h->data = realloc(h->data, sizeof(int) * h->size);
        //if (!h->data) exit(1);
        printf("Overflow\n");
        return;
    }

    h->count++;
    index = h->count - 1;
    h->data[index] = value;
    while (index != 0 && h->data[parent(index)] > h->data[index]) {
        swap(&h->data[index], &h->data[parent(index)]);
        index = parent(index);
    }

    /*for (index = h->count++; index; index = p) {
        p = parent(index);
        if (h->data[p] <= value) break;
        h->data[index] = h->data[p];
    }
    h->data[index] = value;*/
}

void decreaseKey(BinHeapT *h, unsigned int index, int newValue) {
    h->data[index] = newValue;
    while (index != 0 && h->data[parent(index)] > h->data[index]) {
        swap(&h->data[index], &h->data[parent(index)]);
        index = parent(index);
    }
}

int getMin(BinHeapT *h) {
    return h->data[0];
}

void minHeapify(BinHeapT *h, unsigned int index) {
    unsigned int left = leftChild(index);
    unsigned int right = rightChild(index);
    unsigned int smallest = index;

    if (left < h->count && h->data[left] < h->data[smallest]) {
        smallest = left;
    }

    if (right < h->count && h->data[right] < h->data[smallest]) {
        smallest = left;
    }

    if (smallest != index) {
        int temp = h->data[index];
        h->data[index] = h->data[smallest];
        h->data[smallest] = temp;
        minHeapify(h, smallest);
    }
}

int extractMin(BinHeapT *h) {
    int minItem = h->data[0];

    //replace the first item with the last item
    h->data[0] = h->data[h->count - 1];
    h->count = h->count - 1;

    minHeapify(h, 0);
    return minItem;
}

void printHeap(BinHeapT *h) {
    unsigned int i;
    for (i = 0; i < h->count; i++) {
        printf("%d ", h->data[i]);
    }
    printf("\n");
}

