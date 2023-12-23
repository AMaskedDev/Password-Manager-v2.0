cmake_minimum_required(VERSION 3.27)
project(Password_Manager_v2_0)

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(Password_Manager_v2_0
        main.cpp)
