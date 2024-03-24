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
#include <type_traits>
#include <utility>
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
// TEST MOVE 

class TestClass {
public:
    bool moved_from;

    TestClass() : moved_from(false) {}

    TestClass(TestClass&& other) : moved_from(false) {
        other.moved_from = true;
    }
};
// --------------------------------------------------------------------------------

TEST(MoveTest, TestClassMove) {
    TestClass obj;
    TestClass moved_obj = cslt::move(obj);

    EXPECT_TRUE(obj.moved_from); // Check if the original object is in a moved-from state
    EXPECT_FALSE(moved_obj.moved_from); // The moved object should not be in a moved-from state
}
// --------------------------------------------------------------------------------

TEST(MoveTest, MoveBasicType) {
    int a = 5;
    int b = cslt::move(a); // This should compile

    EXPECT_EQ(a, 5); // Moving a basic type doesn't change its value
    EXPECT_EQ(b, 5);
}
// --------------------------------------------------------------------------------

TEST(MoveTest, MoveStdVector) {
    std::vector<int> vec = {1, 2, 3};
    std::vector<int> moved_vec = cslt::move(vec);

    EXPECT_TRUE(vec.empty()); // vec should be empty after move
    EXPECT_EQ(moved_vec.size(), 3); // moved_vec should have the elements
}
// ================================================================================
// ================================================================================
// TEST MOVE_IF_NOEXCEPT

class NoexceptMoveClass {
public:
    bool wasMoved;
    NoexceptMoveClass() : wasMoved(false) {}
    NoexceptMoveClass(NoexceptMoveClass&& other) noexcept : wasMoved(true) { other.wasMoved = true; }
    NoexceptMoveClass& operator=(NoexceptMoveClass&& other) noexcept {
        wasMoved = true;
        other.wasMoved = true;
        return *this;
    }
};
// --------------------------------------------------------------------------------
// Class with throwing move constructor

class ThrowingMoveClass {
public:
    bool wasMoved;
    ThrowingMoveClass() : wasMoved(false) {}
    ThrowingMoveClass(ThrowingMoveClass&& other) : wasMoved(true) { other.wasMoved = true; }
    ThrowingMoveClass& operator=(ThrowingMoveClass&& other) {
        wasMoved = true;
        other.wasMoved = true;
        return *this;
    }
};
// --------------------------------------------------------------------------------
// Test for noexcept move

TEST(MoveIfNoexceptTest, NoexceptMove) {
    NoexceptMoveClass obj;
    NoexceptMoveClass movedObj = cslt::move_if_noexcept(obj);
    EXPECT_TRUE(movedObj.wasMoved);
}
// ================================================================================
// ================================================================================

// Helper functions to identify argument types
void consume(int&) {
    // Function that takes an lvalue reference
}

void consume(int&&) {
    // Function that takes an rvalue reference
}

// A helper class to test forwarding of class instances
class MynewClass {};

void consumeClass(MynewClass&) {
    // Function that takes an lvalue reference to MynewClass
}

void consumeClass(MynewClass&&) {
    // Function that takes an rvalue reference to MynewClass
}

// Test fixture for our tests
class ForwardTest : public ::testing::Test {
protected:
    // Set-up code for each test here.
};

// Test that cslt::forward correctly forwards lvalues
TEST_F(ForwardTest, ForwardsLvaluesCorrectly) {
    int x = 42;
    MynewClass myClassInstance;
    // Expect that we can call a function expecting an lvalue reference
    EXPECT_NO_THROW(consume(cslt::forward<int&>(x)));
    EXPECT_NO_THROW(consumeClass(cslt::forward<MynewClass&>(myClassInstance)));
}

// Test that cslt::forward correctly forwards rvalues
TEST_F(ForwardTest, ForwardsRvaluesCorrectly) {
    // Expect that we can call a function expecting an rvalue reference
    EXPECT_NO_THROW(consume(cslt::forward<int>(42)));
    MynewClass tempClassInstance;
    EXPECT_NO_THROW(consumeClass(cslt::forward<MynewClass>(std::move(tempClassInstance))));
}

// Test that cslt::forward can forward an lvalue as an rvalue when explicitly cast
TEST_F(ForwardTest, ForwardsLvalueAsRvalueWhenCast) {
    int x = 42;
    MynewClass myClassInstance;
    // Explicitly casting an lvalue to an rvalue reference type
    EXPECT_NO_THROW(consume(cslt::forward<int&&>(x)));
    EXPECT_NO_THROW(consumeClass(cslt::forward<MynewClass&&>(myClassInstance)));
}
// ================================================================================
// ================================================================================
// eof
