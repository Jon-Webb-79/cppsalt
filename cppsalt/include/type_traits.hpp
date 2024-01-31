// ================================================================================
// ================================================================================
// - File:    type_traits.hpp
// - Purpose: Describe the file purpose here
//
// Source Metadata
// - Author:  Jonathan A. Webb
// - Date:    January 29, 2024
// - Version: 1.0
// - Copyright: Copyright 2022, Jon Webb Inc.
// ================================================================================
// ================================================================================
// Include modules here

#ifndef type_traits_HPP
#define type_traits_HPP
#include <type_traits>
// ================================================================================
// ================================================================================

namespace cslt {

    /**
     * @brief Overloaded functions to removed lvalue and rvalue references
     */
    template<class T> struct remove_reference { typedef T type; };
    template<class T> struct remove_reference<T&> { typedef T type; };
    template<class T> struct remove_reference<T&&> { typedef T type; };
// ================================================================================
// ================================================================================

    template<typename T>
    using is_nothrow_move_constructible = std::is_nothrow_move_constructible<T>;

    template<typename T>
    using is_copy_constructible = std::is_copy_constructible<T>;
// ================================================================================
// ================================================================================ 
 
}
// ================================================================================ 
// ================================================================================ 
#endif /* file_name_HPP */
// ================================================================================
// ================================================================================
// eof
