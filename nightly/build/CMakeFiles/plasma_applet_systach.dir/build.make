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

# Include any dependencies generated for this target.
include CMakeFiles/plasma_applet_systach.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/plasma_applet_systach.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/plasma_applet_systach.dir/flags.make

ui_generalSettings.h: /home/mkersey/plasmoids/systach/nightly/sources/generalSettings.ui
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mkersey/plasmoids/systach/nightly/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating ui_generalSettings.h"
	/usr/bin/cmake -DKDE4_HEADER:BOOL=ON -DKDE_UIC_EXECUTABLE:FILEPATH=/usr/lib/x86_64-linux-gnu/qt4/bin/uic -DKDE_UIC_FILE:FILEPATH=/home/mkersey/plasmoids/systach/nightly/sources/generalSettings.ui -DKDE_UIC_H_FILE:FILEPATH=/home/mkersey/plasmoids/systach/nightly/build/ui_generalSettings.h -DKDE_UIC_BASENAME:STRING=generalSettings -P /usr/share/kde4/apps/cmake/modules/kde4uic.cmake

ui_datasourceSettings.h: /home/mkersey/plasmoids/systach/nightly/sources/datasourceSettings.ui
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mkersey/plasmoids/systach/nightly/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating ui_datasourceSettings.h"
	/usr/bin/cmake -DKDE4_HEADER:BOOL=ON -DKDE_UIC_EXECUTABLE:FILEPATH=/usr/lib/x86_64-linux-gnu/qt4/bin/uic -DKDE_UIC_FILE:FILEPATH=/home/mkersey/plasmoids/systach/nightly/sources/datasourceSettings.ui -DKDE_UIC_H_FILE:FILEPATH=/home/mkersey/plasmoids/systach/nightly/build/ui_datasourceSettings.h -DKDE_UIC_BASENAME:STRING=datasourceSettings -P /usr/share/kde4/apps/cmake/modules/kde4uic.cmake

ui_advancedSettings.h: /home/mkersey/plasmoids/systach/nightly/sources/advancedSettings.ui
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mkersey/plasmoids/systach/nightly/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating ui_advancedSettings.h"
	/usr/bin/cmake -DKDE4_HEADER:BOOL=ON -DKDE_UIC_EXECUTABLE:FILEPATH=/usr/lib/x86_64-linux-gnu/qt4/bin/uic -DKDE_UIC_FILE:FILEPATH=/home/mkersey/plasmoids/systach/nightly/sources/advancedSettings.ui -DKDE_UIC_H_FILE:FILEPATH=/home/mkersey/plasmoids/systach/nightly/build/ui_advancedSettings.h -DKDE_UIC_BASENAME:STRING=advancedSettings -P /usr/share/kde4/apps/cmake/modules/kde4uic.cmake

CMakeFiles/plasma_applet_systach.dir/plasma_applet_systach_automoc.o: CMakeFiles/plasma_applet_systach.dir/flags.make
CMakeFiles/plasma_applet_systach.dir/plasma_applet_systach_automoc.o: plasma_applet_systach_automoc.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mkersey/plasmoids/systach/nightly/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/plasma_applet_systach.dir/plasma_applet_systach_automoc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/plasma_applet_systach.dir/plasma_applet_systach_automoc.o -c /home/mkersey/plasmoids/systach/nightly/build/plasma_applet_systach_automoc.cpp

CMakeFiles/plasma_applet_systach.dir/plasma_applet_systach_automoc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plasma_applet_systach.dir/plasma_applet_systach_automoc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mkersey/plasmoids/systach/nightly/build/plasma_applet_systach_automoc.cpp > CMakeFiles/plasma_applet_systach.dir/plasma_applet_systach_automoc.i

CMakeFiles/plasma_applet_systach.dir/plasma_applet_systach_automoc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plasma_applet_systach.dir/plasma_applet_systach_automoc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mkersey/plasmoids/systach/nightly/build/plasma_applet_systach_automoc.cpp -o CMakeFiles/plasma_applet_systach.dir/plasma_applet_systach_automoc.s

CMakeFiles/plasma_applet_systach.dir/plasma_applet_systach_automoc.o.requires:
.PHONY : CMakeFiles/plasma_applet_systach.dir/plasma_applet_systach_automoc.o.requires

CMakeFiles/plasma_applet_systach.dir/plasma_applet_systach_automoc.o.provides: CMakeFiles/plasma_applet_systach.dir/plasma_applet_systach_automoc.o.requires
	$(MAKE) -f CMakeFiles/plasma_applet_systach.dir/build.make CMakeFiles/plasma_applet_systach.dir/plasma_applet_systach_automoc.o.provides.build
.PHONY : CMakeFiles/plasma_applet_systach.dir/plasma_applet_systach_automoc.o.provides

CMakeFiles/plasma_applet_systach.dir/plasma_applet_systach_automoc.o.provides.build: CMakeFiles/plasma_applet_systach.dir/plasma_applet_systach_automoc.o

CMakeFiles/plasma_applet_systach.dir/systach.o: CMakeFiles/plasma_applet_systach.dir/flags.make
CMakeFiles/plasma_applet_systach.dir/systach.o: /home/mkersey/plasmoids/systach/nightly/sources/systach.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mkersey/plasmoids/systach/nightly/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/plasma_applet_systach.dir/systach.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/plasma_applet_systach.dir/systach.o -c /home/mkersey/plasmoids/systach/nightly/sources/systach.cpp

CMakeFiles/plasma_applet_systach.dir/systach.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plasma_applet_systach.dir/systach.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mkersey/plasmoids/systach/nightly/sources/systach.cpp > CMakeFiles/plasma_applet_systach.dir/systach.i

CMakeFiles/plasma_applet_systach.dir/systach.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plasma_applet_systach.dir/systach.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mkersey/plasmoids/systach/nightly/sources/systach.cpp -o CMakeFiles/plasma_applet_systach.dir/systach.s

CMakeFiles/plasma_applet_systach.dir/systach.o.requires:
.PHONY : CMakeFiles/plasma_applet_systach.dir/systach.o.requires

CMakeFiles/plasma_applet_systach.dir/systach.o.provides: CMakeFiles/plasma_applet_systach.dir/systach.o.requires
	$(MAKE) -f CMakeFiles/plasma_applet_systach.dir/build.make CMakeFiles/plasma_applet_systach.dir/systach.o.provides.build
.PHONY : CMakeFiles/plasma_applet_systach.dir/systach.o.provides

CMakeFiles/plasma_applet_systach.dir/systach.o.provides.build: CMakeFiles/plasma_applet_systach.dir/systach.o

# Object files for target plasma_applet_systach
plasma_applet_systach_OBJECTS = \
"CMakeFiles/plasma_applet_systach.dir/plasma_applet_systach_automoc.o" \
"CMakeFiles/plasma_applet_systach.dir/systach.o"

# External object files for target plasma_applet_systach
plasma_applet_systach_EXTERNAL_OBJECTS =

lib/plasma_applet_systach.so: CMakeFiles/plasma_applet_systach.dir/plasma_applet_systach_automoc.o
lib/plasma_applet_systach.so: CMakeFiles/plasma_applet_systach.dir/systach.o
lib/plasma_applet_systach.so: CMakeFiles/plasma_applet_systach.dir/build.make
lib/plasma_applet_systach.so: /usr/lib/libkdeui.so.5.11.3
lib/plasma_applet_systach.so: /usr/lib/libplasma.so.3.0.0
lib/plasma_applet_systach.so: /usr/lib/x86_64-linux-gnu/libQtDeclarative.so
lib/plasma_applet_systach.so: /usr/lib/libkdeui.so.5.11.3
lib/plasma_applet_systach.so: /usr/lib/x86_64-linux-gnu/libQtGui.so
lib/plasma_applet_systach.so: /usr/lib/x86_64-linux-gnu/libQtSvg.so
lib/plasma_applet_systach.so: /usr/lib/libkdecore.so.5.11.3
lib/plasma_applet_systach.so: /usr/lib/x86_64-linux-gnu/libQtDBus.so
lib/plasma_applet_systach.so: /usr/lib/x86_64-linux-gnu/libQtCore.so
lib/plasma_applet_systach.so: CMakeFiles/plasma_applet_systach.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared module lib/plasma_applet_systach.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/plasma_applet_systach.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/plasma_applet_systach.dir/build: lib/plasma_applet_systach.so
.PHONY : CMakeFiles/plasma_applet_systach.dir/build

CMakeFiles/plasma_applet_systach.dir/requires: CMakeFiles/plasma_applet_systach.dir/plasma_applet_systach_automoc.o.requires
CMakeFiles/plasma_applet_systach.dir/requires: CMakeFiles/plasma_applet_systach.dir/systach.o.requires
.PHONY : CMakeFiles/plasma_applet_systach.dir/requires

CMakeFiles/plasma_applet_systach.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/plasma_applet_systach.dir/cmake_clean.cmake
.PHONY : CMakeFiles/plasma_applet_systach.dir/clean

CMakeFiles/plasma_applet_systach.dir/depend: ui_generalSettings.h
CMakeFiles/plasma_applet_systach.dir/depend: ui_datasourceSettings.h
CMakeFiles/plasma_applet_systach.dir/depend: ui_advancedSettings.h
	cd /home/mkersey/plasmoids/systach/nightly/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mkersey/plasmoids/systach/nightly/sources /home/mkersey/plasmoids/systach/nightly/sources /home/mkersey/plasmoids/systach/nightly/build /home/mkersey/plasmoids/systach/nightly/build /home/mkersey/plasmoids/systach/nightly/build/CMakeFiles/plasma_applet_systach.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/plasma_applet_systach.dir/depend

