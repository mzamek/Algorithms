# CMakeLists.txt
cmake_minimum_required(VERSION 3.16.3)
# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(DataStructures)

add_executable(${PROJECT_NAME} main.cpp)
include_directories(datastructures)