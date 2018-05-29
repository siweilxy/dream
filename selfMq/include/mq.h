//
// Created by siwei on 18-5-27.
//

#ifndef DREAM_MQ_H
#define DREAM_MQ_H

#include "core.h"
#include <arpa/inet.h>
namespace dreamMq {

    class mq {
    private:
        int selfportC2C;
        int selfIpC2C;
        int selfIpC2S;
        int serverIp;

        int socketfd;
        struct sockaddr_in serveraddr,clientaddr;

    public:
        void init();

        void pub();

        void sub();
    };

}
#endif //DREAM_MQ_H
