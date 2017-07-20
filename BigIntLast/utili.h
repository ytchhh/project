#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "./BigInt/BigInt.h"

#define PORT 5050
#define IP_ADDRESS "127.0.0.1"
#define LISTEN_QUEUE_SIZE 5
