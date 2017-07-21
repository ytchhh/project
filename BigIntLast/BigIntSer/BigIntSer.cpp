#include "../utili.h"

/*
	服务器端
*/

typedef enum {ADD,SUB,DIV,MUL,QUIT}OPER_ENUM;	//操作符

typedef struct BigIntOper
{
	OPER_ENUM command;			//操作符
	BigInt *bt1;				//计算的数1
	BigInt *bt2;				//计算的数2
}BigIntOper;



void SendData(int sock,BigInt *pbt)		//发送数据
{
	char sendbuf[BUFFER_SIZE];
	long data_len = pbt->size();
	memset(sendbuf,0,BUFFER_SIZE);
	for(long i = 0 ; i < data_len; ++i)
		sendbuf[i] = (*pbt)[i];
	send(sock,(char*)&data_len,sizeof(long),0);
	send(sock,sendbuf,data_len,0);
}

void RecvData(int sock,BigInt &bt)	//接受数据
{
	char recvbuf[BUFFER_SIZE];
	//bt.show();
	bt.clear();
	long data_len;
	recv(sock,(char*)&data_len,sizeof(long),0);
	recv(sock,recvbuf,data_len,0);
	for(int i = 0; i < data_len; ++i)
		bt.push_back(recvbuf[i]);
	cout<<"recvive bt over"<<endl;
}


void BigIntServer(int sockSer)			//服务器所做的工作
{
	int comm;
	int sockConn = sockSer;
	BigInt bt;
	BigInt bt1;
	BigInt bt2;
	while(1)
	{
		recv(sockConn,(char*)&comm,sizeof(int),0);		//接受操作符
		cout<<"command : "<<comm<<endl;
		RecvData(sockConn,bt1);
		cout<<"bt1 = ";
		bt1.show();
		RecvData(sockConn,bt2);
		cout<<"bt2 = ";
		bt2.show();
		switch(comm)
		{
			case ADD:
				BigInt::Add(bt,bt1,bt2);
				break;
			case SUB:
				BigInt::Sub(bt,bt1,bt2);
				break;
			case MUL:
				break;
			case DIV:
				break;
			default:
				break;
		}
		SendData(sockConn,&bt);
	}
	close(sockConn);

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
		if( (childpid = fork()) ==  0)
			BigIntServer(sockConn);
			//////////////////////////
		close(sockConn);
	}
	close(sockSer);
	return 0;
}

