#include <stdio.h>
/*
You are programming a toaster! The toaster does not have a lot of memory, so you need to be careful 
about the data types you use (remember that different data types use different amounts of memory). 
To make this easier, you'd like an easy way to track how much memory your variables are going to use.

Your job is to write a program that shows, in human-readable form (see below for specifics), 
how much memory a set of variables of a certain type will use. Your program should read a character that 
identifies the data type ('i' for int, 's' for short, 'c' for char, 'd' for double). Next it should read 
an integer that indicates how many variables of the given type you wish to store.

Your program should then calculate the amount of memory required to store the given variables. 
Your program needs to be written in such a way that it would also perform correctly on other computers. 
In other words, rather than hard-coding specific sizes for the different variable types, your program 
needs to use the "sizeof()" function to determine how much memory an individual variable of a given type needs.

Finally, you need to output the amount of space required by your variables to the screen. Y
ou need to make sure you provide this output in a form that is easy to read for humans. T
he following examples illustrate what this means:
*/

int main(){
    int numberOfVars, i;
    char typeOfVars;
    int memoryspace = 0;
    int mb = 0;
    int kb = 0;
    int b = 0;

    scanf("%c %d", &typeOfVars, &numberOfVars);
    if(typeOfVars == 'i'){
        memoryspace = sizeof(int)*numberOfVars;
    }
    else if(typeOfVars == 's'){
        memoryspace = sizeof(short)*numberOfVars;
    }
    else if(typeOfVars == 'c'){
        memoryspace = sizeof(char)*numberOfVars;
    }
    else if(typeOfVars == 'd'){
        memoryspace = sizeof(double)*numberOfVars;
    }
    //============================================
    mb = memoryspace/1000000;
    kb = (memoryspace - (mb * 1000000))/1000;
    b = memoryspace - (mb * 1000000) - (kb * 1000);
    
    if(memoryspace >= 1000000){
        printf("%d MB and %d KB and %d B ",mb, kb, b);
    }
    else if(memoryspace >= 1000 && memoryspace < 1000000){
        printf("%d KB and %d B ", kb, b);
    }
    else if(memoryspace < 1000){
        printf("%d B ", b);
    }

}