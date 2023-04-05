cmake_minimum_required(VERSION 3.24)
project(qtProj)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(qtProj main.cpp MyWidget.cpp MyWidget.h)
target_link_libraries(qtProj
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

