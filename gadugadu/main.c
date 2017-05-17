/*
 ** showip.c -- show IP addresses for a host given on the command line
 */

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>

#define PORT "3490"
#define SERVER_IP "localhost"

#define MSG 48 
void server();
void client();
// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }

    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}
int main(int argc, char *argv[])
{
#ifdef SERVER
    server();
#else
    client();
#endif

    return 0;
}

void client()
{
    struct addrinfo hints, *res;
    int sockfd;

    printf("\nCLIENT\n");

    // first, load up address structs with getaddrinfo():

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    getaddrinfo(SERVER_IP, PORT, &hints, &res);

    // make a socket:

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    // connect!

    int c = connect(sockfd, res->ai_addr, res->ai_addrlen);
    if (c < 0)
    {
        fprintf(stderr, "connect error\n");
        return;
    }

    //    char msg[MSG];

    //char msg[MSG];
    char *msg = (char*)malloc(sizeof(char)*MSG);
    memset(msg, 0, sizeof(char)*MSG);

    sprintf(msg, "Hello World!I am a client!");
    //char *msg = "Hello World!";
    const char *cmsg=msg;
    if( 0 >= send(sockfd, cmsg, /*strlen(cmsg)*/MSG, 0))
    {
        fprintf(stderr, "send error \n");
        return;

    }
    int r=recv(sockfd, msg, MSG, 0);

    if (r < 0)
    {
        fprintf(stderr, "receive error %d\n", r);
        return;
    }else
    printf("%s\n", msg);
}


void server()
{
    struct addrinfo hints, *res;

    printf("\nSERVER\n");

    // SOCKET and BIND

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;  // use IPv4 or IPv6, whichever
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;     // fill in my IP for me

    getaddrinfo(NULL, PORT, &hints, &res);

    int s = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    if (s < 0)
    {
        fprintf(stderr, "socket descriptor error\n");
        return;
    }

    int yes=1;
    setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));

    bind(s, res->ai_addr, res->ai_addrlen);

    int l=listen(s, 10);

    if (l < 0)
    {
        fprintf(stderr, "listen error\n");
        return;
    }
    struct sockaddr_storage their_addr;
    socklen_t addr_size = sizeof their_addr;
    printf("server: waiting for connections...\n");
    int new_fd;
    int i=0;

    new_fd = accept(s, (struct sockaddr *)&their_addr, &addr_size);    

    while(1)
    {
        if(new_fd < 0)
            continue;

        char str[INET6_ADDRSTRLEN];
        inet_ntop(their_addr.ss_family,
                  get_in_addr((struct sockaddr *)&their_addr),
                  str, sizeof str);
        printf("server: got connection from %s\n", str);


        char *msg = (char*)malloc(sizeof(char)*MSG);
        memset(msg, 0, sizeof(char)*MSG);

        sprintf(msg, "Hello World! I am server %d ", i++);
        const char *cmsg=msg;
        if( 0 >= send(new_fd, cmsg, MSG, 0))
        {
            fprintf(stderr, "send error \n");
            return;

        }
        memset(msg, 0, sizeof(char)*MSG);
        
        int r=recv(new_fd, msg, MSG, 0);

        if (r < 0)
        {
            fprintf(stderr, "receive error %d\n", r);
            return;
        }else
        {
            printf("\n%s\n", msg);
            return;
        }

    }

}
