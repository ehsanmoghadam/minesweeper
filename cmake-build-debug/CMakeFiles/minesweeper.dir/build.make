# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\ehsan jm\Desktop\tamrin\minesweeper"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\ehsan jm\Desktop\tamrin\minesweeper\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/minesweeper.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/minesweeper.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/minesweeper.dir/flags.make

CMakeFiles/minesweeper.dir/main.cpp.obj: CMakeFiles/minesweeper.dir/flags.make
CMakeFiles/minesweeper.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\ehsan jm\Desktop\tamrin\minesweeper\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/minesweeper.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\minesweeper.dir\main.cpp.obj -c "C:\Users\ehsan jm\Desktop\tamrin\minesweeper\main.cpp"

CMakeFiles/minesweeper.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/minesweeper.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\ehsan jm\Desktop\tamrin\minesweeper\main.cpp" > CMakeFiles\minesweeper.dir\main.cpp.i

CMakeFiles/minesweeper.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/minesweeper.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\ehsan jm\Desktop\tamrin\minesweeper\main.cpp" -o CMakeFiles\minesweeper.dir\main.cpp.s

# Object files for target minesweeper
minesweeper_OBJECTS = \
"CMakeFiles/minesweeper.dir/main.cpp.obj"

# External object files for target minesweeper
minesweeper_EXTERNAL_OBJECTS =

minesweeper.exe: CMakeFiles/minesweeper.dir/main.cpp.obj
minesweeper.exe: CMakeFiles/minesweeper.dir/build.make
minesweeper.exe: CMakeFiles/minesweeper.dir/linklibs.rsp
minesweeper.exe: CMakeFiles/minesweeper.dir/objects1.rsp
minesweeper.exe: CMakeFiles/minesweeper.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\ehsan jm\Desktop\tamrin\minesweeper\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable minesweeper.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\minesweeper.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/minesweeper.dir/build: minesweeper.exe

.PHONY : CMakeFiles/minesweeper.dir/build

CMakeFiles/minesweeper.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\minesweeper.dir\cmake_clean.cmake
.PHONY : CMakeFiles/minesweeper.dir/clean

CMakeFiles/minesweeper.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\ehsan jm\Desktop\tamrin\minesweeper" "C:\Users\ehsan jm\Desktop\tamrin\minesweeper" "C:\Users\ehsan jm\Desktop\tamrin\minesweeper\cmake-build-debug" "C:\Users\ehsan jm\Desktop\tamrin\minesweeper\cmake-build-debug" "C:\Users\ehsan jm\Desktop\tamrin\minesweeper\cmake-build-debug\CMakeFiles\minesweeper.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/minesweeper.dir/depend

