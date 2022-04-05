cmake_minimum_required(VERSION 3.1)

project(task2)

set(taskk1_SRC CString.cpp CString1.cpp CString0.cpp main.cpp Test.cpp)
set(taskk1_HDR CString.h CString1.h CString0.h headers.h Factory.h)

add_executable(${PROJECT_NAME} ${taskk1_SRC} ${taskk1_HDR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 /std:c++14")