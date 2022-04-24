#include <stdio.h>
#include <stdlib.h>

char * allocateCharArray(int);
void printChar(char *);

int main(){
    int i, numChars;
    char *data;
    
    printf("Enter number of characters: ");
    scanf("%d", &numChars);

    data = allocateCharArray(numChars);

    for (i=0;i<numChars;i++){
        printf("Enter a character in binary (8bits): ");
        scanf("%s", data + i);   
        printChar(data + i);     
    }    

    return 0;
}

char * allocateCharArray(int num){
    char * ptr = (char *) malloc(num * sizeof(char));
    return ptr;
}

void printChar(char * array){

    char c = strtol(array, 0, 2);
    printf("%s = %c = %d = 0x%.2X\n", array, c, c, c);

}