
# Created by timoptr on 25/11/2018.


# Sets the minimum version of CMake required to build your native library.
# This ensures that a certain set of CMake features is available to
# your build.

cmake_minimum_required(VERSION 3.6)

project(sample-lib)

# Specifies a library name, specifies whether the library is STATIC or
# SHARED, and provides relative paths to the source code. You can
# define multiple libraries by adding multiple add_library() commands,
# and CMake builds them for you. When you build your app, Gradle
# automatically packages shared libraries with your APK.
add_library( # Specifies the name of the library.
        sample-lib

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).)

# Link to dependencies

# Specify visibily of folder and include path
target_include_directories(sample-lib PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE src)

if (ENABLE_UNIT_TEST)
    # Register tests
    file(GLOB TESTS_SRCS test/*.cpp)
    list(LENGTH TESTS_SRCS NUMBER_TEST_CLASS)
    if (NOT (${NUMBER_TEST_CLASS} EQUAL 0))
        add_executable(sample-tests ${TESTS_SRCS})
        target_link_libraries(sample-tests gtest_main sample-lib)
        add_test(NAME hr COMMAND sample-tests)
    endif ()
endif ()
