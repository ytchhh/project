#include <stdio.h>
#include <stdlib.h>
#include "./BigInt/BigInt.h"
#include <unistd.h>

#define BUFFER_SIZE 1024

int main()
{
	printf("Content-Type:text/html\n\n");
	printf("<html>");
	printf("<head>");
	
	printf("<title> result </title>");
	printf("<body>");
	printf("<H1 align=center>Hello World</H1>");

	char x[BUFFER_SIZE],y[BUFFER_SIZE];
	int cmd;
	char *data = getenv("QUERY_STRING");
	printf("data = %s<br>",data);

	sscanf(data,"x=%[^&]&y=%[^&]&cmd=%d",x,y,&cmd);

	printf("<p>x = %s<br>",x);
	printf("<p>y = %s<br>",y);
	printf("<p>cmd = %d<br>",cmd);
	
	BigInt bt1;
	BigInt bt2;
	BigInt bt;

	int i = 0;
	if(x[0] == '-')
	{
		i = 1;
		while(x[i] != '\0')
		{
			bt1.push_front(x[i]);
			i++;
		}
		bt1.push_front('-');
	}
	else
	{
		i = 0;
		while(x[i] != '\0')
		{
			bt1.push_front(x[i]);
			++i;
		}
		bt1.push_front('+');
	}
	if(y[0] == '-')
	{
		i = 1;
		while(y[i] != '\0')
		{
			bt2.push_front(y[i]);
			++i;
		}
		bt2.push_front('-');
	}
	else
	{
		i = 0;
		while(y[i] != '\0')
		{
			bt2.push_front(y[i]);
			++i;
		}
		bt2.push_front('+');
	}

	switch(cmd)
	{
		case 1:
			BigInt::Add(bt,bt1,bt2);
			break;
		case 2:
			BigInt::Sub(bt,bt1,bt2);
			break;
		case 3:
			break;
		case 4:
			break;
		default:
			break;
	}
	i = bt.size();
	int j = 1;
	char str[i];
	str[0] = bt[0];
	if()
	for(i = bt.size(); i > 1; --i,++j)
	{
		

		str[j] = bt[i-1];
	}
	str[j] = '\0';
	printf("<p>result = %s",str);
	printf("</body>");
	printf("</head>");
	printf("</html>");
	return 0;
}
