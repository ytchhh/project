
#include"../utili.h"

/*
	客户端 采用
*/

typedef enum {ADD,SUB,DIV,MUL,QUIT}OPER_ENUM;	//操作符

typedef struct BigIntOper					//将要计算的数据值传送地址，能提高效率
{
	OPER_ENUM command;			//操作符
	BigInt *bt1;				//计算的数1
	BigInt *bt2;				//计算的数2
}BigIntOper;

void SendData(int sock,BigIntOper *pBig)				//发送数据
{
	char sendbuf[BUFFER_SIZE];
	memset(sendbuf,0,BUFFER_SIZE);
	int comm = pBig->command;
	long data_len = pBig->bt1->size();
	char temp[data_len];
	send(sock,(char*)&comm,sizeof(int),0);			//发送操作符
	send(sock,(char*)&data_len,sizeof(long),0);		//发送bt1数据的长度
	
	for(int i = 0; i < data_len; ++i)
		temp[i] = (*pBig->bt1)[i];

	memcpy(sendbuf,temp,data_len);
	
	send(sock,sendbuf,data_len,0);
	cout<<"send bt1 over!"<<endl;

	data_len = pBig->bt2->size();
	send(sock,(char*)&data_len,sizeof(long),0);
	for(int i = 0; i < data_len; ++i)
		temp[i] = (*pBig->bt2)[i];
	memcpy(sendbuf,temp,data_len);
	send(sock,sendbuf,data_len,0);
	cout<<"send bt2 over!"<<endl;
}

void RecvData(int sockCli,BigInt &bt)			//接受数据
{
	bt.clear();
	char recvbuf[BUFFER_SIZE];
	long data_len;
	memset(recvbuf,0,BUFFER_SIZE);
	recv(sockCli,(char*)&data_len,sizeof(long),0);
	
	recv(sockCli,recvbuf,data_len,0);

	for(long i = 0; i < data_len; ++i)
		bt.push_back(recvbuf[i]);
}

int main()
{
    int sockCli = socket(AF_INET, SOCK_STREAM, 0);
	if(sockCli == -1)
	{
		perror("socket");
		exit(1);
	}
	
	//客户端程序填充服务端的资料
	struct sockaddr_in addrSer;
	addrSer.sin_family = AF_INET;
	addrSer.sin_port = htons(PORT);
	addrSer.sin_addr.s_addr = inet_addr(IP_ADDRESS);
	socklen_t len = sizeof(struct sockaddr);
	//客户端发起连接请求
	int res = connect(sockCli, (struct sockaddr*)&addrSer, len);
	if(res == -1)
	{
		printf("Client Connect Server Fail.\n");
		close(sockCli);
		exit(1);
	}
	else
	{
		printf("Client Connect Server OK.\n");
	}

	int select = 1;
	long n;
	
	BigInt bt1,bt2;
	string str1,str2;
	BigIntOper bo;
	BigInt bt;
	while(select)
	{
		cout<<"|               welcome to BigInt                 |"<<endl;
		cout<<"|-------------------------------------------------|"<<endl;
		cout<<"|[1]输入两个大数         [2]显示两个大数          |"<<endl;
		cout<<"|[3]bt = bt1+bt2         [4]bt = bt1-bt2          |"<<endl;
		cout<<"|[5]bt = bt1*bt2         [6]bt = bt1/bt2          |"<<endl;
		cout<<"|[0]退出系统                                      |"<<endl;
		cout<<"|-------------------------------------------------|"<<endl;
		cout<<"请输入选择:>";
		cin>>select;
		switch(select)
		{
			case 1:
				cout<<"请输入要加载的第一个大数:>";
				cin>>str1;
				cout<<"请输入要加载的第二个大数:>";
				cin>>str2;
				bt1 = str1;
				bt2 = str2;
				break;
			case 2:
				cout<<"bt1 = ";
				bt1.show();
				cout<<"bt2 = ";
				bt2.show();
				break;
			case 3:
				bo.command = ADD;
				bt.clear();
				bo.bt1 = &bt1;
				bo.bt2 = &bt2;
				SendData(sockCli,&bo);
				RecvData(sockCli,bt);
				break;
			case 4:
				bt.clear();
				bo.command = SUB;
				t1 = &bt1;
				bo.bt2 = &bt2;
				SendData(sockCli,&bo);
				RecvData(sockCli,bt);
				break;
			case 0:
				break;
			default:
				break;
		}
		if(select >= 3 && select <= 6)
		{
			cout<<"result = ";
			bt.show();
		}
	}
	close(sockCli);
	return 0;
}
