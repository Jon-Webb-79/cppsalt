// ================================================================================
// ================================================================================
// - File:    memory.hpp
// - Purpose: Memory management functions and classes
//
// Source Metadata
// - Author:  Jonathan A. Webb
// - Date:    March 24, 2024
// - Version: 1.0
// - Copyright: Copyright 2024, Jon Webb Inc.
// ================================================================================
// ================================================================================
// Include modules here

#ifndef cslt_memory_HPP
#define cslt_memory_HPP 

#include "util.hpp"
// ================================================================================
// ================================================================================

namespace cslt {

    /**
     * @brief A class to manage dynamically allocated memory that can only be assigned to one variable at a time 
     *
     * @tparam T The pointer data type
     * @param p A pointer to a variable of type T
     */
    template <typename T>
    class unique_ptr {
    private:
        T* ptr = nullptr;
// ================================================================================

    public:
        explicit unique_ptr(T *p) : ptr(p) {}
// --------------------------------------------------------------------------------

        ~unique_ptr() {
            delete ptr;
        }
// --------------------------------------------------------------------------------

        // Disable the lvalue copy constructor 
        unique_ptr(const unique_ptr&) = delete;

        // Disable the lvalue assignment operator
        unique_ptr& operator=(const unique_ptr&) = delete;
// --------------------------------------------------------------------------------

        /**
         * @brief rvalue copy constructor 
         *
         * @param move The object instantiation of unique_ptr that is being copied
         */
        unique_ptr(unique_ptr&& move) noexcept : ptr(move.ptr) {
            move.ptr = nullptr;
        }
// --------------------------------------------------------------------------------

        /**
         * @brief rvalue assignment operator 
         * @param move An object instantiation of unique_ptr 
         * @return A unique_ptr object
         */
        unique_ptr& operator=(unique_ptr&& move) noexcept {
            if (this != &move) {
                delete ptr;
                ptr = nullptr;
                move.ptr = nullptr;
            }
            return *this;
        }
// --------------------------------------------------------------------------------

        /**
         * @brief reference operator overload
         */
        T& operator*() const {return *ptr;}

        /**
         * @brief pointer operator overload
         */
        T* operator->() const {return ptr;}

        /**
         * @brief returns pointer to ptr
         */
        T* get() const {return ptr;}
// --------------------------------------------------------------------------------

        /**
         * @brief releases a raw pointer back to the user
         * @return temp A raw pointer to memory previously controlled by unique_ptr object
         */
        T* release() {
            T* temp = ptr;
            ptr = nullptr;
            return temp;
        }
// --------------------------------------------------------------------------------

        /**
         * @brief Deletes existing memory in unique_ptr and reassignes it to new memory 
         *
         * @param p Pointer to new memory, defaulted to nullptr
         */
        void reset(T* p = nullptr) {
            T* temp = ptr;
            ptr = p;
            delete temp;
        }
// --------------------------------------------------------------------------------

        /**
         * @brief operator overload for bool comparison of pointer status
         */
        explicit operator bool() const {return ptr != nullptr;}

    };
// ================================================================================
// ================================================================================ 

    /**
     * @brief Function to return a unique_ptr object with variadac arugments
     */
    template <typename T, typename... Args>
    unique_ptr<T> make_unique(Args&&... args) {
        return unique_ptr<T>(new T(cslt::forward<Args>(args)...));
    }
// ================================================================================
// ================================================================================ 

    /**
     * @brief Class to manage heap memory allocations that can be shared 
     *
     * @tparam T The type of data managed in this class 
     * @param p A pointer of type T
     * @param counter A counter for hte number of assets sharing this memory
     */
    template <typename T>
    class shared_ptr {
    private:
        T* ptr = nullptr;
        unsigned* counter = nullptr; // Pointer to the reference count
// --------------------------------------------------------------------------------

        void release() {
            if (counter && --(*counter) == 0) {
                delete ptr;
                delete counter;
            }
            ptr = nullptr;
            counter = nullptr;
        }
// ================================================================================

    public:
        // Default constructor
        explicit shared_ptr(T* p = nullptr) : ptr(p), counter(p ? new unsigned(1) : nullptr) {}
// --------------------------------------------------------------------------------

        // Destructor
        ~shared_ptr() {
            release();
        }
// --------------------------------------------------------------------------------

        // Copy constructor
        shared_ptr(const shared_ptr& other) : ptr(other.ptr), counter(other.counter) {
            if (counter) {
                (*counter)++;
            }
        }
// --------------------------------------------------------------------------------

        // Copy assignment operator
        shared_ptr& operator=(const shared_ptr& other) {
            if (this != &other) {
                release(); // Release current resources
                ptr = other.ptr;
                counter = other.counter;
                if (counter) {
                    (*counter)++;
                }
            }
            return *this;
        }
// --------------------------------------------------------------------------------

        // Move constructor
        shared_ptr(shared_ptr&& other) noexcept : ptr(other.ptr), counter(other.counter) {
            other.ptr = nullptr;
            other.counter = nullptr;
        }
// --------------------------------------------------------------------------------

        // Move assignment operator
        shared_ptr& operator=(shared_ptr&& other) noexcept {
            if (this != &other) {
                release(); // Clean up current state
                ptr = other.ptr;
                counter = other.counter;
                other.ptr = nullptr;
                other.counter = nullptr;
            }
            return *this;
        }
// --------------------------------------------------------------------------------

        // Reset method
        void reset(T* p = nullptr) {
            if (ptr != p) {
                release(); // Clean up current state
                ptr = p;
                counter = p ? new unsigned(1) : nullptr;
            }
        }
// --------------------------------------------------------------------------------

        // Swap method
        void swap(shared_ptr& other) noexcept {
            cslt::swap(ptr, other.ptr);
            cslt::swap(counter, other.counter);
        }
// --------------------------------------------------------------------------------

        // Dereference and arrow operators
        T& operator*() const { return *ptr; }
        T* operator->() const { return ptr; }

        // Conversion to bool for checking if non-null
        explicit operator bool() const { return ptr != nullptr; }

        // Additional utility methods...
    };
    
// ================================================================================
// ================================================================================

    /**
     * @brief Function to return a shared_ptr object with variadac arugments
     */
    template <typename T, typename... Args>
    shared_ptr<T> make_shared(Args&&... args) {
        return shared_ptr<T>(new T(cslt::forward<Args>(args)...));
    }
// ================================================================================
// ================================================================================

}  /* end of cslt namespace */
// ================================================================================
// ================================================================================
#endif /* cslt_memory_HPP */
