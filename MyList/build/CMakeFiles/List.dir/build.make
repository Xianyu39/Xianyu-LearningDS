# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\pspro\cmake-3.19.2-win64-x64\cmake-3.19.2-win64-x64\bin\cmake.exe

# The command to remove a file.
RM = D:\pspro\cmake-3.19.2-win64-x64\cmake-3.19.2-win64-x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\pspro\C_C++_pro\DataStructure_Algorithms\MyList

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\pspro\C_C++_pro\DataStructure_Algorithms\MyList\build

# Include any dependencies generated for this target.
include CMakeFiles/List.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/List.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/List.dir/flags.make

CMakeFiles/List.dir/src/i.cxx.obj: CMakeFiles/List.dir/flags.make
CMakeFiles/List.dir/src/i.cxx.obj: CMakeFiles/List.dir/includes_CXX.rsp
CMakeFiles/List.dir/src/i.cxx.obj: ../src/i.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\pspro\C_C++_pro\DataStructure_Algorithms\MyList\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/List.dir/src/i.cxx.obj"
	D:\pspro\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\List.dir\src\i.cxx.obj -c D:\pspro\C_C++_pro\DataStructure_Algorithms\MyList\src\i.cxx

CMakeFiles/List.dir/src/i.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/List.dir/src/i.cxx.i"
	D:\pspro\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\pspro\C_C++_pro\DataStructure_Algorithms\MyList\src\i.cxx > CMakeFiles\List.dir\src\i.cxx.i

CMakeFiles/List.dir/src/i.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/List.dir/src/i.cxx.s"
	D:\pspro\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\pspro\C_C++_pro\DataStructure_Algorithms\MyList\src\i.cxx -o CMakeFiles\List.dir\src\i.cxx.s

# Object files for target List
List_OBJECTS = \
"CMakeFiles/List.dir/src/i.cxx.obj"

# External object files for target List
List_EXTERNAL_OBJECTS =

../bin/libList.dll: CMakeFiles/List.dir/src/i.cxx.obj
../bin/libList.dll: CMakeFiles/List.dir/build.make
../bin/libList.dll: CMakeFiles/List.dir/linklibs.rsp
../bin/libList.dll: CMakeFiles/List.dir/objects1.rsp
../bin/libList.dll: CMakeFiles/List.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\pspro\C_C++_pro\DataStructure_Algorithms\MyList\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ..\bin\libList.dll"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\List.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/List.dir/build: ../bin/libList.dll

.PHONY : CMakeFiles/List.dir/build

CMakeFiles/List.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\List.dir\cmake_clean.cmake
.PHONY : CMakeFiles/List.dir/clean

CMakeFiles/List.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\pspro\C_C++_pro\DataStructure_Algorithms\MyList D:\pspro\C_C++_pro\DataStructure_Algorithms\MyList D:\pspro\C_C++_pro\DataStructure_Algorithms\MyList\build D:\pspro\C_C++_pro\DataStructure_Algorithms\MyList\build D:\pspro\C_C++_pro\DataStructure_Algorithms\MyList\build\CMakeFiles\List.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/List.dir/depend

