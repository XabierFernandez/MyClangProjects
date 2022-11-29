#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *ifile;  
    FILE *ofile;

    char filename[] = "myGrades.txt";
    int num, lastNum, myGrade;


    scanf("%d", &myGrade);
    lastNum = 0;
    //==============================
    ifile = fopen(filename, "r"); 
    while (fscanf(ifile, "%d", &num)!= EOF) {
            lastNum = num;         
    }    
    fclose(ifile);
    //==============================
    if(lastNum!=myGrade){
        ofile = fopen(filename, "a"); 
        fprintf(ofile, " %d", myGrade); 
        fclose(ofile);
    }
    //==============================
    ifile = fopen(filename, "r"); 
    while (fscanf(ifile, "%d", &num)!= EOF) {
            printf("%d ",num);
    }    
    fclose(ifile);
    //==============================
    
    return 0;
}