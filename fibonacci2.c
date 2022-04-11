#include <stdio.h>
// Fibonacci numbers: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ...
long double fibonacci(long double n);

int main(void) {
    int N;
    long double fib;
    printf("Which Fibonacci number would you like: ");
    scanf("%d", &N);
    if (N<=0) {
        printf("%d is not positive. Aborting!\n", N);
    } else {
        fib = fibonacci((long double)N);
        printf("The %dth Fibonacci number is %Lf.\n", N, fib);
    }
	return 0;
}

long double fibonacci(long double n) {    
    if (n==1) {
        return 0;
    } else if (n==2) {
        return 1;
    } else {
        return (fibonacci(n-1) + fibonacci(n-2));
    }
}