cmake_minimum_required(VERSION 3.24)
project(ColorPanelWidget)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(ColorPanelWidget main.cpp colorpanel.cpp)
target_link_libraries(ColorPanelWidget
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

