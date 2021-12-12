#include <stdio.h>

int main(void) {
    int sum=0;
    int expenditure;
    scanf("%d", &expenditure);
    while (expenditure!=-1) {
        sum = sum + expenditure;
        scanf("%d", &expenditure);
    }
    printf("%d\n",sum);
    return 0;
}
