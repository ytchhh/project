#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<mysql/mysql.h>

int main()
{
    printf("Content-Type:text/html;charset=utf-8\n\n");

    MYSQL m_sql;
    mysql_init(&m_sql);
    MYSQL *sql = mysql_real_connect(&m_sql,"localhost","root","123","test",3306,NULL,0);
    if(sql == NULL)
    {
        printf("<p>Connect Mysql Fail.\n");
        exit(1);
    }
    
    char user[20] = {0};
    char password[20] = {0};
    int i = 0;
    char *data = getenv("QUERY_STRING");
    if(data == NULL)
        printf("<p>接收数据出错.");
    else
    {
        while(*data != '=')
            data++;
        data++; //skip =
        while(*data != '&')
        {
            user[i++] = *data;
            data++;
        }
        data++; //skip &
        while(*data != '=')
            data++;
        data++; //skip =
        
        i = 0;
        while(*data != '\0')
        {
            password[i++] = *data;
            data++;
        }
    }

    //printf("<p>user_name = %s, user_passwd=%s",user,password);

    //char sql[100] = {0};
    //sprintf(sql, "insert into user_info values ('%s','%s');", user, password);

    char query_sql[100] = {0};  
    sprintf(query_sql, "insert into user_info values ('%s','%s');", user, password);
    mysql_query(&m_sql, query_sql);
    mysql_close(&m_sql);

    //printf("<p> Register Success.");
    //sleep(1);

    FILE *fp = fopen("./htdocs/index.html","r");
    if(NULL == fp)
    {
        printf("<h1> Not Found 404</h1>");
        exit(1);
    }

    char buf[128];
    while(!feof(fp))
    {
        fgets(buf, 128, fp);
        printf(buf);
    }
    
    fclose(fp);
    return 0;
}









