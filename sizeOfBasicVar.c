#include <stdio.h>
int main() {
    char c;
    int i;
    double d;
    char listChar[3];
    int listInt[3];
    double listDouble[3];
    
    printf("%zu byte\n", sizeof(char));
    printf("%zu bytes\n", sizeof(i));
    printf("%zu bytes\n", sizeof(d));

    printf("%zu bytes\n", sizeof(listChar));
    printf("%zu bytes\n", sizeof(listInt));
    printf("%zu bytes\n", sizeof(listDouble));
    return(0);

    
}