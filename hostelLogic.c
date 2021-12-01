#include <stdio.h>

int main(void) {
 
    int customerAge=0;
    int weightLuggage=0;
    int youPay=0;

    scanf("%d",&customerAge);
    scanf("%d",&weightLuggage);
    
    if(customerAge==60){
        youPay=0;
    }else if(customerAge<10){
        youPay=5;
    }else{
        youPay=30;
        if(weightLuggage>20){
            youPay=youPay+10;
        }
    }
    printf("%d\n",youPay);
    
    return 0;
}
