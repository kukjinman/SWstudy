# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kukjin.chung/SWstudy/github/SWstudy/c++_dev/Cmake_Study/13_install

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kukjin.chung/SWstudy/github/SWstudy/c++_dev/Cmake_Study/13_install/build

# Include any dependencies generated for this target.
include CMakeFiles/foo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/foo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/foo.dir/flags.make

CMakeFiles/foo.dir/foo/foo.c.o: CMakeFiles/foo.dir/flags.make
CMakeFiles/foo.dir/foo/foo.c.o: ../foo/foo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kukjin.chung/SWstudy/github/SWstudy/c++_dev/Cmake_Study/13_install/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/foo.dir/foo/foo.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/foo.dir/foo/foo.c.o   -c /home/kukjin.chung/SWstudy/github/SWstudy/c++_dev/Cmake_Study/13_install/foo/foo.c

CMakeFiles/foo.dir/foo/foo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/foo.dir/foo/foo.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kukjin.chung/SWstudy/github/SWstudy/c++_dev/Cmake_Study/13_install/foo/foo.c > CMakeFiles/foo.dir/foo/foo.c.i

CMakeFiles/foo.dir/foo/foo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/foo.dir/foo/foo.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kukjin.chung/SWstudy/github/SWstudy/c++_dev/Cmake_Study/13_install/foo/foo.c -o CMakeFiles/foo.dir/foo/foo.c.s

CMakeFiles/foo.dir/foo/foo.c.o.requires:

.PHONY : CMakeFiles/foo.dir/foo/foo.c.o.requires

CMakeFiles/foo.dir/foo/foo.c.o.provides: CMakeFiles/foo.dir/foo/foo.c.o.requires
	$(MAKE) -f CMakeFiles/foo.dir/build.make CMakeFiles/foo.dir/foo/foo.c.o.provides.build
.PHONY : CMakeFiles/foo.dir/foo/foo.c.o.provides

CMakeFiles/foo.dir/foo/foo.c.o.provides.build: CMakeFiles/foo.dir/foo/foo.c.o


# Object files for target foo
foo_OBJECTS = \
"CMakeFiles/foo.dir/foo/foo.c.o"

# External object files for target foo
foo_EXTERNAL_OBJECTS =

libfoo.so: CMakeFiles/foo.dir/foo/foo.c.o
libfoo.so: CMakeFiles/foo.dir/build.make
libfoo.so: CMakeFiles/foo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kukjin.chung/SWstudy/github/SWstudy/c++_dev/Cmake_Study/13_install/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library libfoo.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/foo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/foo.dir/build: libfoo.so

.PHONY : CMakeFiles/foo.dir/build

CMakeFiles/foo.dir/requires: CMakeFiles/foo.dir/foo/foo.c.o.requires

.PHONY : CMakeFiles/foo.dir/requires

CMakeFiles/foo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/foo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/foo.dir/clean

CMakeFiles/foo.dir/depend:
	cd /home/kukjin.chung/SWstudy/github/SWstudy/c++_dev/Cmake_Study/13_install/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kukjin.chung/SWstudy/github/SWstudy/c++_dev/Cmake_Study/13_install /home/kukjin.chung/SWstudy/github/SWstudy/c++_dev/Cmake_Study/13_install /home/kukjin.chung/SWstudy/github/SWstudy/c++_dev/Cmake_Study/13_install/build /home/kukjin.chung/SWstudy/github/SWstudy/c++_dev/Cmake_Study/13_install/build /home/kukjin.chung/SWstudy/github/SWstudy/c++_dev/Cmake_Study/13_install/build/CMakeFiles/foo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/foo.dir/depend

