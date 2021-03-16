//
// Created by Denisa on 3/1/2020.
//
#include "toDo.h"

sentinel createSentinel() {
    sentinel Sentinel;
    Sentinel.firstSentinel = NULL;
    Sentinel.lastSentinel = NULL;
    Sentinel.sentinelTotalPower = 0;
    return Sentinel;
}

void parseSentinelData(FILE *input, sentinel *Sentinel) {
    int noOfSentinels = 0, sentinelDamageCapacity = 0;
    fscanf(input, "%d", &noOfSentinels);
    for (int i = 0; i < noOfSentinels; i++) {
        fscanf(input, "%d", &sentinelDamageCapacity);
        addLast(&Sentinel->firstSentinel, &Sentinel->lastSentinel, sentinelDamageCapacity);
    }
    addLast(&Sentinel->firstSentinel, &Sentinel->lastSentinel, 1); //adding 1, the power of JimKong-nu
    Sentinel->sentinelTotalPower = sumOfNodes(Sentinel->firstSentinel, Sentinel->lastSentinel);
}

country createCountry() {
    country Country;
    Country.name = (char *) malloc(MAX_COUNTRY_NAME * sizeof(char));
    Country.firstWave = NULL;
    Country.lastWave = NULL;
    Country.strength = 0;
    return Country;
}

country *parseCountriesData(FILE *input, int *noOfCountries) {
    fscanf(input, "%d", *(&noOfCountries));
    country *countries = (country *) malloc(*noOfCountries * sizeof(country));
    for (int i = 0; i < *noOfCountries; i++) {
        countries[i] = createCountry();
        fscanf(input, "%s", countries[i].name);
        //I want to read the waves from the input file for each country until I reach a newline character, or, for the last country in the file, until I reach the end of file marker
        char c;
        while ((c = fgetc(input)) && c != '\n' && c != EOF) {
            int wave = 0;
            fscanf(input, "%d", &wave);
            addLast(&countries[i].firstWave, &countries[i].lastWave, wave);
        }
        countries[i].strength = sumOfNodes(countries[i].firstWave, countries[i].lastWave);
    }
    return countries;
}

int computeStrongest(int noOfCountries, country *countries) {
    int maxStrength = countries[0].strength, strongest = 0; //to compute the strongest country, I compare the strength of the first country with the rest.
    //whenever I find a more powerful country, I save its index in the variable strongest, because I will use it for the final task as well
    for (int i = 1; i < noOfCountries; i++) {
        if (maxStrength < countries[i].strength) {
            maxStrength = countries[i].strength;
            strongest = i;
        }
    }
    return strongest;
}

char *computeWeakest(int noOfCountries, country *countries) {
    int minStrength = countries[0].strength, weakest = 0; //to compute the weakest country, I compare the strength of the first country with the rest.
    //I directly return its name, because I do not need to use other data from tha weakest country further
    for (int i = 1; i < noOfCountries; i++) {
        if (minStrength > countries[i].strength) {
            minStrength = countries[i].strength;
            weakest = i;
        }
    }
    return countries[weakest].name;
}

int computeTotalPowerOfWaves(int noOfCountries, country *countries) {
    int totalPowerOfWaves = 0;
    for (int i = 0; i < noOfCountries; i++) {
        totalPowerOfWaves += countries[i].strength;
    }
    return totalPowerOfWaves;
}

void theHittingBlow(FILE *output, int noOfCountries, country *countries, sentinel Sentinels) {
    int remainingPower = Sentinels.sentinelTotalPower, hittingBlow = 0;
    int totalPowerOfWaves = computeTotalPowerOfWaves(noOfCountries, countries);
    bool hasPower = true;
    //my while loop will stop when JimKong-nu has been defeated, or when the countries remain out of waves
    while (totalPowerOfWaves != 0 && hasPower == true) {
        for (int i = 0; i < noOfCountries && hasPower; i++) {
            remainingPower -= countries[i].firstWave->data; //the remaining power of the bunker
            totalPowerOfWaves -= countries[i].firstWave->data;
            if (countries[i].firstWave->next == NULL)
                countries[i].firstWave->data = 0; //if it reaches the last wave of a country, I give that wave the value 0 in order to continue with the attack
            else {
                countries[i].firstWave = countries[i].firstWave->next; //moving to the next wave of a country
            }
            if (remainingPower <= 0) {
                hasPower = false;
                hittingBlow = i; //saving the index of the country that had the hitting blow
            }
        }
    }
    if (hasPower == false) {
        fprintf(output, "The last hit was done by: %s \n", countries[hittingBlow].name);
    }
}

void damageOfStrongestCountry(FILE *output, int strongestCountry, country *countries, sentinel Sentinels) {
    int defeatedSentinelCount = 0;
    bool defeatedCountry = false; //boolean var to stop the while loop when the strongest country remains without waves
    while (defeatedCountry == false) {
        if (Sentinels.firstSentinel->data < countries[strongestCountry].strength) {
            //when the country has enough strength, I substract the power of the sentinels from it, to compute how many sentinels the country could have defeated on its own
            countries[strongestCountry].strength -= Sentinels.firstSentinel->data;
            Sentinels.firstSentinel = Sentinels.firstSentinel->next;
            defeatedSentinelCount++;
        } else {
            fprintf(output,
                    "%s could have brought down the first %d sentinels and would have had chipped off %d life points from sentinel %d.",
                    countries[strongestCountry].name, defeatedSentinelCount, countries[strongestCountry].strength,
                    defeatedSentinelCount + 1);
            defeatedCountry = true;
        }
    }
}