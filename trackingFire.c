#include <stdio.h>
#include <stdlib.h>
// Be sure to include any other library you may need...

/*
You have been hired to assist firefighters locate wildfires in a large geographic area. 
The area is divided into smaller zones. Each zone is scanned via satellite for its average temperature. 
If a zone has an average temperature strictly greater than 1000°F, we assume there is a fire in that zone. 
If the temperature is between 100 degrees (included) and 1000 degrees (included), we have to further investigate, 
so it becomes a "zone to watch."

The large geographic area you are watching is a rectangle with a certain length and width, 
each given in terms of zones. For example, if the area to be scanned  has a length of 6 and 
width of 9 then it will be divided into 6*9 zones:

----length = 6----
[ ][ ][ ][ ][ ][ ]   |
[ ][ ][ ][ ][ ][ ]   w
[ ][ ][ ][ ][ ][ ]   i
[ ][ ][ ][ ][ ][ ]   d
[ ][ ][ ][ ][ ][ ]   t
[ ][ ][ ][ ][ ][ ]   h
[ ][ ][ ][ ][ ][ ]   =
[ ][ ][ ][ ][ ][ ]   9
[ ][ ][ ][ ][ ][ ]   |

Input:
6
9
70   71   70   72   70   69
71   73   68   71   73   72
70   71   70   76   1900 78
69   71   100  800  75   71
70   70   71   79   70   69
70   71   112  1005 75   72
70   71   70   900  70   70
72   70   70   72   70   69
73   74   73   72   70   70

[ ][ ][ ][ ][ ][ ]
[ ][ ][ ][ ][ ][ ]
[ ][ ][ ][ ][X][ ]
[ ][ ][*][*][ ][ ]
[ ][ ][ ][ ][ ][ ]
[ ][ ][*][X][ ][ ]
[ ][ ][ ][*][ ][ ]
[ ][ ][ ][ ][ ][ ]
[ ][ ][ ][ ][ ][ ]

*/

// Write your allocateString() prototype here
int ** allocateIntStarArray(int);
int * allocateIntArray(int);

int main(void) {
    int length, width, i, j;
    int * arrayLength;
    int ** arrayArea;

    scanf("%d", &length); 
    scanf("%d", &width);  

    arrayArea = allocateIntStarArray(width);
    arrayLength = allocateIntArray(length);

    //read input and initializa array
    for(i=0;i<width;i++){        
        for(j=0;j<length;j++){
            scanf("%d", &arrayLength[j]);           
            if( arrayLength[j] > 1000){
                printf("[X]");
            }
            else if( arrayLength[j] >= 100 && arrayLength[j] <= 1000){
                printf("[*]");
            }
            else{
                printf("[ ]");
            }              
        }
        arrayArea[i] = &arrayLength[0];
        printf("\n");
    }
    

    
    //write values to the output
    //for(i=0;i<width;i++){
    //   for(j=0;j<length;j++){ 
    //        printf("%d\n", arrayArea[i][j]);
    //   }
    //}

	
    free(arrayArea);
    free(arrayLength);

    return 0;
}

int ** allocateIntStarArray(int num){
    int ** ptr = (int **) malloc(num * sizeof(int *));
    return ptr;
}

int * allocateIntArray(int num){
    int * ptr = (int *) malloc(num * sizeof(int));
    return ptr;
}