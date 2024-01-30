# ================================================================================
# ================================================================================
# - File:    CMakeLists.txt
# - Purpose: Primary CMake file for C++ build system
#
# Source Metadata
# - Author:  Jonathan A. Webb 
# - Date:    January 25, 2024
# - Version: 1.0
# - Copyright: Copyright 2024, Jonathan A. Webb Inc.
# ================================================================================
# ================================================================================
# Set minimum cmake version
# Create the test executable using unit_test.c and test_hello.c
add_executable(unit_tests
	test_except.cpp
    test_types.cpp 
    test_io.cpp
    test_util.cpp
    test_type_traits.cpp
)

# Link the test executable against the Hello library and cmocka
target_link_libraries(unit_tests cppsalt)

# Register the unit_tests executable as a test for CTest
add_test(NAME unit_tests COMMAND unit_test)

# ================================================================================
# ================================================================================
# eof
