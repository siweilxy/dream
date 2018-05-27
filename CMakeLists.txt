cmake_minimum_required(VERSION 3.5)
project(dream)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    LICENSE
    README.md)

set(TEST_FILES
    test/main.cpp
)

#add_executable(dream ${SOURCE_FILES})
add_executable(gtest ${TEST_FILES})
