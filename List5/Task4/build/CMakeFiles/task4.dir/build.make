# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/xeno/Documents/RTOS/List5/Task4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xeno/Documents/RTOS/List5/Task4/build

# Include any dependencies generated for this target.
include CMakeFiles/task4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/task4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/task4.dir/flags.make

CMakeFiles/task4.dir/task4.c.o: CMakeFiles/task4.dir/flags.make
CMakeFiles/task4.dir/task4.c.o: ../task4.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xeno/Documents/RTOS/List5/Task4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/task4.dir/task4.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/task4.dir/task4.c.o   -c /home/xeno/Documents/RTOS/List5/Task4/task4.c

CMakeFiles/task4.dir/task4.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/task4.dir/task4.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/xeno/Documents/RTOS/List5/Task4/task4.c > CMakeFiles/task4.dir/task4.c.i

CMakeFiles/task4.dir/task4.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/task4.dir/task4.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/xeno/Documents/RTOS/List5/Task4/task4.c -o CMakeFiles/task4.dir/task4.c.s

CMakeFiles/task4.dir/task4.c.o.requires:

.PHONY : CMakeFiles/task4.dir/task4.c.o.requires

CMakeFiles/task4.dir/task4.c.o.provides: CMakeFiles/task4.dir/task4.c.o.requires
	$(MAKE) -f CMakeFiles/task4.dir/build.make CMakeFiles/task4.dir/task4.c.o.provides.build
.PHONY : CMakeFiles/task4.dir/task4.c.o.provides

CMakeFiles/task4.dir/task4.c.o.provides.build: CMakeFiles/task4.dir/task4.c.o


# Object files for target task4
task4_OBJECTS = \
"CMakeFiles/task4.dir/task4.c.o"

# External object files for target task4
task4_EXTERNAL_OBJECTS =

task4: CMakeFiles/task4.dir/task4.c.o
task4: CMakeFiles/task4.dir/build.make
task4: CMakeFiles/task4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xeno/Documents/RTOS/List5/Task4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable task4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/task4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/task4.dir/build: task4

.PHONY : CMakeFiles/task4.dir/build

CMakeFiles/task4.dir/requires: CMakeFiles/task4.dir/task4.c.o.requires

.PHONY : CMakeFiles/task4.dir/requires

CMakeFiles/task4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/task4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/task4.dir/clean

CMakeFiles/task4.dir/depend:
	cd /home/xeno/Documents/RTOS/List5/Task4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xeno/Documents/RTOS/List5/Task4 /home/xeno/Documents/RTOS/List5/Task4 /home/xeno/Documents/RTOS/List5/Task4/build /home/xeno/Documents/RTOS/List5/Task4/build /home/xeno/Documents/RTOS/List5/Task4/build/CMakeFiles/task4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/task4.dir/depend

