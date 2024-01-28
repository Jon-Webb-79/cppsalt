// ================================================================================
// ================================================================================
// - File:    io.hpp
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

#ifndef io_HPP
#define io_HPP

#include <iostream>

namespace cslt {
    // Standard character streams
    extern std::ostream& cout;  // Reference to standard cout
    extern std::istream& cin;   // Reference to standard cin
    extern std::ostream& cerr;  // Reference to standard cerr
    extern std::ostream& clog;  // Reference to standard clog

    // Wide character streams
    extern std::wostream& wcout; // Reference to standard wcout
    extern std::wistream& wcin;  // Reference to standard wcin
    extern std::wostream& wcerr; // Reference to standard wcerr
    extern std::wostream& wclog; // Reference to standard wclog
}
// ================================================================================
// ================================================================================

#endif /* io_HPP */
// ================================================================================
// ================================================================================
// eof
