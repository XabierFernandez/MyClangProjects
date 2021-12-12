#include <stdio.h>

int main(void) {
    int inhabitans = 0;
    int days = 1;
    int infected = 1;
    
    scanf("%d", &inhabitans);

    while (infected < inhabitans) {   
        //printf("Day: %d - Infected: %d\n", days, infected); 
        days++;
        infected = (2*infected)+infected;               
    }
    //printf("Day: %d - Infected: %d\n", days, infected); 
    printf("%d\n", days);

    return 0;
}
