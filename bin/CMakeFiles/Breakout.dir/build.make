# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/gustavo/Área de Trabalho/Unicamp/Sexto semestre/EA872/MultiplayerBreakoutEA872"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/gustavo/Área de Trabalho/Unicamp/Sexto semestre/EA872/MultiplayerBreakoutEA872/bin"

# Include any dependencies generated for this target.
include CMakeFiles/Breakout.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Breakout.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Breakout.dir/flags.make

CMakeFiles/Breakout.dir/src/breakout.cpp.o: CMakeFiles/Breakout.dir/flags.make
CMakeFiles/Breakout.dir/src/breakout.cpp.o: ../src/breakout.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/gustavo/Área de Trabalho/Unicamp/Sexto semestre/EA872/MultiplayerBreakoutEA872/bin/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Breakout.dir/src/breakout.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Breakout.dir/src/breakout.cpp.o -c "/home/gustavo/Área de Trabalho/Unicamp/Sexto semestre/EA872/MultiplayerBreakoutEA872/src/breakout.cpp"

CMakeFiles/Breakout.dir/src/breakout.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Breakout.dir/src/breakout.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/gustavo/Área de Trabalho/Unicamp/Sexto semestre/EA872/MultiplayerBreakoutEA872/src/breakout.cpp" > CMakeFiles/Breakout.dir/src/breakout.cpp.i

CMakeFiles/Breakout.dir/src/breakout.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Breakout.dir/src/breakout.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/gustavo/Área de Trabalho/Unicamp/Sexto semestre/EA872/MultiplayerBreakoutEA872/src/breakout.cpp" -o CMakeFiles/Breakout.dir/src/breakout.cpp.s

CMakeFiles/Breakout.dir/src/breakout.cpp.o.requires:

.PHONY : CMakeFiles/Breakout.dir/src/breakout.cpp.o.requires

CMakeFiles/Breakout.dir/src/breakout.cpp.o.provides: CMakeFiles/Breakout.dir/src/breakout.cpp.o.requires
	$(MAKE) -f CMakeFiles/Breakout.dir/build.make CMakeFiles/Breakout.dir/src/breakout.cpp.o.provides.build
.PHONY : CMakeFiles/Breakout.dir/src/breakout.cpp.o.provides

CMakeFiles/Breakout.dir/src/breakout.cpp.o.provides.build: CMakeFiles/Breakout.dir/src/breakout.cpp.o


# Object files for target Breakout
Breakout_OBJECTS = \
"CMakeFiles/Breakout.dir/src/breakout.cpp.o"

# External object files for target Breakout
Breakout_EXTERNAL_OBJECTS =

Breakout: CMakeFiles/Breakout.dir/src/breakout.cpp.o
Breakout: CMakeFiles/Breakout.dir/build.make
Breakout: libmodel.a
Breakout: libview.a
Breakout: libcontroller.a
Breakout: CMakeFiles/Breakout.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/gustavo/Área de Trabalho/Unicamp/Sexto semestre/EA872/MultiplayerBreakoutEA872/bin/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Breakout"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Breakout.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Breakout.dir/build: Breakout

.PHONY : CMakeFiles/Breakout.dir/build

CMakeFiles/Breakout.dir/requires: CMakeFiles/Breakout.dir/src/breakout.cpp.o.requires

.PHONY : CMakeFiles/Breakout.dir/requires

CMakeFiles/Breakout.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Breakout.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Breakout.dir/clean

CMakeFiles/Breakout.dir/depend:
	cd "/home/gustavo/Área de Trabalho/Unicamp/Sexto semestre/EA872/MultiplayerBreakoutEA872/bin" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/gustavo/Área de Trabalho/Unicamp/Sexto semestre/EA872/MultiplayerBreakoutEA872" "/home/gustavo/Área de Trabalho/Unicamp/Sexto semestre/EA872/MultiplayerBreakoutEA872" "/home/gustavo/Área de Trabalho/Unicamp/Sexto semestre/EA872/MultiplayerBreakoutEA872/bin" "/home/gustavo/Área de Trabalho/Unicamp/Sexto semestre/EA872/MultiplayerBreakoutEA872/bin" "/home/gustavo/Área de Trabalho/Unicamp/Sexto semestre/EA872/MultiplayerBreakoutEA872/bin/CMakeFiles/Breakout.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Breakout.dir/depend

