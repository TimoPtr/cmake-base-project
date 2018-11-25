
# Created by timoptr on 25/11/2018.


# Sets the minimum version of CMake required to build your native library.
# This ensures that a certain set of CMake features is available to
# your build.

cmake_minimum_required(VERSION 3.6)

project(cmake-base-project)

# Define option which allow enable and disable library or unitest
option(ENABLE_UNIT_TEST "Enable Unit test" OFF)
option(ENABLE_SAMPLE_LIB "Enable Sample lib" OFF)

# Add option to adding a new library

if (ENABLE_UNIT_TEST)
    enable_testing()
    set(CMAKE_CXX_STANDARD 11)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)

    include(CTest)
    add_subdirectory(gtest)
endif ()

# Add subdirectory to add the library
if (ENABLE_SAMPLE_LIB)
    add_subdirectory(sample-lib)
endif ()