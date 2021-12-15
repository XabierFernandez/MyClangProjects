#include <stdio.h>


int main(void) {

    char name[50];
    int scores[30];
    
    int numStudents=0;

    int i, j, score, rank;

    scanf("%d", &numStudents);
    for (i=0; i<numStudents; i++) {
        scanf("%d", &score);
        scores[i]=score;
    }

    for (i=0; i<numStudents; i++) {
        scanf("%s", name);
        rank=numStudents;
        for (j=0;j<numStudents;j++){
            if (scores[i]>scores[j+1]){
                if(rank>0){
                    rank--;
                }
            }else if(scores[i]<scores[j+1]){
                rank++;
            }
        }  
        printf("%s rank is %d\n", name,rank);  
    }
    

    return 0;
}