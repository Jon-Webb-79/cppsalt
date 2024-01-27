// ================================================================================
// ================================================================================
// - File:    except.cpp
// - Purpose: This file contains class definitions for the exceptions available
//            under the cslt namespace.
//
// Source Metadata
// - Author:  Jonathan A. Webb
// - Date:    January 25, 2024
// - Version: 1.0
// - Copyright: Copyright 2022, Jon Webb Inc.
// ================================================================================
// ================================================================================
// Include modules here

#include "include/except.hpp"
#include "string.h"

namespace cslt {

    exception::exception(const char* msg) {
        unsigned int len = strlen(msg);
        message = new char[len + 1];
        message[len] = '\0';
        strcpy(message, msg);
    }
// --------------------------------------------------------------------------------

    exception::exception(const exception& other) {
        message = new char[strlen(other.message) + 1];
        strcpy(message, other.message);
    }
// --------------------------------------------------------------------------------

    exception& exception::operator=(const exception& other) {
        if (this != &other) {
            delete[] message;
            message = new char[strlen(other.message) + 1];
            strcpy(message, other.message);
        }
        return *this;
    }
// --------------------------------------------------------------------------------

    exception::~exception() {
        delete[] message;
    }
// --------------------------------------------------------------------------------

    const char* exception::what() const noexcept {
        return message;
    }
// ================================================================================
// ================================================================================

} // namespace cslt
// ================================================================================
// ================================================================================
// eof
