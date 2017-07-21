#pragma once


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <cstring>
#include <sys/socket.h>
#include <deque>
#include <string>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "./BigInt/BigInt.h"
#include <iostream>
using namespace std;

#define PORT 5050
#define IP_ADDRESS "127.0.0.1"
#define LISTEN_QUEUE_SIZE 5
#define BUFFER_SIZE 1024


