#include <stdio.h>

int main(void) {
 
    int membersPerTeams=0;
    int weightTeam_1=0;
    int weightTeam_2=0;
    int weightMember_1=0;
    int weightMember_2=0;
    int i;
    int j;
    scanf("%d",&membersPerTeams);
    for(i=0;i<membersPerTeams;i++){
        scanf("%d",&weightMember_1);
        weightTeam_1=weightTeam_1+weightMember_1;
        scanf("%d",&weightMember_2);
        weightTeam_2=weightTeam_2+weightMember_2;
    }
    

    if(weightTeam_1>weightTeam_2){
        printf("Team 1 has an advantage\n");
    }else if(weightTeam_2>weightTeam_1){
        printf("Team 2 has an advantage\n");
    }else{
        printf("Both teams have the same chances\n");
    }
    printf("Total weight for team 1: %d\n",weightTeam_1);
    printf("Total weight for team 2: %d\n",weightTeam_2);
    return 0;
}