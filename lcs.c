#include <stdio.h>
#include <stdlib.h>

int lcs(int, char *, int, char *);
int max(int num1, int num2);
char * allocateCharArray(int);
void printChar(char *);

//--------------------------------------
int lcs(int m, char *x, int n, char *y) 
{ 
    int dp[m + 1][n + 1]; 
    int i, j; 
   
    for (i = 0; i <= m; i++) 
    { 
        for (j = 0; j <= n; j++) 
        { 
            if(i == 0 || j == 0) 
                dp[i][j] = 0; 
            else if (x[i-1] == y[j-1]) 
                dp[i][j] = dp[i-1][j-1] + 1; 
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
        } 
    } 

    return dp[m][n];
}
//--------------------------------------
char * allocateCharArray(int num){
    char * ptr = (char *) malloc(num * sizeof(char));
    return ptr;
}
//--------------------------------------
int max(int a, int b) 
{  
    return (a > b) ? a : b;  
}
//--------------------------------------
int main()
{
    int i, m, n, result;
    char *x;
    char *y;

    //------------------------------------------
    printf("\nEnter number of characters of m: ");
    scanf("%d", &m);
    x = allocateCharArray(m);
    scanf("%s", x);
    printf("str introduced: %s\n", x);
    //------------------------------------------
    printf("Enter number of characters of n: ");
    scanf("%d", &n);
    y = allocateCharArray(n);
    scanf("%s", y);
    printf("str introduced: %s\n", y);
    //------------------------------------------
    char * str1 = "editing";
    char * str2 = "distance";
    //result = lcs(m, x, n, y);
    result = lcs(7, str1, 8, str2);
    printf("Result: %d \n", result);
    free(x);
    free(y);

	return 0;
}