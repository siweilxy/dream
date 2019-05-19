//
// Created by siwei on 18-5-27.
//

#ifndef DREAM_LOG_H
#define DREAM_LOG_H

#include <string>
#include <boost/log/common.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/attributes/timer.hpp>
#include <boost/log/attributes/named_scope.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/support/date_time.hpp>

namespace logging = boost::log;
namespace sinks = boost::log::sinks;
namespace attrs = boost::log::attributes;
namespace src = boost::log::sources;
namespace expr = boost::log::expressions;
namespace keywords = boost::log::keywords;
using boost::shared_ptr;
enum severity_level
{
    normal, notification, warning, error, critical
};

#define RED "\033[31m"
#define END "\033[0m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define VIOLET "\033[35m"

template<typename CharT, typename TraitsT>
inline std::basic_ostream<CharT, TraitsT>& operator<<(
        std::basic_ostream<CharT, TraitsT>& strm, severity_level lvl)
{
    static const char* const str[] =
    { "normal", "notification", "warning", "error", "critical" };
    if (static_cast<std::size_t>(lvl) < (sizeof(str) / sizeof(*str)))
        strm << str[lvl];
    else
        strm << static_cast<int>(lvl);
    return strm;
}

namespace dream
{
class log
{
private:
    src::severity_logger<severity_level> slg;
    src::logger lg;
public:
    void init();
    void Normal(int line, std::string&& file, std::string&& message);
    void Warning(int line, std::string&& file, std::string&& message);
    void Error(int line, std::string&& file, std::string&& message);
    void Notification(int line, std::string&& file, std::string&& message);
    void Critical(int line, std::string&& file, std::string&& message);
    static log* getInstance();
};
}

#define ERROR_LOG(msg) dream::log::getInstance()->Error(__LINE__,__FILE__,msg);
#define NORMAL_LOG(msg) dream::log::getInstance()->Normal(__LINE__,__FILE__,msg);
#define WARNING_LOG(msg) dream::log::getInstance()->Warning(__LINE__,__FILE__,msg);
#define NOTIFICATION_LOG(msg) dream::log::getInstance()->Notification(__LINE__,__FILE__,msg);
#define CRITICAL_LOG(msg) dream::log::getInstance()->Critical(__LINE__,__FILE__,msg);

#endif //DREAM_LOG_H
