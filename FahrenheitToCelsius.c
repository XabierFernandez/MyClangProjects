#include <stdio.h>

// insert prototype for function ftoc() here
double ftoc(int x);
// insert prototype for function ctof() here
double ctof(int x);

int main(void) {

    int usertemp;
    char unit;
    double convertedtemp;

    scanf("%d %c", &usertemp, &unit);
    if (unit=='C'){
        // insert function call here to convert usertemp 
           /* from Celsius to Fahrenheit and store the result in convertedtemp */
        convertedtemp = ctof(usertemp);        // complete this line to print out the conversion result
        printf("%.1lf F\n",convertedtemp);
    } else if (unit=='F'){

        // insert function call here to convert usertemp 
           /* from Fahrenheit to Celsius and store the result in convertedtemp */
        convertedtemp = ftoc(usertemp);  
        // complete this line to print out the conversion result
        printf("%.1lf C\n",convertedtemp);
    }

    return 0;

}

/* Function definitions below are provided for you*/

/* Conversion from Celsius to Fahrenheit: */
double ctof(int x){
    return((9.0/5)*x+32);
}

/* Conversion from Fahrenheit to Celsius: */
double ftoc(int x){
    return(5.0/9*(x-32));
}

