cmake_minimum_required(VERSION 3.5)
project(12_target_link_libraries)

message(STATUS "12_target_link_libraries")

message(STATUS "CMAKE_SOURCE_DIR : ${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_BINARY_DIR : ${CMAKE_BINARY_DIR}")

#If there is no include_directories 
#file(GLOB ./bar) ./bar and ./foo cannot be detected. 
include_directories(${CMAKE_SOURCE_DIR}/bar)
include_directories(${CMAKE_SOURCE_DIR}/foo)

file(GLOB sources_service ./*.cpp ./*.cc ./*.c)


message(" sources_service : ${sources_service}")


add_library(foo SHARED ${CMAKE_SOURCE_DIR}/foo/foo.c )
add_library(bar SHARED ${CMAKE_SOURCE_DIR}/bar/bar.c )


add_executable(main ${sources_service} )

target_link_libraries(main foo bar)

#This will be in 13_install

set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR})
message("install path : ${CMAKE_INSTALL_PREFIX}")

install(TARGETS main
        RUNTIME  DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
        )

# ?? what is the purpose of using install??


