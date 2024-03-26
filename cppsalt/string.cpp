// ================================================================================
// ================================================================================
// - File:    string.cpp
// - Purpose: Describe the file purpose here
//
// Source Metadata
// - Author:  Jonathan A. Webb
// - Date:    March 24, 2024
// - Version: 1.0
// - Copyright: Copyright 2022, Jon Webb Inc.
// ================================================================================
// ================================================================================
// Include modules here

#include "include/string.hpp"

namespace cslt {

    String::String(const char* str)
        : ptr(std::strlen(str) + 1), len(std::strlen(str)), alloc(std::strlen(str) + 1) {
            std::strcpy(ptr.get(), str);
            ptr[std::strlen(str)] = '\0';
        }
// --------------------------------------------------------------------------------

    /**
     * This class relies on the array_ptr copy constructor to manage deep copies
     */
    String::String(const String& other) : ptr(other.ptr), len(other.len), alloc(other.alloc) {}
// --------------------------------------------------------------------------------

    /** 
     * Assignment operator, which relies on array_ptr implementation to manage a deep 
     * copy of the String
     */

    String& String::operator=(const String& other) {
        if (this != &other) {
            ptr = other.ptr;
            len = other.len;
            alloc = other.alloc;
        }
        return *this;
    }
// --------------------------------------------------------------------------------

    /**
     * This class is an rvalue copy constructor that relies on the shared_ptr copy 
     * constructor to manage move semantics.
     */
    String::String(String&& other) noexcept : ptr(other.ptr), len(other.len), alloc(other.alloc) {}
// --------------------------------------------------------------------------------

    /**
     * This class is an rvalue assignment operator that relies on the shared_ptr 
     * copy assignment operator to manage move semantics
     */
    String& String::operator=(String&& other) noexcept {
        if (this != &other) {
            ptr = cslt::move(other.ptr);
            len = other.len;
            alloc = other.alloc;
        }
        return *this;
    }
// --------------------------------------------------------------------------------

    cslt::size_t String::size() const {
        return len;
    }
// --------------------------------------------------------------------------------

    cslt::size_t String::memory() const {
        return alloc;
    }
// --------------------------------------------------------------------------------

    const char* String::c_string() const {
        return ptr.get();
    }
}
// ================================================================================
// ================================================================================
// eof
