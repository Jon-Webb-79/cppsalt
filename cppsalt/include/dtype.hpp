// ================================================================================
// ================================================================================
// - File:    dtype.hpp
// - Purpose: Describe the file purpose here
//
// Source Metadata
// - Author:  Jonathan A. Webb
// - Date:    January 27, 2024
// - Version: 1.0
// - Copyright: Copyright 2022, Jon Webb Inc.
// ================================================================================
// ================================================================================
// Include modules here

#ifndef dtype_HPP
#define dtype_HPP

#include <cstddef>
// Include sys/types.h outside of the namespace for Unix-like systems
#if defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
    #include <sys/types.h>  
#endif

namespace cslt {
    // Wrap size_t from the standard library
    using size_t = std::size_t;

    #if defined(__unix__) || defined(__unix) || \
        (defined(__APPLE__) && defined(__MACH__))

        // Unix-like environment (Linux, macOS, etc.)
        // ssize_t is already defined in sys/types.h
        using ssize_t = ::ssize_t;

    #elif defined(_WIN32) || defined(_WIN64)

        // Windows environment
        // Define ssize_t manually
        using ssize_t = signed long long;

    #else

        // For other environments, provide a custom definition
        // The type should be signed and capable of holding the largest possible size
        using ssize_t = signed long long;

    #endif
}

#endif /* file_name_HPP */
// ================================================================================
// ================================================================================
// eof
