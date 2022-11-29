#include<stdio.h>

#define SIZE 8 

int binarySearch(int arr[], int start, int end, int key)
{
    int mid;
    
    while(start <= end)
    {
        mid = (start + end) / 2;
      
        if(arr[mid] == key)
            return 1;
         
        if(arr[mid] < key)
             start = mid + 1;
        else
             end = mid - 1;
    }
     
    return 0;
}

int main()
{

    int page_number[SIZE] = {10, 23, 45, 70, 90, 100, 111, 123};

    int key = 45;

    printf("Searching Element: %d\n",key);

    if(binarySearch(page_number,0,SIZE - 1, key) == 1)
        printf("Search Found\n");
    else
        printf("Search Not Found\n");

    key = 150;

    printf("Searching Element: %d\n",key);

    if(binarySearch(page_number,0,SIZE - 1, key) == 1)
        printf("Search Found\n");
    else
        printf("Search Not Found\n");

    return 0;
}
