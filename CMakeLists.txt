cmake_minimum_required(VERSION 3.1...3.20)
 
set (CMAKE_CXX_STANDARD 20)

set(CMAKE_BUILD_TYPE "Debug")
# endif()
project(CathchWind)
 
if(NOT POLICY CMP0070 AND POLICY CMP0053)
  # Only set CMP0053 to OLD with CMake<3.10, otherwise there is a warning.
  cmake_policy(SET CMP0053 OLD)
endif()
if(POLICY CMP0071)
  cmake_policy(SET CMP0071 NEW)
endif()
#FindMyLib
# include_directories(/Users/skywalker/Desktop/code/Arthur_Morgan/main.hpp  /Users/skywalker/Desktop/code/Arthur_Morgan/MultiThread/CXXThread.hpp /Users/skywalker/Desktop/code/Arthur_Morgan/DataStructure/Array.hpp) 
ADD_SUBDIRECTORY(MultiThread DataStructure)
#CGAL
#set(CGAL_DIR /opt/homebrew/Cellar/cgal/5.3.1/lib/cmake/CGAL)
#find_package(CGAL COMPONENTS Core)
#include(${CGAL_USE_FILE})

add_executable(app lamda/main.cpp lamda/stu.cpp)
