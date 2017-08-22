#pragma once

#include<unistd.h>
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<sys/types.h>
#include<string.h>
#include<arpa/inet.h>

#define SERVER_IP  "192.168.51.212"
#define SERVER_PORT 10001

#define LISTEN_QUEUE_SIZE 5
#define MAX_BUFFER_SIZE   255

