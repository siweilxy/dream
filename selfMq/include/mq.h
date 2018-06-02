//
// Created by siwei on 18-5-27.
//

#ifndef DREAM_MQ_H
#define DREAM_MQ_H

#include "core.h"
#include <arpa/inet.h>
#include <string>
namespace dreamMq {

    class mq {
    private:
        int selfportC2C;
        int selfIpC2C;
        int selfIpC2S;
        int serverIp;

        int socketfd;
        struct sockaddr_in serveraddr,clientaddr;
        socklen_t len;
        char message[BUF_SIZE];
        char buf[BUF_SIZE];
        pthread_t t;

    public:
        void init();
        void pub(std::string& message,int length);
        void sub();
        void receive();
    };

}
#endif //DREAM_MQ_H
