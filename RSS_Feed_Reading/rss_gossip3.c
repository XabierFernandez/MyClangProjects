#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include <sys/wait.h>

void open_url(char *url){
    char launch[255];
    sprintf(launch, "cmd /c start %s", url);
    system(launch);
    sprintf(launch, "x-www-browser '%s' &", url);
    system(launch);
    sprintf(launch, "open '%s'", url);
    system(launch);
}

void error(char *msg)
{
    fprintf(stderr,"%s:%s",msg,strerror(errno));
    exit(1);
}

void die_die(int sig){
    puts("Goodbye cruel world!!");
    exit(1);
}

int catch_signal(int sig, void (*handler)(int)){
    struct sigaction action;
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    return sigaction(sig, &action, NULL);
}

int main(int argc, char *argv[])
{
    if(catch_signal(SIGINT, die_die) == -1){
        error("Can't map the handler");
    }
    char *phrase = argv[1];
    char *vars[] = {"RSS_FEED=https://www.hindustantimes.com/feeds/rss/astrology/rssfeed.xml", NULL};
    int fd[2];

    if(pipe(fd) == -1){
        error("Can't create pipe");
    }

    pid_t pid = fork();
    if (pid == -1) {
        error("Can't fork process");
    }
    if (!pid) {
        dup2(fd[1],1); // this will set standard output to the write end of the pipe
        close(fd[0]);  // the child won't read from the pipe, so we'll close the read end
        if (execle("/usr/bin/python3", "/usr/bin/python3", "./rssgossip2.py", "-u",
        phrase, NULL, vars) == -1) {
            error("Can't run script");
        }
    }
    dup2(fd[0], 0); // this will redirect the standard input to reas end of the pipe
    close(fd[1]);   // this will close the write end of the pipe because the parent won't write to it
    char line[255];
    while(fgets(line, 255, stdin)){
        printf("%s", line);
        if(line[0] == '\t'){
            open_url(line + 1);
        }
    }
    return 0;
}

