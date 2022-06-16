cmake_minimum_required (VERSION 3.0)

set (CMAKE_CXX_STANDARD 11)

project(study)
# set(CMAKE_C_FLAGS "-g -Wall  -I C:\\Program Files\\mingw64\\include -L C:\\Program Files\\mingw64\\lib")#
# set(CMAKE_CXX_COMPILER "g++")#设置C++编译器
# set(CMAKE_CXX_FLAGS "-g -Wall  -I C:\\Program Files\\mingw64\\include -L C:\\Program Files\\mingw64\\lib")
 

# <pre name="code" class="cpp"><pre name="code" class="cpp">set(CMAKE_C_COMPILER "gcc")#设置C编译器
# MESSAGE(STATUS "This is BINARY dir " ${HELLO_BINARY_DIR})
# MESSAGE(STATUS "This is SOURCE dir " ${HELLO_SOURCE_DIR})

# add_executable(getCircle "main.cpp" "main.h" "getCircle.cpp" "getCircle.hpp")
# add_executable(test "test.cpp")
# add_executable(getCircle "getCircle.cpp")
# add_executable(main "study.cpp" "pointAndCircle.cpp" "pointAndCircle.hpp")
add_executable(class01 "class01.cpp")
# add_executable(test "student.cpp")