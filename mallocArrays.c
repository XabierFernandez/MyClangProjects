#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int * array;
    int arrayLength=5;
    array = (int *) malloc(arrayLength*sizeof(int));
    array[0] = 3;
    array[1] = 44;
    array[2] = 2;
    * (array + 3) = 7;
    * (array + 4) = -1;

    for (int i=0;i<arrayLength;i++){
        printf("array[%d]=%d\n", i, array[i]);
    }
    free(array);
    return 0;
}