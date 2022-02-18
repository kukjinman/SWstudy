cmake_minimum_required(VERSION 3.5)
project(string)

message(STATUS "string")

message(STATUS "CMAKE_SOURCE_DIR : ${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_BINARY_DIR : ${CMAKE_BINARY_DIR}")


set(_version "1.0.0")

message(" version : "  ${_version})

string(REPLACE "." ";" VERSION_LIST ${_version})

message(" VERSION_LIST : "  ${VERSION_LIST})

#ref url
#https://junstar92.tistory.com/207

