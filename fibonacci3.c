#include <stdio.h>
/*
f0 = 0,f1 = 1
fn = f(n-1) + f(n-2)
for n > 1*/

 long double fibonacci(long double n) {
    long double f0 = 0;
    long double f1 = 1;
    long double fn = 0;
    while (n-- > 1) {
        /*long double t = f0;
        f0 = f1;
        f1 = f1 + t;*/
        fn = f0+f1;
        f0 = f1;
        f1 = fn;
        printf("f0=%Lf, f1=%Lf,t=%Lf,n=%LF\n",f0,f1,fn,n);
    }
    return fn;
}

int  main() {
   int i, N;
	
   printf("Which Fibonacci numbers would you like to find?: ");
   scanf("%d", &N);
   printf("%dth fibonacci number is = %Lf\t\n", N, fibonacci((long double)(N-1)));	
   return 0;
}