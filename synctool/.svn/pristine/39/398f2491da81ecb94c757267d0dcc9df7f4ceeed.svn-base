#include<stdio.h>
#include<unistd.h>
#include<mysql/mysql.h>
#include<stdlib.h>

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

    MYSQL_ROW sqlrow;
    MYSQL_RES *res_ptr;
    
    char select[100] = {0};
    sprintf(select,"select user_passwd from user_info where user_name='%s'",user);
    int res = mysql_query(&m_sql, select);
    
    res_ptr = mysql_store_result(&m_sql);
    if(res_ptr)
    {
        sqlrow = mysql_fetch_row(res_ptr);
        //printf(sqlrow[0]);
    }
    else
    {
        printf("<p>database data error.");
        exit(1);
    }
    if(strcmp(sqlrow[0], password) == 0)
    {
        FILE *fp = fopen("./htdocs/bigcalc.html","r");
        if(NULL == fp)
        {
            printf("<h1> hi Not Found 404</h1>");
            exit(1);
        }
        
        char buf[128];
        while(!feof(fp))
        {
            fgets(buf, 128, fp);
            printf(buf);
        }
        
        fclose(fp);    
    }
    else
    {
        printf("<p>user name or user password error.");
    }

    mysql_close(&m_sql);
    /*
    /////////////////////////////////////////////////////////////////////////////////
    //页面调转
    //FILE *fp = fopen("/home/51cc/Desktop/Linux_BigInt/cgi/htdocs/bigcalc.html","r");
    FILE *fp = fopen("./htdocs/bigcalc.html","r");
    if(NULL == fp)
    {
        printf("<h1> hi Not Found 404</h1>");
        exit(1);
    }

    char buf[128];
    while(!feof(fp))
    {
        fgets(buf, 128, fp);
        printf(buf);
    }

    fclose(fp);
    */
    return 0;
}
