#include <stdio.h>

/*
Within this program, we will pass an array with 6 integers to a function, have the function swap 
the first and last integer, the second and the second to last integer, the third and the third to last integer.

The function is called reverseArray and doesn't return anything (void). It should take one parameter, 
representing the array of integers. 

The main function first reads 6 integers from the input, and assigns them to the array. The main function 
then calls reverseArray, passing the array as an argument.

The main function then prints the reversed array.
*/


void reverseArray(int *);
void swap(int *,int *);

int main() {
    int arr[6] = {0,0,0,0,0,0};
    int i, input;

    for (i=0;i<6;i++){
        scanf("%d", &input);
        arr[i] = input;
    }
    reverseArray(arr);
    // display array
    for(i=0; i<6; i++) {
        printf("%d", arr[i]);
    }

    return 0;
}
void reverseArray(int * arr){
    // pointer1 pointing at the beginning of the array
    int *pointer1 = arr;
    // pointer2 pointing at end of the array
    int * pointer2 = (arr + (6 - 1));
    while (pointer1 < pointer2) {
        swap(pointer1, pointer2);
        pointer1++;
        pointer2--;
    }
   
}

void swap(int * a, int * b){
    int tmp = * a;
    * a = * b;
    * b = tmp;
}

