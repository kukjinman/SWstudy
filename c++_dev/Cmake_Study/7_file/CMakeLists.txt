cmake_minimum_required(VERSION 3.5)
project(STREQUAL)

message(STATUS "STREQUAL")

message(STATUS "CMAKE_SOURCE_DIR : ${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_BINARY_DIR : ${CMAKE_BINARY_DIR}")

#create file
file(WRITE "${CMAKE_SOURCE_DIR}/testfile1.txt" "\n")
file(WRITE "${CMAKE_SOURCE_DIR}/testfile2.txt" "test\n")

#remove file
file(REMOVE "${CMAKE_SOURCE_DIR}/testfile1.txt")

#make directory
file(MAKE_DIRECTORY test_file_create_dir1 test_file_create_dir2)

#download
file(DOWNLOAD https://helpx.adobe.com/kr/photoshop/using/convert-color-image-black-white.html "${CMAKE_SOURCE_DIR}/test.html")


