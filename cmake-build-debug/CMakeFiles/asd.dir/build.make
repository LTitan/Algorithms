# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ltitan/mygit/Algorithms

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ltitan/mygit/Algorithms/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/asd.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/asd.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/asd.dir/flags.make

CMakeFiles/asd.dir/graph/mainTest.cpp.o: CMakeFiles/asd.dir/flags.make
CMakeFiles/asd.dir/graph/mainTest.cpp.o: ../graph/mainTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ltitan/mygit/Algorithms/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/asd.dir/graph/mainTest.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/asd.dir/graph/mainTest.cpp.o -c /Users/ltitan/mygit/Algorithms/graph/mainTest.cpp

CMakeFiles/asd.dir/graph/mainTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/asd.dir/graph/mainTest.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ltitan/mygit/Algorithms/graph/mainTest.cpp > CMakeFiles/asd.dir/graph/mainTest.cpp.i

CMakeFiles/asd.dir/graph/mainTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/asd.dir/graph/mainTest.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ltitan/mygit/Algorithms/graph/mainTest.cpp -o CMakeFiles/asd.dir/graph/mainTest.cpp.s

# Object files for target asd
asd_OBJECTS = \
"CMakeFiles/asd.dir/graph/mainTest.cpp.o"

# External object files for target asd
asd_EXTERNAL_OBJECTS =

asd: CMakeFiles/asd.dir/graph/mainTest.cpp.o
asd: CMakeFiles/asd.dir/build.make
asd: CMakeFiles/asd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ltitan/mygit/Algorithms/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable asd"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/asd.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/asd.dir/build: asd

.PHONY : CMakeFiles/asd.dir/build

CMakeFiles/asd.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/asd.dir/cmake_clean.cmake
.PHONY : CMakeFiles/asd.dir/clean

CMakeFiles/asd.dir/depend:
	cd /Users/ltitan/mygit/Algorithms/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ltitan/mygit/Algorithms /Users/ltitan/mygit/Algorithms /Users/ltitan/mygit/Algorithms/cmake-build-debug /Users/ltitan/mygit/Algorithms/cmake-build-debug /Users/ltitan/mygit/Algorithms/cmake-build-debug/CMakeFiles/asd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/asd.dir/depend

