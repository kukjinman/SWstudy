cmake_minimum_required(VERSION 3.5)
project(STREQUAL)

message(STATUS "STREQUAL")

set(VAR true)

if(${VAR} STREQUAL "true1")
	message(STATUS "STREQUAL true")
else()
	message(STATUS "STREQUAL false")
endif()
