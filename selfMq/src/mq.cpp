//
// Created by siwei on 18-5-27.
//

#include "mq.h"
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>

namespace dreamMq{
    void mq::init()
    {
        socketfd = socket(AF_INET,SOCK_DGRAM,0);
        memset(&serveraddr, sizeof(serveraddr),0);
        serveraddr.sin_family = AF_INET;
        serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
        serveraddr.sin_port = htons(clientC2SPort);

        bind(socketfd,(sockaddr*)&serveraddr, sizeof(serveraddr));
    }
}
