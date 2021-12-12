#include <stdio.h>

int main(void) {
    //! showArray(word, cursors[i])
    char word[101]; //arrray of characters (string)
    int repetitions=0;

    scanf("%d %s", &repetitions, word);
    for (int i=0;i<repetitions;i++){
        for(int j=0;j<sizeof(word);j++){
            if(word[j]!='\0'){
                printf("%c", word[j]);
            }else{
                break;
            }
        }
        printf("\n");
    }

    return 0;
}