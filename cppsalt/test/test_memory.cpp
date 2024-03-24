// ================================================================================
// ================================================================================
// - File:    test_memory.cpp
// - Purpose: This file implements google test as a method to test C++ code.
//            This file tests classes and methods from memory.hpp file
//
// Source Metadata
// - Author:  Jonathan A. Webb
// - Date:    March 24, 2024
// - Version: 1.0
// - Copyright: Copyright 2024, Jon Webb Inc.
// ================================================================================
// ================================================================================
// - Begin test

#include <gtest/gtest.h>
#include "../include/memory.hpp"

class MyClass {
public:
    static int count; // Track the number of instances
    MyClass() { ++count; }
    ~MyClass() { --count; }
};
int MyClass::count = 0;
// --------------------------------------------------------------------------------

// Test Fixture for unique_ptr tests
class UniquePtrTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Reset MyClass instance count before each test
        MyClass::count = 0;
    }
};
// --------------------------------------------------------------------------------

// Test that unique_ptr constructor takes ownership of a dynamically allocated object
TEST_F(UniquePtrTest, ConstructorTakesOwnership) {
    {
        cslt::unique_ptr<MyClass> ptr(new MyClass());
        EXPECT_EQ(MyClass::count, 1) << "unique_ptr should take ownership of the object";
    } // unique_ptr goes out of scope here
    EXPECT_EQ(MyClass::count, 0) << "unique_ptr destructor should delete the object";
}
// --------------------------------------------------------------------------------

// Test that unique_ptr destructor deletes the managed object
TEST_F(UniquePtrTest, DestructorDeletesObject) {
    {
        cslt::unique_ptr<MyClass> ptr(new MyClass());
        // No need to explicitly test anything here; we're setting up for the destructor call
    }
    EXPECT_EQ(MyClass::count, 0) << "unique_ptr destructor should delete the object";
}
// ================================================================================
// ================================================================================

class Resource {
public:
    static int count;  // Tracks the number of active instances
    int value;
    Resource(int val) : value(val) { ++count; }
    ~Resource() { --count; }
    void setValue(int val) { value = val; }
    int getValue() const { return value; }
};
int Resource::count = 0;

// Test Fixture
class UniquePtrTst2 : public ::testing::Test {
protected:
    void SetUp() override {
        Resource::count = 0;  // Reset the Resource count before each test
    }
};

// Constructor and Destructor
TEST_F(UniquePtrTst2, ConstructorDestructor) {
    {
        cslt::unique_ptr<Resource> ptr(new Resource(10));
        EXPECT_EQ(Resource::count, 1);
    }
    EXPECT_EQ(Resource::count, 0);
}

// Move Constructor
TEST_F(UniquePtrTst2, MoveConstructor) {
    cslt::unique_ptr<Resource> original(new Resource(20));
    cslt::unique_ptr<Resource> movedTo(cslt::move(original));
    EXPECT_EQ(Resource::count, 1);
    EXPECT_TRUE(!original);
    EXPECT_EQ(movedTo->getValue(), 20);
}

// Move Assignment
TEST_F(UniquePtrTst2, MoveAssignment) {
    cslt::unique_ptr<Resource> original(new Resource(30));
    cslt::unique_ptr<Resource> movedTo = cslt::move(original);
    EXPECT_EQ(Resource::count, 1);
    EXPECT_TRUE(!original);
    EXPECT_EQ(movedTo->getValue(), 30);
}

// Dereference and Member Access
TEST_F(UniquePtrTst2, DereferenceMemberAccess) {
    cslt::unique_ptr<Resource> ptr(new Resource(40));
    (*ptr).setValue(50);
    EXPECT_EQ((*ptr).getValue(), 50);
    ptr->setValue(60);
    EXPECT_EQ(ptr->getValue(), 60);
}

// Reset Method
TEST_F(UniquePtrTst2, ResetMethod) {
    cslt::unique_ptr<Resource> ptr(new Resource(70));
    ptr.reset(new Resource(80));
    EXPECT_EQ(Resource::count, 1);
    EXPECT_EQ(ptr->getValue(), 80);
    ptr.reset();
    EXPECT_TRUE(!ptr);
    EXPECT_EQ(Resource::count, 0);
}

// Release Method
TEST_F(UniquePtrTst2, ReleaseMethod) {
    cslt::unique_ptr<Resource> ptr(new Resource(90));
    Resource* rawPtr = ptr.release();
    EXPECT_TRUE(!ptr);
    EXPECT_EQ(Resource::count, 1);
    EXPECT_EQ(rawPtr->getValue(), 90);
    delete rawPtr;  // Clean up
}
// ================================================================================
// ================================================================================
// Shared Pointer tests 

// Helper class to track instances
class Trackable {
public:
    static int instances;
    Trackable() { ++instances; }
    ~Trackable() { --instances; }
};
int Trackable::instances = 0;
// --------------------------------------------------------------------------------

// Test fixture
class SharedPtrTest : public ::testing::Test {
protected:
    void SetUp() override {
        Trackable::instances = 0; // Reset the instance counter before each test
    }

    void TearDown() override {
        // Clean up code if necessary
    }
};
// --------------------------------------------------------------------------------

// Test single ownership and destructor
TEST_F(SharedPtrTest, SingleOwner) {
    {
        cslt::shared_ptr<Trackable> ptr(new Trackable());
        EXPECT_EQ(Trackable::instances, 1);
    }
    EXPECT_EQ(Trackable::instances, 0); // Destructor should be called
}
// --------------------------------------------------------------------------------

// Test shared ownership
TEST_F(SharedPtrTest, SharedOwnership) {
    cslt::shared_ptr<Trackable> ptr1(new Trackable());
    {
        cslt::shared_ptr<Trackable> ptr2 = ptr1; // Share ownership
        EXPECT_EQ(Trackable::instances, 1);
    } // ptr2 goes out of scope
    EXPECT_EQ(Trackable::instances, 1); // ptr1 still owns the object
}
// --------------------------------------------------------------------------------

// Test the copy constructor
TEST_F(SharedPtrTest, CopyConstructor) {
    cslt::shared_ptr<Trackable> original(new Trackable());
    cslt::shared_ptr<Trackable> copy = original; // Use the copy constructor

    EXPECT_EQ(Trackable::instances, 1); // Still one instance, now shared by two owners
}
// --------------------------------------------------------------------------------

// Test the copy assignment operator
TEST_F(SharedPtrTest, CopyAssignment) {
    cslt::shared_ptr<Trackable> original(new Trackable());
    cslt::shared_ptr<Trackable> assigned;
    assigned = original; // Use the copy assignment operator

    EXPECT_EQ(Trackable::instances, 1); // One instance, two owners
}
// --------------------------------------------------------------------------------

// Test the move constructor
TEST_F(SharedPtrTest, MoveConstructor) {
    cslt::shared_ptr<Trackable> original(new Trackable());
    cslt::shared_ptr<Trackable> moved = std::move(original); // Use the move constructor

    EXPECT_EQ(Trackable::instances, 1);
    EXPECT_TRUE(!original); // original should be empty
}
// --------------------------------------------------------------------------------

// Test the move assignment operator
TEST_F(SharedPtrTest, MoveAssignment) {
    cslt::shared_ptr<Trackable> original(new Trackable());
    cslt::shared_ptr<Trackable> moved;
    moved = std::move(original); // Use the move assignment operator

    EXPECT_EQ(Trackable::instances, 1);
    EXPECT_TRUE(!original); // original should be empty
}
// --------------------------------------------------------------------------------

// Test reset method
TEST_F(SharedPtrTest, Reset) {
    cslt::shared_ptr<Trackable> ptr(new Trackable());
    ptr.reset(new Trackable()); // Replace the managed object

    EXPECT_EQ(Trackable::instances, 1); // The first object should be deleted
}
// --------------------------------------------------------------------------------

// Test reset to nullptr
TEST_F(SharedPtrTest, ResetToNullptr) {
    cslt::shared_ptr<Trackable> ptr(new Trackable());
    ptr.reset(); // Reset without a new object

    EXPECT_EQ(Trackable::instances, 0); // The managed object should be deleted
}
// ================================================================================
// ================================================================================
// eof
