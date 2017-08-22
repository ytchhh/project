#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<errno.h>
#include<sys/types.h>
int port=8888;

int main(int argc,char *argv[])
{
		int sockfd;
		int i=0;
		int z;
		char buf[80],str1[80];
		struct hostent *host;
		struct sockaddr_in adr_srvr;
		if(argc<2){
				fprintf(stderr,"please enter the server's hostname!\n");
				exit(1);
		}
		if((host=gethostbyname(argv[1]))==NULL){
				herror("gethostbyname error!");
				exit(1);
		}
		FILE *fp;
		printf("open file....\n");
		fp=fopen("liu","r");
		if(fp==NULL){
				perror("failed to open file");
				exit(1);
		}
		printf("connecting server....\n");
		adr_srvr.sin_family=AF_INET;
		adr_srvr.sin_port=htons(port);
		adr_srvr.sin_addr=*((struct in_addr *)host->h_addr);
		bzero(&(adr_srvr.sin_zero),8);
		sockfd=socket(AF_INET,SOCK_DGRAM,0);
		if(sockfd==-1){
				perror("socket error!");
				exit(1);
		}
		printf("send file ...\n");
		for(i=0;i<3;i++){
				fgets(str1,80,fp);
				printf("%d:%s",i,str1);
				sprintf(buf,"%d:%s",i,str1);
				z=sendto(sockfd,buf,sizeof(buf),0,(struct sockaddr *)&adr_srvr,sizeof(adr_srvr));
				if(z<0){
						perror("recvfrom error");
						exit(1);
				}
		}
		printf("send ....\n");
		sprintf(buf,"stop\n");
		z=sendto(sockfd,buf,sizeof(buf),0,(struct sockaddr *)&adr_srvr,sizeof(adr_srvr));
		if(z<0){
				perror("sendto error");
				exit(1);
		}
		fclose(fp);
		close(sockfd);
		exit(0);
}
