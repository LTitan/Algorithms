# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.14.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.14.4/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ltitan/Desktop/Algorithms

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ltitan/Desktop/Algorithms/bin

# Include any dependencies generated for this target.
include CMakeFiles/asd.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/asd.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/asd.dir/flags.make

CMakeFiles/asd.dir/string/sequences.cpp.o: CMakeFiles/asd.dir/flags.make
CMakeFiles/asd.dir/string/sequences.cpp.o: ../string/sequences.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ltitan/Desktop/Algorithms/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/asd.dir/string/sequences.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/asd.dir/string/sequences.cpp.o -c /Users/ltitan/Desktop/Algorithms/string/sequences.cpp

CMakeFiles/asd.dir/string/sequences.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/asd.dir/string/sequences.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ltitan/Desktop/Algorithms/string/sequences.cpp > CMakeFiles/asd.dir/string/sequences.cpp.i

CMakeFiles/asd.dir/string/sequences.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/asd.dir/string/sequences.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ltitan/Desktop/Algorithms/string/sequences.cpp -o CMakeFiles/asd.dir/string/sequences.cpp.s

# Object files for target asd
asd_OBJECTS = \
"CMakeFiles/asd.dir/string/sequences.cpp.o"

# External object files for target asd
asd_EXTERNAL_OBJECTS =

asd: CMakeFiles/asd.dir/string/sequences.cpp.o
asd: CMakeFiles/asd.dir/build.make
asd: CMakeFiles/asd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ltitan/Desktop/Algorithms/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable asd"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/asd.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/asd.dir/build: asd

.PHONY : CMakeFiles/asd.dir/build

CMakeFiles/asd.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/asd.dir/cmake_clean.cmake
.PHONY : CMakeFiles/asd.dir/clean

CMakeFiles/asd.dir/depend:
	cd /Users/ltitan/Desktop/Algorithms/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ltitan/Desktop/Algorithms /Users/ltitan/Desktop/Algorithms /Users/ltitan/Desktop/Algorithms/bin /Users/ltitan/Desktop/Algorithms/bin /Users/ltitan/Desktop/Algorithms/bin/CMakeFiles/asd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/asd.dir/depend

