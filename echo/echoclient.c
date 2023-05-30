#include "csapp.h"

int main(int argc, char **argv){ //argc: Argument count argv: Argument vector
    int clientfd;
    char *host, *port, buf[MAXLINE];
    rio_t rio;

    if(argc != 3){ 
        fprintf(stderr, "usage: %s <host> <port>\n", argv[0]); //argv[0]: program name itself, arg[3]: NULL
        exit(0);                                               //arg[1] & arg[2] : arg1, arg2                      
    }
    host = argv[1];
    port = argv[2];

    clientfd = Open_clientfd(host,port);
    Rio_readinitb(&rio, clientfd);

    while (Fgets(buf, MAXLINE, stdin) != NULL){
        Rio_writen(clientfd, buf, strlen(buf));
        Rio_readlineb(&rio, buf, MAXLINE);
        Fputs(buf, stdout);
    }
    Close(clientfd);
    exit(0);
}