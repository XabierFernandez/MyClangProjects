#include<stdio.h>
int main(void) {

    // Sorting from smallest to largest
    int list[] = {759, 14, 2, 900, 106, 77, -10, 8, -3, 5}; /* unsorted list */

    int i, j;
    int swap;
    int swapped;
    int size = sizeof list / sizeof list[0];
    
    printf("Unsorted list: \n");
    for (i=0; i<size; i++) {
        printf("%d ", list[i]);
    }
    
    for (j=0; j<size-1; j++) {
        swapped = 0;
        for (i=0; i<size-1; i++) {
            if (list[i] > list[i+1]) {
                swap = list[i];
                list[i] = list[i+1];
                list[i+1] = swap;
                swapped=1;
            }
        }
        if(swapped==0){
            break;
        }
    }
    
    printf("\nSorted list: \n");
    for (i=0; i<size; i++) {
        printf("%d ", list[i]);
    }
     printf("\n");


    return 0;
}