#include <stdio.h>

int min(int num1, int num2);

int main(){
    int countNumbers=0;
    int i;
    int num=0;
    int prevnum=0;
    scanf("%d",&countNumbers);
    for (i=0;i<countNumbers;i++){
        scanf("%d",&num);
        prevnum = min(num,prevnum);
    }
    printf("%d",prevnum);
}


int min(int num1, int num2){

    if (num1 < num2){
        return num1;
    }else if (num1 > num2){
        return num2;
    }else{
        return num1;
    } 

}