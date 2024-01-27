// ================================================================================
// ================================================================================
// - File:    except.hpp
// - Purpose: This file contains prototype class definitions for the exceptions 
//            available under the cslt namespace
//
// Source Metadata
// - Author:  Jonathan A. Webb
// - Date:    January 25, 2024
// - Version: 1.0
// - Copyright: Copyright 2022, Jon Webb Inc.
// ================================================================================
// ================================================================================
// Include modules here

#ifndef except_HPP
#define except_HPP
// ================================================================================
// ================================================================================
namespace cslt {

// ================================================================================
// ================================================================================
    /**
     * Class exception
     * Represents an exception of any type.
     *
     * This exception is thrown for any type of exception.
     * It holds an error message that can be retrieved using the what() method.
     */
    class exception {
    private:
        char* message;  // Dynamically allocated message for the exception
// ================================================================================

    public:
        /**
         * Constructor for exception exception.
         * @param msg The message for the exception. Defaults to a standard error message if not provided.
         */
        explicit exception(const char* msg = "Exception raised!");
// --------------------------------------------------------------------------------

        /**
         * Copy constructor for exception.
         * Creates a deep copy of another exception instance.
         * @param other The exception instance to be copied.
         */
        exception(const exception& other);
// --------------------------------------------------------------------------------

        /**
         * Copy assignment operator.
         * Replaces the current instance's contents with another exception instance.
         * @param other The exception instance to be copied.
         * @return Reference to the current instance.
         */
        exception& operator=(const exception& other);
// --------------------------------------------------------------------------------

        /**
         * Destructor for exception.
         * Frees the dynamically allocated message.
         */
        virtual ~exception();
// --------------------------------------------------------------------------------

        /**
         * Retrieves the error message.
         * @return A constant character pointer to the error message.
         */
        const char* what() const noexcept;
    }; 
// ================================================================================
// ================================================================================

    class logic_error : public exception {
    public:
        explicit logic_error(const char* msg = "Logic Error Raised!") : exception(msg) {};
    };
// ================================================================================
// ================================================================================

    class invalid_argument : public logic_error {
    public:
        explicit invalid_argument(const char *msg = "Invalid Argument Error Raised!") : logic_error(msg) {};
    };
// ================================================================================
// ================================================================================

    class domain_error : public logic_error {
    public:
        explicit domain_error(const char *msg = "Domain Error Raised!") : logic_error(msg) {};
    };
// ================================================================================
// ================================================================================

    class length_error : public logic_error {
    public:
        explicit length_error(const char *msg = "Length Error Raised!") : logic_error(msg) {};
    };
// ================================================================================
// ================================================================================

    class out_of_range : public logic_error {
    public:
        explicit out_of_range(const char *msg = "Out of Range Error Raised!") : logic_error(msg) {};
    };
// ================================================================================
// ================================================================================

    class future_error : public logic_error {
    public:
        explicit future_error(const char *msg = "Future Error Raised!") : logic_error(msg) {};
    };
// ================================================================================
// ================================================================================

    class runtime_error: public exception {
    public:
        explicit runtime_error(const char* msg = "Runtime Error Raised!") : exception(msg) {};
    };
// ================================================================================
// ================================================================================

    class range_error : public runtime_error {
    public:
        explicit range_error(const char *msg = "Range Error Raised!") : runtime_error(msg) {};
    };
// ================================================================================
// ================================================================================

    class overflow_error : public runtime_error {
    public:
        explicit overflow_error(const char *msg = "Overflow Error Raised!") : runtime_error(msg) {};
    };
// ================================================================================
// ================================================================================

    class underflow_error : public runtime_error {
    public:
        explicit underflow_error(const char *msg = "Underflow Error Raised!") : runtime_error(msg) {};
    };
// ================================================================================
// ================================================================================

    class regex_error : public runtime_error {
    public:
        explicit regex_error(const char *msg = "Regex Error Raised!") : runtime_error(msg) {};
    };
// ================================================================================
// ================================================================================

    class system_error : public runtime_error {
    public:
        explicit system_error(const char *msg = "System Error Raised!") : runtime_error(msg) {};
    };
// ================================================================================
// ================================================================================

    class tx_exception : public runtime_error {
    public:
        explicit tx_exception(const char *msg = "TX Exception Raised!") : runtime_error(msg) {};
    };
// ================================================================================
// ================================================================================

    class nonexistent_local_time : public runtime_error {
    public:
        explicit nonexistent_local_time(const char *msg = "Nonexistent Local Time Error Raised!") : runtime_error(msg) {};
    };
// ================================================================================
// ================================================================================

    class ambiguous_local_time : public runtime_error {
    public:
        explicit ambiguous_local_time(const char *msg = "Ambiguous Local Time Error Raised!") : runtime_error(msg) {};
    };
// ================================================================================
// ================================================================================

    class format_error : public runtime_error {
    public:
        explicit format_error(const char *msg = "Format Error Raised!") : runtime_error(msg) {};
    };
// ================================================================================
// ================================================================================

    class bad_typeid : public exception {
    public:
        explicit bad_typeid(const char *msg = "Bad Type ID Error Raised!") : exception(msg) {};
    };
// ================================================================================
// ================================================================================

    class bad_cast : public exception {
    public:
        explicit bad_cast(const char *msg = "Bad Cast Error Raised!") : exception(msg) {};
    };
// ================================================================================
// ================================================================================

    class bad_optional_access : public exception {
    public:
        explicit bad_optional_access(const char *msg = "Bad Optional Access Error Raised!") : exception(msg) {};
    };
// ================================================================================
// ================================================================================

    class bad_expected_access : public exception {
    public:
        explicit bad_expected_access(const char *msg = "Bad Expected Access Error Raised!") : exception(msg) {};
    };
// ================================================================================ 
// ================================================================================

    class bad_weak_ptr : public exception {
    public:
        explicit bad_weak_ptr(const char *msg = "Bad Weak Pointer Error Raised!") : exception(msg) {};
    };
// ================================================================================
// ================================================================================

    class bad_function_call : public exception {
    public:
        explicit bad_function_call(const char *msg = "Bad Function Call Error Raised!") : exception(msg) {}
    };
// ================================================================================
// ================================================================================

    class bad_alloc : public exception {
    public:
        explicit bad_alloc(const char *msg = "Memory Allocation Error Raised!") : exception(msg) {}
    };
// ================================================================================
// ================================================================================

    class bad_array_new_length : public bad_alloc {
    public:
        explicit bad_array_new_length(const char *msg = "Bad Array New Length Error Raised!") : bad_alloc(msg) {};
    };
// ================================================================================
// ================================================================================

    class bad_exception : public exception {
    public:
        explicit bad_exception(const char *msg = "Bad Exception Error Raised!") : exception(msg) {}
    };
// ================================================================================
// ================================================================================

    class bad_variant_access : public exception {
        explicit bad_variant_access(const char *msg = "Bad Variant Access Error Raised!") : exception(msg) {};
    };
// ================================================================================
// ================================================================================

} /* namespace cslt */
// ================================================================================
// ================================================================================

#endif /* except_HPP */
// ================================================================================
// ================================================================================
// eof
