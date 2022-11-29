#include <stdio.h>

int main(void) {
    FILE *ifile;  
    int N, result, done;
    float avgYourClass, num;

    ifile = fopen("gradeComparison.txt", "r"); 

    done = 0;                            
    N=0;
    avgYourClass = 0;
    result = 0;
    
    while ((fscanf(ifile, "%f", &num)!= EOF) && !done) {
            if (N==0){
                avgYourClass = num;
            }else{
                if(num > avgYourClass){
                   result = 1; 
                   done = 1;
                }
            }
            
            N++;
    }
    
    fclose(ifile);
    
    if(result){
         printf("No %d\n", N);
    }else{
        printf("Yes\n");
    }
    
    return 0;
}

