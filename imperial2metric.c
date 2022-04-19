/*
***Inputs****
4
10 m
1245.243 g
37.2 c
23 g
*/
/*
***Outputs****
32.808000 ft
2.745761 lbs
98.960000 f
0.050715 lbs
*/
#include <stdio.h>

int numberOfCoversions;
double inputNumber;
char inputChar;

void convertMeter2Feet(double input);
void convertGramToPound(double input);
void convertCelsius2Farenheit(double input);

int main(){

    printf("Give number of conversions\n");
    scanf("%d", &numberOfCoversions);
    for(int i;i<numberOfCoversions;i++){
        scanf("%lf %c", &inputNumber, &inputChar);
        if(inputChar == 'm'){
            convertMeter2Feet(inputNumber);
        }
        else if(inputChar == 'g'){
            convertGramToPound(inputNumber);
        }
        else if(inputChar == 'c'){
            convertCelsius2Farenheit(inputNumber);
        }
    }
}

void convertMeter2Feet(double input){
    double calculation = input / 0.304803706;
    printf("%.6lf ft\n", calculation);
}

void convertGramToPound(double input){
    double calculation = input / 453.51470867275;
    printf("%.6lf lbs\n", calculation);
}

void convertCelsius2Farenheit(double input){
    double calculation = (input * 1.8) + 32;
    printf("%.6lf ft\n", calculation);
}


