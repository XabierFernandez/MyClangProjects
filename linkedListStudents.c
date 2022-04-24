#include <stdio.h>
#include <stdlib.h>

struct student {
      char name[50];
      int age;
      struct student *next;
};

struct student *createStudent(char studentName[], int studentAge);

// Write other function prototypes here (if any)

int main(void) {
    struct student *studptr;
    int myAge;
    char myName[50];
    scanf("%s %d", myName, &myAge);
    studptr = createStudent(myName, myAge);
    printf("New student created: %s is %d years old.\n", studptr->name, studptr->age);
    free(studptr);
    return 0;
}

// Write your createStudent function here (and any other functions you see fit)

struct student *createStudent(char studentName[], int studentAge){
    struct student * ptr;
    int i = 0;
    int studentNameLength=0;
    ptr = (struct student *) malloc(sizeof(struct student));
    studentNameLength = sizeof(studentName);
 
    //while (studentName[i]!='\0') {
    //    ptr->name[i] = studentName[i];
    //    i++;
    //}
    for (i=0;i<studentNameLength;i++){
        ptr->name[i] = studentName[i];
    }
    

    ptr->age = studentAge;
    ptr->next = NULL;
    return ptr;
}