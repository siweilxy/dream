#include "log.h"
#include "mq.h"
#include "system.h"
int main()
{
    dream::log::getInstance()->init();
    ERROR_LOG("111");
    NORMAL_LOG("NORMAL");
    dreamMq::mq mq;
    mq.init();
    dream::system sys;
    sys.printSysInfo();
    while(1){
        sleep(1);
        std::string s ="This text is red This text has default color";
        ERROR_LOG(s.c_str());
        //mq.pub(s,s.size());
    }
    return 0;
}
