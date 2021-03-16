//
// Created by Denisa on 5/5/2020.
//

#include <stdbool.h>
#include "sortingAlgorithms.h"

int *initVars(int *array) {
    noOfAccesses = 0;
    noOfComparisons = 0;
    noOfAssignments = 0;
    noOfActions = 0;
    return array;
}

void printData(FILE *output, char *string) {
    noOfActions = noOfAssignments + noOfComparisons + noOfAccesses;
    fprintf(output, "The required data for %s is:\n", string);
    fprintf(output, "noOfAccesses: %d\nnoOfComparisons: %d\nnoOfAssignments: %d\nTotal number of actions: %d\n\n", noOfAccesses, noOfComparisons, noOfAssignments, noOfActions);
}

void swap(int *x, int *y) {
    int aux = *x;
    *x = *y;
    *y = aux;
    noOfComparisons++;      //I usually swap the elements after comparing them
    noOfAssignments += 2;   //2 assignments, from the parameters x and y
    noOfAccesses += 4;      //I access the array twice when comparing the elements, then twice when swapping them
}

void bubbleSort(FILE *output, int *array, int length) {
    fprintf(output, "Bubble sort started:\n");
    bool carryOn = true;
    int i, j;
        for (i = 0; i < length - 1 && carryOn; i++) {
            carryOn = false;
            for (j = 0; j < length - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    swap(&array[j], &array[j + 1]);
                    carryOn = true;
                }
            }
        }
    printArrayToFile(output, array, length);
    printData(output, "bubble sort");
}

//quick sort; pivot chosen as median of the first, middle and last element, and then moved to the end of the array

int medianOfThree(int *array, int left, int right) {
    int mid = (left + right)/2;
    if (array[right] < array[left]) {
        swap(&array[right], &array[left]);
    }
    if (array[mid] < array[left]) {
        swap(&array[mid], &array[left]);
    }
    if (array[right] < array[mid]) {
        swap(&array[right], &array[mid]);
    }
    swap(&array[mid], &array[right]);
    noOfAccesses -= 2;
    noOfComparisons--;      //here I don't compare the two values beforehand, I simply swap them
    return array[right];
}

int partition(int *array, int left, int right) {
    int pivot = medianOfThree(array, left, right);
    noOfAccesses++;
    int i = (left - 1), j;
    for (j = left; j <= right-1; j++) {
        if (array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i+1], &array[right]);
    return (i + 1);
}

void quickSort(int *array, int left, int right) {
    if (left < right) {
        int part = partition(array, left, right);
        quickSort(array, left, part - 1);
        quickSort(array, part + 1, right);
    }
}

void quickSortPrint(FILE *output, int *array, int left, int right, int length) {
    fprintf(output, "Quick sort started:\n");
    quickSort(array, left, right);
    printArrayToFile(output, array, length);
    printData(output, "quick sort");
}

//countingSort

int *initFrequencyArray(int n) {
    int *frequency = (int *) malloc(sizeof(int) * (n+1));
    for (int i = 0; i <= n; i++) {
        frequency[i] = 0;
    }
    return frequency;
}

int computeMax(int a, int b) {
    return (a > b) ? a : b;
}

int getMax(int *array, int length) {
    int i, max = array[0];
    noOfAccesses++;
    for (i = 1; i < length; i++) {
        max = computeMax(array[i], max);
        noOfAccesses++;
    }
    return max;
}

void countingSort(FILE *output, int *array, int length) {
    fprintf(output, "Counting sort started:\n");
    int i, j = 0;
    int max = getMax(array, length);
    int * freq = initFrequencyArray(max);
    for (i = 0; i < length; i++) {
       freq[array[i]]++;
       noOfAccesses++;
    }
    for (i = 0; i <= max; i++) {
       while (freq[i] != 0) {
           array[j] = i;
           noOfAccesses++;
           noOfAssignments++;
           j++;
           freq[i]--;
       }
    }
    free(freq);
    printArrayToFile(output, array, length);
    printData(output, "counting sort");
}

//radix sort

void radixSort(FILE *output, int *array, int length) {
    fprintf(output, "Radix Sort started:\n");
    int max = getMax(array, length);
    for (int exp = 1; max/exp > 0; exp *= 10) {
        countingSortRadix(array, length, exp);
    }
    printArrayToFile(output, array, length);
    printData(output, "radix sort");
}

void countingSortRadix(int *array, int length, int exp) {
    int *output = initFrequencyArray(length);
    int i;
    int *freq = initFrequencyArray(9);
    for (i = 0; i < length; i++) {
        freq[(array[i]/exp)%10]++;
        noOfAccesses++;
    }
    for (i = 1; i < 10; i++) {
        freq[i] += freq[i-1];
    }

    for (i = length - 1; i >= 0; i--) {
        output[freq[(array[i]/exp)%10] - 1] = array[i];
        freq[(array[i]/exp)%10]--;
        noOfAccesses += 3;
    }
    for (i = 0; i < length; i++) {
        array[i] = output[i];
        noOfAccesses++;
        noOfAssignments++;
    }
    free(freq);
    free(output);
}