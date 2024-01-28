// ================================================================================
// ================================================================================
// - File:    test_types.cpp
// - Purpose: This file implements google test as a method to test C++ code.
//            Describe the type of testing to be completed
//
// Source Metadata
// - Author:  Jonathan A. Webb
// - Date:    January 27, 2024
// - Version: 1.0
// - Copyright: Copyright 2024, Jon Webb Inc.
// ================================================================================
// ================================================================================
// - Begin test

#include "../include/dtype.hpp"
#include <gtest/gtest.h>
#include <type_traits>
// ================================================================================
// ================================================================================
// TEST SIZE_T IMPLEMENTATION 

TEST(CsltTypesTest, SizeTExists) {
    cslt::size_t size_var = 0;
    EXPECT_GE(size_var, 0); // Basic check for unsigned property
}
// --------------------------------------------------------------------------------
// Test properties of cslt::size_t

TEST(CsltTypesTest, SizeTProperties) {
    EXPECT_TRUE(std::is_unsigned<cslt::size_t>::value); // Check if it's unsigned
    EXPECT_EQ(sizeof(cslt::size_t), sizeof(std::size_t)); // Check size consistency
}
// ================================================================================
// ================================================================================
// TEST SSIZE_T 

#if defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__)) || defined(_WIN32) || defined(_WIN64)
// Test existence of cslt::ssize_t
TEST(CsltTypesTest, SSizeTExists) {
    cslt::ssize_t ssize_var = 0;
    ssize_var = -1; // Basic check for signed property
    EXPECT_LT(ssize_var, 0);
}
// --------------------------------------------------------------------------------
// Test properties of cslt::ssize_t

TEST(CsltTypesTest, SSizeTProperties) {
    EXPECT_TRUE(std::is_signed<cslt::ssize_t>::value); // Check if it's signed
    // Optional: Check size consistency with expected size
    // This might vary based on your definition in different environments
    // EXPECT_EQ(sizeof(cslt::ssize_t), expected_size);
}

// You can add more tests specific to cslt::ssize_t here

#endif /* ssize_t specific tests */
// ================================================================================
// ================================================================================
// eof
