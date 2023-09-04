cmake_minimum_required(VERSION 3.1...3.20)

set(CMAKE_CXX_STANDARD 20)
# endif()
project(DesignPattern)
#FindMyLib
# include_directories(/Users/skywalker/Desktop/code/Arthur_Morgan/main.hpp  /Users/skywalker/Desktop/code/Arthur_Morgan/MultiThread/CXXThread.hpp /Users/skywalker/Desktop/code/Arthur_Morgan/DataStructure/Array.hpp)
#CGAL
#set(CGAL_DIR /opt/homebrew/Cellar/cgal/5.3.1/lib/cmake/CGAL)
#find_package(CGAL COMPONENTS Core)
#include(${CGAL_USE_FILE})

add_executable(DesignPattern DesignPattern.cpp CuriouslyRecurringTemplatePattern.cpp)
