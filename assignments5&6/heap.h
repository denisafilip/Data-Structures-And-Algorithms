//
// Created by Denisa on 6/11/2020.
//

#ifndef ASSIGNMENT5_HEAP_H

#include <stdio.h>
#include <stdlib.h>

static const unsigned int base_size = 8;

typedef struct heap
{
    unsigned int size; /**< Size of the allocated memory (number of items) */
    unsigned int count; /**<  current number of elements */
    int *data; /**<  storage for heap elements */
} BinHeapT;


unsigned int parent(unsigned int i);
unsigned int rightChild(unsigned int i);
unsigned int leftChild(unsigned int i);
void swap(int *x, int *y);
BinHeapT *createBinHeap(unsigned int size);
void insertBinHeap(BinHeapT *h, int value);
int getMin(BinHeapT *h);
void minHeapify(BinHeapT *h, unsigned int index);
int extractMin(BinHeapT *h);
void printHeap(BinHeapT *h);
void decreaseKey(BinHeapT *h, unsigned int index, int newValue);
#define ASSIGNMENT5_HEAP_H

#endif //ASSIGNMENT5_HEAP_H



