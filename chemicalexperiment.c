#include <stdio.h>

int main(void) {
    int temperature = 0;
    int maxlimit = 0;
    int minlimit = 0;
    int flagAlert   = 0;
    
    scanf("%d %d", &minlimit, &maxlimit); 
    while (temperature != -999) {  
        scanf("%d", &temperature); 
        if((temperature != -999)&&(flagAlert == 0)){  
            if((temperature >= minlimit)&&(temperature <= maxlimit)){
                printf("Nothing to report\n"); 
            }else{
                printf("Alert!\n");
                flagAlert=1;
            } 
        }      
    }

    return 0;
}