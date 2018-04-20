make_minimum_required(VERSION 3.6)
project(dream)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    LICENSE
    README.md)
set(TEST_FILES
    test/main   
)

add_executable(dream ${SOURCE_FILES})
add_executable(test ${$TEST_FILES})
