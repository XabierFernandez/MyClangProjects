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

int beers = 2000000;
pthread_mutex_t beers_lock = PTHREAD_MUTEX_INITIALIZER;
void* drink_lots(void *a){
    int i;
    pthread_mutex_lock(&beers_lock);
    for(i = 0; i < 100000; i++){
        beers = beers -1;
    }
    pthread_mutex_unlock(&beers_lock);
    printf("beers = %i\n", beers);
    return NULL;
}


int main(int argc, char *argv[]){  
    // this variable records all the 
    // information about the thread  
    pthread_t threads[20];
    int thrd;
    printf("%i bottles of beer on the wall\n%i bottles of beer\n", beers, beers);
    for(thrd = 0; thrd < 20; thrd++){
        pthread_create(&threads[thrd], NULL, drink_lots, NULL);
    }
    void* result;
    for(thrd = 0; thrd < 20; thrd++){
        pthread_join(threads[thrd], &result);
    }
    printf("There are now %i bottles of beer on the wall\n", beers);
    return 0;
}