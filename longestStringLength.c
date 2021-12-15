#include <stdio.h>

int main(void) {

    char word[100];
    int numWords = 0;
    int maxLenght = 0;
    int countChar = 0;
    int positionChar = 0;
    int i;

    scanf("%d", &numWords);
    for(i=0;i<numWords;i++){
        scanf("%s", word);
        positionChar=0;
        countChar =0;
        while (word[positionChar]!='\0'){
            countChar++;
            positionChar++;
        }
        if (countChar>maxLenght){
            maxLenght = countChar;
        }
    }

    printf("%d\n", maxLenght);

    return 0;
}
