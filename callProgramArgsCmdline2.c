#include <stdio.h>
#include <stdlib.h> // for atoi and atof
#include <string.h> // for strcmp

int main(int argc, char *argv[]) {
    int numPlants;
    double pricePlant;
    
    
    if (argc == 3) {
        numPlants = atoi(argv[1]);
        pricePlant = atof(argv[2]);
        printf("%d plants for %.2lf dollars each cost %.2lf dollars.", numPlants, pricePlant, (numPlants*pricePlant));
    }
    else{
        printf("invalid input");
    }

    return 0;
}