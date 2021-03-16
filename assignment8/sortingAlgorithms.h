//
// Created by Denisa on 5/5/2020.
//

#ifndef ASSIGNMENT8_SORTINGALGORITHMS_H

#include "IOFunctions.h"
int noOfComparisons, noOfAssignments, noOfAccesses, noOfActions;

int *initVars(int *array);
void printData(FILE *output, char *string);
void swap(int *x, int *y);
void bubbleSort(FILE *output, int *array, int length);

//quickSort
int medianOfThree(int *array, int left, int right);
int partition(int *array, int left, int right);
void quickSort(int *array, int left, int right);
void quickSortPrint(FILE *output, int *array, int left, int right, int length);

//counting Sort
int *initFrequencyArray(int n);
int computeMax(int a, int b);
int getMax(int *array, int length);
void countingSort(FILE *output, int *array, int length);

void radixSort(FILE *output, int *array, int length);
void countingSortRadix(int *array, int length, int exp);
#define ASSIGNMENT8_SORTINGALGORITHMS_H

#endif //ASSIGNMENT8_SORTINGALGORITHMS_H
