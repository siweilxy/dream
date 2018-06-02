#include "log.h"
#include "mq.h"
int main()
{
    dream::log::getInstance()->init();
    ERROR_LOG("111");
    NORMAL_LOG("NORMAL");
    dreamMq::mq mq;
    mq.init();
    while(1){
        sleep(1);
        std::string s ="1234567890";
        mq.pub(s,s.size());
    }
    return 0;
}