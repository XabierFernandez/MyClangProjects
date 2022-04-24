#include <stdio.h>

struct date {
        int year;
        int month;
        int day;
    };

/* function prototypes */
void printDate(struct date);
void readDate(struct date *);
struct date advanceDay(struct date); 

int main(void) {
	struct date today, tomorrow;
	readDate(&today);
	printDate(today);
	tomorrow = advanceDay(today);
	printDate(tomorrow);
	return 0;
}

/* add your function definitions here */
void readDate(struct date *dateptr) {
    scanf("%d %d %d", &(*dateptr).year, &(*dateptr).month, &(*dateptr).day);
}

void printDate(struct date dt){
	if(dt.month<10){
		printf("0%d/", dt.month);
	}else{
		printf("%d/", dt.month);
	}  
	
	if(dt.day<10){
		printf("0%d/", dt.day);
	}else{
		printf("%d/", dt.day);
	}    
    printf("%d\n", dt.year);    
}

struct date advanceDay(struct date dt){
	struct date tomorrow;
	int monthsDays [12] ={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if(dt.month==12 && dt.day==31){
		tomorrow.year=dt.year + 1;
		tomorrow.month=1;
		tomorrow.day=1;
	}
	else if(dt.day==monthsDays[(dt.month-1)]){
		tomorrow.year=dt.year;
		tomorrow.month=dt.month + 1;
		tomorrow.day=1;		
	}else{
		tomorrow.year=dt.year;
		tomorrow.month=dt.month;
		tomorrow.day=dt.day + 1;	
	}

	return tomorrow;
}






