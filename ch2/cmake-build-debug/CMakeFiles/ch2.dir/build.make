# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/169/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/169/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lyx/code_ws/thread_learn/ch2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lyx/code_ws/thread_learn/ch2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ch2.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/ch2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ch2.dir/flags.make

CMakeFiles/ch2.dir/main.cpp.o: CMakeFiles/ch2.dir/flags.make
CMakeFiles/ch2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lyx/code_ws/thread_learn/ch2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ch2.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ch2.dir/main.cpp.o -c /home/lyx/code_ws/thread_learn/ch2/main.cpp

CMakeFiles/ch2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ch2.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lyx/code_ws/thread_learn/ch2/main.cpp > CMakeFiles/ch2.dir/main.cpp.i

CMakeFiles/ch2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ch2.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lyx/code_ws/thread_learn/ch2/main.cpp -o CMakeFiles/ch2.dir/main.cpp.s

# Object files for target ch2
ch2_OBJECTS = \
"CMakeFiles/ch2.dir/main.cpp.o"

# External object files for target ch2
ch2_EXTERNAL_OBJECTS =

ch2: CMakeFiles/ch2.dir/main.cpp.o
ch2: CMakeFiles/ch2.dir/build.make
ch2: CMakeFiles/ch2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lyx/code_ws/thread_learn/ch2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ch2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ch2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ch2.dir/build: ch2
.PHONY : CMakeFiles/ch2.dir/build

CMakeFiles/ch2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ch2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ch2.dir/clean

CMakeFiles/ch2.dir/depend:
	cd /home/lyx/code_ws/thread_learn/ch2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lyx/code_ws/thread_learn/ch2 /home/lyx/code_ws/thread_learn/ch2 /home/lyx/code_ws/thread_learn/ch2/cmake-build-debug /home/lyx/code_ws/thread_learn/ch2/cmake-build-debug /home/lyx/code_ws/thread_learn/ch2/cmake-build-debug/CMakeFiles/ch2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ch2.dir/depend

