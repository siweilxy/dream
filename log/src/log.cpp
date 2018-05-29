//
// Created by siwei on 18-5-27.
//

#include "log.h"

namespace dream{
    void log::init()
    {
        // This is a simple tutorial/example of Boost.Log usage

        // The first thing we have to do to get using the library is
        // to set up the logging sinks - i.e. where the logs will be written to.
        //logging::add_console_log(std::clog, keywords::format = "%TimeStamp%: %Message%");

        logging::add_console_log(std::clog, keywords::format = expr::stream
                << expr::format_date_time< boost::posix_time::ptime >("TimeStamp", "%Y-%m-%d %H:%M:%S.%f")
                << " <" << expr::attr< severity_level >("Severity")
                << "> " << expr::message);

        // One can also use lambda expressions to setup filters and formatters
       /* logging::add_file_log
                (
                "sample.log",
                keywords::filter = expr::attr< severity_level >("Severity") >= warning,
                keywords::format = expr::stream
                        << expr::format_date_time< boost::posix_time::ptime >("TimeStamp", "%Y-%m-%d, %H:%M:%S.%f")
                        << " [" << expr::format_date_time< attrs::timer::value_type >("Uptime", "%O:%M:%S")
                        << "] [" << expr::format_named_scope("Scope", keywords::format = "%n (%f:%l)")
                        << "] <" << expr::attr< severity_level >("Severity")
                        << "> " << expr::message

        /*keywords::format = expr::format("%1% [%2%] [%3%] <%4%> %5%")
            % expr::format_date_time< boost::posix_time::ptime >("TimeStamp", "%Y-%m-%d, %H:%M:%S.%f")
            % expr::format_date_time< attrs::timer::value_type >("Uptime", "%O:%M:%S")
            % expr::format_named_scope("Scope", keywords::format = "%n (%f:%l)")
            % expr::attr< severity_level >("Severity")
            % expr::message

        );*/

        // Also let's add some commonly used attributes, like timestamp and record counter.
        logging::add_common_attributes();
        logging::core::get()->add_thread_attribute("Scope", attrs::named_scope());

        BOOST_LOG_FUNCTION();

        // Now our logs will be written both to the console and to the file.
        // Let's do a quick test and output something. We have to create a logger for this.


        // And output...
       // BOOST_LOG(lg) << "Hello, World!";

        // Now, let's try logging with severity


        // Let's pretend we also want to profile our code, so add a special timer attribute.
        slg.add_attribute("Uptime", attrs::timer());
    }

    void log::Critical(int line,std::string&& file,std::string&& message)
    {
        BOOST_LOG_SEV(slg, critical) <<file<<" "<<line<<" "<<message;
    }

    void log::Notification(int line,std::string&& file,std::string&& message)
    {
        BOOST_LOG_SEV(slg, notification)  <<file<<" "<<line<<" "<<message;;
    }

    void log::Normal(int line,std::string&& file,std::string&& message)
    {
        BOOST_LOG_SEV(slg, normal)  <<file<<" "<<line<<" "<<message;;
    }

    void log::Error(int line,std::string&& file,std::string&& message)
    {
        BOOST_LOG_SEV(slg, error)  <<file<<" "<<line<<" "<<message;;
    }

    void log::Warning(int line,std::string&& file,std::string&& message)
    {
        BOOST_LOG_SEV(slg, warning)  <<file<<" "<<line<<" "<<message;;
    }

    dream::log* log::getInstance()
    {
        static dream::log* log = new dream::log;
        return log;
    }
}