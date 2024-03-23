// ================================================================================
// ================================================================================
// - File:    vec.hpp
// - Purpose: Describe the file purpose here
//
// Source Metadata
// - Author:  Jonathan A. Webb
// - Date:    February 01, 2024
// - Version: 1.0
// - Copyright: Copyright 2022, Jon Webb Inc.
// ================================================================================
// ================================================================================
// Include modules here

#ifndef vec_HPP
#define vec_HPP
#include "dtype.hpp"
#include "except.hpp"
#include <initializer_list>
#include <algorithm>

namespace cslt {

    template<typename T>
    class vector {
// ================================================================================ 
// PRIVATE VARIABLE DEFINITIONS
    private:
        T *_data;
        cslt::size_t _len = 0;
        cslt::size_t _alloc;
// ================================================================================ 
// PUBLIC FUNCTION DEFINITIONS
    public:
// -------------------------------------------------------------------------------- 
// Instantiate with 1 element

        vector() : _data(new T[1]), _alloc(1) {};
// --------------------------------------------------------------------------------
// Instnatiate with user defined number of elements 

        vector(cslt::size_t buff) : _data(new T[buff]), _alloc(buff) {};
// --------------------------------------------------------------------------------
// Constructor for initializer list

        vector(std::initializer_list<T> ilist) : _data(new T[ilist.size()]), _len(ilist.size()), _alloc(ilist.size()) {
            std::copy(ilist.begin(), ilist.end(), _data);
        }
// --------------------------------------------------------------------------------
// push data to the function.

        void push_back(const T& value) {
            if (_len >= _alloc) {
                // Doubling the allocation size
                _alloc = (_alloc > 0) ? _alloc * 2 : 1;
                T* newData = new T[_alloc];
                
                std::copy(_data, _data + _len, newData);

                // Deallocating old block
                delete[] _data;

                // Assigning new block to _data
                _data = newData;
            }

            // Adding new element
            _data[_len++] = value;
        } 
// --------------------------------------------------------------------------------
// push_back for data pushed to a specifc index 

        void push_back(const T& value, cslt::size_t index) {
            if (index > _len) { // Check bounds
                throw cslt::out_of_range("Index is out of bounds");
            }

            // Ensure there's enough space, reallocating if necessary
            if (_len + 1 > _alloc) {
                _alloc = (_alloc > 0) ? _alloc * 2 : 1;
                T* newData = new T[_alloc];
                std::copy(_data, _data + _len, newData);
                delete[] _data;
                _data = newData;
            }

            // Shift elements to the right to make space
            for (cslt::size_t i = _len; i > index; --i) {
                _data[i] = _data[i - 1];
            }

            // Insert the new element
            _data[index] = value;

            // Increment the length
            _len++;
        }
// --------------------------------------------------------------------------------
// Reserve memory 

        void reserve(cslt::size_t buff) {
            if (buff <= _alloc)
                return;

            T* new_data = new T[buff];
            // Use std::move_if_noexcept to take advantage of move semantics if possible and safe
            std::move(_data, _data + _len, new_data);

            delete[] _data;
            _data = new_data;
            _alloc = buff; // Update the allocated size
} 
// --------------------------------------------------------------------------------
// Return size of array 

        const cslt::size_t size() {
            return _len;
        }
// --------------------------------------------------------------------------------
// Return allocated length of array

        const cslt::size_t alloc() {
            return _alloc;
        }
// -------------------------------------------------------------------------------- 
// Destructor

        ~vector() {
            delete[] _data;
            _len = 0;
        }
    };
}
// ================================================================================
// ================================================================================ 

#endif /* file_name_HPP */
// ================================================================================
// ================================================================================
// eof
