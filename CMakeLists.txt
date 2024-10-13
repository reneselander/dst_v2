cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(SOURCES main.cpp calculations.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})