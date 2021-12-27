cmake_minimum_required(VERSION 3.5)
project(add_library)

message(STATUS "9_include_directories")

message(STATUS "CMAKE_SOURCE_DIR : ${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_BINARY_DIR : ${CMAKE_BINARY_DIR}")

#If there is no include_directories 
#file(GLOB ./bar) ./bar and ./foo cannot be detected. 
include_directories(${CMAKE_SOURCE_DIR}/bar)
include_directories(${CMAKE_SOURCE_DIR}/foo)


file(GLOB sources_service ./*.cpp ./*.cc ./*.c)
file(GLOB foo_files ${CMAKE_SOURCE_DIR}/foo/*.c)
file(GLOB bar_files ./bar/*.cpp ./bar/*.cc ./bar/*.c)

message(" sources_service : ${foo_files}")
message(" foo_files : ${foo_files}")
message(" bar_files : ${foo_files}")

add_executable(main ${sources_service} ${foo_files} ${bar_files})

