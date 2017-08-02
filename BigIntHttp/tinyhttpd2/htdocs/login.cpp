#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <mysql.h>

int main()
{
	printf("Content-Type:text/html\n\n");
	printf("<html>");
	printf("<head>");

	MYSQL mysql;
	MYSQL_RES *res;
	MYSQL_ROW row;
	bool IsExist = false;			//判断用户名和密码是否存在


	if(NULL == mysql_init(&mysql))
	{
		printf("mysql_init error<br>");
		return -1;
	}
	
	//尝试和主机上的Mysql数据库建立连接
	if(NULL == mysql_real_connect(&mysql,"localhost","root","19961102","information",0,NULL,0))
	{
		printf("mysql_real_connect error<br>");
		return -1;
	}
	//printf("connect mysql successful<br>");
	
	char user[20],password[20];
	char *data = getenv("QUERY_STRING");
	//printf("data = %s<br>",data);
	sscanf(data,"user=%[^&]&password=%[^&]",user,password);
	//printf("user = %s<br>",user);
	//printf("password = %s<br>",password);
	
	int ret;
	char buf[1024];
	MYSQL_RES *res_ptr;
	MYSQL_ROW sqlrow;

	sprintf(buf,"select passwd from nature where name='%s'",user);
	//printf("%s<br>",buf);
	
	

	ret = mysql_query(&mysql,buf);

	if(ret == 0)
	{
		res_ptr = mysql_store_result(&mysql);
		if(res_ptr)
		{
			while(sqlrow = mysql_fetch_row(res_ptr))
			{
				if(strcmp(sqlrow[0],user)==0 && strcmp(sqlrow[1],password)==0 )
				{
					IsExist = true;
					break;
				}
			}
		}
		else
		{
			printf("database data error<br>");
			exit(1);
		}
	}


	if(IsExist)				//如果用户名和密码存在
	{
		//printf("Hello world<br>");
		
		
		printf("Content-Type:text/html\n\n");
		printf("<html>");
		printf("<head>");
		
		printf("<script language=\"javascript\" type=\"text/javascript\">");
		printf("window.location.href='home.html'");
		printf("</script>");

		
		printf("</head>");
		printf("<body>");
		printf("</body>");
		printf("</html>");
	
	}
	
	else
	{
		printf("<meta charset=utf-8>");
		printf("用户名密码错误<br>");
	}
	

	//mysql_close(&mysql);

	return 0;
}
