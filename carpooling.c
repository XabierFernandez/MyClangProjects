#include <stdio.h>

int main(void) {
 
    int passengers=0;
    double costGasTrip =0.0;
    double youPay=0;

    scanf("%d%lf",&passengers,&costGasTrip);
    if(passengers>0){
       youPay=(costGasTrip + 1)/(passengers+1); 
    }else{
        youPay=costGasTrip; 
    }
    
    printf("%.2lf\n",youPay);

    return 0;
}