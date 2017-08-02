#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <mysql.h>

int main()
{
	printf("Content-Type:text/html;charset=utf-8\n\n");

	MYSQL mysql;
	mysql_init(&mysql);
	if(NULL == mysql_real_connect(&mysql,"localhost","root","19961102","information",0,NULL,0))
	{
		printf("Connect Mysql Fail<br>");
		exit(1);
	}
	//printf("Connect Mysql successful<br>");

	char username[20] = {'\0'};
	char password[20] = {'\0'};
	char *data = getenv("QUERY_STRING");
	//printf("data = %s<br>",data);
	if(data == NULL)
		printf("接收数据出错\n");
	else
		sscanf(data,"username=%[^&]&password=%[^&]",username,password);

	//printf("user = %s<br>",username);
	//printf("password = %s<br>",password);
	
	char buf[100] = {'\0'};
	sprintf(buf,"select * from nature where name = '%s'",username);
	int ret = mysql_query(&mysql,buf);
	
	MYSQL_ROW sqlrow;
	MYSQL_RES *res_ptr;

	if(ret == 0)
	{
		res_ptr = mysql_store_result(&mysql);
		if(res_ptr)
		{
			while(sqlrow = mysql_fetch_row(res_ptr))
			{
				if(strcmp(sqlrow[0],username) == 0)
				{
					printf("你输入的账号已经存在，请重新输入<br>");
					exit(1);
				}
			}
		}
		else
		{
			printf("database data error<br>");
			exit(1);
		}
	}
	char query_sql[100] = {'\0'};
	sprintf(query_sql,"insert into nature values ('%s','%s')",username,password);
	ret = mysql_query(&mysql,query_sql);	//增加数据
	if(ret == 0)
	{
	
		printf("<html>");
		printf("<head>");
		printf("<title>");
		printf("消息");
		printf("</title>");
		printf("<meta http-equiv=\"Refresh\" content=\"5;url=head.html\"/>");
		printf("<style type = \"text/css\">");
		printf("body {text-align:center;}");
		printf("</style>");
		printf("</head>");
		printf("<body>");
		printf("<h1>注册成功!</h1>");
		printf("<h3>没有自动跳转请点击<a href=\"\">连接</a>!</h3>");
		printf("</body>");
		printf("</html>");
		printf("</head>");
	}
	mysql_close(&mysql);			//关闭连接
	

	return 0;
}
