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
include CMakeFiles/view.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/view.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/view.dir/flags.make

CMakeFiles/view.dir/src/view/view.cpp.o: CMakeFiles/view.dir/flags.make
CMakeFiles/view.dir/src/view/view.cpp.o: ../src/view/view.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/gustavo/Área de Trabalho/Unicamp/Sexto semestre/EA872/MultiplayerBreakoutEA872/bin/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/view.dir/src/view/view.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/view.dir/src/view/view.cpp.o -c "/home/gustavo/Área de Trabalho/Unicamp/Sexto semestre/EA872/MultiplayerBreakoutEA872/src/view/view.cpp"

CMakeFiles/view.dir/src/view/view.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/view.dir/src/view/view.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/gustavo/Área de Trabalho/Unicamp/Sexto semestre/EA872/MultiplayerBreakoutEA872/src/view/view.cpp" > CMakeFiles/view.dir/src/view/view.cpp.i

CMakeFiles/view.dir/src/view/view.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/view.dir/src/view/view.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/gustavo/Área de Trabalho/Unicamp/Sexto semestre/EA872/MultiplayerBreakoutEA872/src/view/view.cpp" -o CMakeFiles/view.dir/src/view/view.cpp.s

CMakeFiles/view.dir/src/view/view.cpp.o.requires:

.PHONY : CMakeFiles/view.dir/src/view/view.cpp.o.requires

CMakeFiles/view.dir/src/view/view.cpp.o.provides: CMakeFiles/view.dir/src/view/view.cpp.o.requires
	$(MAKE) -f CMakeFiles/view.dir/build.make CMakeFiles/view.dir/src/view/view.cpp.o.provides.build
.PHONY : CMakeFiles/view.dir/src/view/view.cpp.o.provides

CMakeFiles/view.dir/src/view/view.cpp.o.provides.build: CMakeFiles/view.dir/src/view/view.cpp.o


# Object files for target view
view_OBJECTS = \
"CMakeFiles/view.dir/src/view/view.cpp.o"

# External object files for target view
view_EXTERNAL_OBJECTS =

libview.a: CMakeFiles/view.dir/src/view/view.cpp.o
libview.a: CMakeFiles/view.dir/build.make
libview.a: CMakeFiles/view.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/gustavo/Área de Trabalho/Unicamp/Sexto semestre/EA872/MultiplayerBreakoutEA872/bin/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libview.a"
	$(CMAKE_COMMAND) -P CMakeFiles/view.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/view.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/view.dir/build: libview.a

.PHONY : CMakeFiles/view.dir/build

CMakeFiles/view.dir/requires: CMakeFiles/view.dir/src/view/view.cpp.o.requires

.PHONY : CMakeFiles/view.dir/requires

CMakeFiles/view.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/view.dir/cmake_clean.cmake
.PHONY : CMakeFiles/view.dir/clean

CMakeFiles/view.dir/depend:
	cd "/home/gustavo/Área de Trabalho/Unicamp/Sexto semestre/EA872/MultiplayerBreakoutEA872/bin" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/gustavo/Área de Trabalho/Unicamp/Sexto semestre/EA872/MultiplayerBreakoutEA872" "/home/gustavo/Área de Trabalho/Unicamp/Sexto semestre/EA872/MultiplayerBreakoutEA872" "/home/gustavo/Área de Trabalho/Unicamp/Sexto semestre/EA872/MultiplayerBreakoutEA872/bin" "/home/gustavo/Área de Trabalho/Unicamp/Sexto semestre/EA872/MultiplayerBreakoutEA872/bin" "/home/gustavo/Área de Trabalho/Unicamp/Sexto semestre/EA872/MultiplayerBreakoutEA872/bin/CMakeFiles/view.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/view.dir/depend

