cmake_minimum_required(VERSION 3.13)
project(qt_project)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets CONFIG REQUIRED)

add_executable(qt_project main.cpp utilitaries.h Decor.cpp Decor.h Personnage.cpp Personnage.h Window.cpp Window.h)

target_link_libraries(qt_project Qt5::Widgets)