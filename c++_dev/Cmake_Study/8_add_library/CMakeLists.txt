cmake_minimum_required(VERSION 3.5)
project(add_library)

message(STATUS "STREQUAL")

message(STATUS "CMAKE_SOURCE_DIR : ${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_BINARY_DIR : ${CMAKE_BINARY_DIR}")

add_library(foo STATIC foo.c )
add_library(foo2 SHARED foo.c )

#x64에서 main 생성이 안됨... 
#build 서버에서 mkdir build로 만들고 해당 build dir에서
#cmake .. 실행 -> 그후 make 실행하여 output 생성 됨
#Makefile에 해당 command 실행되도록 make install안에 설정
add_executable(main main.c foo.c bar.c)

