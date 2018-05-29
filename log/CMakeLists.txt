cmake_minimum_required(VERSION 3.5)
project(log)

add_definitions(-DBOOST_LOG_DYN_LINK)

macro(source_group_by_dir source_files)
        set(sgbd_cur_dir ${CMAKE_CURRENT_SOURCE_DIR})
        foreach(sgbd_file ${${source_files}})
            string(REGEX REPLACE ${sgbd_cur_dir}//(.*/) //1 sgbd_fpath ${sgbd_file})
            string(REGEX REPLACE "/(.*/)/.*" //1 sgbd_group_name ${sgbd_fpath})
            string(COMPARE EQUAL ${sgbd_fpath} ${sgbd_group_name} sgbd_nogroup)
            string(REPLACE "/" "//" sgbd_group_name ${sgbd_group_name})
            if(sgbd_nogroup)
                set(sgbd_group_name "//")
            endif(sgbd_nogroup)
            source_group(${sgbd_group_name} FILES ${sgbd_file})
        endforeach(sgbd_file)
endmacro(source_group_by_dir)

FILE(GLOB_RECURSE all_files
        include/*.h
        src/*.cpp
        )

source_group(all_files)

include_directories(include/)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -DBOOST_LOG_DYN_LINK -lboost_log_setup")

message(${all_files})
add_library(log SHARED ${all_files})
target_link_libraries(log boost_log_setup boost_log boost_thread boost_system pthread)
