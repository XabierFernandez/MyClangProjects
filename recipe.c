#include <stdio.h>

int main(void) {
 
    int arrIngredients[10];
    int ingredient=0;
    int id=0;
    int i=0;

    for(i=0;i<10;i++){
        scanf("%d",&ingredient);
        arrIngredients[i]=ingredient;
    }
    scanf("%d",&id);
    printf("%d\n",arrIngredients[id]);

    return 0;
}
