#include <stdio.h>

/*
A delivery company has hired you to manage their tracking services division. 
It is your job to store all of the currently used tracking codes in the company's database. 
These codes consist of either all integers, all decimal numbers, or all characters. 
The chief technology officer has warned you that the database is old and has limited space, 
so you want to determine how much memory the tracking codes will occupy before storing them. 
You decide to write a program to assist you in this process. 

Your program should first read an integer number indicating how many tracking codes you plan on entering. 
Next, for each successive tracking code your program should read in the integer length of code followed by 
a space and then the type of code ('i' for integer, 'd' for decimal, or 'c' for character). 
Finally your program should print the total amount of space required to store all of the tracking codes (in bytes). 
If the user enters an incorrect type for any tracking number, the program should print 'Invalid tracking code type' and exit.
*/

int main(){
    int numberOfTrackingCodes, trackingCodeLength, i;
    long unsigned int sum=0;
    char typeCode;
    int invalid = 0;

    scanf("%d",&numberOfTrackingCodes);
    for(i=0;i<numberOfTrackingCodes;i++){
        scanf("%d %c",&trackingCodeLength, &typeCode);
        if(typeCode == 'i'){
            sum = sum + (trackingCodeLength * 4);
        }
        else if(typeCode == 'd'){
            sum = sum + (trackingCodeLength * 8);
        }
        else if(typeCode == 'c'){
            sum = sum + (trackingCodeLength * 1);
        }
        else{
            printf("Invalid tracking code type\n");
            invalid = 1;
            break;
        }
    }
    if (invalid == 0){
        printf("%zu bytes\n", sum);
    }
}