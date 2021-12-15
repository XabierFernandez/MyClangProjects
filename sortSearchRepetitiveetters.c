#include <stdio.h>
#include <string.h>

int main(void) {

    char word[50];

    int i, j;
    int swap;
    int swapped;    
    int counter=0;
    int repeated=0;
    
    printf("Please enter a word: ");
    scanf("%s", word);
    int len = strlen(word);
    
    printf("\nUnsorted letters: \"%s\" \n",word);
    printf("%d\n",len);
    for (j=0; j<len-1; j++) {
        swapped = 0;
        for (i=0; i<len-1; i++) {
            if (word[i] > word[i+1]) {
                swap = word[i];
                word[i] = word[i+1];
                word[i+1] = swap;
                swapped=1;
            }
        }
        if(swapped==0){
            break;
        }
    }
    
    printf("\nSorted letters: \n");
    for (i=0; i<len; i++) {
        if(word[i]!='\0'){
          printf("%c", word[i]);  
        }else{
            break;
        }
    }
    
    printf("\n");

    for (i=0; i<len; i++) {
        if(word[i]==word[i+1]){
         if(repeated==0){
            counter++;  
            repeated=1;
         }          
        }else{
            repeated=0;
        }
    }
    printf("%d\n",counter);
    return 0;
}