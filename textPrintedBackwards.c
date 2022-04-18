#include <stdio.h>
int main(void){
 
    char text[68][40];
    int word;
    for(word = 0; word < 68; word++){
            scanf("%s", text[word]);
    } 

     for(word = 67; word >=0; word--){
            print("%s", text[word]);
    }       
    return 0;
}