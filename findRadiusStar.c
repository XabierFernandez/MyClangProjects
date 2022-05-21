#include <stdio.h>
//add additional header files here
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct star {
    char name[50];
    int temperature;
    double luminosity;
    double radius;
    char classification;
};

void printStars(struct star mystars[], int N); 
//add your propotypes here
int readStars(struct star * mystars); 
void computeRadii(struct star mystars[], int N);
void classifyStars(struct star mystars[], int N);

// Do not modify the main() function!
int main(void) {
    struct star mystars[50];
    int N;

    N = readStars(mystars);
    //computeRadii(mystars, N);
    //classifyStars(mystars, N);
    //printStars(mystars, N);
    //printf("%d %lf",mystars[0].temperature,mystars[0].luminosity);
    return 0;
}

// Do not modify the printStars() function!
void printStars(struct star mystars[], int N) {
    int i;
    for (i=0; i<N; i++) {
        printf("%s is a ", mystars[i].name);
        if (mystars[i].classification == 'M') {
        	printf("Main Sequence Star\n");
        } else if (mystars[i].classification == 'G') {
            printf("Giant\n");
        } else if (mystars[i].classification == 'S') {
        	printf("Supergiant\n");
        } else if (mystars[i].classification == 'W') {
        	printf("White Dwarf\n");
        } else if (mystars[i].classification == 'N') {
        	printf("Unclassified Star\n");
        } else {
        	printf(" !!! Warning: '%c' not a valid classification code!!!\n", mystars[i].classification);
        }
        printf("Temp = %d Kelvin, Lum = %.4lf Sol, Rad = %.2lf * R_Sun\n\n", mystars[i].temperature, mystars[i].luminosity, mystars[i].radius);
    }
}

//add the functions readStars(), computeRadii() and classifyStars() here.

int readStars(struct star * mystars){
    int numStar,N;
    char *nameStar;
    int temperature;
    double luminosity;
    FILE *ifile;
    char line[1024];

    numStar=0;
    //==============================
    ifile = fopen("stardata.txt", "r"); 
    while (fscanf(ifile,"%s %d %lf",nameStar, &temperature, &luminosity)!= EOF) {
            
            //mystars[numStar].name = nameStar;
            //mystars[numStar].temperature = temperature;
            //mystars[numStar].luminosity = luminosity;
           printf("%s %d %lf",nameStar, &temperature, &luminosity);
            //numStar++;
    }  
    fclose(ifile);
    //==============================
    return numStar;

}

void computeRadii(struct star mystars[], int N) {


}

void classifyStars(struct star mystars[], int N) {

 
}