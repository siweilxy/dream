#include "log.h"
int main()
{
    dream::log::getInstance()->init();
    ERROR_LOG("111");
    return 0;
}