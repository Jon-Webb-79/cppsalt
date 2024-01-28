// ================================================================================
// ================================================================================
// - File:    util.hpp
// - Purpose: Describe the file purpose here
//
// Source Metadata
// - Author:  Jonathan A. Webb
// - Date:    January 28, 2024
// - Version: 1.0
// - Copyright: Copyright 2022, Jon Webb Inc.
// ================================================================================
// ================================================================================
// Include modules here

#ifndef util_HPP
#define util_HPP
// ================================================================================
// ================================================================================

/**
 * @brief This function is used to swap two variables of the same type in memory.
 *
 * @param a A veriable of type T 
 * @param b A variable of type T
 */

namespace cslt {

    template<typename T>
    void swap(T &a, T &b) {
        T temp = a;
        a = b;
        b = temp;
    }
// --------------------------------------------------------------------------------

    /**
     * @ Struct pair 
     *
     * A struct that contains two user defined variables.
     *
     * @attribute first A user defined attribute of struct pair 
     * @attribute second A user defined attribute of struct pair
     */
    template<typename A, typename B>
    struct pair {
        A first;
        B second;
// --------------------------------------------------------------------------------
// Constructor
        pair() : first(), second() {}
        pair(const A& first_val, const B& second_val) : first(first_val), second(second_val) {}
// --------------------------------------------------------------------------------
// Copy constructor

        pair(const pair& other) : first(other.first), second(other.second) {}
// --------------------------------------------------------------------------------
// Overload equl operator 

        pair& operator=(const pair& other) {
            if (this != &other) {
                first = other.first;
                second = other.second;
            }
            return *this;
        }
// --------------------------------------------------------------------------------
// Swap data
    void swap (pair& pr) noexcept ( noexcept(cslt::swap(first,pr.first)) &&
                                noexcept(cslt::swap(second,pr.second)) ) {
        cslt::swap(first,pr.first);
        cslt::swap(second,pr.second);
    }
};
// ================================================================================
// ================================================================================

    /**
     * @brief This function creates and returns a copy of the pair struct 
     *
     * @param first_val: A value of type defined by the user 
     * @param second_val: A value of type defined by the user 
     * @return A struct of type pair
     */
    template<typename A, typename B>
    pair<A, B> make_pair(const A& first_val, const B& second_val) {
        return pair<A, B>(first_val, second_val);
    }
// ================================================================================
// ================================================================================

} /* end of cslt namespace */
// ================================================================================
// ================================================================================

#endif /* file_name_HPP */
// ================================================================================
// ================================================================================
// eof
