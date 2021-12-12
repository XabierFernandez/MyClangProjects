#include <stdio.h>

int main(void) {
    int numberToGuess = 0;
    int numberGuessed = 0;
    int tries = 0;
    
    scanf("%d", &numberToGuess);

    while (numberGuessed != numberToGuess) {  
        scanf("%d", &numberGuessed); 
        tries++;
        if(numberGuessed < numberToGuess){
            printf("it is more\n"); 
        }
        if(numberGuessed > numberToGuess){
            printf("it is less\n"); 
        }        
                      
    }
    printf("Number of tries needed:\n%d",tries); 

    return 0;
}