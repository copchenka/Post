# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.2.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\BOOK\CLionProjects\Post

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\BOOK\CLionProjects\Post\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Post.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Post.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Post.dir/flags.make

CMakeFiles/Post.dir/main.c.obj: CMakeFiles/Post.dir/flags.make
CMakeFiles/Post.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\BOOK\CLionProjects\Post\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Post.dir/main.c.obj"
	C:\PROGRA~2\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Post.dir\main.c.obj   -c C:\Users\BOOK\CLionProjects\Post\main.c

CMakeFiles/Post.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Post.dir/main.c.i"
	C:\PROGRA~2\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\BOOK\CLionProjects\Post\main.c > CMakeFiles\Post.dir\main.c.i

CMakeFiles/Post.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Post.dir/main.c.s"
	C:\PROGRA~2\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\BOOK\CLionProjects\Post\main.c -o CMakeFiles\Post.dir\main.c.s

CMakeFiles/Post.dir/post.c.obj: CMakeFiles/Post.dir/flags.make
CMakeFiles/Post.dir/post.c.obj: ../post.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\BOOK\CLionProjects\Post\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Post.dir/post.c.obj"
	C:\PROGRA~2\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Post.dir\post.c.obj   -c C:\Users\BOOK\CLionProjects\Post\post.c

CMakeFiles/Post.dir/post.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Post.dir/post.c.i"
	C:\PROGRA~2\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\BOOK\CLionProjects\Post\post.c > CMakeFiles\Post.dir\post.c.i

CMakeFiles/Post.dir/post.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Post.dir/post.c.s"
	C:\PROGRA~2\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\BOOK\CLionProjects\Post\post.c -o CMakeFiles\Post.dir\post.c.s

# Object files for target Post
Post_OBJECTS = \
"CMakeFiles/Post.dir/main.c.obj" \
"CMakeFiles/Post.dir/post.c.obj"

# External object files for target Post
Post_EXTERNAL_OBJECTS =

Post.exe: CMakeFiles/Post.dir/main.c.obj
Post.exe: CMakeFiles/Post.dir/post.c.obj
Post.exe: CMakeFiles/Post.dir/build.make
Post.exe: CMakeFiles/Post.dir/linklibs.rsp
Post.exe: CMakeFiles/Post.dir/objects1.rsp
Post.exe: CMakeFiles/Post.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\BOOK\CLionProjects\Post\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Post.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Post.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Post.dir/build: Post.exe

.PHONY : CMakeFiles/Post.dir/build

CMakeFiles/Post.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Post.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Post.dir/clean

CMakeFiles/Post.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\BOOK\CLionProjects\Post C:\Users\BOOK\CLionProjects\Post C:\Users\BOOK\CLionProjects\Post\cmake-build-debug C:\Users\BOOK\CLionProjects\Post\cmake-build-debug C:\Users\BOOK\CLionProjects\Post\cmake-build-debug\CMakeFiles\Post.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Post.dir/depend

