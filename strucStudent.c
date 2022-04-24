#include <stdio.h>


struct student{
	char firstName[30];
	char lastName[30];
	int birthYear;
	double aveGrade;
};

void printStudent(struct student stud);
void printStudentPtr(struct student *stud);
void readStudent(struct student *studptr);

int main(void) {
    
    struct student me={"Petra", "Bonfert-Taylor", 1989, 3.5};
	struct student you={"Remi", "Sharrock", 2005, 3.5};
	struct student *metoo;

    readStudent(&metoo);
	printStudent(me);
	printStudent(you);
    printStudentPtr(&metoo);

    struct student learner;
    printf("First name: ");
    scanf("%s", learner.firstName);
    printf("Last name: ");
    scanf("%s", learner.lastName);
    printf("Year of birth:");
    scanf("%d", &learner.birthYear);
    printf("Average grade: ");
    scanf("%lf", &learner.aveGrade);
    
    printf("Name: %s %s\n", learner.firstName, learner.lastName);
	printf("Year of birth: %d\n",learner.birthYear);
	printf("Average grade: %.2lf\n",learner.aveGrade);
    
	return 0;
}

void readStudent(struct student *studptr) {
    printf("\nEnter a new student record: \n");
    printf("First name: ");
    scanf("%s", (*studptr).firstName);
    printf("Last name: ");
    scanf("%s", (*studptr).lastName);
    printf("Birth year: ");
    scanf("%d", &(*studptr).birthYear);
    printf("Average grade: ");
    scanf("%lf", &(*studptr).aveGrade);
}

void printStudent(struct student stud){
    printf("Name: %s %s\n", stud.firstName, stud.lastName);
	printf("Year of birth: %d\n",stud.birthYear);
	printf("Average grade: %.2lf\n",stud.aveGrade);
}

void printStudentPtr(struct student *stud){
    printf("Name: %s %s\n", (*stud).firstName, (*stud).lastName);
	printf("Year of birth: %d\n",(*stud).birthYear);
	printf("Average grade: %.2lf\n",(*stud).aveGrade);
}