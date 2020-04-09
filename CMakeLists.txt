cmake_minimum_required(VERSION 3.8)
project(KZ-YX-Final-Project-MPL)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SOURCE_FILES *.cpp)

add_executable(KZ-YX-Final-Project-MPL ${SOURCE_FILES} main.cpp)
