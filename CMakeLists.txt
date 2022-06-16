cmake_minimum_required(VERSION 3.0)

project(main)

set(CMAKE_BUILD_TYPE RELEASE) #指定编译类型

include_directories(include) #头文件

file(GLOB SOURCES "src" main.cpp) #源文件

add_library(main SHARED ${SOURCES})#生成动态链接库
add_library(main STATIC ${SOURCES})#生成静态链接库

set(PROJECT_LINK_LIBS lib.so) #将库文件存到变量中

link_directories(/path) #添加外部库文件的搜索路径

target_link_libraries(main.exe ${PROJECT_LINK_LIBS}) #链接外部库文件

add_executable(main.cpp "test.h")


