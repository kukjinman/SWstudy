cmake_minimum_required(VERSION 3.5)
project(ThreadPool)


message(STATUS "CMAKE_SOURCE_DIR : ${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_BINARY_DIR : ${CMAKE_BINARY_DIR}")

add_compile_options(-std=c++11)
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -pthread")

#compile option
#g++ -std=c++11 1_lockguard.cpp -pthread -lpthread -Wl,--no-as-needed

include_directories(${CMAKE_SOURCE_DIR}/ThreadPool_class)

add_executable(unit_test ./UnitTest/test_main.cpp ./ThreadPool_class/ThreadPool.h ./ThreadPool_class/ThreadPool.cpp ./Linux_CPU_Checker/cpuChecker.h)

