#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>


void error(char *msg)
{
    printf("err\n");
    fprintf(stderr,"%s:%s\n",msg,strerror(errno));
}

void * does_not(void *a){
    int i = 0;
    for(i = 0; i < 5; i++){
        sleep(1);
        puts("Does not!");
    }

    return NULL;
}

void * does_too(void *a){
    int i = 0;
    for(i = 0; i < 5; i++){
        sleep(1);
        puts("Does too!");
    }

    return NULL;
}

int main(int argc, char *argv[]){  
    // this variable records all the 
    // information about the thread  
    pthread_t t0;
    pthread_t t1;
    // Createthe threads
    if(pthread_create(&t0, NULL, does_not, NULL) == -1)
        error("Can't create thread t0");
    if(pthread_create(&t0, NULL, does_too, NULL) == -1)
        error("Can't create thread t1");
    
    void* result;
    if(pthread_join(t0, &result) == -1)
        error("Can't join thread t0");
    if(pthread_join(t1, &result) == -1)
        error("Can't join thread t1");
    
    return 0;
}