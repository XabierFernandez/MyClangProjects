#include <stdio.h>

int main(void) {
    //! showArray(word, cursors=[i])
    char word[50];
    int i = 0;
    int result = 0;
    scanf("%s", word);
    while (word[i]!='\0'){
        i++;
    }
    if(i%2==0){
        result=1;
    }else{
        result=2;
    }
    printf("%d\n", result);

    return 0;
}

