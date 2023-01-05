#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>

void error(char *msg)
{
    printf("err\n");
    fprintf(stderr,"%s:%s",msg,strerror(errno));
}

int read_in(int socket, char *buf, int len){
    char *s = buf;
    int slen = len;
    int c = rev(socket, s, slen, 0);
    while((c > 0) && (s[c-1] != '\n')){
        s += c;
        slen -= c;
        c = recv(socket, s, slen, 0);
    }
    if(c < 0) return c;
    else if(c == 0) buf[0] = '\0';
    else s[c - 1] = '\0';

    return len - slen;
}

int main(int argc, char *argv[]){
    int listener_d = socket(PF_INET, SOCK_STREAM, 0);
    if(listener_d == -1) error("Can't open socket");
    int reuse = 1;
    if(setsockopt(listener_d, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(int)) == -1)
        error("Can't set the reuse option on the socket");
    struct sockaddr_in name;
    name.sin_family =PF_INET;
    name.sin_port = (in_port_t)htons(30000);
    name.sin_addr.s_addr = htonl(INADDR_ANY);
    int c = bind (listener_d, (struct sockaddr *) &name, sizeof(name));
    if(c == -1) error("Can't bind socket");
    if(listen(listener_d, 10) == -1) error("Can't listen");

    while(1){
        struct sockaddr_storage client_addr;
        unsigned int address_size = sizeof(client_addr);
        int connect_d = accept(listener_d, (struct sockaddr *)&client_addr, &address_size);
        if(connect_d == -1) error("Can't open secondary socket");
        char *msg = "Internet Knock-Knock Protocol Server\r\nVersion 1.0\r\nKnock! Knock!\r\n>";
        if(send(connect_d, msg, strlen(msg), 0) == -1) error("send");
        close(connect_d);
    }

    

    return 0;
}