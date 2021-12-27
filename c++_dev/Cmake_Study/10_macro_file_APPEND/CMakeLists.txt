cmake_minimum_required(VERSION 3.5)
project(10_macro)

message(STATUS "10_macro")

message(STATUS "CMAKE_SOURCE_DIR : ${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_BINARY_DIR : ${CMAKE_BINARY_DIR}")



macro(add_artifact_file SRC DEST)
    file(RELATIVE_PATH path ${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/${SRC})
    file(APPEND "${CMAKE_SOURCE_DIR}/testfile1.txt" "${path}:${DEST}\n")
endmacro()

#If there is no include_directories 
#file(GLOB ./bar) ./bar and ./foo cannot be detected. 
include_directories(${CMAKE_SOURCE_DIR}/bar)
include_directories(${CMAKE_SOURCE_DIR}/foo)

file(WRITE "${CMAKE_SOURCE_DIR}/testfile1.txt" "\n")
add_artifact_file("./foo" "./")

file(GLOB sources_service ./*.cpp ./*.cc ./*.c)
file(GLOB foo_files ${CMAKE_SOURCE_DIR}/foo/*.c)
file(GLOB bar_files ./bar/*.cpp ./bar/*.cc ./bar/*.c)

message(" sources_service : ${foo_files}")
message(" foo_files : ${foo_files}")
message(" bar_files : ${foo_files}")

add_executable(main ${sources_service} ${foo_files} ${bar_files})

