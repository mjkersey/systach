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

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mkersey/plasmoids/systach/nightly/sources

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mkersey/plasmoids/systach/nightly/build

# Utility rule file for plasma_applet_systach_automoc.

# Include the progress variables for this target.
include CMakeFiles/plasma_applet_systach_automoc.dir/progress.make

CMakeFiles/plasma_applet_systach_automoc:
	/usr/bin/automoc4 /home/mkersey/plasmoids/systach/nightly/build/plasma_applet_systach_automoc.cpp /home/mkersey/plasmoids/systach/nightly/sources /home/mkersey/plasmoids/systach/nightly/build /usr/lib/x86_64-linux-gnu/qt4/bin/moc /usr/bin/cmake

plasma_applet_systach_automoc: CMakeFiles/plasma_applet_systach_automoc
plasma_applet_systach_automoc: CMakeFiles/plasma_applet_systach_automoc.dir/build.make
.PHONY : plasma_applet_systach_automoc

# Rule to build all files generated by this target.
CMakeFiles/plasma_applet_systach_automoc.dir/build: plasma_applet_systach_automoc
.PHONY : CMakeFiles/plasma_applet_systach_automoc.dir/build

CMakeFiles/plasma_applet_systach_automoc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/plasma_applet_systach_automoc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/plasma_applet_systach_automoc.dir/clean

CMakeFiles/plasma_applet_systach_automoc.dir/depend:
	cd /home/mkersey/plasmoids/systach/nightly/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mkersey/plasmoids/systach/nightly/sources /home/mkersey/plasmoids/systach/nightly/sources /home/mkersey/plasmoids/systach/nightly/build /home/mkersey/plasmoids/systach/nightly/build /home/mkersey/plasmoids/systach/nightly/build/CMakeFiles/plasma_applet_systach_automoc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/plasma_applet_systach_automoc.dir/depend

