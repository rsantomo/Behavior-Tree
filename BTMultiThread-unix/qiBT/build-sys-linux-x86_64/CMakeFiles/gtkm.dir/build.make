# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/michele/BTMultiThread-unix

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/michele/BTMultiThread-unix/qiBT/build-sys-linux-x86_64

# Include any dependencies generated for this target.
include CMakeFiles/gtkm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gtkm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gtkm.dir/flags.make

CMakeFiles/gtkm.dir/src/main.cpp.o: CMakeFiles/gtkm.dir/flags.make
CMakeFiles/gtkm.dir/src/main.cpp.o: ../../src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/michele/BTMultiThread-unix/qiBT/build-sys-linux-x86_64/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/gtkm.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gtkm.dir/src/main.cpp.o -c /home/michele/BTMultiThread-unix/src/main.cpp

CMakeFiles/gtkm.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtkm.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/michele/BTMultiThread-unix/src/main.cpp > CMakeFiles/gtkm.dir/src/main.cpp.i

CMakeFiles/gtkm.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtkm.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/michele/BTMultiThread-unix/src/main.cpp -o CMakeFiles/gtkm.dir/src/main.cpp.s

CMakeFiles/gtkm.dir/src/main.cpp.o.requires:
.PHONY : CMakeFiles/gtkm.dir/src/main.cpp.o.requires

CMakeFiles/gtkm.dir/src/main.cpp.o.provides: CMakeFiles/gtkm.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/gtkm.dir/build.make CMakeFiles/gtkm.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/gtkm.dir/src/main.cpp.o.provides

CMakeFiles/gtkm.dir/src/main.cpp.o.provides.build: CMakeFiles/gtkm.dir/src/main.cpp.o

# Object files for target gtkm
gtkm_OBJECTS = \
"CMakeFiles/gtkm.dir/src/main.cpp.o"

# External object files for target gtkm
gtkm_EXTERNAL_OBJECTS =

libgtkm.a: CMakeFiles/gtkm.dir/src/main.cpp.o
libgtkm.a: CMakeFiles/gtkm.dir/build.make
libgtkm.a: CMakeFiles/gtkm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libgtkm.a"
	$(CMAKE_COMMAND) -P CMakeFiles/gtkm.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtkm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gtkm.dir/build: libgtkm.a
.PHONY : CMakeFiles/gtkm.dir/build

CMakeFiles/gtkm.dir/requires: CMakeFiles/gtkm.dir/src/main.cpp.o.requires
.PHONY : CMakeFiles/gtkm.dir/requires

CMakeFiles/gtkm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gtkm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gtkm.dir/clean

CMakeFiles/gtkm.dir/depend:
	cd /home/michele/BTMultiThread-unix/qiBT/build-sys-linux-x86_64 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/michele/BTMultiThread-unix /home/michele/BTMultiThread-unix /home/michele/BTMultiThread-unix/qiBT/build-sys-linux-x86_64 /home/michele/BTMultiThread-unix/qiBT/build-sys-linux-x86_64 /home/michele/BTMultiThread-unix/qiBT/build-sys-linux-x86_64/CMakeFiles/gtkm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gtkm.dir/depend

