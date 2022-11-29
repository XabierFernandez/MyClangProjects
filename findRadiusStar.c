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
void computeRadii(struct star *mystars, int N);
void classifyStars(struct star mystars[], int N);

// Do not modify the main() function!
int main(void) {
    struct star mystars[50];
    int N;

    N = readStars(mystars);
    computeRadii(mystars, N);
    classifyStars(mystars, N);
    printStars(mystars, N);
    //printf("NumStarS=%d, %s, %d, %lf\n",N,mystars[0].name,mystars[0].temperature, mystars[0].luminosity);
    //printf("NumStarS=%d, %s, %d, %lf\n",N,mystars[1].name,mystars[1].temperature, mystars[1].luminosity);
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
    int numStar, numFields;
    char *nameStar, *token;     
    int temperature;
    double luminosity;
    FILE *ifile;
    char line [1024];

    numStar=0;
    numFields=0;
    //==============================
    ifile = fopen("stardata.txt", "r"); 
    while (fgets(line, sizeof line, ifile)) {
        // Returns first token
        token = strtok(line, " ");
        //printf("NumStars= %d\n", numStar);
        // Keep printing tokens while one of the
        // delimiters present in str[].
        while (token != NULL) {
            if(numFields==0){
                strcpy(mystars[numStar].name, token);
                //printf("Name= %s\n",token);
                numFields=1;
                token = strtok(NULL, " ");
            }
            if(numFields==1){
                mystars[numStar].temperature=atoi(token);
                //printf("Temperature= %d\n",atoi(token));
                numFields=2;
                token = strtok(NULL, " ");
            }
            if(numFields==2){
                mystars[numStar].luminosity=atof(token);
                //printf("Luminosity= %lf\n",atof(token)); 
                numFields=-1;
                token = strtok(NULL, " ");               
            }            
        }
        numFields=0;
        numStar++;
    }
    fclose(ifile);
    //==============================
    return numStar;

}

void computeRadii(struct star *mystars, int N) {
    int i;
    
    for(i=0;i<N; i++){
        mystars[N].radius = pow(2, (3500/mystars[N].temperature)) * sqrt(mystars[N].luminosity);
    }
    

}

void classifyStars(struct star mystars[], int N) {
    int i;
    
    for(i=0;i<N; i++){
        if((mystars[N].luminosity>=pow(-2,10) && mystars[N].luminosity<=pow(6,10))
            || (mystars[N].radius>=0.1 && mystars[N].luminosity<=10)){
                mystars[N].classification = 'M';
            }
        else if((mystars[N].luminosity>=pow(3,10) && mystars[N].luminosity<=pow(5,10))
            || (mystars[N].radius>=10 && mystars[N].luminosity<=100)){
                mystars[N].classification = 'G';
            }
        else if((mystars[N].luminosity>=pow(5,10) && mystars[N].luminosity<=pow(6,10))
            || mystars[N].radius>100){
                mystars[N].classification = 'S';
            }
        else if(mystars[N].radius>=0.010 ){
                mystars[N].classification = 'W';
            }
        else{
            mystars[N].classification = 'N';
        }        
    }
 
}