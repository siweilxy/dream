/*
 * system.h
 *
 *  Created on: May 20, 2019
 *      Author: siwei
 */

#ifndef SYS_SYSTEM_H_
#define SYS_SYSTEM_H_

#include <string>
#include <map>
namespace dream
{

class system
{
public:
    system();
    ~system();

private:
    void printSysInfo();
    void master();
    void child();
    void father();
private:
    int cpus;
    std::string filePath;
    std::map<int, int> childs;
};

} /* namespace dream */

#endif /* SYS_SYSTEM_H_ */
