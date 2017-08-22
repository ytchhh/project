#include"utili.h"

int main()
{
    int sockCli = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockCli == -1)
    {
        perror("socket");
    }

    struct sockaddr_in addrSer,addrCli;
    addrSer.sin_family = AF_INET;
    addrSer.sin_port = htons(SERVER_PORT);
    addrSer.sin_addr.s_addr = inet_addr(SERVER_IP);

    socklen_t len = sizeof(struct sockaddr);
    char sendbuf[MAX_BUFFER_SIZE];
    char recvbuf[MAX_BUFFER_SIZE];

    while(1)
    {
        printf("Cli:>");
        scanf("%s",sendbuf);
        sendto(sockCli, sendbuf, strlen(sendbuf)+1, 0, (struct sockaddr*)&addrSer, len);

        recvfrom(sockCli, recvbuf, MAX_BUFFER_SIZE, 0, (struct sockaddr*)&addrSer, &len);
        printf("Ser:>%s\n",recvbuf);

    }

    close(sockCli);
    return 0;
}
