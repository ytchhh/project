#!/bin/bash

if [ -d ../syncdir/bigint ]; then
    kill `ps -ewf |grep '\./httpd' |grep -v grep |awk '{print $2}'`
    rm -fr /opt/bigint
    \cp -fr ../syncdir/bigint /opt/
else
    echo "cannot find bigint in syncdir" 1>&2
    exit 1
fi

function configdb()
{
    mysql test -e "drop table user_info; create table user_info (user_name varchar(32), user_passwd varchar(32));insert into user_info values('leo', '1234'); select * from user_info"

    mysqladmin -u root  password 123
}



biroot=/opt/bigint
function configbi()
{

    bihttpd=$biroot/Web_Server
    bidb=$biroot/BigInt_Sql
    bihtdocs=$bihttpd/htdocs
    bisrv=$biroot/BigInt_Server

    #1. compile httpd.
    gcc $bihttpd/httpd.c  -o $bihttpd/httpd -lpthread

    #2. compile db cgi
    gcc $bidb/login.c -o $bihtdocs/login.cgi -lmysqlclient  -L/usr/lib64/mysql
    gcc $bidb/register.c -o  $bihtdocs/reg.cgi -lmysqlclient -L/usr/lib64/mysql

    #3. compile bi server
    cd $bisrv;
    make
    \cp BigIntSer.cgi -fr $bihtdocs
    cd -

}

function startbi()
{
    cd $bihttpd
    nohup ./httpd 1>/var/log/bi.log 2>&1 &
}


###########
#   main  #
###########

configdb

configbi

startbi

