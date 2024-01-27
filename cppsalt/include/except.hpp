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

    /**
     * Class logic_error 
     * Represents a logic error caught in run time.
     *
     * This class defines the type of objects thrown as an exception to report errors 
     * in the internal logic of the program, such as violation of logical preconditions 
     * or class invariants.
     */
    class logic_error : public exception {
    public:
        explicit logic_error(const char* msg = "Logic Error Raised!") : exception(msg) {};
    };
// ================================================================================
// ================================================================================

    /** 
     * Class invalid_argument 
     * Represents the detection of an invalid argument pass to a function or class.
     *
     * This class defines the type of objects thrown as exceptions to report an 
     * invalid Argument 
     */
    class invalid_argument : public logic_error {
    public:
        explicit invalid_argument(const char *msg = "Invalid Argument Error Raised!") : logic_error(msg) {};
    };
// ================================================================================
// ================================================================================

    /**
     * Class domain_error 
     * Represents the detection of domain errors 
     *
     * This class defines the type of objects thrown as exceptions to report 
     * domain errors.  Generally, the domain of a mathematical function is the  
     * subset of values that it is defined for.  For example the square root
     * function is only defined for non-negative numbers.  Thus, a negative 
     * number for such a function would qualify as a domain error.
     */
    class domain_error : public logic_error {
    public:
        explicit domain_error(const char *msg = "Domain Error Raised!") : logic_error(msg) {};
    };
// ================================================================================
// ================================================================================

    /** 
     * Class length_error 
     * Represents the detection of length errors 
     *
     * This class defines the type of objects thrown as exceptions to report a 
     * length error.  It is a standard exception that can be thrown by programs.  
     * Some components of the CPPSalt library, such as vector and string 
     * also throw exceptions of this type to signal errors resizing.
     */
    class length_error : public logic_error {
    public:
        explicit length_error(const char *msg = "Length Error Raised!") : logic_error(msg) {};
    };
// ================================================================================
// ================================================================================

    /**
     * Class out_of_range 
     * Represents the detection of out of range errors 
     *
     * This class defines the type of objects thrown as exceptions to report 
     * and out-of-range error.  It is a standard exception that can be thrown by 
     * programs.  Some components of the CPPSalt library, such as vector, and 
     * string also throw exceptions of this type to signal arguments out 
     * of range. 
     */
    class out_of_range : public logic_error {
    public:
        explicit out_of_range(const char *msg = "Out of Range Error Raised!") : logic_error(msg) {};
    };
// ================================================================================
// ================================================================================

    /**
     * Class future_error 
     * Represents the detection of future errors 
     *
     * This class defines the type of objects thrown as exceptions to report 
     * operations on future objects or other elements of the librarythat may 
     * access future's shared state.
     */
    class future_error : public logic_error {
    public:
        explicit future_error(const char *msg = "Future Error Raised!") : logic_error(msg) {};
    };
// ================================================================================
// ================================================================================

    /**
     * Class runtime_error 
     * Represents the detection of a run time error 
     *
     * This class defines the type of objects thrown as exceptions to report 
     * errors that can only be detected during rutime.
     */
    class runtime_error: public exception {
    public:
        explicit runtime_error(const char* msg = "Runtime Error Raised!") : exception(msg) {};
    };
// ================================================================================
// ================================================================================

    /**
     * Class range_error 
     * Represents the detection of a range error 
     *
     * This class defines the type of objects thrown as exceptions to report 
     * range errors in internal computations.  It is a standard exception that 
     * can be thrown by programs.  Some components of this library also throw 
     * exceptions of this type to signal range errors.
     */
    class range_error : public runtime_error {
    public:
        explicit range_error(const char *msg = "Range Error Raised!") : runtime_error(msg) {};
    };
// ================================================================================
// ================================================================================

    /**
     * Class overflow_error 
     * Represents the detection of an overflow error during runtime 
     *
     * This class defines the type of objects thrown as exceptions to arithmetic 
     * overflow errors.  It is a standard exception that can be thrown by programs.
     * Some components of this library also throw errors of this type to signal 
     * range errors.
     */
    class overflow_error : public runtime_error {
    public:
        explicit overflow_error(const char *msg = "Overflow Error Raised!") : runtime_error(msg) {};
    };
// ================================================================================
// ================================================================================

    /**
     * Class underflow_errors 
     * Represents underflow errors determined in runtime 
     *
     * This class defines the type of objects thrown as exceptions to arithmetic 
     * underflow erros. No component of this library throws exceptions of this 
     * type.  It is designed as a standard exception to be thrown by programmers.
     */
    class underflow_error : public runtime_error {
    public:
        explicit underflow_error(const char *msg = "Underflow Error Raised!") : runtime_error(msg) {};
    };
// ================================================================================
// ================================================================================

    /**
     * Class regex_error
     * Represents the detection of a regex error 
     *
     * Defines the type of exception to be thrown to report errors in the regular
     * expressions library 
     */
    class regex_error : public runtime_error {
    public:
        explicit regex_error(const char *msg = "Regex Error Raised!") : runtime_error(msg) {};
    };
// ================================================================================
// ================================================================================

    /**
     * Class system_error
     * Represents the detection of a system error.
     *
     * This class defines the type of objects thrown as exceptions to report 
     * conditions originating during runtime from the operating system or 
     * other low-level application program interfaces which have an associated 
     * error code.
     */
    class system_error : public runtime_error {
    public:
        explicit system_error(const char *msg = "System Error Raised!") : runtime_error(msg) {};
    };
// ================================================================================
// ================================================================================

    /**
     * Class tx_exception 
     * Represents an exception raised by the keyword ``atomic_cancel``
     */
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

    /**
     * Class format_error 
     * Represents the detection of a format error 
     *
     * Defines the type of exception object thrown to report erros in the 
     * formatting library 
     */
    class format_error : public runtime_error {
    public:
        explicit format_error(const char *msg = "Format Error Raised!") : runtime_error(msg) {};
    };
// ================================================================================
// ================================================================================

    /**
     * Class bad_typeid 
     * Represents the detection of a bad type id error 
     *
     * Type of exception thrown by typeid is applied on a pointer to a 
     * polymorphic type which has a null pointer value.  Its member ``.what()``
     * returns a null-terminated character sequence identifying the exception.
     */
    class bad_typeid : public exception {
    public:
        explicit bad_typeid(const char *msg = "Bad Type ID Error Raised!") : exception(msg) {};
    };
// ================================================================================
// ================================================================================

    /**
     * Class bad_cast 
     * Represents the detection of a bad cast error 
     *
     * The type of exception thrown by ``dynamic_cast`` when it fails in the 
     * run time check performed on references to polymorphic class types.
     * The run-time check fails if the object would be an incomplete object 
     * of the destination type.  Its member ``.what()`` returns a null-terminated 
     * character sequence identifying the exception. Some functions in this 
     * library may also throw this exception to signal a type-casting error.
     */
    class bad_cast : public exception {
    public:
        explicit bad_cast(const char *msg = "Bad Cast Error Raised!") : exception(msg) {};
    };
// ================================================================================
// ================================================================================

    /**
     * Class bad_optional_access 
     * Represents the detection of a bad optional access error.
     *
     * Defines a type of object to be thrown when accessing an optional object 
     * that does not contain a value.
     */
    class bad_optional_access : public exception {
    public:
        explicit bad_optional_access(const char *msg = "Bad Optional Access Error Raised!") : exception(msg) {};
    };
// ================================================================================
// ================================================================================

    /**
     * Class bad_excpected_access 
     * Represents the detection of a bad expcected access error 
     *
     * Defines a type of object to be thrown when accessing an expected object 
     * that contains an unexpected value.
     */
    class bad_expected_access : public exception {
    public:
        explicit bad_expected_access(const char *msg = "Bad Expected Access Error Raised!") : exception(msg) {};
    };
// ================================================================================ 
// ================================================================================

    /**
     * Class bad_weak_ptr 
     * Represents the detection of a bad weak pointer error 
     *
     * Exception thrown by a shared_pointer constructor when constructed with an 
     * expired weak pointer.
     */
    class bad_weak_ptr : public exception {
    public:
        explicit bad_weak_ptr(const char *msg = "Bad Weak Pointer Error Raised!") : exception(msg) {};
    };
// ================================================================================
// ================================================================================

    /**
     * Class bad_function_call 
     * Represents the detection of a bad function call 
     *
     * Object thrown by empty function objects when their functional call 
     * is invoked.
     */
    class bad_function_call : public exception {
    public:
        explicit bad_function_call(const char *msg = "Bad Function Call Error Raised!") : exception(msg) {}
    };
// ================================================================================
// ================================================================================

    /**
     * Class bad_alloc 
     * Represents the detection of a bad memory allocation 
     *
     * Type of exception thrown by the standard definition of the ``new`` and ``new[]``
     * operators when they fail to allocate the requested storage space.
     */
    class bad_alloc : public exception {
    public:
        explicit bad_alloc(const char *msg = "Memory Allocation Error Raised!") : exception(msg) {}
    };
// ================================================================================
// ================================================================================

    /**
     * Class bad_array_new_length 
     * Represents the detection of a bad array new length error 
     *
     * Is the type of object thrown as exceptions by the ``new`` expression 
     * to report invalid array lengths if the array is negative, total size of the 
     * new array would exceed implementation-defined maximum value, or
     * the number of initializer clause exceeds the number of elements to
     * initialize.
     */
    class bad_array_new_length : public bad_alloc {
    public:
        explicit bad_array_new_length(const char *msg = "Bad Array New Length Error Raised!") : bad_alloc(msg) {};
    };
// ================================================================================
// ================================================================================

    /**
     * Class bad_exception 
     * Represents the detection of a bad exception error 
     *
     * The type of exception thrown if the cslt::exception_ptr stores a copy of 
     * the caught exception and if the constructor of the exception object 
     * caught by cslt::current_exception throwns an exception.  Also thrown if 
     * a dynamic exception specification is violated.
     */
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
