#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

void error(char *msg)
{
fprintf(stderr,"%s:%s",msg,strerror(errno));
exit(1);
}


int main(int argc, char *argv[]){
    char *feeds[] = {"http://www.msn.com/rss/MsnEntertainment.aspx",
                    "https://www.rollingstone.com/rock.xml",
                    "https://eonline.com/gossip.xml", NULL};
    int times = 3;
    char *phrase = argv[1];
    int i;
    for(i = 0; i<times; i++){
        char var[255];
        sprintf(var,"RSS_FEED=%s", feeds[i]);
        char *vars[] = {var,NULL};
        pid_t pid = fork();
        if(pid == -1){
            error("Can't run script: ");
        }
        if(!pid){
            if(execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py", phrase, NULL, vars ) == -1){
                error("Can't run script: ");
            }
        }        
    }
    return 0;
}