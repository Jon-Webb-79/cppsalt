// ================================================================================
// ================================================================================
// - File:    test_type_traits.cpp
// - Purpose: This file implements google test as a method to test C++ code.
//            Describe the type of testing to be completed
//
// Source Metadata
// - Author:  Jonathan A. Webb
// - Date:    January 29, 2024
// - Version: 1.0
// - Copyright: Copyright 2024, Jon Webb Inc.
// ================================================================================
// ================================================================================
// - Begin test

#include <gtest/gtest.h>
#include "../include/type_traits.hpp"
// ================================================================================
// ================================================================================

TEST(RemoveReferenceTest, BasicTypes) {
    static_assert(std::is_same<cslt::remove_reference<int>::type, int>::value, "Failed for int");
    static_assert(std::is_same<cslt::remove_reference<float>::type, float>::value, "Failed for float");
    // ... other basic types
}
// --------------------------------------------------------------------------------

TEST(RemoveReferenceTest, ReferenceTypes) {
    static_assert(std::is_same<cslt::remove_reference<int&>::type, int>::value, "Failed for int&");
    static_assert(std::is_same<cslt::remove_reference<float&>::type, float>::value, "Failed for float&");
    // ... other reference types
}
// --------------------------------------------------------------------------------

TEST(RemoveReferenceTest, RvalueReferenceTypes) {
    static_assert(std::is_same<cslt::remove_reference<int&&>::type, int>::value, "Failed for int&&");
    static_assert(std::is_same<cslt::remove_reference<float&&>::type, float>::value, "Failed for float&&");
    // ... other rvalue reference types
}
// ================================================================================
// ================================================================================

// A test class with a noexcept move constructor
class NoexceptMoveClass {
public:
    NoexceptMoveClass(NoexceptMoveClass&&) noexcept {}
};
// --------------------------------------------------------------------------------

// A test class without a noexcept move constructor
class ThrowingMoveClass {
public:
    ThrowingMoveClass(ThrowingMoveClass&&) {}
};
// --------------------------------------------------------------------------------

TEST(IsNothrowMoveConstructibleTest, ValidatesNoexceptMoveConstructor) {
    static_assert(cslt::is_nothrow_move_constructible<NoexceptMoveClass>::value, "NoexceptMoveClass should be nothrow move constructible");

    static_assert(!cslt::is_nothrow_move_constructible<ThrowingMoveClass>::value, "ThrowingMoveClass should not be nothrow move constructible");

    static_assert(cslt::is_nothrow_move_constructible<int>::value, "int should be nothrow move constructible");
}
// ================================================================================
// ================================================================================
// eof
