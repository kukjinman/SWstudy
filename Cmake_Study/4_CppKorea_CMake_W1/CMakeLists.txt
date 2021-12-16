cmake_minimum_required(VERSION 3.5)

#Linux 
#which cmake -> cmake installed path

project(hell_world)

message(STATUS "hell world")

find_package(Threads REQUIRED)

add_definitions(-DSEARCH_PATH=1)

include_directories(/home/kukjin.chung/SWstudy/github/SWstudy/Cmake_Study/4_CppKorea_CMake_W1/atxt_Folder)

SET(SPATH "W:/SWstudy/github/SWstudy/Cmake_Study/4_CppKorea_CMake_W1/atxt_Folder")


find_library(TXT_PATH 
	NAMES a.txt
	PATHS SPATH
	HINTS ../../
)

message("---------------")
message(STATUS " Found txt : ${TXT_PATH}")

message(STATUS " SEARCH_PATH : ${SPATH}")

