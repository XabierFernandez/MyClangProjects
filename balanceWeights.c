#include <stdio.h>

int main(void) {
 
    double arrWeightOfCar[50];
    int numOfCars=0;
    double weightOfCar=0;
    double totalWeightOfCar=0;
    int i=0;

    scanf("%d",&numOfCars);

    for(i=0;i<numOfCars;i++){
        scanf("%lf",&weightOfCar);
        arrWeightOfCar[i]=weightOfCar;
        totalWeightOfCar=totalWeightOfCar + weightOfCar;
    }

    for(i=0;i<numOfCars;i++){
        printf("%.1lf\n",(totalWeightOfCar/numOfCars) - arrWeightOfCar[i]);
    }

    return 0;
}