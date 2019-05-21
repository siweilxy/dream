#include "log.h"
#include "mq.h"
#include "system.h"
int main()
{
    dream::log::getInstance()->init();
    dream::system sys;
    return 0;
}
