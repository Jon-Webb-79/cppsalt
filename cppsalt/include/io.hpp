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

#include <iostream>  // For std::cin, std::cout, std::cerr, std::log and wide versions
#include <sstream>  // For std::ostringstream, std::istring, std::stringstream
#include <fstream>  // for std::ifstream, std::ofstream
#include <streambuf>  // For std::streambuf

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
    
    // Set up wrappers around streams 
    class istream : public std::istream {};
    class iostream : public std::iostream {};
    class ostringstream : public std::ostringstream {};
    class ifstream : public std::ifstream {
    public:
        using std::ifstream::ifstream;
    };
    class ofstream : public std::ofstream {
    public:
        using std::ofstream::ofstream;
    };
    class istringstream : public std::istringstream {
    public:
        using std::istringstream::istringstream;
    };
    class wifstream : public std::wifstream {
    public:
        using std::wifstream::wifstream;  // Using constructors from std::wifstream
    };
    class wofstream : public std::wofstream {
    public:
        using std::wofstream::wofstream;  // Using constructors from std::wofstream
    }; 
    class wistringstream : public std::wistringstream {};
    class wostringstream : public std::wostringstream {};
    class stringstream : public std::stringstream {};
    class wstringstream : public std::wstringstream {};
    class streambuf : public std::streambuf {};
    class filebuf : public std::filebuf {};

    using std::endl;
}
// ================================================================================
// ================================================================================

#endif /* io_HPP */
// ================================================================================
// ================================================================================
// eof
