#include <stdio.h>

int main(void) {
 
    int isTinuviel=0;
    int isCalaelen=0;
    int isFalarion=0;
    int isDorthonion=0;

    int height=0;
    int numberOfLeaflets=0;

    scanf("%d",&height);
    scanf("%d",&numberOfLeaflets);
    
    isTinuviel=(height<=5)&&(numberOfLeaflets>=8);
    isCalaelen=(height>=10)&&(numberOfLeaflets>=10);
    isFalarion=(height<=8)&&(numberOfLeaflets<=5);
    isDorthonion=(height>=12)&&(numberOfLeaflets<=7);

    if(isTinuviel){
        printf("Tinuviel\n");
    }else if(isCalaelen){
        printf("Calaelen\n");
    }else if(isFalarion){
        printf("Falarion\n");
    }else if(isDorthonion){
        printf("Dorthonion\n");
    }else{
        printf("Uncertain\n");
    }
    
    return 0;
}
