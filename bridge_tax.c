#include <stdio.h>

int main(void) {
 
    int die1=0;
    int die2=0;
    int specialTax=36;
    int youPay=0;

    scanf("%d%d",&die1,&die2);
    youPay=die1+die2;

    if(youPay>=10){
       youPay=36; 
       printf("Special Tax\n%d\n",youPay);
    }else{
        youPay=youPay*2; 
       printf("Regular Tax\n%d\n",youPay);
    }

    return 0;
}