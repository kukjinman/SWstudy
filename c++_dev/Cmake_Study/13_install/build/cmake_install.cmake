# Install script for directory: /home/kukjin.chung/SWstudy/github/SWstudy/c++_dev/Cmake_Study/13_install

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/kukjin.chung/SWstudy/github/SWstudy/c++_dev/Cmake_Study/13_install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}/home/kukjin.chung/SWstudy/github/SWstudy/c++_dev/Cmake_Study/13_install/bin/main" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/kukjin.chung/SWstudy/github/SWstudy/c++_dev/Cmake_Study/13_install/bin/main")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/kukjin.chung/SWstudy/github/SWstudy/c++_dev/Cmake_Study/13_install/bin/main"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/kukjin.chung/SWstudy/github/SWstudy/c++_dev/Cmake_Study/13_install/bin/main")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/kukjin.chung/SWstudy/github/SWstudy/c++_dev/Cmake_Study/13_install/bin" TYPE EXECUTABLE FILES "/home/kukjin.chung/SWstudy/github/SWstudy/c++_dev/Cmake_Study/13_install/build/main")
  if(EXISTS "$ENV{DESTDIR}/home/kukjin.chung/SWstudy/github/SWstudy/c++_dev/Cmake_Study/13_install/bin/main" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/kukjin.chung/SWstudy/github/SWstudy/c++_dev/Cmake_Study/13_install/bin/main")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/kukjin.chung/SWstudy/github/SWstudy/c++_dev/Cmake_Study/13_install/bin/main"
         OLD_RPATH "/home/kukjin.chung/SWstudy/github/SWstudy/c++_dev/Cmake_Study/13_install/build:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/kukjin.chung/SWstudy/github/SWstudy/c++_dev/Cmake_Study/13_install/bin/main")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/kukjin.chung/SWstudy/github/SWstudy/c++_dev/Cmake_Study/13_install/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
