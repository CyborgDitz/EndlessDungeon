# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2024.3.1.1\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2024.3.1.1\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Projects\C++\EndlessDungeon

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Projects\C++\EndlessDungeon\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/EndlessDungeon.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/EndlessDungeon.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/EndlessDungeon.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/EndlessDungeon.dir/flags.make

CMakeFiles/EndlessDungeon.dir/main.cpp.obj: CMakeFiles/EndlessDungeon.dir/flags.make
CMakeFiles/EndlessDungeon.dir/main.cpp.obj: CMakeFiles/EndlessDungeon.dir/includes_CXX.rsp
CMakeFiles/EndlessDungeon.dir/main.cpp.obj: C:/Projects/C++/EndlessDungeon/main.cpp
CMakeFiles/EndlessDungeon.dir/main.cpp.obj: CMakeFiles/EndlessDungeon.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Projects\C++\EndlessDungeon\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/EndlessDungeon.dir/main.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/EndlessDungeon.dir/main.cpp.obj -MF CMakeFiles\EndlessDungeon.dir\main.cpp.obj.d -o CMakeFiles\EndlessDungeon.dir\main.cpp.obj -c C:\Projects\C++\EndlessDungeon\main.cpp

CMakeFiles/EndlessDungeon.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/EndlessDungeon.dir/main.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Projects\C++\EndlessDungeon\main.cpp > CMakeFiles\EndlessDungeon.dir\main.cpp.i

CMakeFiles/EndlessDungeon.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/EndlessDungeon.dir/main.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Projects\C++\EndlessDungeon\main.cpp -o CMakeFiles\EndlessDungeon.dir\main.cpp.s

CMakeFiles/EndlessDungeon.dir/playerController.cpp.obj: CMakeFiles/EndlessDungeon.dir/flags.make
CMakeFiles/EndlessDungeon.dir/playerController.cpp.obj: CMakeFiles/EndlessDungeon.dir/includes_CXX.rsp
CMakeFiles/EndlessDungeon.dir/playerController.cpp.obj: C:/Projects/C++/EndlessDungeon/playerController.cpp
CMakeFiles/EndlessDungeon.dir/playerController.cpp.obj: CMakeFiles/EndlessDungeon.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Projects\C++\EndlessDungeon\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/EndlessDungeon.dir/playerController.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/EndlessDungeon.dir/playerController.cpp.obj -MF CMakeFiles\EndlessDungeon.dir\playerController.cpp.obj.d -o CMakeFiles\EndlessDungeon.dir\playerController.cpp.obj -c C:\Projects\C++\EndlessDungeon\playerController.cpp

CMakeFiles/EndlessDungeon.dir/playerController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/EndlessDungeon.dir/playerController.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Projects\C++\EndlessDungeon\playerController.cpp > CMakeFiles\EndlessDungeon.dir\playerController.cpp.i

CMakeFiles/EndlessDungeon.dir/playerController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/EndlessDungeon.dir/playerController.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Projects\C++\EndlessDungeon\playerController.cpp -o CMakeFiles\EndlessDungeon.dir\playerController.cpp.s

CMakeFiles/EndlessDungeon.dir/gridRender.cpp.obj: CMakeFiles/EndlessDungeon.dir/flags.make
CMakeFiles/EndlessDungeon.dir/gridRender.cpp.obj: CMakeFiles/EndlessDungeon.dir/includes_CXX.rsp
CMakeFiles/EndlessDungeon.dir/gridRender.cpp.obj: C:/Projects/C++/EndlessDungeon/gridRender.cpp
CMakeFiles/EndlessDungeon.dir/gridRender.cpp.obj: CMakeFiles/EndlessDungeon.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Projects\C++\EndlessDungeon\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/EndlessDungeon.dir/gridRender.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/EndlessDungeon.dir/gridRender.cpp.obj -MF CMakeFiles\EndlessDungeon.dir\gridRender.cpp.obj.d -o CMakeFiles\EndlessDungeon.dir\gridRender.cpp.obj -c C:\Projects\C++\EndlessDungeon\gridRender.cpp

CMakeFiles/EndlessDungeon.dir/gridRender.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/EndlessDungeon.dir/gridRender.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Projects\C++\EndlessDungeon\gridRender.cpp > CMakeFiles\EndlessDungeon.dir\gridRender.cpp.i

CMakeFiles/EndlessDungeon.dir/gridRender.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/EndlessDungeon.dir/gridRender.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Projects\C++\EndlessDungeon\gridRender.cpp -o CMakeFiles\EndlessDungeon.dir\gridRender.cpp.s

CMakeFiles/EndlessDungeon.dir/dungeonController.cpp.obj: CMakeFiles/EndlessDungeon.dir/flags.make
CMakeFiles/EndlessDungeon.dir/dungeonController.cpp.obj: CMakeFiles/EndlessDungeon.dir/includes_CXX.rsp
CMakeFiles/EndlessDungeon.dir/dungeonController.cpp.obj: C:/Projects/C++/EndlessDungeon/dungeonController.cpp
CMakeFiles/EndlessDungeon.dir/dungeonController.cpp.obj: CMakeFiles/EndlessDungeon.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Projects\C++\EndlessDungeon\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/EndlessDungeon.dir/dungeonController.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/EndlessDungeon.dir/dungeonController.cpp.obj -MF CMakeFiles\EndlessDungeon.dir\dungeonController.cpp.obj.d -o CMakeFiles\EndlessDungeon.dir\dungeonController.cpp.obj -c C:\Projects\C++\EndlessDungeon\dungeonController.cpp

CMakeFiles/EndlessDungeon.dir/dungeonController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/EndlessDungeon.dir/dungeonController.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Projects\C++\EndlessDungeon\dungeonController.cpp > CMakeFiles\EndlessDungeon.dir\dungeonController.cpp.i

CMakeFiles/EndlessDungeon.dir/dungeonController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/EndlessDungeon.dir/dungeonController.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Projects\C++\EndlessDungeon\dungeonController.cpp -o CMakeFiles\EndlessDungeon.dir\dungeonController.cpp.s

CMakeFiles/EndlessDungeon.dir/common.cpp.obj: CMakeFiles/EndlessDungeon.dir/flags.make
CMakeFiles/EndlessDungeon.dir/common.cpp.obj: CMakeFiles/EndlessDungeon.dir/includes_CXX.rsp
CMakeFiles/EndlessDungeon.dir/common.cpp.obj: C:/Projects/C++/EndlessDungeon/common.cpp
CMakeFiles/EndlessDungeon.dir/common.cpp.obj: CMakeFiles/EndlessDungeon.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Projects\C++\EndlessDungeon\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/EndlessDungeon.dir/common.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/EndlessDungeon.dir/common.cpp.obj -MF CMakeFiles\EndlessDungeon.dir\common.cpp.obj.d -o CMakeFiles\EndlessDungeon.dir\common.cpp.obj -c C:\Projects\C++\EndlessDungeon\common.cpp

CMakeFiles/EndlessDungeon.dir/common.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/EndlessDungeon.dir/common.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Projects\C++\EndlessDungeon\common.cpp > CMakeFiles\EndlessDungeon.dir\common.cpp.i

CMakeFiles/EndlessDungeon.dir/common.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/EndlessDungeon.dir/common.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Projects\C++\EndlessDungeon\common.cpp -o CMakeFiles\EndlessDungeon.dir\common.cpp.s

CMakeFiles/EndlessDungeon.dir/game.cpp.obj: CMakeFiles/EndlessDungeon.dir/flags.make
CMakeFiles/EndlessDungeon.dir/game.cpp.obj: CMakeFiles/EndlessDungeon.dir/includes_CXX.rsp
CMakeFiles/EndlessDungeon.dir/game.cpp.obj: C:/Projects/C++/EndlessDungeon/game.cpp
CMakeFiles/EndlessDungeon.dir/game.cpp.obj: CMakeFiles/EndlessDungeon.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Projects\C++\EndlessDungeon\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/EndlessDungeon.dir/game.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/EndlessDungeon.dir/game.cpp.obj -MF CMakeFiles\EndlessDungeon.dir\game.cpp.obj.d -o CMakeFiles\EndlessDungeon.dir\game.cpp.obj -c C:\Projects\C++\EndlessDungeon\game.cpp

CMakeFiles/EndlessDungeon.dir/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/EndlessDungeon.dir/game.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Projects\C++\EndlessDungeon\game.cpp > CMakeFiles\EndlessDungeon.dir\game.cpp.i

CMakeFiles/EndlessDungeon.dir/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/EndlessDungeon.dir/game.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Projects\C++\EndlessDungeon\game.cpp -o CMakeFiles\EndlessDungeon.dir\game.cpp.s

# Object files for target EndlessDungeon
EndlessDungeon_OBJECTS = \
"CMakeFiles/EndlessDungeon.dir/main.cpp.obj" \
"CMakeFiles/EndlessDungeon.dir/playerController.cpp.obj" \
"CMakeFiles/EndlessDungeon.dir/gridRender.cpp.obj" \
"CMakeFiles/EndlessDungeon.dir/dungeonController.cpp.obj" \
"CMakeFiles/EndlessDungeon.dir/common.cpp.obj" \
"CMakeFiles/EndlessDungeon.dir/game.cpp.obj"

# External object files for target EndlessDungeon
EndlessDungeon_EXTERNAL_OBJECTS =

EndlessDungeon.exe: CMakeFiles/EndlessDungeon.dir/main.cpp.obj
EndlessDungeon.exe: CMakeFiles/EndlessDungeon.dir/playerController.cpp.obj
EndlessDungeon.exe: CMakeFiles/EndlessDungeon.dir/gridRender.cpp.obj
EndlessDungeon.exe: CMakeFiles/EndlessDungeon.dir/dungeonController.cpp.obj
EndlessDungeon.exe: CMakeFiles/EndlessDungeon.dir/common.cpp.obj
EndlessDungeon.exe: CMakeFiles/EndlessDungeon.dir/game.cpp.obj
EndlessDungeon.exe: CMakeFiles/EndlessDungeon.dir/build.make
EndlessDungeon.exe: raylib_build/raylib/libraylib.a
EndlessDungeon.exe: CMakeFiles/EndlessDungeon.dir/linkLibs.rsp
EndlessDungeon.exe: CMakeFiles/EndlessDungeon.dir/objects1.rsp
EndlessDungeon.exe: CMakeFiles/EndlessDungeon.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Projects\C++\EndlessDungeon\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable EndlessDungeon.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\EndlessDungeon.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/EndlessDungeon.dir/build: EndlessDungeon.exe
.PHONY : CMakeFiles/EndlessDungeon.dir/build

CMakeFiles/EndlessDungeon.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\EndlessDungeon.dir\cmake_clean.cmake
.PHONY : CMakeFiles/EndlessDungeon.dir/clean

CMakeFiles/EndlessDungeon.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Projects\C++\EndlessDungeon C:\Projects\C++\EndlessDungeon C:\Projects\C++\EndlessDungeon\cmake-build-debug C:\Projects\C++\EndlessDungeon\cmake-build-debug C:\Projects\C++\EndlessDungeon\cmake-build-debug\CMakeFiles\EndlessDungeon.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/EndlessDungeon.dir/depend

