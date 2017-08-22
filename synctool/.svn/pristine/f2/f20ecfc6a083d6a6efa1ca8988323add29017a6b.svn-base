#include"utili.h"

int main()
{
    int sockSer = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockSer == -1)
    {
        perror("socket");
    }

    struct sockaddr_in addrSer,addrCli;
    addrSer.sin_family = AF_INET;
    addrSer.sin_port = htons(SERVER_PORT);
    addrSer.sin_addr.s_addr = inet_addr(SERVER_IP);

    socklen_t len = sizeof(struct sockaddr);
    int res = bind(sockSer, (struct sockaddr*)&addrSer, len);
    if(res == -1)
    {
        perror("bind");
    }

    char sendbuf[MAX_BUFFER_SIZE];
    char recvbuf[MAX_BUFFER_SIZE];

    while(1)
    {
        recvfrom(sockSer, recvbuf, MAX_BUFFER_SIZE, 0, (struct sockaddr*)&addrCli, &len);
        printf("Cli:>%s\n",recvbuf);

        printf("Ser:>");
        scanf("%s",sendbuf);
        sendto(sockSer, sendbuf, strlen(sendbuf)+1, 0, (struct sockaddr*)&addrCli, len);
    }

    close(sockSer);
    return 0;
}
