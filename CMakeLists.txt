cmake_minimum_required(VERSION 3.1...3.20)
 
set (CMAKE_CXX_STANDARD 20)

set(CMAKE_BUILD_TYPE "Debug")
# endif()
project(CatchWind)
 
#if(NOT POLICY CMP0070 AND POLICY CMP0053)
#  # Only set CMP0053 to OLD with CMake<3.10, otherwise there is a warning.
#  cmake_policy(SET CMP0053 OLD)
#endif()
#if(POLICY CMP0071)
#  cmake_policy(SET CMP0071 NEW)
#endif()

add_executable(DesignPattern DesignPattern.cpp DesignPattern/CuriouslyRecurringTemplatePattern.cpp)
