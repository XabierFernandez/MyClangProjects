#include <stdio.h>

int main(void){
    int numberStars = 0;
    int i = 0;
    int j = 0;
    scanf("%d", &numberStars);
    for(i = 0; i<numberStars; i++){
        for(j = 0; j<numberStars; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

