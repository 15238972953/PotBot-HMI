cmake_minimum_required(VERSION 3.10)

project(PotBotHMI)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

include_directories(src)

# 告诉Qt去ui目录找.ui文件
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_SOURCE_DIR}/ui)

set(SOURCES
    src/main.cpp
    src/mainwindow.cpp
)

set(HEADERS
    src/mainwindow.h
)

set(UIS
    ui/mainwindow.ui
)

add_executable(PotBotHMI
    ${SOURCES}
    ${HEADERS}
    ${UIS}
)

target_link_libraries(PotBotHMI Qt5::Widgets)