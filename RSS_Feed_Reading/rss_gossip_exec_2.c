#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

/* minimum required number of parameters */
#define MIN_REQUIRED 2

/* display usage */
int help() {
   printf("Usage: program [-u ] [-h ] 'string'\n");
   printf("\ta string \n");
   printf("\t-u: a string \n");
   printf("\t-h: a single parameter\n");

   return 1;
}

void error(char *msg)
{
    printf("err\n");
    fprintf(stderr,"%s:%s",msg,strerror(errno));
}


int main(int argc, char *argv[]){
    char *feeds[] = {"https://www.hindustantimes.com/feeds/rss/astrology/rssfeed.xml",
                    "https://www.hindustantimes.com/feeds/rss/books/rssfeed.xml",
                    "https://www.hindustantimes.com/feeds/rss/business/rssfeed.xml"};
    int times = 3;
    int select = 0;
    char *opt = NULL;
    char *phrase = NULL;
    //printf("argc:%d\n", argc);
    

    if (argc < MIN_REQUIRED) {
      return help();
    }
    else if((argc==2) && (strcmp("-h", argv[1]) != 0) && (strcmp("-u", argv[1]) != 0)){
        phrase = argv[1];
        /* printf("argv[1]:%s\n", argv[1]);
        printf("comp1\n"); */
        select = 1;
    }
    else if((argc==2) && (strcmp("-h", argv[1]) == 0)){
        return help();
    }
    else if((argc==3) && (strcmp("-u", argv[1]) == 0)){
        opt = argv[1];
        phrase = argv[2];
        /* printf("argv[1]:%s\n", argv[1]);
        printf("argv[2]:%s\n", argv[2]);
        printf("comp2\n"); */
        select = 2;
    }
    else{
        return help();
    }


//printf("phrase:%s\n",phrase);


    int i;
    for(i = 0; i<times; i++){
        char var[255];
        sprintf(var,"RSS_FEED=%s", feeds[i]);
        char *vars[] = {var,NULL};
        pid_t pid = fork();
        if(pid == -1){
            error("Can't run script: ");
            return 1;
        }
        if(!pid){
            if(select==1){
                if(execle("/usr/bin/python3", "/usr/bin/python3", "rssgossip.py", phrase, NULL, vars) == -1){
                    error("Can't run script: ");
                    return 1;               
                }
            }
            if(select==2){
                if(execle("/usr/bin/python3", "/usr/bin/python3", "rssgossip.py", opt, phrase, NULL, vars) == -1){
                    error("Can't run script: ");
                    return 1;               
                }
            }
            
        }        
    }
    return 0;
}