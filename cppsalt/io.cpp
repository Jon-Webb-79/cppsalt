// ================================================================================
// ================================================================================
// - File:    io.cpp
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

#include "include/io.hpp"

// ================================================================================
// ================================================================================
// overload iostream

namespace cslt {
    std::ostream& cout = std::cout;  // Initialize with standard cout
    std::istream& cin = std::cin;    // Initialize with standard cin
    std::ostream& cerr = std::cerr;  // Initialize with standard cerr
    std::ostream& clog = std::clog;  // Initialize with standard clog

    std::wostream& wcout = std::wcout; // Initialize with standard wcout
    std::wistream& wcin = std::wcin;   // Initialize with standard wcin
    std::wostream& wcerr = std::wcerr; // Initialize with standard wcerr
    std::wostream& wclog = std::wclog; // Initialize with standard wclog
}
// ================================================================================
// ================================================================================
// eof
