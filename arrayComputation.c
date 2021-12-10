#include <stdio.h>

int main(void) {
 
    double ingredientsPrices[10];
    double ingredientsWeights[10];
    double ingredientsPrice=0.0;
    double ingredientsWeight=0.0;
    int numIngredients=0;
    double total=0.0;
    int i;

    scanf("%d",&numIngredients);
    for(i=0;i<numIngredients;i++){
        scanf("%lf",&ingredientsPrice);
        ingredientsPrices[i]=ingredientsPrice;
    }

    for(i=0;i<numIngredients;i++){
        scanf("%lf",&ingredientsWeight);
        ingredientsWeights[i]=ingredientsWeight;
    }

    for(i=0;i<numIngredients;i++){
        total=total + (ingredientsWeights[i]*ingredientsPrices[i]);
    }
    
    printf("%lf\n",total);

    return 0;
}