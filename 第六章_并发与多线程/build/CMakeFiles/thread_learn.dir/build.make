# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /opt/cmake-3.21.5-linux-x86_64/bin/cmake

# The command to remove a file.
RM = /opt/cmake-3.21.5-linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lyx/code_ws/thread-tutorial/第六章_并发与多线程

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lyx/code_ws/thread-tutorial/第六章_并发与多线程/build

# Include any dependencies generated for this target.
include CMakeFiles/thread_learn.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/thread_learn.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/thread_learn.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/thread_learn.dir/flags.make

CMakeFiles/thread_learn.dir/main.cpp.o: CMakeFiles/thread_learn.dir/flags.make
CMakeFiles/thread_learn.dir/main.cpp.o: ../main.cpp
CMakeFiles/thread_learn.dir/main.cpp.o: CMakeFiles/thread_learn.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lyx/code_ws/thread-tutorial/第六章_并发与多线程/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/thread_learn.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/thread_learn.dir/main.cpp.o -MF CMakeFiles/thread_learn.dir/main.cpp.o.d -o CMakeFiles/thread_learn.dir/main.cpp.o -c /home/lyx/code_ws/thread-tutorial/第六章_并发与多线程/main.cpp

CMakeFiles/thread_learn.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/thread_learn.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lyx/code_ws/thread-tutorial/第六章_并发与多线程/main.cpp > CMakeFiles/thread_learn.dir/main.cpp.i

CMakeFiles/thread_learn.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/thread_learn.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lyx/code_ws/thread-tutorial/第六章_并发与多线程/main.cpp -o CMakeFiles/thread_learn.dir/main.cpp.s

# Object files for target thread_learn
thread_learn_OBJECTS = \
"CMakeFiles/thread_learn.dir/main.cpp.o"

# External object files for target thread_learn
thread_learn_EXTERNAL_OBJECTS =

thread_learn: CMakeFiles/thread_learn.dir/main.cpp.o
thread_learn: CMakeFiles/thread_learn.dir/build.make
thread_learn: CMakeFiles/thread_learn.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lyx/code_ws/thread-tutorial/第六章_并发与多线程/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable thread_learn"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/thread_learn.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/thread_learn.dir/build: thread_learn
.PHONY : CMakeFiles/thread_learn.dir/build

CMakeFiles/thread_learn.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/thread_learn.dir/cmake_clean.cmake
.PHONY : CMakeFiles/thread_learn.dir/clean

CMakeFiles/thread_learn.dir/depend:
	cd /home/lyx/code_ws/thread-tutorial/第六章_并发与多线程/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lyx/code_ws/thread-tutorial/第六章_并发与多线程 /home/lyx/code_ws/thread-tutorial/第六章_并发与多线程 /home/lyx/code_ws/thread-tutorial/第六章_并发与多线程/build /home/lyx/code_ws/thread-tutorial/第六章_并发与多线程/build /home/lyx/code_ws/thread-tutorial/第六章_并发与多线程/build/CMakeFiles/thread_learn.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/thread_learn.dir/depend

