#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <signal.h>
#include <pthread.h>

#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "netutils.h"
#include "command.h"
#include "miscutils.h"
#include "configparser.h"
#include "logutils.h"

const int STR_MAX_LEN = 1024;

void sighandler(int signo)
{
    CommandExecuter::runningflag = 0;
}

int main(int argc, char** argv)
{
    string myname, port;
    int sockfd, ret;
    sockaddr_in myaddr;
    sockaddr_in peeraddr;
    socklen_t len;
    pthread_t tid;
    char buff[64];

    miscutils::initdaemon(argc, argv);

    gethostname(buff, 64);

    gparser->initkvmap("conf/lasync.conf");

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd == -1)
    {
        perror("socket");
        goto ERROR;
    }

    ret = gparser->getvalue("port", port);
    if(!ret)
    {
        glogger << "cannot get server listen port" << endl;
        goto ERROR;
    }

    myaddr.sin_family = AF_INET;
    myaddr.sin_port = htons(atoi(port.c_str()));
    myaddr.sin_addr.s_addr = INADDR_ANY;

    len = sizeof(struct sockaddr);

    ret = bind(sockfd, (struct sockaddr*)&myaddr, len);
    if(ret == -1)
    {
        perror("bind");
        goto ERROR;
    }

    ret = pthread_create(&tid, NULL, CommandExecuter::executecmd, NULL);
    if(ret)
    {
        glogger << "cannot create thread" << endl;
        goto ERROR;
    }

    while(1)
    {
        char recvbuf[STR_MAX_LEN];
        int msglen = recvfrom(sockfd, recvbuf, STR_MAX_LEN, 0, (struct sockaddr*)&peeraddr, &len);
        CommandExecuter::extractmsg((char*)recvbuf, msglen, peeraddr, myname);
    }
    return 0;

ERROR:
    close(sockfd);
    exit(1);
}

