#include "log.h"
int main()
{
    dream::log::getInstance()->init();
    ERROR_LOG("111");
    NORMAL_LOG("NORMAL");
    return 0;
}