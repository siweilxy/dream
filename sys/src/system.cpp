/*
 * system.cpp
 *
 *  Created on: May 20, 2019
 *      Author: siwei
 */

#include "system.h"
#include "log.h"
#include <sys/sysinfo.h>
#include <string>

namespace dream
{

system::system()
{
    // TODO Auto-generated constructor stub

}

system::~system()
{
    // TODO Auto-generated destructor stub
}

void system::printSysInfo()
{
    NORMAL_LOG("**********printSysInfo**********");
    std::string msg = "cpu numbers is " + std::to_string(get_nprocs());

    NORMAL_LOG(msg.c_str());

}

} /* namespace dream */
