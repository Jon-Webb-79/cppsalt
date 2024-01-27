// ================================================================================
// ================================================================================
// - File:    test.cpp
// - Purpose: This file implements google test as a method to test C++ code.
//            Describe the type of testing to be completed
//
// Source Metadata
// - Author:  Jonathan A. Webb
// - Date:    January 25, 2024
// - Version: 1.0
// - Copyright: Copyright 2024, Jon Webb Inc.
// ================================================================================
// ================================================================================
// - Begin test

#include <gtest/gtest.h>
#include "../include/except.hpp"

// ================================================================================
// ================================================================================ 
// Test exception class 

class ExceptionTest : public ::testing::Test {
protected:
    cslt::exception defaultException;
    cslt::exception customException{"Custom error message"};
};
// --------------------------------------------------------------------------------

TEST_F(ExceptionTest, DefaultConstructorProvidesDefaultMessage) {
    EXPECT_STREQ("Exception raised!", defaultException.what());
}
// --------------------------------------------------------------------------------

TEST_F(ExceptionTest, CustomMessageIsSetCorrectly) {
    EXPECT_STREQ("Custom error message", customException.what());
}
// --------------------------------------------------------------------------------

TEST_F(ExceptionTest, CopyConstructorDuplicatesMessage) {
    cslt::exception copiedException = customException;
    EXPECT_STREQ(customException.what(), copiedException.what());
}
// --------------------------------------------------------------------------------

TEST_F(ExceptionTest, CopyAssignmentDuplicatesMessage) {
    cslt::exception assignedException;
    assignedException = customException;
    EXPECT_STREQ(customException.what(), assignedException.what());
}
// --------------------------------------------------------------------------------

TEST_F(ExceptionTest, CanBeCaughtAsCsltException) {
    try {
        throw customException;
    } catch (const cslt::exception& e) {
        EXPECT_STREQ("Custom error message", e.what());
    } catch (...) {
        FAIL() << "Expected std::exception";
    }
}
// --------------------------------------------------------------------------------

TEST_F(ExceptionTest, DefaultExceptionHasDefaultMessage) {
    try {
        throw defaultException;
    } catch (const cslt::exception& e) {
        EXPECT_STREQ("Exception raised!", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::exception";
    }
}
// ================================================================================
// ================================================================================
// TEST BAD_ALLOC CLASS 

class BadAllocTest : public ::testing::Test {
protected:
    cslt::bad_alloc defaultBadAlloc;
    cslt::bad_alloc customBadAlloc{"Custom bad_alloc message"};
};
// --------------------------------------------------------------------------------

TEST_F(BadAllocTest, ConstructorSetsMessage) {
    EXPECT_STREQ("Custom bad_alloc message", customBadAlloc.what());
}
// --------------------------------------------------------------------------------

TEST_F(BadAllocTest, DefaultConstructorProvidesDefaultMessage) {
    EXPECT_STREQ("Memory Allocation Error Raised!", defaultBadAlloc.what()); // Assuming a default message is set for bad_alloc
}
// --------------------------------------------------------------------------------

TEST_F(BadAllocTest, CanBeCaughtAsSpecificType) {
    try {
        throw customBadAlloc;
    } catch (const cslt::bad_alloc& e) {
        EXPECT_STREQ("Custom bad_alloc message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::bad_alloc";
    }
}
// --------------------------------------------------------------------------------

TEST_F(BadAllocTest, CanBeCaughtAsBaseType) {
    try {
        throw customBadAlloc;
    } catch (const cslt::exception& e) {
        EXPECT_STREQ("Custom bad_alloc message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::exception";
    }
}
// ================================================================================
// ================================================================================
// TEST LOGIC_ERROR CLASS 

class LogicErrorTest : public ::testing::Test {
protected:
    cslt::logic_error defaultLogicError;
    cslt::logic_error customLogicError{"Custom logic_error message"};
};
// --------------------------------------------------------------------------------

TEST_F(LogicErrorTest, ConstructorSetsMessage) {
    EXPECT_STREQ("Custom logic_error message", customLogicError.what());
}
// --------------------------------------------------------------------------------

TEST_F(LogicErrorTest, DefaultConstructorProvidesDefaultMessage) {
    EXPECT_STREQ("Logic Error Raised!", defaultLogicError.what()); // Assuming a default message is set for logic_error
}
// --------------------------------------------------------------------------------

TEST_F(LogicErrorTest, CanBeCaughtAsSpecificType) {
    try {
        throw customLogicError;
    } catch (const cslt::logic_error& e) {
        EXPECT_STREQ("Custom logic_error message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::logic_error";
    }
}
// --------------------------------------------------------------------------------

TEST_F(LogicErrorTest, CanBeCaughtAsBaseType) {
    try {
        throw customLogicError;
    } catch (const cslt::exception& e) {
        EXPECT_STREQ("Custom logic_error message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::exception";
    }
}
// ================================================================================
// ================================================================================
// TEST RUNTIME_ERROR CLASS 

class RuntimeErrorTest : public ::testing::Test {
protected:
    cslt::runtime_error defaultRuntimeError;
    cslt::runtime_error customRuntimeError{"Custom runtime_error message"};
};
// --------------------------------------------------------------------------------

TEST_F(RuntimeErrorTest, ConstructorSetsMessage) {
    EXPECT_STREQ("Custom runtime_error message", customRuntimeError.what());
}
// --------------------------------------------------------------------------------

TEST_F(RuntimeErrorTest, DefaultConstructorProvidesDefaultMessage) {
    EXPECT_STREQ("Runtime Error Raised!", defaultRuntimeError.what()); // Assuming a default message is set for runtime_error
}
// --------------------------------------------------------------------------------

TEST_F(RuntimeErrorTest, CanBeCaughtAsSpecificType) {
    try {
        throw customRuntimeError;
    } catch (const cslt::runtime_error& e) {
        EXPECT_STREQ("Custom runtime_error message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::runtime_error";
    }
}
// --------------------------------------------------------------------------------

TEST_F(RuntimeErrorTest, CanBeCaughtAsBaseType) {
    try {
        throw customRuntimeError;
    } catch (const cslt::exception& e) {
        EXPECT_STREQ("Custom runtime_error message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::exception";
    }
}
// ================================================================================
// ================================================================================
// TEST TYPE_ID CLASS 

class BadTypeidTest : public ::testing::Test {
protected:
    cslt::bad_typeid defaultBadTypeid;
    cslt::bad_typeid customBadTypeid{"Custom bad_typeid message"};
};
// --------------------------------------------------------------------------------

TEST_F(BadTypeidTest, ConstructorSetsMessage) {
    EXPECT_STREQ("Custom bad_typeid message", customBadTypeid.what());
}
// --------------------------------------------------------------------------------

TEST_F(BadTypeidTest, DefaultConstructorProvidesDefaultMessage) {
    EXPECT_STREQ("Bad Type ID Error Raised!", defaultBadTypeid.what()); // Assuming a default message is set for bad_typeid_error
}
// --------------------------------------------------------------------------------

TEST_F(BadTypeidTest, CanBeCaughtAsSpecificType) {
    try {
        throw customBadTypeid;
    } catch (const cslt::bad_typeid& e) {
        EXPECT_STREQ("Custom bad_typeid message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::bad_typeid";
    }
}
// --------------------------------------------------------------------------------

TEST_F(BadTypeidTest, CanBeCaughtAsBaseType) {
    try {
        throw customBadTypeid;
    } catch (const cslt::exception& e) {
        EXPECT_STREQ("Custom bad_typeid message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::exception";
    }
}
// ================================================================================
// ================================================================================
// TEST BAD_OPTIONAL_ACCESS CLASS 

class BadOptionalAccessTest : public ::testing::Test {
protected:
    cslt::bad_optional_access defaultBadOptionalAccess;
    cslt::bad_optional_access customBadOptionalAccess{"Custom bad_optional_access message"};
};
// --------------------------------------------------------------------------------

TEST_F(BadOptionalAccessTest, ConstructorSetsMessage) {
    EXPECT_STREQ("Custom bad_optional_access message", customBadOptionalAccess.what());
}
// --------------------------------------------------------------------------------

TEST_F(BadOptionalAccessTest, DefaultConstructorProvidesDefaultMessage) {
    EXPECT_STREQ("Bad Optional Access Error Raised!", defaultBadOptionalAccess.what()); // Assuming a default message is set for bad_optional_access_error
}
// --------------------------------------------------------------------------------

TEST_F(BadOptionalAccessTest, CanBeCaughtAsSpecificType) {
    try {
        throw customBadOptionalAccess;
    } catch (const cslt::bad_optional_access& e) {
        EXPECT_STREQ("Custom bad_optional_access message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::bad_optional_access";
    }
}
// --------------------------------------------------------------------------------

TEST_F(BadOptionalAccessTest, CanBeCaughtAsBaseType) {
    try {
        throw customBadOptionalAccess;
    } catch (const cslt::exception& e) {
        EXPECT_STREQ("Custom bad_optional_access message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::exception";
    }
}
// ================================================================================
// ================================================================================
// TEST BAD_EXPECTED_ACCESS CLASS 

class BadExpectedAccessTest : public ::testing::Test {
protected:
    cslt::bad_expected_access defaultBadExpectedAccess;
    cslt::bad_expected_access customBadExpectedAccess{"Custom bad_expected_access message"};
};
// --------------------------------------------------------------------------------

TEST_F(BadExpectedAccessTest, ConstructorSetsMessage) {
    EXPECT_STREQ("Custom bad_expected_access message", customBadExpectedAccess.what());
}
// --------------------------------------------------------------------------------

TEST_F(BadExpectedAccessTest, DefaultConstructorProvidesDefaultMessage) {
    EXPECT_STREQ("Bad Expected Access Error Raised!", defaultBadExpectedAccess.what()); // Assuming a default message is set for bad_expected_access_error
}
// --------------------------------------------------------------------------------

TEST_F(BadExpectedAccessTest, CanBeCaughtAsSpecificType) {
    try {
        throw customBadExpectedAccess;
    } catch (const cslt::bad_expected_access& e) {
        EXPECT_STREQ("Custom bad_expected_access message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::bad_expected_access";
    }
}
// --------------------------------------------------------------------------------

TEST_F(BadExpectedAccessTest, CanBeCaughtAsBaseType) {
    try {
        throw customBadExpectedAccess;
    } catch (const cslt::exception& e) {
        EXPECT_STREQ("Custom bad_expected_access message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::exception";
    }
}
// ================================================================================
// ================================================================================
// TEST BAD_WEAK_POINTER CLASS 

class BadWeakPtrTest : public ::testing::Test {
protected:
    cslt::bad_weak_ptr defaultBadWeakPtr;
    cslt::bad_weak_ptr customBadWeakPtr{"Custom bad_weak_ptr message"};
};
// --------------------------------------------------------------------------------

TEST_F(BadWeakPtrTest, ConstructorSetsMessage) {
    EXPECT_STREQ("Custom bad_weak_ptr message", customBadWeakPtr.what());
}
// --------------------------------------------------------------------------------

TEST_F(BadWeakPtrTest, DefaultConstructorProvidesDefaultMessage) {
    EXPECT_STREQ("Bad Weak Pointer Error Raised!", defaultBadWeakPtr.what()); // Assuming a default message is set for bad_weak_ptr_error
}
// --------------------------------------------------------------------------------

TEST_F(BadWeakPtrTest, CanBeCaughtAsSpecificType) {
    try {
        throw customBadWeakPtr;
    } catch (const cslt::bad_weak_ptr& e) {
        EXPECT_STREQ("Custom bad_weak_ptr message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::bad_weak_ptr";
    }
}
// --------------------------------------------------------------------------------

TEST_F(BadWeakPtrTest, CanBeCaughtAsBaseType) {
    try {
        throw customBadWeakPtr;
    } catch (const cslt::exception& e) {
        EXPECT_STREQ("Custom bad_weak_ptr message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::exception";
    }
}
// ================================================================================
// ================================================================================
// TEST INVALID_ARGUMENT CLASS 

class InvalidArgumentTest : public ::testing::Test {
protected:
    cslt::invalid_argument defaultInvalidArgument;
    cslt::invalid_argument customInvalidArgument{"Custom invalid_argument message"};
};
// --------------------------------------------------------------------------------

TEST_F(InvalidArgumentTest, ConstructorSetsMessage) {
    EXPECT_STREQ("Custom invalid_argument message", customInvalidArgument.what());
}
// --------------------------------------------------------------------------------

TEST_F(InvalidArgumentTest, DefaultConstructorProvidesDefaultMessage) {
    EXPECT_STREQ("Invalid Argument Error Raised!", defaultInvalidArgument.what()); // Assuming a default message is set for invalic_argument_error
}
// --------------------------------------------------------------------------------

TEST_F(InvalidArgumentTest, CanBeCaughtAsSpecificType) {
    try {
        throw customInvalidArgument;
    } catch (const cslt::invalid_argument& e) {
        EXPECT_STREQ("Custom invalid_argument message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::invalid_argument";
    }
}
// --------------------------------------------------------------------------------

TEST_F(InvalidArgumentTest, CanBeCaughtAsBaseType) {
    try {
        throw customInvalidArgument;
    } catch (const cslt::exception& e) {
        EXPECT_STREQ("Custom invalid_argument message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::logic_error";
    }
}
// ================================================================================
// ================================================================================
// TEST DOMAIN_ERROR CLASS 

class DomainErrorTest : public ::testing::Test {
protected:
    cslt::domain_error defaultDomainError;
    cslt::domain_error customDomainError{"Custom domain_error message"};
};
// --------------------------------------------------------------------------------

TEST_F(DomainErrorTest, ConstructorSetsMessage) {
    EXPECT_STREQ("Custom domain_error message", customDomainError.what());
}
// --------------------------------------------------------------------------------

TEST_F(DomainErrorTest, DefaultConstructorProvidesDefaultMessage) {
    EXPECT_STREQ("Domain Error Raised!", defaultDomainError.what()); // Assuming a default message is set for invalic_argument_error
}
// --------------------------------------------------------------------------------

TEST_F(DomainErrorTest, CanBeCaughtAsSpecificType) {
    try {
        throw customDomainError;
    } catch (const cslt::domain_error& e) {
        EXPECT_STREQ("Custom domain_error message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::domain_error";
    }
}
// --------------------------------------------------------------------------------

TEST_F(DomainErrorTest, CanBeCaughtAsBaseType) {
    try {
        throw customDomainError;
    } catch (const cslt::exception& e) {
        EXPECT_STREQ("Custom domain_error message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::logic_error";
    }
}
// ================================================================================
// ================================================================================
// TEST LENGTH_ERROR CLASS 

class LengthErrorTest : public ::testing::Test {
protected:
    cslt::length_error defaultLengthError;
    cslt::length_error customLengthError{"Custom length_error message"};
};
// --------------------------------------------------------------------------------

TEST_F(LengthErrorTest, ConstructorSetsMessage) {
    EXPECT_STREQ("Custom length_error message", customLengthError.what());
}
// --------------------------------------------------------------------------------

TEST_F(LengthErrorTest, DefaultConstructorProvidesDefaultMessage) {
    EXPECT_STREQ("Length Error Raised!", defaultLengthError.what()); // Assuming a default message is set for invalic_argument_error
}
// --------------------------------------------------------------------------------

TEST_F(LengthErrorTest, CanBeCaughtAsSpecificType) {
    try {
        throw customLengthError;
    } catch (const cslt::length_error& e) {
        EXPECT_STREQ("Custom length_error message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::length_error";
    }
}
// --------------------------------------------------------------------------------

TEST_F(LengthErrorTest, CanBeCaughtAsBaseType) {
    try {
        throw customLengthError;
    } catch (const cslt::exception& e) {
        EXPECT_STREQ("Custom length_error message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::logic_error";
    }
}
// ================================================================================
// ================================================================================
// TEST OUT_OF_RANGE_ERROR CLASS 

class OutOfRangeErrorTest : public ::testing::Test {
protected:
    cslt::out_of_range defaultOutOfRangeError;
    cslt::out_of_range customOutOfRangeError{"Custom out_of_range_error message"};
};
// --------------------------------------------------------------------------------

TEST_F(OutOfRangeErrorTest, ConstructorSetsMessage) {
    EXPECT_STREQ("Custom out_of_range_error message", customOutOfRangeError.what());
}
// --------------------------------------------------------------------------------

TEST_F(OutOfRangeErrorTest, DefaultConstructorProvidesDefaultMessage) {
    EXPECT_STREQ("Out of Range Error Raised!", defaultOutOfRangeError.what()); // Assuming a default message is set for invalic_argument_error
}
// --------------------------------------------------------------------------------

TEST_F(OutOfRangeErrorTest, CanBeCaughtAsSpecificType) {
    try {
        throw customOutOfRangeError;
    } catch (const cslt::out_of_range& e) {
        EXPECT_STREQ("Custom out_of_range_error message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::out_of_range_error";
    }
}
// --------------------------------------------------------------------------------

TEST_F(OutOfRangeErrorTest, CanBeCaughtAsBaseType) {
    try {
        throw customOutOfRangeError;
    } catch (const cslt::exception& e) {
        EXPECT_STREQ("Custom out_of_range_error message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::logic_error";
    }
}
// ================================================================================
// ================================================================================
// TEST FUTURE_ERROR CLASS 

class FutureErrorTest : public ::testing::Test {
protected:
    cslt::future_error defaultFutureError;
    cslt::future_error customFutureError{"Custom future_error message"};
};
// --------------------------------------------------------------------------------

TEST_F(FutureErrorTest, ConstructorSetsMessage) {
    EXPECT_STREQ("Custom future_error message", customFutureError.what());
}
// --------------------------------------------------------------------------------

TEST_F(FutureErrorTest, DefaultConstructorProvidesDefaultMessage) {
    EXPECT_STREQ("Future Error Raised!", defaultFutureError.what()); // Assuming a default message is set for invalic_argument_error
}
// --------------------------------------------------------------------------------

TEST_F(FutureErrorTest, CanBeCaughtAsSpecificType) {
    try {
        throw customFutureError;
    } catch (const cslt::future_error& e) {
        EXPECT_STREQ("Custom future_error message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::future_error";
    }
}
// --------------------------------------------------------------------------------

TEST_F(FutureErrorTest, CanBeCaughtAsBaseType) {
    try {
        throw customFutureError;
    } catch (const cslt::exception& e) {
        EXPECT_STREQ("Custom future_error message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::logic_error";
    }
}
// ================================================================================
// ================================================================================
// TEST RANGE_ERROR CLASS 
class RangeErrorTest : public ::testing::Test {
protected:
    cslt::range_error defaultRangeError;
    cslt::range_error customRangeError{"Custom range_error message"};
};
// --------------------------------------------------------------------------------

TEST_F(RangeErrorTest, ConstructorSetsMessage) {
    EXPECT_STREQ("Custom range_error message", customRangeError.what());
}
// --------------------------------------------------------------------------------

TEST_F(RangeErrorTest, DefaultConstructorProvidesDefaultMessage) {
    EXPECT_STREQ("Range Error Raised!", defaultRangeError.what()); // Assuming a default message is set for invalic_argument_error
}
// --------------------------------------------------------------------------------

TEST_F(RangeErrorTest, CanBeCaughtAsSpecificType) {
    try {
        throw customRangeError;
    } catch (const cslt::range_error& e) {
        EXPECT_STREQ("Custom range_error message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::range_error";
    }
}
// --------------------------------------------------------------------------------

TEST_F(RangeErrorTest, CanBeCaughtAsBaseType) {
    try {
        throw customRangeError;
    } catch (const cslt::exception& e) {
        EXPECT_STREQ("Custom range_error message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::runtime_error";
    }
}
// ================================================================================
// ================================================================================
// TEST OVERFLOW_ERROR CLASS 
class OverflowErrorTest : public ::testing::Test {
protected:
    cslt::overflow_error defaultOverflowError;
    cslt::overflow_error customOverflowError{"Custom overflow_error message"};
};
// --------------------------------------------------------------------------------

TEST_F(OverflowErrorTest, ConstructorSetsMessage) {
    EXPECT_STREQ("Custom overflow_error message", customOverflowError.what());
}
// --------------------------------------------------------------------------------

TEST_F(OverflowErrorTest, DefaultConstructorProvidesDefaultMessage) {
    EXPECT_STREQ("Overflow Error Raised!", defaultOverflowError.what()); // Assuming a default message is set for invalic_argument_error
}
// --------------------------------------------------------------------------------

TEST_F(OverflowErrorTest, CanBeCaughtAsSpecificType) {
    try {
        throw customOverflowError;
    } catch (const cslt::overflow_error& e) {
        EXPECT_STREQ("Custom overflow_error message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::overflow_error";
    }
}
// --------------------------------------------------------------------------------

TEST_F(OverflowErrorTest, CanBeCaughtAsBaseType) {
    try {
        throw customOverflowError;
    } catch (const cslt::exception& e) {
        EXPECT_STREQ("Custom overflow_error message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::runtime_error";
    }
}
// ================================================================================
// ================================================================================
// TEST UNDERFLOW ERROR 

class UnderflowErrorTest : public ::testing::Test {
protected:
    cslt::underflow_error defaultUnderflowError;
    cslt::underflow_error customUnderflowError{"Custom underflow_error message"};
};
// --------------------------------------------------------------------------------

TEST_F(UnderflowErrorTest, ConstructorSetsMessage) {
    EXPECT_STREQ("Custom underflow_error message", customUnderflowError.what());
}
// --------------------------------------------------------------------------------

TEST_F(UnderflowErrorTest, DefaultConstructorProvidesDefaultMessage) {
    EXPECT_STREQ("Underflow Error Raised!", defaultUnderflowError.what()); // Assuming a default message is set for invalic_argument_error
}
// --------------------------------------------------------------------------------

TEST_F(UnderflowErrorTest, CanBeCaughtAsSpecificType) {
    try {
        throw customUnderflowError;
    } catch (const cslt::underflow_error& e) {
        EXPECT_STREQ("Custom underflow_error message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::underflow_error";
    }
}
// --------------------------------------------------------------------------------

TEST_F(UnderflowErrorTest, CanBeCaughtAsBaseType) {
    try {
        throw customUnderflowError;
    } catch (const cslt::exception& e) {
        EXPECT_STREQ("Custom underflow_error message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::runtime_error";
    }
}
// ================================================================================
// ================================================================================
// TEST REGEX_ERROR CLASS 

class RegexErrorTest : public ::testing::Test {
protected:
    cslt::regex_error defaultRegexError;
    cslt::regex_error customRegexError{"Custom regex_error message"};
};
// --------------------------------------------------------------------------------

TEST_F(RegexErrorTest, ConstructorSetsMessage) {
    EXPECT_STREQ("Custom regex_error message", customRegexError.what());
}
// --------------------------------------------------------------------------------

TEST_F(RegexErrorTest, DefaultConstructorProvidesDefaultMessage) {
    EXPECT_STREQ("Regex Error Raised!", defaultRegexError.what()); // Assuming a default message is set for invalic_argument_error
}
// --------------------------------------------------------------------------------

TEST_F(RegexErrorTest, CanBeCaughtAsSpecificType) {
    try {
        throw customRegexError;
    } catch (const cslt::regex_error& e) {
        EXPECT_STREQ("Custom regex_error message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::regex_error";
    }
}
// --------------------------------------------------------------------------------

TEST_F(RegexErrorTest, CanBeCaughtAsBaseType) {
    try {
        throw customRegexError;
    } catch (const cslt::exception& e) {
        EXPECT_STREQ("Custom regex_error message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::runtime_error";
    }
}
// ================================================================================
// ================================================================================
// TEST TX_EXCEPTION CLASS 

class TXExceptionTest : public ::testing::Test {
protected:
    cslt::tx_exception defaultTXException;
    cslt::tx_exception customTXException{"Custom tx_exception message"};
};
// --------------------------------------------------------------------------------

TEST_F(TXExceptionTest, ConstructorSetsMessage) {
    EXPECT_STREQ("Custom tx_exception message", customTXException.what());
}
// --------------------------------------------------------------------------------

TEST_F(TXExceptionTest, DefaultConstructorProvidesDefaultMessage) {
    EXPECT_STREQ("TX Exception Raised!", defaultTXException.what()); // Assuming a default message is set for invalic_argument_error
}
// --------------------------------------------------------------------------------

TEST_F(TXExceptionTest, CanBeCaughtAsSpecificType) {
    try {
        throw customTXException;
    } catch (const cslt::tx_exception& e) {
        EXPECT_STREQ("Custom tx_exception message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::tx_exception";
    }
}
// --------------------------------------------------------------------------------

TEST_F(TXExceptionTest, CanBeCaughtAsBaseType) {
    try {
        throw customTXException;
    } catch (const cslt::exception& e) {
        EXPECT_STREQ("Custom tx_exception message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::runtime_error";
    }
}
// ================================================================================
// ================================================================================
// TEST NONEXISTENT_LOCAL_TIME CLASS 

class NonexistentLocalTimeTest : public ::testing::Test {
protected:
    cslt::nonexistent_local_time defaultNonexistentLocalTime;
    cslt::nonexistent_local_time customNonexistentLocalTime{"Custom nonexistent_local_time message"};
};
// --------------------------------------------------------------------------------

TEST_F(NonexistentLocalTimeTest, ConstructorSetsMessage) {
    EXPECT_STREQ("Custom nonexistent_local_time message", customNonexistentLocalTime.what());
}
// --------------------------------------------------------------------------------

TEST_F(NonexistentLocalTimeTest, DefaultConstructorProvidesDefaultMessage) {
    EXPECT_STREQ("Nonexistent Local Time Error Raised!", defaultNonexistentLocalTime.what()); // Assuming a default message is set for invalic_argument_error
}
// --------------------------------------------------------------------------------

TEST_F(NonexistentLocalTimeTest, CanBeCaughtAsSpecificType) {
    try {
        throw customNonexistentLocalTime;
    } catch (const cslt::nonexistent_local_time& e) {
        EXPECT_STREQ("Custom nonexistent_local_time message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::nonexistent_local_time";
    }
}
// --------------------------------------------------------------------------------

TEST_F(NonexistentLocalTimeTest, CanBeCaughtAsBaseType) {
    try {
        throw customNonexistentLocalTime;
    } catch (const cslt::exception& e) {
        EXPECT_STREQ("Custom nonexistent_local_time message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::runtime_error";
    }
}
// ================================================================================
// ================================================================================
// TEST AMBIGUOUS_LOCAL_TIME CLASS 

class AmbiguousLocalTimeTest : public ::testing::Test {
protected:
    cslt::ambiguous_local_time defaultAmbiguousLocalTime;
    cslt::ambiguous_local_time customAmbiguousLocalTime{"Custom ambiguous_local_time message"};
};
// --------------------------------------------------------------------------------

TEST_F(AmbiguousLocalTimeTest, ConstructorSetsMessage) {
    EXPECT_STREQ("Custom ambiguous_local_time message", customAmbiguousLocalTime.what());
}
// --------------------------------------------------------------------------------

TEST_F(AmbiguousLocalTimeTest, DefaultConstructorProvidesDefaultMessage) {
    EXPECT_STREQ("Ambiguous Local Time Error Raised!", defaultAmbiguousLocalTime.what()); // Assuming a default message is set for invalic_argument_error
}
// --------------------------------------------------------------------------------

TEST_F(AmbiguousLocalTimeTest, CanBeCaughtAsSpecificType) {
    try {
        throw customAmbiguousLocalTime;
    } catch (const cslt::ambiguous_local_time& e) {
        EXPECT_STREQ("Custom ambiguous_local_time message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::ambiguous_local_time";
    }
}
// --------------------------------------------------------------------------------

TEST_F(AmbiguousLocalTimeTest, CanBeCaughtAsBaseType) {
    try {
        throw customAmbiguousLocalTime;
    } catch (const cslt::exception& e) {
        EXPECT_STREQ("Custom ambiguous_local_time message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::runtime_error";
    }
}
// ================================================================================
// ================================================================================
// TEST FORMAT_ERROR CLASS 

class FormatErrorTest : public ::testing::Test {
protected:
    cslt::format_error defaultFormatError;
    cslt::format_error customFormatError{"Custom format_error message"};
};
// --------------------------------------------------------------------------------

TEST_F(FormatErrorTest, ConstructorSetsMessage) {
    EXPECT_STREQ("Custom format_error message", customFormatError.what());
}
// --------------------------------------------------------------------------------

TEST_F(FormatErrorTest, DefaultConstructorProvidesDefaultMessage) {
    EXPECT_STREQ("Format Error Raised!", defaultFormatError.what()); // Assuming a default message is set for invalic_argument_error
}
// --------------------------------------------------------------------------------

TEST_F(FormatErrorTest, CanBeCaughtAsSpecificType) {
    try {
        throw customFormatError;
    } catch (const cslt::format_error& e) {
        EXPECT_STREQ("Custom format_error message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::format_error";
    }
}
// --------------------------------------------------------------------------------

TEST_F(FormatErrorTest, CanBeCaughtAsBaseType) {
    try {
        throw customFormatError;
    } catch (const cslt::exception& e) {
        EXPECT_STREQ("Custom format_error message", e.what());
    } catch (...) {
        FAIL() << "Expected cslt::runtime_error";
    }
}
// ================================================================================
// ================================================================================
// eof
