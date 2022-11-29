#include <stdio.h>
#include <math.h>


int main(void) {

    int num;
    double resultsqrt;
    scanf("%d", &num);
    
    resultsqrt = sqrt(num);
    printf("%.8lf\n", resultsqrt);
    printf("%.10lf\n", exp(1));
    printf("gcc -std=c11 -Wall -fmax-errors=10 -Wextra -lmath program.c -o program");

    return 0;

}
