# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.12.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.12.3/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/hanzhongtao/Programs/cg/c/mframework

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/hanzhongtao/Programs/cg/c/mframework/build

# Include any dependencies generated for this target.
include src/nodes/testnode/CMakeFiles/testnode.dir/depend.make

# Include the progress variables for this target.
include src/nodes/testnode/CMakeFiles/testnode.dir/progress.make

# Include the compile flags for this target's objects.
include src/nodes/testnode/CMakeFiles/testnode.dir/flags.make

src/nodes/testnode/CMakeFiles/testnode.dir/CAdd.cpp.o: src/nodes/testnode/CMakeFiles/testnode.dir/flags.make
src/nodes/testnode/CMakeFiles/testnode.dir/CAdd.cpp.o: ../src/nodes/testnode/CAdd.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hanzhongtao/Programs/cg/c/mframework/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/nodes/testnode/CMakeFiles/testnode.dir/CAdd.cpp.o"
	cd /Users/hanzhongtao/Programs/cg/c/mframework/build/src/nodes/testnode && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testnode.dir/CAdd.cpp.o -c /Users/hanzhongtao/Programs/cg/c/mframework/src/nodes/testnode/CAdd.cpp

src/nodes/testnode/CMakeFiles/testnode.dir/CAdd.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testnode.dir/CAdd.cpp.i"
	cd /Users/hanzhongtao/Programs/cg/c/mframework/build/src/nodes/testnode && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hanzhongtao/Programs/cg/c/mframework/src/nodes/testnode/CAdd.cpp > CMakeFiles/testnode.dir/CAdd.cpp.i

src/nodes/testnode/CMakeFiles/testnode.dir/CAdd.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testnode.dir/CAdd.cpp.s"
	cd /Users/hanzhongtao/Programs/cg/c/mframework/build/src/nodes/testnode && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hanzhongtao/Programs/cg/c/mframework/src/nodes/testnode/CAdd.cpp -o CMakeFiles/testnode.dir/CAdd.cpp.s

src/nodes/testnode/CMakeFiles/testnode.dir/CAddClassFactory.cpp.o: src/nodes/testnode/CMakeFiles/testnode.dir/flags.make
src/nodes/testnode/CMakeFiles/testnode.dir/CAddClassFactory.cpp.o: ../src/nodes/testnode/CAddClassFactory.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hanzhongtao/Programs/cg/c/mframework/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/nodes/testnode/CMakeFiles/testnode.dir/CAddClassFactory.cpp.o"
	cd /Users/hanzhongtao/Programs/cg/c/mframework/build/src/nodes/testnode && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testnode.dir/CAddClassFactory.cpp.o -c /Users/hanzhongtao/Programs/cg/c/mframework/src/nodes/testnode/CAddClassFactory.cpp

src/nodes/testnode/CMakeFiles/testnode.dir/CAddClassFactory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testnode.dir/CAddClassFactory.cpp.i"
	cd /Users/hanzhongtao/Programs/cg/c/mframework/build/src/nodes/testnode && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hanzhongtao/Programs/cg/c/mframework/src/nodes/testnode/CAddClassFactory.cpp > CMakeFiles/testnode.dir/CAddClassFactory.cpp.i

src/nodes/testnode/CMakeFiles/testnode.dir/CAddClassFactory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testnode.dir/CAddClassFactory.cpp.s"
	cd /Users/hanzhongtao/Programs/cg/c/mframework/build/src/nodes/testnode && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hanzhongtao/Programs/cg/c/mframework/src/nodes/testnode/CAddClassFactory.cpp -o CMakeFiles/testnode.dir/CAddClassFactory.cpp.s

# Object files for target testnode
testnode_OBJECTS = \
"CMakeFiles/testnode.dir/CAdd.cpp.o" \
"CMakeFiles/testnode.dir/CAddClassFactory.cpp.o"

# External object files for target testnode
testnode_EXTERNAL_OBJECTS =

../lib/libtestnode.dylib: src/nodes/testnode/CMakeFiles/testnode.dir/CAdd.cpp.o
../lib/libtestnode.dylib: src/nodes/testnode/CMakeFiles/testnode.dir/CAddClassFactory.cpp.o
../lib/libtestnode.dylib: src/nodes/testnode/CMakeFiles/testnode.dir/build.make
../lib/libtestnode.dylib: ../lib/libbase.a
../lib/libtestnode.dylib: src/nodes/testnode/CMakeFiles/testnode.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/hanzhongtao/Programs/cg/c/mframework/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library ../../../../lib/libtestnode.dylib"
	cd /Users/hanzhongtao/Programs/cg/c/mframework/build/src/nodes/testnode && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testnode.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/nodes/testnode/CMakeFiles/testnode.dir/build: ../lib/libtestnode.dylib

.PHONY : src/nodes/testnode/CMakeFiles/testnode.dir/build

src/nodes/testnode/CMakeFiles/testnode.dir/clean:
	cd /Users/hanzhongtao/Programs/cg/c/mframework/build/src/nodes/testnode && $(CMAKE_COMMAND) -P CMakeFiles/testnode.dir/cmake_clean.cmake
.PHONY : src/nodes/testnode/CMakeFiles/testnode.dir/clean

src/nodes/testnode/CMakeFiles/testnode.dir/depend:
	cd /Users/hanzhongtao/Programs/cg/c/mframework/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/hanzhongtao/Programs/cg/c/mframework /Users/hanzhongtao/Programs/cg/c/mframework/src/nodes/testnode /Users/hanzhongtao/Programs/cg/c/mframework/build /Users/hanzhongtao/Programs/cg/c/mframework/build/src/nodes/testnode /Users/hanzhongtao/Programs/cg/c/mframework/build/src/nodes/testnode/CMakeFiles/testnode.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/nodes/testnode/CMakeFiles/testnode.dir/depend

