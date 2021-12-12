#include <stdio.h>

int main(void) {

    char firstname[20]; //arrray of characters (string)
    char lastname[20]; //arrray of characters (string)
    char tempCharFirstname;
    char tempCharLastname;
    int numOfPersons=0;

    scanf("%d", &numOfPersons);
    for (int i=0;i<numOfPersons;i++){
        scanf("%s", firstname);
        scanf("%s", lastname);
        for(int j=0;j<20;j++){
            tempCharFirstname=firstname[j];
            tempCharLastname=lastname[j];
            lastname[j]=tempCharFirstname;
            firstname[j]=tempCharLastname;
        }
        printf("%s %s\n",firstname, lastname);

    }

    return 0;
}
