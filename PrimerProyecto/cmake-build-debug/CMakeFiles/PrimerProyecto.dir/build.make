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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "F:\Universidad\Semestre 11\Lenguajes\Proyectos\PrimerProyect\PrimerProyectoLenguajes\PrimerProyecto"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "F:\Universidad\Semestre 11\Lenguajes\Proyectos\PrimerProyect\PrimerProyectoLenguajes\PrimerProyecto\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/PrimerProyecto.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PrimerProyecto.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PrimerProyecto.dir/flags.make

CMakeFiles/PrimerProyecto.dir/main.c.obj: CMakeFiles/PrimerProyecto.dir/flags.make
CMakeFiles/PrimerProyecto.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="F:\Universidad\Semestre 11\Lenguajes\Proyectos\PrimerProyect\PrimerProyectoLenguajes\PrimerProyecto\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/PrimerProyecto.dir/main.c.obj"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\PrimerProyecto.dir\main.c.obj   -c "F:\Universidad\Semestre 11\Lenguajes\Proyectos\PrimerProyect\PrimerProyectoLenguajes\PrimerProyecto\main.c"

CMakeFiles/PrimerProyecto.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PrimerProyecto.dir/main.c.i"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "F:\Universidad\Semestre 11\Lenguajes\Proyectos\PrimerProyect\PrimerProyectoLenguajes\PrimerProyecto\main.c" > CMakeFiles\PrimerProyecto.dir\main.c.i

CMakeFiles/PrimerProyecto.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PrimerProyecto.dir/main.c.s"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "F:\Universidad\Semestre 11\Lenguajes\Proyectos\PrimerProyect\PrimerProyectoLenguajes\PrimerProyecto\main.c" -o CMakeFiles\PrimerProyecto.dir\main.c.s

# Object files for target PrimerProyecto
PrimerProyecto_OBJECTS = \
"CMakeFiles/PrimerProyecto.dir/main.c.obj"

# External object files for target PrimerProyecto
PrimerProyecto_EXTERNAL_OBJECTS =

PrimerProyecto.exe: CMakeFiles/PrimerProyecto.dir/main.c.obj
PrimerProyecto.exe: CMakeFiles/PrimerProyecto.dir/build.make
PrimerProyecto.exe: CMakeFiles/PrimerProyecto.dir/linklibs.rsp
PrimerProyecto.exe: CMakeFiles/PrimerProyecto.dir/objects1.rsp
PrimerProyecto.exe: CMakeFiles/PrimerProyecto.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="F:\Universidad\Semestre 11\Lenguajes\Proyectos\PrimerProyect\PrimerProyectoLenguajes\PrimerProyecto\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable PrimerProyecto.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\PrimerProyecto.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PrimerProyecto.dir/build: PrimerProyecto.exe

.PHONY : CMakeFiles/PrimerProyecto.dir/build

CMakeFiles/PrimerProyecto.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\PrimerProyecto.dir\cmake_clean.cmake
.PHONY : CMakeFiles/PrimerProyecto.dir/clean

CMakeFiles/PrimerProyecto.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "F:\Universidad\Semestre 11\Lenguajes\Proyectos\PrimerProyect\PrimerProyectoLenguajes\PrimerProyecto" "F:\Universidad\Semestre 11\Lenguajes\Proyectos\PrimerProyect\PrimerProyectoLenguajes\PrimerProyecto" "F:\Universidad\Semestre 11\Lenguajes\Proyectos\PrimerProyect\PrimerProyectoLenguajes\PrimerProyecto\cmake-build-debug" "F:\Universidad\Semestre 11\Lenguajes\Proyectos\PrimerProyect\PrimerProyectoLenguajes\PrimerProyecto\cmake-build-debug" "F:\Universidad\Semestre 11\Lenguajes\Proyectos\PrimerProyect\PrimerProyectoLenguajes\PrimerProyecto\cmake-build-debug\CMakeFiles\PrimerProyecto.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/PrimerProyecto.dir/depend

