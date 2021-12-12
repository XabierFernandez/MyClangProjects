#include <stdio.h>

int main(void) {
 
    int citiesPopupation[10];
    int population=0;
    int numOfCities=0;
    int result=0;
    int i;

    scanf("%d",&numOfCities);
    for(i=0;i<numOfCities;i++){
        scanf("%d",&population);
        citiesPopupation[i]=population;
        if (citiesPopupation[i]>10000){
            result=result+1;
        }
    }

    
    printf("%d\n",result);

    return 0;
}

