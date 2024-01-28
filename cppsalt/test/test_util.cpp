// ================================================================================
// ================================================================================
// - File:    test_util.cpp
// - Purpose: This file implements google test as a method to test C++ code.
//            Describe the type of testing to be completed
//
// Source Metadata
// - Author:  Jonathan A. Webb
// - Date:    January 28, 2024
// - Version: 1.0
// - Copyright: Copyright 2024, Jon Webb Inc.
// ================================================================================
// ================================================================================
// - Begin test

#include "gtest/gtest.h"
#include <gtest/gtest.h>
#include "../include/util.hpp"
// ================================================================================
// ================================================================================

// Define a simple class directly in the test file
class MyClass {
public:
    int value;

    MyClass(int val) : value(val) {}

    // Optionally, define a swap member function
    void swap(MyClass& other) {
        cslt::swap(value, other.value);
    }
};
// ================================================================================
// ================================================================================

TEST(TestSwap, test_swap_scalar) {
    int a = 5;
    int b = 6;
    cslt::swap(a, b);
	EXPECT_EQ(a, 6);
    EXPECT_EQ(b, 5);
}
// --------------------------------------------------------------------------------

TEST(TestSwap, test_swap_class) {
    MyClass obj1(10);
    MyClass obj2(20);

    // Perform the swap
    // Using member function swap
    obj1.swap(obj2);
    // Alternatively, you could use std::swap(obj1, obj2);

    // Check if values were swapped
    EXPECT_EQ(obj1.value, 20);
    EXPECT_EQ(obj2.value, 10);
}
// ================================================================================
// ================================================================================
// TEST PAIR 

TEST(TestPair, TestInstantiatePair) {
    cslt::pair<int, float> a(2, 32.1);
    EXPECT_EQ(a.first, 2);
    EXPECT_FLOAT_EQ(a.second, 32.1);
} 
// --------------------------------------------------------------------------------

TEST(TestPair, TestOperatorOverload) {
    cslt::pair <float,int> planet, homeplanet;

    planet = cslt::make_pair(37.1f,6371);

    homeplanet = planet;
    EXPECT_FLOAT_EQ(homeplanet.first, 37.1);
    EXPECT_EQ(homeplanet.second, 6371);
}
// --------------------------------------------------------------------------------

TEST(TestPair, TestSwapMethod) {
    cslt::pair<int, int> one = cslt::make_pair(1, 2);
    cslt::pair<int, int> two = cslt::make_pair(3, 4);
    one.swap(two);
    EXPECT_EQ(one.first, 3);
    EXPECT_EQ(one.second, 4);
    EXPECT_EQ(two.first, 1);
    EXPECT_EQ(two.second, 2);
}
// ================================================================================
// ================================================================================
// eof
