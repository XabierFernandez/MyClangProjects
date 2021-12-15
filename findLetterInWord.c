#include <stdio.h>

int main(void) {
    char word[50];
    char letter1='t';
    char letter2='T';
    int i = 0;
    int found = 0;
    int numChars = 0;

    
    printf("Please enter your word: ");
    scanf("%s", word);
    while(word[numChars]!='\0'){
        numChars++;
    }
 
    while (!found && i<numChars ) {
        if (letter1 == word[i] || letter2 == word[i]) { 
            if(i<=(numChars/2)){
                found = 1;
            }else{
                found = 2;
            }
        }else{
            i++;
        }
    }
    
    if (!found) {
        found = -1;
    }

    printf("%d\n",found);

	return 0;
}
