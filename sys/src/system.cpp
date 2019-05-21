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
#include <json.hpp>
namespace dream
{

system::system()
{
    cpus = get_nprocs();
    char* path = nullptr;
    path = getenv("filePath");
    if (path == nullptr)
    {
        ERROR_LOG("filePath is empty");
        exit(0);
    }
    filePath = path;
    printSysInfo();
    master();
}

system::~system()
{
    // TODO Auto-generated destructor stub
}

void system::printSysInfo()
{
    NORMAL_LOG("**********printSysInfo**********");
    std::string msg = "cpu numbers is " + std::to_string(cpus);
    NORMAL_LOG(msg.c_str());
    msg = "filePath is " + filePath;
    NORMAL_LOG(msg.c_str());
}

void system::child()
{
    std::string msg;
    NORMAL_LOG("this is child");
    msg = "child";
    while (1)
    {
        sleep(1);
    }
}

void system::father()
{
    std::string msg;
    NORMAL_LOG("this is father");
    for (auto child : childs)
    {
        msg = std::to_string(child.first) + ":" + std::to_string(child.second);
        NORMAL_LOG(msg.c_str());
    }

    while (1)
    {
        sleep(1);
    }
}

void system::master()
{
    pid_t fpid;
    int i = 0;
    while (childs.size() <= cpus)
    {
        childs.insert({i,fpid});
        i++;
        fpid = fork();
        if (fpid < 0)
        {
            ERROR_LOG("error in fork");
        } else if (fpid == 0)
        {
            child();
        } else
        {
            if (childs.size() >= cpus)
            {
                father();
            }
        }

    }
}

} /* namespace dream */
