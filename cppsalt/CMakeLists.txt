# ================================================================================
# ================================================================================
# - File:    CMakeLists.txt
# - Purpose: Primary CMake file for C build system
#
# Source Metadata
# - Author:  Jonathan A. Webb
# - Date:    January 25, 2024
# - Version: 1.0
# - Copyright: Copyright 2024, Jonathan A. Webb Inc.
# ================================================================================
# ================================================================================
cmake_minimum_required(VERSION 3.28.1)
project(cppsalt)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable testing
enable_testing()

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Define the cppsalt library
add_library(cppsalt 
    except.cpp
    io.cpp
)

target_include_directories(cppsalt PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_options(cppsalt PRIVATE -Wall -Wpedantic)

# Fetch Google Test
include(FetchContent)
set(GTEST_VERSION 1.12.0)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-${GTEST_VERSION}.tar.gz
)
FetchContent_MakeAvailable(googletest)

# Define the unit test executable
add_executable(unit_tests 
    test/test_except.cpp
    test/test_types.cpp
    test/test_io.cpp
)
target_link_libraries(unit_tests gtest gtest_main cppsalt)
target_compile_options(unit_tests PRIVATE -Wall -Wpedantic)

# Register the unit_tests executable as a test for CTest
add_test(NAME unit_tests COMMAND unit_tests)

# ================================================================================
# ================================================================================
# eof
