cmake_minimum_required(VERSION 2.8)

project(dining-philosophers)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS -pthread)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} "main.cpp" "condition.cpp" "key.cpp" "action.cpp" "keypressedcondition.cpp" "philosopher.cpp" "curses/cursesterminal.cpp" "curses/cursesobject.cpp" "curses/cursestext.cpp")

target_link_libraries(dining-philosophers ${CURSES_LIBRARIES})
