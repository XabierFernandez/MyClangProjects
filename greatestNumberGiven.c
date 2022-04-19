#include <stdio.h>

int numberOfIntergers;
double inputNumber;
char inputChar;

void convertMeter2Feet(double input);
void convertGramToPound(double input);
void convertCelsius2Farenheit(double input);

int main(){
    int i;
    scanf("%d", &numberOfIntergers);
    for(i=0;i<numberOfIntergers;i++){
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