cmake_minimum_required(VERSION 2.8)

project(dining-philosophers)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(${PROJECT_NAME} "main.cpp")
