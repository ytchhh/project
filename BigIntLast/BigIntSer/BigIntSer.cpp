#include "../utili.h"

/*
	服务器端
*/

typedef enum {ADD,SUB,DIV,QUIT}OPER_ENUM;	//操作符

typedef struct BigIntOper
{
	OPER_ENUM command;			//操作符
	BigInt *bt1;				//计算的数1
	BigInt *bt2;				//计算的数2
}BigIntOper;


void SendData(int sock,BigInt &bt)		//发送数据
{
	char sendbuf[BUFFER_SIZE];
	long data_len;
	memset(sendbuf,0,BUFFER_SIZE);
	send(sock,(char*)data_len,sizeof(long),0);
	send(sock,sendbuf,BUFFER_SIZE,0);
}

void RecvData(int sock,BigIntOper *pBig)	//接受数据
{
	char recvbuf[BUFFER_SIZE];

	int comm = recv(sock,(char*)comm,sizeof(comm),0);
	long data_len;
	recv(sock,(char*)data_len,sizeof(long),0);
	char temp[data_len];
	recv(sock,recvbuf,data_len,0);
	for(int i = 0; i < data_len; ++i)
		pBig->bt1->push_back(recvbuf[i]);
	cout<<"recvive bt1 over"<<endl;

	recv(sock,(char*)&data_len,sizeof(long),0);
	recv(sock,recvbuf,data_len,0);
	for(int i = 0; i < data_len; ++i)
		pBig->bt2->push_back(recvbuf[i]);
	cout<<"recvive bt2 over"<<endl;
}



int main()
{
	int sockSer = socket(AF_INET,SOCK_STREAM,0);
	if(sockSer == -1)
	{
		printf("sock error");
		exit(1);
	}
	
	//服务器填充sockaddr结构
	struct sockaddr_in addrSer,addrCli;
	addrSer.sin_family = AF_INET;
	addrSer.sin_port = htons(PORT);
	addrSer.sin_addr.s_addr = inet_addr(IP_ADDRESS);
	socklen_t len = sizeof(struct sockaddr);
	//捆绑sockSer描述符
	int res = bind(sockSer,(struct sockaddr*)(&addrSer),len);
	if(res == -1)
	{
		perror("bind");
		close(sockSer);
		exit(1);
	}
	//监听sockSer描述符
	res = listen(sockSer,LISTEN_QUEUE_SIZE);
	if(res == -1)
	{
		perror("listen");
		close(sockSer);
		exit(1);
	}
	
	BigInt bt1,bt2,bt;
	BigIntOper bo;
	pid_t childpid;
	printf("Server wait Connect...........\n");
	//服务器阻塞，直到客户端建立连接
	while(1)
	{
		int sockConn = accept(sockSer,(struct sockaddr*)&addrCli,&len);
		if(sockConn == -1)
		{
			printf("Server Accept Client Fail\n");
			close(sockSer);
			exit(1);
		}
		else
			printf("Server Accept Client OK\n");
		if( (childpid = fork()) == 0)
		{
			RecvData(sock,&bo);
			switch(bo->command)
			{
				case Add:
					bt = bo->bt1 + bo->bt2;
					break;
				default:
					break;
			}
			SendData(sock,bt);
			//////////////////////////
			exit(0);
		}
		close(sockConn);
	}
	close(sockSer);
	return 0;
}

