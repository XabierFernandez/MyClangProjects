int main(void) {
    int length, width, i, j, value;
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
            arrayArea[i][j] = arrayLength[j];
        }
    }
    free(arrayLength);

    //write output
    for(i=0;i<width;i++){
        for(j=0;j<length;j++){ 
            value = arrayArea[i][j];
            if( value > 1000){
                printf("[X]");
            }
            else if( value >= 100){
                printf("[*]");
            }
            else{
                printf("[ ]");
            }
        }
        printf("\n");
    }
    //write values to the output
    for(i=0;i<width;i++){
        for(j=0;j<length;j++){ 
            printf("%d\n", arrayArea[i][j]);
        }
    }

	
    free(arrayArea);

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