#cmake .. -DCMAKE_BUILD_TYPE=Debug
#cmake .. -DCMAKE_BUILD_TYPE=Release
project (CFILTER)

cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_COMPILER "g++")

#set(CMAKE_BUILD_TYPE "Debug")
#set(CMAKE_CXX_FLAGS "-g -O1 -Wall -std=c++0x")

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-O3 -Wall -std=c++0x")

IF ( FOUND_CCACHE )
    MESSAGE(STATUS "use ccache")
    SET(CMAKE_C_COMPILER "ccache")
    SET(CMAKE_C_COMPILER_ARG1 "gcc")
    SET(CMAKE_CXX_COMPILER "ccache")
    SET(CMAKE_CXX_COMPILER_ARG1 "g++")
ENDIF()

add_subdirectory(src)
