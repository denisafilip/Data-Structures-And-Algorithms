#include "toDo.h"

#define FILE_PATH "../output.dat"
#define INPUT_FILE_PATH "../input.dat"
#define ERROR_CODE "sorry, the file could not be opened"

int main() {
    FILE *output = fopen(FILE_PATH, "w");
    if (output == NULL) {
        perror(ERROR_CODE);
        exit(1);
    }
    FILE *input = fopen(INPUT_FILE_PATH, "r");
    if (input == NULL) {
        perror(ERROR_CODE);
        exit(1);
    }

    int noOfCountries = 0;
    sentinel Sentinel = createSentinel();
    parseSentinelData(input, &Sentinel);

    country *countries = parseCountriesData(input, &noOfCountries);

    //finding out if the tyrant JimKong-nu was killed by the rebel alliance or not; if yes, also finding out which country had the hitting blow
    int forceOfRebelAlliance = computeTotalPowerOfWaves(noOfCountries, countries);
    if (forceOfRebelAlliance > Sentinel.sentinelTotalPower) {
        fprintf(output, "The tyrant was killed! \n");
        theHittingBlow(output, noOfCountries, countries, Sentinel);
    } else {
        fprintf(output, "The tyrant was not killed! \n");
    }

    //computing the strongest and weakest countries
    int strongestCountry = computeStrongest(noOfCountries, countries);
    fprintf(output, "The strongest country was: %s \n", countries[strongestCountry].name);
    fprintf(output, "The weakest country was: %s \n", computeWeakest(noOfCountries, countries));

    if (countries[strongestCountry].strength >= Sentinel.sentinelTotalPower) {
        fprintf(output, "%s could have defeated all the sentinels. \n", countries[strongestCountry].name);
    } else {
        fprintf(output, "No country could have defeated all the sentinels. \n");
    }

    //finding out how much damage the strongest country could have done on its own
    damageOfStrongestCountry(output, strongestCountry, countries, Sentinel);
    return 0;
}