cmake_minimum_required(VERSION 3.29)
project(practice_graph)

set(CMAKE_CXX_STANDARD 20)

add_executable(practice_graph main.cpp
        custom-graph/Graph.cpp
        custom-graph/Graph.h)
