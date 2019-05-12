cmake_minimum_required(VERSION 3.14)
project(GraphBuilder)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")
add_executable(GraphBuilder main.cpp decoder/Decoder.h decoder/Decoder.cpp tests/tests.h checker/Checker.cpp checker/Checker.h checker/utils/NoSuchFormatException.h checker/utils/EmptyStringException.h  constants/Constants.h parallel/execute.h parallel/execute.cpp)