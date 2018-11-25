# cmake-base-project
Architecture of project using cmake / googletest, multi module


## Architecture of a library

- include folder : contains all public headers
- src folder : contains all the sources
- test : contains all unit test
- CMakeLists.txt : the configuration of the module 


## Add library 

Use this template 

```camke
# Sets the minimum version of CMake required to build your native library.
# This ensures that a certain set of CMake features is available to
# your build.

cmake_minimum_required(VERSION 3.6)

project(PROJECT-NAME)

# Specifies a library name, specifies whether the library is STATIC or
# SHARED, and provides relative paths to the source code. You can
# define multiple libraries by adding multiple add_library() commands,
# and CMake builds them for you. When you build your app, Gradle
# automatically packages shared libraries with your APK.
add_library( # Specifies the name of the library.
        LIBRARY-NAME

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        )

# Link to dependencies
target_link_libraries(LIBRARY-NAME OTHER-LIBRARIES-DEPENDENCIES)

# Specify visibily of folder and include path
target_include_directories(LIBRARY-NAME PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE src)

if (ENABLE_UNIT_TEST)
    # Register tests
    file(GLOB TESTS_SRCS test/*.cpp)
    list(LENGTH TESTS_SRCS NUMBER_TEST_CLASS)
    if (NOT (${NUMBER_TEST_CLASS} EQUAL 0))
        add_executable(LIBRARY-NAME-TEST ${TESTS_SRCS})
        target_link_libraries(LIBRARY-NAME-TEST gtest_main LIBRARY-NAME)
        add_test(NAME TEST-NAME COMMAND LIBRARY-NAME-TEST)
    endif ()
endif ()

```

replace PROJECT-NAME by the name of your project and LIBRARY-NAME by the name of your library

Add to the main cmake an Option ``option(ENABLE_SAMPLE_LIB "Enable Sample lib" OFF)`` to allow enable disable library build
and a block at the end 
````cmake
if (ENABLE_SAMPLE_LIB)
    add_subdirectory(sample-lib)
endif ()
````