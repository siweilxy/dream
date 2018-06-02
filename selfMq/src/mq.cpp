//
// Created by siwei on 18-5-27.
//

#include "mq.h"
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include "log.h"
#include <pthread.h>

namespace dreamMq{

    namespace{
        void* startReceiveThread(void* data)
        {
            mq* m = (mq*)data;
            while (1)
            {
                m->receive();
            }
        }
    }


    void mq::init()
    {
        socketfd = socket(AF_INET,SOCK_DGRAM,0);
        memset(&serveraddr, sizeof(serveraddr),0);
        serveraddr.sin_family = AF_INET;
        serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
        serveraddr.sin_port = htons(clientC2SPort);
        bind(socketfd,(sockaddr*)&serveraddr, sizeof(serveraddr));
        len = sizeof(serveraddr);
        pthread_create(&t,nullptr,startReceiveThread, this);
        WARNING_LOG("init mq success");
    }

    void mq::pub(std::string& pubMessage,int length) {
        sendto(socketfd,pubMessage.c_str(),length,0,(struct sockaddr*)&serveraddr,len);
        WARNING_LOG("pub success");
    }

    void mq::sub() {}

    void mq::receive() {
        int length = recvfrom(socketfd,message,BUF_SIZE,0,(struct sockaddr*)&serveraddr,&len);
        memcpy(buf,message,length);
        WARNING_LOG(buf);
    }
}
