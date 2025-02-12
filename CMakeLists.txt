cmake_minimum_required(VERSION 3.28)
project(professional_sleep_sort)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR}/Utilities)

add_executable(professional_sleep_sort main.cpp
        Utilities/ThreadPool.cpp
        Utilities/ThreadPool.h
        Utilities/Task.h)
