#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    FILE *my_file = fopen("gcc_command.txt", "r");
    int descriptor = fileno(my_file);
    printf("\nFile descriptor number=%d\n", descriptor);
    dup2(4, 3);
    descriptor = fileno(my_file);
    printf("\nFile descriptor number=%d\n", descriptor);

    return 0;
}