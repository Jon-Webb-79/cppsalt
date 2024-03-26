// ================================================================================
// ================================================================================
// - File:    string.hpp
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

#ifndef string_HPP
#define string_HPP

#include "dtype.hpp"
#include "memory.hpp"
#include <cstring>
// ================================================================================
// ================================================================================

namespace cslt {

    /**
     * @brief This class manages a string implementation as a char array 
     *
     * @param str A null terminated string literal
     */
    class String {  
        array_ptr<char> ptr = nullptr;
        cslt::size_t len = 0;
        cslt::size_t alloc = 0;
// ================================================================================

        /**
         * @brief Constructor for class that takes a string literal as an input
         */
        String(const char* str);
// --------------------------------------------------------------------------------

        /**
         * @brief Copy constructor for String class. 
         *
         * @param other An object of String
         */
        String(const String& other);
// --------------------------------------------------------------------------------

        /**
         * @brief This method is an lvalue assignment operator for the String class.
         *
         * @param other An object of type String
         * @returns A String object
         */
        String& operator=(const String& other);
// --------------------------------------------------------------------------------

        /**
         * @brief This method is an rvalue copy constructor to enable move semantics
         *
         * @param other An object of type String
         */
        String(String&& other) noexcept;
// --------------------------------------------------------------------------------

        /**
         * @brief This method is an rvalue assignment operator to enable move semantics 
         *
         * @param other An object of type String 
         * @returns A String object
         */
        String& operator=(String&& other) noexcept;
// --------------------------------------------------------------------------------

        /**
         * @brief This function returns the size of the string in indices
         *
         * @returns string length, not including the null terminator
         */
        cslt::size_t size() const;
// --------------------------------------------------------------------------------

        /**
         * @brief This function returns the size of allocated memory to include the null temrinator in indices 
         *
         * @returns allocated memory, including the null temrinator
         */
        cslt::size_t memory() const;
// --------------------------------------------------------------------------------

        /**
         * @brief This function returns the string as a c-style string literal 
         * 
         * @returns A c-style string literal
         */
        const char* c_string() const;
    };

} /* end of cslt namespace */
// ================================================================================
// ================================================================================
#endif /* file_name_HPP */
// ================================================================================
// ================================================================================
// eof
