// ================================================================================
// ================================================================================
// - File:    test_io.cpp
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

#include <gtest/gtest.h>
#include <sstream>
#include "../include/io.hpp"
// ================================================================================ 
// ================================================================================
// Test in, out, log and err functions 

TEST(CsltIOTest, StreamIdentity) {
    EXPECT_EQ(&cslt::cout, &std::cout);
    EXPECT_EQ(&cslt::cin, &std::cin);
    EXPECT_EQ(&cslt::cerr, &std::cerr);
    EXPECT_EQ(&cslt::clog, &std::clog);
    EXPECT_EQ(&cslt::wcout, &std::wcout);
    EXPECT_EQ(&cslt::wcin, &std::wcin);
    EXPECT_EQ(&cslt::wcerr, &std::wcerr);
    EXPECT_EQ(&cslt::wclog, &std::wclog);
}
// --------------------------------------------------------------------------------

// TEST(CsltIOTest, OutputStream) {
//     cslt::ostringstream oss;
//     cslt::cout.rdbuf(oss.rdbuf());
//     cslt::cout << "Test output";
//     EXPECT_EQ(oss.str(), "Test output");
//     // Reset the buffer to avoid affecting other tests
//     cslt::cout.rdbuf(cslt::cout.rdbuf());
// }
// ================================================================================
// ================================================================================
// TEST OSTREAM 

TEST(CsltIOStreamTest, OStreamFunctionality) {
    cslt::ostringstream oss;
    oss << "Hello, world!";
    EXPECT_EQ(oss.str(), "Hello, world!");
}
// --------------------------------------------------------------------------------

TEST(CsltIOStreamTest, IStreamFunctionality) {
    std::string data = "Test string";
    cslt::istringstream iss(data);
    std::string readData;
    std::getline(iss, readData);
    EXPECT_EQ(readData, data);
}
// ================================================================================
// ================================================================================
// TEST IFSTREAM AND OFSTREAM 

TEST(CsltFileStreamTest, IfstreamFunctionality) {
    // Create a file for testing
    {
        cslt::ofstream outFile("example.txt");
        outFile << "Test content";
    }  // The file is closed here as outFile goes out of scope

    // Now open the file with cslt::ifstream
    cslt::ifstream file("example.txt");
    EXPECT_TRUE(file.is_open());

    // Optionally, perform additional file reading tests...

    // Clean up: Delete the file after the test
    std::remove("example.txt");
}
// --------------------------------------------------------------------------------

TEST(CsltFileStreamTest, OfstreamFunctionality) {
    cslt::ofstream file("output.txt");
    EXPECT_TRUE(file.is_open());
    file << "Test output";
    // Additional file writing tests...
}
// ================================================================================
// ================================================================================
// TEST STRINGSTREAM 

TEST(CsltStringStreamTest, StringStreamFunctionality) {
    cslt::stringstream ss;
    ss << "Test";
    std::string output;
    ss >> output;
    EXPECT_EQ(output, "Test");
}
// ================================================================================
// ================================================================================
// TEST WOFSTREAM AND WIFSTREAM 

TEST(CsltWideStreamTest, WideOfstreamFunctionality) {
    // Create a file for testing
    {
        cslt::ofstream outFile("woutput.txt");
        outFile << "Test content";
    }  // The file is closed here as outFile goes out of scope
    cslt::wofstream wfile("woutput.txt");
    EXPECT_TRUE(wfile.is_open());
    wfile << L"Test wide output";
    // Clean up: Delete the file after the test
    std::remove("woutput.txt");
}
// --------------------------------------------------------------------------------

TEST(CsltWideStreamTest, WideIfstreamFunctionality) {
    // Create a file for testing
    {
        cslt::ofstream outFile("wexample.txt");
        outFile << "Test content";
    }  // The file is closed here as outFile goes out of scope

    cslt::wifstream wfile("wexample.txt");
    EXPECT_TRUE(wfile.is_open());
    std::remove("wexample.txt");
}
// ================================================================================
// ================================================================================
// TEST STREAMBUF AND FILEBUF

TEST(CsltStreambufTest, StreambufFunctionality) {
    cslt::streambuf sbuf;
    std::ostream os(&sbuf);
    os << "Buffer test";
    // Additional buffer operation tests...
}
// ================================================================================
// ================================================================================
// eof
