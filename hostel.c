#include <stdio.h>

int main(void) {
 
    int hourPastNoon=0;
    int baseprice=10;
    int feePerHourAfterNoon=5;
    int youPay=0;

    scanf("%d",&hourPastNoon);
    youPay=10+(hourPastNoon*feePerHourAfterNoon);

    if(youPay>53){
       youPay=53; 
    }

    printf("%d\n",youPay);

    return 0;
}