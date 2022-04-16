#include <stdio.h>

/*
Write a function isReverse() that checks whether a given word is the reverse of another given word. 
More precisely, the function should take as inputs two words (null-terminated arrays of characters) 
and return an integer. If indeed the second word is the reverse of the first then the function should 
return the integer 1, otherwise it should return a 0.

Your main() function should read two words from the user input (you can assume that neither word has 
more than 99 characters) and then call the function isReverse, passing both words to this function. 
The function should return an integer as described above and your main program needs to print out a sentence, 
indicating whether indeed, the first word is the reverse of the second word (see below examples).

Note: The name of the function needs to be isReverse.
*/

int isReverse(char *, char *);

int main() {

    char str1[99];
    char str2[99];
    int result = 0;

    scanf("%s", str1);
    scanf("%s", str2);
    result = isReverse(str1, str2 );

    if(result==1){
        printf ("%s is the reverse of %s", str1, str2);
    }
    else{
        printf ("%s is not the reverse of %s", str1, str2);
    }

    return 0;
}

int isReverse(char * str1, char * str2 ){
    int result = 0;
    int i, lengthOfStr1, lengthOfStr2;

    for (lengthOfStr1 = 0; *(str1 + lengthOfStr1) != '\0'; lengthOfStr1++);
    for (lengthOfStr2 = 0; *(str2 + lengthOfStr2) != '\0'; lengthOfStr2++);
    char *pointer1 = str1;
    char *pointer2 = str2 + (lengthOfStr2-1);

    if(lengthOfStr1 == lengthOfStr2){
        for(i=0;i<lengthOfStr1;i++){
            if(*pointer1==*pointer2){
                result = 1;
            }
            else {
                result = 0;
                break;
            }
            pointer1++;
            pointer2--;
        }
    }
    return result;
}



