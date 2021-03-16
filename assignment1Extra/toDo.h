//
// Created by Denisa on 3/1/2020.
//

#ifndef ASSIGNMENT1EXTRA_TODO_H
#define ASSIGNMENT1EXTRA_TODO_H

#include "lists.h"
#include <string.h>
#include <stdbool.h>

#define MAX_COUNTRY_NAME 100

typedef struct _sentinel {
    NodeT *firstSentinel, *lastSentinel; //the first and last nodes that form the singly linked list of the sentinels
    int sentinelTotalPower; //the total power of the sentinels that defeat JimKong-nu + its own power of 1
} sentinel;

sentinel createSentinel();

void parseSentinelData(FILE *input, sentinel *Sentinel);


typedef struct _country {
    char *name;
    NodeT *firstWave, *lastWave; //first and last waves that form the sll of the waves of each country
    int strength; //the sum of all the waves of a country
} country;

country createCountry();

country *parseCountriesData(FILE *input, int *noOfCountries);

char *computeWeakest(int noOfCountries, country *countries);

int computeStrongest(int noOfCountries, country *countries);

int computeTotalPowerOfWaves(int noOfCountries, country *countries);

void theHittingBlow(FILE *output, int noOfCountries, country *countries, sentinel Sentinels);

void damageOfStrongestCountry(FILE *output, int strongestCountry, country *countries, sentinel Sentinels);

#endif //ASSIGNMENT1EXTRA_TODO_H
