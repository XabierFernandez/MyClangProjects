#include <stdio.h>
 
void printArray(int *, int);
void squareArray(int *, int);
void setToZero(short **);

int main(void) {
    int i;
    int *iAdr = &i;
 
    *iAdr = 10;
 
    printf(" i = %d\n", i);
    printf(" *iAdr = %d\n", *iAdr);
 
    *iAdr = *iAdr - 2;
    printf(" i = %d\n", i);
    printf(" *iAdr = %d\n", *iAdr);
 
    (*iAdr) += 1;
    printf(" i = %d\n", i);
    printf(" *iAdr = %d\n", *iAdr);
 

    int numbers[] = {4, -1, 8, 3, 0, -11}; 
    printf("Random answer= %d\n", numbers[10]);

    int array[] = {6, 2, -4, 8, 5, 1};
    int N = 6;
    printArray(array, 6);
    squareArray(array, 6);
    printArray(array, 6);

    short a[3] = {234,655, 843};
    short b[2] = {12, 62};
    short c[4] = {3456, 3467, 23, 276};
    short * arrays[3] = {a, b, c};
    * arrays[0] = 5;
    arrays[0][0] = 0;
    * (arrays[0] + 1) = 6;
    arrays[0][1] = 0;
    * (arrays[0] + 2) = 7;
    arrays[0][2] = 0;
    * arrays[1] = 3;
    arrays[1][0] = 0;
    * (arrays[1] + 1) = 4;
    arrays[1][1] = 0;

    short a_arr[3] = {1245, 1924, 234};
    short b_arr[2] = {24, 256};
    short * t[2] = {a_arr,b_arr};
    setToZero(t);

    char a_carr[4];
    char b_carr[6];
    char c_carr[9];
    char * words[3] = {a_carr, b_carr, c_carr};
    printf("Please enter a word with at  most 3 letters: ");
    scanf("%s", a_carr);
    printf("Please enter a word with at  most 5 letters: ");
    scanf("%s", b_carr);
    printf("Please enter a word with at  most 8 letters: ");
    scanf("%s", c_carr);
    printf("You entered: \n");
    printf("%s %s %s.\n", a_carr, b_carr, c_carr);
    printf("%s %s %s.\n", words[0], words[1], words[2]);

    return 0;
}

void squareArray(int * ptr, int size) {
    int i;
    for (i=0; i<size; i++) {
        ptr[i] = ptr[i]*ptr[i];
        // *(ptr+i) = (*(ptr+i))*(*(ptr+i));
    }
}

void printArray(int * ptr, int size) {
    int i;
    for (i=0; i<size; i++) {
        // printf("%d ", *(ptr+i));
        printf("%d ", ptr[i]);
    }
    printf("\n");
}

void setToZero(short ** t){
    *(*t) = 0; //t[0][0]  OR  *(t[0] + 0)
    *((*t) + 1) = 0;//t[0][1]  OR *(t[0] + 1)
    *((*t) + 2) = 0;//t[0][2]  OR *(t[0] + 2)
    *(*(t+1)) = 0;//t[1][0]  OR *(t[1] + 0)
    *(*(t+1)+1) = 0;//t[1][1]  OR *(t[1] + 1)
}