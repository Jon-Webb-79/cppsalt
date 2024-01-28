.. _Exception:

***********
exception.h
***********

The prototypes in the ``except.hpp`` header file can be used by developers 
to identify possible errors in code that can be identified in the classic
``try``, ``throw``, ``catch`` architecture, like that shown below.  In this 
example, a custom exception is developed from the base class of ``exception``.

.. code-block:: cpp

   #include "except.hpp"
   #include "io.hpp"

   class myexception: public cstl::exception {
       virtual const char* what() const throw() {
           return "My exception happened";
       }
   };

   int main() {
       try {
           throw myexception;
       }
       catch (exception& e) {
           cslt::cout << e.what() << cslt::endl;
       }
       return 0;
   }

.. code-block:: bash 

   >> My exception happened

In addition to being available for developers to use, these exceptions
are used by several classes and functions in this library. The classes that can 
be used to identify or warn users of potential errors are defined in the following 
files.

- :download:`except.hpp <../../../cppsalt/include/except.hpp>`
- :download:`except.cpp <../../../cppsalt/except.cpp>`

The classes within the ``except.hpp`` header file are defined below.

.. _exception_class:

cslt::exception 
===============
The ``exception`` class provides a consistent interface to catch all exceptions defined in 
this header file.

.. note::
   This class is separate from the standard C++ exception classes and does not inherit from ``std::exception``.

Constructors
------------

.. function:: exception(const char* msg = "Exception Raised!")

   Constructs an exception with a specified error message. If no message is provided, a default message is used.

   :param const char* msg: The error message for the exception. Defaults to "Exception Raised!".
   :returns: An instance of ``exception``.

Operator 
--------

.. function:: operator=(const exception_error& other)

   Replaces the exception 

   :param other: Another exception object

Methods
-------

.. function:: const char* what() const noexcept

   Retrieves the error message associated with the exception.

   :returns: A constant character pointer to the error message.

Example Usage
-------------

Below is an example of how to use the ``exception`` class:

.. code-block:: cpp

       #include "except.hpp"
       #include "io.hpp"

       int main()
       try {
           throw cslt::exception("An error occurred");
       } catch (const cslt::exception& e) {
           cslt::cerr << e.what() << cslt::endl;
       }
   return 0;
   }

.. code-block:: bash 

   >> An error occurred

.. _logic_error:

cslt::logic_error 
=================
The ``logic_error`` class defines a type of object to be thrown as an exception.
It reports errors that are consequences of faulty logic within the program 
such as violating logical preconditions or class invariants and may be 
preventable. No CPPSalt library components throw this exception directly; 
however, the user may wish to use this as a method to catch a broad range 
of errors.

Other types of errors that are derived from ``logic_error`` are 
:ref:`cslt::invalid_argument <invalid_argument>`,
:ref:`cslt::domain_error <domain_error>`, :ref:`cslt::length_error <length_error>`, 
:ref:`cslt::out_of_range <out_of_range>`, and
:ref:`cslt::future_error <future_error>`.

This exception encompases the :ref:`cslt::invalid_argument <invalid_argument>`,
xx, and xx classes.

.. note:: Future versions of this documentation will define the daughter types here.

The ``logic_error`` class inherits from the :ref:`exception <exception_class>` class.

.. graphviz::

   digraph inheritance {
       node [shape=box];
       edge [color=black, arrowhead=onormal];
       "exception" [label="exception Class"];
       "logic_error" [label="logic_error Class"];
       "logic_error" -> "exception";
   }

Constructors
------------

.. function:: logic_error(const char* msg = "Logic Error Raised!")

   Constructs an exception with a specified error message. If no message is provided, a default message is used.

   :param const char* msg: The error message for the exception. Defaults to "Logic Error Raised!".
   :returns: An instance of ``exception``.

Operator 
--------

.. function:: operator=(const length_error& other)

   Replaces the length error 

   :param other: Another length_error object

Methods
-------

.. function:: const char* what() const noexcept

   Retrieves the error message associated with the exception.

   :returns: A constant character pointer to the error message.

Example Usage
-------------

Below is an example of how to use the ``logic_error`` class:

.. code-block:: cpp

   #include "except.hpp"
   #include "io.gpp"

   float return_array_value(float a[5], cslt::size_t index) {
       if (index > 4)
           throw cslt::logic_error("Index out of bounds!");
        return a[index];
    }

    int main()
        float b[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
        float result;
        try { 
            result = return_array_index(b, 6);
        } catch (const cslt::logic_error& e) {
            cslt::cerr << e.what() << cslt::endl;
            result = return_array_index(b, 4); 
        }
   return 0;
   }

.. code-block:: bash 

   >> Index out of bounds

.. _invalid_argument:

cslt::invalid_argument 
======================
The ``invalid_argument`` class defines a type of object to be thrown as an exception.
It reports errors that arise because an argument value has not been accepted.

The ``invalid_argument`` class inherits the :ref:`logic_error <logic_error>` class,
which inherits from the :ref:`exception <exception_class>` class.

.. graphviz::

   digraph inheritance {
       node [shape=box];
       edge [color=black, arrowhead=onormal];
       "exception" [label="exception Class"];
       "logic_error" [label="logic_error Class"];
       "invalid_argument" [label="invalid_argument Class"];
       "invalid_argument" -> "logic_error" -> "exception";
   }


Constructors
------------

.. function:: invalid_argument(const char* msg = "Invalid Argument Error Raised!")

   Constructs an exception with a specified error message. If no message is provided, a default message is used.

   :param const char* msg: The error message for the exception. Defaults to "Invalid Argument Error Raised!".
   :returns: An instance of ``invalid_argument``, ``logic_error``, and ``exception``.

Operator 
--------

.. function:: operator=(const invalid_argument& other)

   Replaces the invalid argument error 

   :param other: Another invalid_argument object

Methods
-------

.. function:: const char* what() const noexcept

   Retrieves the error message associated with the exception.

   :returns: A constant character pointer to the error message.

.. _domain_error:

cslt::domain_error 
==================
The ``domain_error`` class defines a type of object to be thrown as an exception.
It may also be used by the implementation to report domain errors, that is,
situations where the inputs are outside the domain on which operations
are defined.  This is particularly applied to mathematical functions such  as 
square root where the result is negative, and the results must be positive.

The ``domain_error`` class inherits the :ref:`logic_error <logic_error>` class,
which inherits from the :ref:`exception <exception_class>` class.

.. graphviz::

   digraph inheritance {
       node [shape=box];
       edge [color=black, arrowhead=onormal];
       "exception" [label="exception Class"];
       "logic_error" [label="logic_error Class"];
       "domain_error" [label="domain_error Class"];
       "domain_error" -> "logic_error" -> "exception";
   }


Constructors
------------

.. function:: domain_error(const char* msg = "Domain Error Raised!")

   Constructs an exception with a specified error message. If no message is provided, a default message is used.

   :param const char* msg: The error message for the exception. Defaults to "Domain Error Raised!".
   :returns: An instance of ``domain_error``, ``logic_error``, and ``exception``.

Operator 
--------

.. function:: operator=(const domain_error& other)

   Replaces the domain error 

   :param other: Another domain_error object

Methods
-------

.. function:: const char* what() const noexcept

   Retrieves the error message associated with the exception.

   :returns: A constant character pointer to the error message.

.. _length_error:

cslt::length_error 
==================
The ``length_error`` class defines the type of exception to report a length 
error.  This is a standard exception that can be thrown by programs.  Some 
components of the CPPSalt library such as ``vector`` and ``string`` throw 
exceptions of this type to signal sizing errors.

The ``length_error`` class inherits the :ref:`logic_error <logic_error>` class,
which inherits from the :ref:`exception <exception_class>` class.

.. graphviz::

   digraph inheritance {
       node [shape=box];
       edge [color=black, arrowhead=onormal];
       "exception" [label="exception Class"];
       "logic_error" [label="logic_error Class"];
       "length_error" [label="length_error Class"];
       "length_error" -> "logic_error" -> "exception";
   }


Constructors
------------

.. function:: length_error(const char* msg = "Length Error Raised!")

   Constructs an exception with a specified error message. If no message is provided, a default message is used.

   :param const char* msg: The error message for the exception. Defaults to "Length Error Raised!".
   :returns: An instance of ``length_error``, ``logic_error``, and ``exception``.

Operator 
--------

.. function:: operator=(const length_error& other)

   Replaces the length error 

   :param other: Another length_error object

Methods
-------

.. function:: const char* what() const noexcept

   Retrieves the error message associated with the exception.

   :returns: A constant character pointer to the error message.

.. code-block:: cpp 

   #include "except.hpp"
   #include "io.hpp"
   #include "vector.hpp"

   int main() {
       try {
           cslt::vector<int> myvector;
           myvector.resize(myvector.max_size()+1);
       }
       catch (const cslt::length_error& e) {
           cslt::cerr << e.what() << cslt::endl;
       }
       return 0;
   }

.. code-block:: bash 

   Length Error Raised!

.. _out_of_range:

cslt::out_of_range 
==================
The ``out_of_range`` class defines the type of objects thrown as exceptions to report 
an out-of-range error.  It is a standard exception that can be thrown by 
programs.  Some components of the CPPSalt library such as ``vector``, ``string``,
``MinHeap``, and ``MaxHeap`` throw this type to signal arguments out of range.

The ``out_of_range`` class inherits the :ref:`logic_error <logic_error>` class,
which inherits from the :ref:`exception <exception_class>` class.

.. graphviz::

   digraph inheritance {
       node [shape=box];
       edge [color=black, arrowhead=onormal];
       "exception" [label="exception Class"];
       "logic_error" [label="logic_error Class"];
       "out_of_range" [label="out_of_range Class"];
       "out_of_range" -> "logic_error" -> "exception";
   }


Constructors
------------

.. function:: out_of_range(const char* msg = "Out of Range Error Raised!")

   Constructs an exception with a specified error message. If no message is provided, a default message is used.

   :param const char* msg: The error message for the exception. Defaults to "Out of Range Error Raised!".
   :returns: An instance of ``out_of_range``, ``logic_error``, and ``exception``.

Operator 
--------

.. function:: operator=(const out_of_range& other)

   Replaces the out of range error 

   :param other: Another out_of_range object

Methods
-------

.. function:: const char* what() const noexcept

   Retrieves the error message associated with the exception.

   :returns: A constant character pointer to the error message.

.. code-block:: cpp 

   #include "except.hpp"
   #include "io.hpp"
   #include "vector.hpp"

   int main (void) {
       cslt::vector<int> myvector(10);
       try {
           myvector.at(20)=100;      // vector::at throws an out-of-range
       }
           catch (const cslt::out_of_range& oor) {
           std::cerr << oor.what() << '\n';
       }
       return 0;
   } 

.. code-block:: bash 

   Out of Range Error Raised!

.. _future_error:

cslt::future_error 
==================
The ``future_error`` class defines the type of object thrown as an exception to report 
invalid operations on ``future`` objects or other elements of the library.

The ``future_error`` class inherits the :ref:`logic_error <logic_error>` class,
which inherits from the :ref:`exception <exception_class>` class.

.. graphviz::

   digraph inheritance {
       node [shape=box];
       edge [color=black, arrowhead=onormal];
       "exception" [label="exception Class"];
       "logic_error" [label="logic_error Class"];
       "future_error" [label="future_error Class"];
       "future_error" -> "logic_error" -> "exception";
   }


Constructors
------------

.. function:: future_error(const char* msg = "Future Error Raised!")

   Constructs an exception with a specified error message. If no message is provided, a default message is used.

   :param const char* msg: The error message for the exception. Defaults to "Future Error Raised!".
   :returns: An instance of ``out_of_range``, ``logic_error``, and ``exception``.

Operator 
--------

.. function:: operator=(const future_error& other)

   Replaces the future error 

   :param other: Another future_error object

Methods
-------

.. function:: const char* what() const noexcept

   Retrieves the error message associated with the exception.

   :returns: A constant character pointer to the error message.

.. _runtime_error:

cslt::runtime_error
===================
The ``runtime_error`` class defines a type of object to be thrown as an exception. 
It reports errors that are due to events beyond the scope
of the program and can not be easily predicted.

Other types of errors that are derived from ``runtime_error`` are 
:ref:`cslt::range_error <range_error>`, :ref:`cslt::overflow_error <overflow_error>`
:ref:`cslt::underflow_error <underflow_error>`, :ref:`cslt::regex_error <regex_error>`, 
:ref:`cslt::system_error <system_error>` and :ref:`cslt::format_error <format_error>`.

The ``runtime_error`` class inherits the :ref:`exception <exception_class>` class.

.. graphviz::

   digraph inheritance {
       node [shape=box];
       edge [color=black, arrowhead=onormal];
       "exception" [label="exception Class"];
       "runtime_error" [label="runtime_error Class"];
       "runtime_error" -> "exception";
   }


Constructors
------------

.. function:: runtime_error(const char* msg = "Runtime Error Raised!")

   Constructs an exception with a specified error message. If no message is provided, a default message is used.

   :param const char* msg: The error message for the exception. Defaults to "Runtime Error Raised!".
   :returns: An instance of ``out_of_range``, `and ``exception``.

Operator 
--------

.. function:: operator=(const runtime_error& other)

   Replaces the runtime error 

   :param other: Another runtime_error object

Methods
-------

.. function:: const char* what() const noexcept

   Retrieves the error message associated with the exception.

   :returns: A constant character pointer to the error message.

.. _range_error:

cslt::range_error
=================
The ``range_error`` class defines a type of object thrown as an exception to report 
range errors in internal computations.  It is a standard exception that can be thrown by
programs.  Some components of this library throw this exception to signal 
range errors.

The ``runtime_error`` class inherits the :ref:`exception <exception_class>` class
and the :ref:`runtime_error <runtime_error>` class.

.. graphviz::

   digraph inheritance {
       node [shape=box];
       edge [color=black, arrowhead=onormal];
       "exception" [label="exception Class"];
       "runtime_error" [label="runtime_error Class"];
       "range_error" [label="range_error Class"];
       "range_error" -> "runtime_error" -> "exception";
   }


Constructors
------------

.. function:: range_error(const char* msg = "Range Error Raised!")

   Constructs an exception with a specified error message. If no message is provided, a default message is used.

   :param const char* msg: The error message for the exception. Defaults to "Range Error Raised!".
   :returns: An instance of ``range_error``, ``runtime_error``, and ``exception``.

Operator 
--------

.. function:: operator=(const range_error& other)

   Replaces the range error 

   :param other: Another range_error object

Methods
-------

.. function:: const char* what() const noexcept

   Retrieves the error message associated with the exception.

   :returns: A constant character pointer to the error message.

.. _overflow_error:

cslt::overflow_error
====================
The ``overflow_error`` class defines a type of object that can be thrown to
signal arithmetic overflow errors.

The ``overflow_error`` class inherits the :ref:`exception <exception_class>` class
and the :ref:`runtime_error <runtime_error>` class.

.. graphviz::

   digraph inheritance {
       node [shape=box];
       edge [color=black, arrowhead=onormal];
       "exception" [label="exception Class"];
       "runtime_error" [label="runtime_error Class"];
       "overflow_error" [label="overflow_error Class"];
       "overflow_error" -> "runtime_error" -> "exception";
   }


Constructors
------------

.. function:: overflow_error(const char* msg = "Overflow Error Raised!")

   Constructs an exception with a specified error message. If no message is provided, a default message is used.

   :param const char* msg: The error message for the exception. Defaults to "Overflow Error Raised!".
   :returns: An instance of ``overflow_error``, ``runtime_error``, and ``exception``.

Operator 
--------

.. function:: operator=(const overflow_error& other)

   Replaces the overflow error 

   :param other: Another overflow_error object

Methods
-------

.. function:: const char* what() const noexcept

   Retrieves the error message associated with the exception.

   :returns: A constant character pointer to the error message.

.. _underflow_error:

cslt::underflow_error
=====================
The ``underflow_error`` class defines a type of object that can be thrown to
signal arithmetic underflow errors.

The ``underflow_error`` class inherits the :ref:`exception <exception_class>` class
and the :ref:`runtime_error <runtime_error>` class.

.. graphviz::

   digraph inheritance {
       node [shape=box];
       edge [color=black, arrowhead=onormal];
       "exception" [label="exception Class"];
       "runtime_error" [label="runtime_error Class"];
       "underflow_error" [label="underflow_error Class"];
       "underflow_error" -> "runtime_error" -> "exception";
   }


Constructors
------------

.. function:: underflow_error(const char* msg = "Underflow Error Raised!")

   Constructs an exception with a specified error message. If no message is provided, a default message is used.

   :param const char* msg: The error message for the exception. Defaults to "Underflow Error Raised!".
   :returns: An instance of ``underflow_error``, ``runtime_error``, and ``exception``.

Operator 
--------

.. function:: operator=(const undeflow_error& other)

   Replaces the underflow error 

   :param other: Another underflow_error object

Methods
-------

.. function:: const char* what() const noexcept

   Retrieves the error message associated with the exception.

   :returns: A constant character pointer to the error message.

.. _system_error:

cslt::system_error
==================
The ``system_error`` class defines 

The ``system_error`` class inherits the :ref:`exception <exception_class>` class
and the :ref:`runtime_error <runtime_error>` class.

.. graphviz::

   digraph inheritance {
       node [shape=box];
       edge [color=black, arrowhead=onormal];
       "exception" [label="exception Class"];
       "runtime_error" [label="runtime_error Class"];
       "system_error" [label="system_error Class"];
       "system_error" -> "system_error" -> "exception";
   }


Constructors
------------

.. function:: system_error(const char* msg = "System Error Raised!")

   Constructs an exception with a specified error message. If no message is provided, a default message is used.

   :param const char* msg: The error message for the exception. Defaults to "System Error Raised!".
   :returns: An instance of ``system_error``, ``runtime_error``, and ``exception``.

Operator 
--------

.. function:: operator=(const system_error& other)

   Replaces the system error 

   :param other: Another system_error object

Methods
-------

.. function:: const char* what() const noexcept

   Retrieves the error message associated with the exception.

   :returns: A constant character pointer to the error message.

.. _regex_error:

cslt::regex_error
=====================
The ``regex_error`` class defines a type of object to be thrown to report 
errors with th eregular expressions library

The ``regex_error`` class inherits the :ref:`exception <exception_class>` class
and the :ref:`runtime_error <runtime_error>` class.

.. graphviz::

   digraph inheritance {
       node [shape=box];
       edge [color=black, arrowhead=onormal];
       "exception" [label="exception Class"];
       "runtime_error" [label="runtime_error Class"];
       "regex_error" [label="regex_error Class"];
       "regex_error" -> "runtime_error" -> "exception";
   }


Constructors
------------

.. function:: regex_error(const char* msg = "Regex Error Raised!")

   Constructs an exception with a specified error message. If no message is provided, a default message is used.

   :param const char* msg: The error message for the exception. Defaults to "Regex Error Raised!".
   :returns: An instance of ``regex_error``, ``runtime_error``, and ``exception``.

Operator 
--------

.. function:: operator=(const regex_error& other)

   Replaces the regex error 

   :param other: Another regex object

Methods
-------

.. function:: const char* what() const noexcept

   Retrieves the error message associated with the exception.

   :returns: A constant character pointer to the error message.

.. _format_error:

cslt::format_error
==================
The ``format_error`` class defines a type of exception object to throw when 
errors occur in the ``formatting`` library.

The ``format_error`` class inherits the :ref:`exception <exception_class>` class
and the :ref:`runtime_error <runtime_error>` class.

.. graphviz::

   digraph inheritance {
       node [shape=box];
       edge [color=black, arrowhead=onormal];
       "exception" [label="exception Class"];
       "runtime_error" [label="runtime_error Class"];
       "format_error" [label="format_error Class"];
       "format_error" -> "format_error" -> "exception";
   }


Constructors
------------

.. function:: format_error(const char* msg = "Format Error Raised!")

   Constructs an exception with a specified error message. If no message is provided, a default message is used.

   :param const char* msg: The error message for the exception. Defaults to "Format Error Raised!".
   :returns: An instance of ``format_error``, ``runtime_error``, and ``exception``.

Operator 
--------

.. function:: operator=(const format_error& other)

   Replaces the format error 

   :param other: Another format_error object

Methods
-------

.. function:: const char* what() const noexcept

   Retrieves the error message associated with the exception.

   :returns: A constant character pointer to the error message.

.. _bad_typeid:

cslt::bad_typeid
================
The ``bad_typeid`` class defines the type of exception to be applied to a polymorphic
type which as a null pointer value.

The ``bad_typeid`` class inherits the :ref:`exception <exception_class>` class.

.. graphviz::

   digraph inheritance {
       node [shape=box];
       edge [color=black, arrowhead=onormal];
       "exception" [label="exception Class"];
       "bad_typeid" [label="bad_typeid Class"];
       "bad_typeid" -> "exception";
   }


Constructors
------------

.. function:: bad_typeid(const char* msg = "Bad Type ID Error Raised!")

   Constructs an exception with a specified error message. If no message is provided, a default message is used.

   :param const char* msg: The error message for the exception. Defaults to "Bad Type ID Error Raised!".
   :returns: An instance of ``bad_typeid``, and ``exception``.

Operator 
--------

.. function:: operator=(const bad_typeid& other)

   Replaces the bad_typeid error 

   :param other: Another bad_typeid object

Methods
-------

.. function:: const char* what() const noexcept

   Retrieves the error message associated with the exception.

   :returns: A constant character pointer to the error message.

.. code-block:: cpp 

   #include "io.hpp"
   #include "except.hpp"

   class Polymorphic {virtual void Member(){}};

   int main () {
       try
       {
           Polymorphic * pb = 0;
	       cslt::cout << typeid(*pb).name();
       }
       catch (std::bad_typeid& bt) {
           cslt::cerr << bt.what() << '\n';
       }
       return 0;
    }

.. code-block:: bash 

   >> Bad Type ID Error Raised!

.. _bad_cast:

cslt::bad_cast
==============
The ``bad_cast`` class defines the type of exception thrown by ``dynamic_cast``
when it fails the run-time check performed on references to polymorphic 
class types.

The ``bad_cast`` class inherits the :ref:`exception <exception_class>` class.

.. graphviz::

   digraph inheritance {
       node [shape=box];
       edge [color=black, arrowhead=onormal];
       "exception" [label="exception Class"];
       "bad_cast" [label="bad_cast Class"];
       "bad_cast" -> "exception";
   }


Constructors
------------

.. function:: bad_cast(const char* msg = "Bad Cast Error Raised!")

   Constructs an exception with a specified error message. If no message is provided, a default message is used.

   :param const char* msg: The error message for the exception. Defaults to "Bad Cast Error Raised!".
   :returns: An instance of ``bad_cast``, and ``exception``.

Operator 
--------

.. function:: operator=(const bad_cast& other)

   Replaces the bad_cast error 

   :param other: Another bad_cast object

Methods
-------

.. function:: const char* what() const noexcept

   Retrieves the error message associated with the exception.

   :returns: A constant character pointer to the error message.

.. code-block:: cpp 

   #include "io.hpp"
   #include "except.hpp"

   int main () {
       try {
           Base b;
           Derived& rd = dynamic_cast<Derived&>(b);
       }
       catch (cslt::bad_cast& bc) {
           cslt::cerr << bc.what() << '\n';
       }
       return 0;
    }   

.. code-block:: bash 

   >> Bad Type Bad Cast Error Raised!

.. _bad_weak_ptr:

cslt::bad_weak_ptr
==================
The ``bad_weak_ptr`` class defines the type of exception thrown by a 
``shared_ptr`` when constructed with an expired ``weak_ptr``.

The ``bad_weak_ptr`` class inherits the :ref:`exception <exception_class>` class.

.. graphviz::

   digraph inheritance {
       node [shape=box];
       edge [color=black, arrowhead=onormal];
       "exception" [label="exception Class"];
       "bad_weak_ptr" [label="bad_weak_ptr Class"];
       "bad_weak_ptr" -> "exception";
   }


Constructors
------------

.. function:: bad_weak_ptr(const char* msg = "Bad Weak Pointer Error Raised!")

   Constructs an exception with a specified error message. If no message is provided, a default message is used.

   :param const char* msg: The error message for the exception. Defaults to "Bad Weak Pointer Error Raised!".
   :returns: An instance of ``bad_weak_ptr``, and ``exception``.

Operator 
--------

.. function:: operator=(const bad_weak_ptr& other)

   Replaces the bad_weak_ptr error 

   :param other: Another bad_weak_ptr object

Methods
-------

.. function:: const char* what() const noexcept

   Retrieves the error message associated with the exception.

   :returns: A constant character pointer to the error message.

.. _bad_function_call:

cslt::bad_function_call
=======================
The ``bad_function_call`` class defines the type of exception thrown by ``cstl::function::operator()``
if the function wrapper has no target.

The ``bad_function_call`` class inherits the :ref:`exception <exception_class>` class.

.. graphviz::

   digraph inheritance {
       node [shape=box];
       edge [color=black, arrowhead=onormal];
       "exception" [label="exception Class"];
       "bad_function_call" [label="bad_function_call Class"];
       "bad_function_call" -> "exception";
   }


Constructors
------------

.. function:: bad_function_call(const char* msg = "Bad Function Call Error Raised!")

   Constructs an exception with a specified error message. If no message is provided, a default message is used.

   :param const char* msg: The error message for the exception. Defaults to "Bad Function Call Error Raised!".
   :returns: An instance of ``bad_function_call``, and ``exception``.

Operator 
--------

.. function:: operator=(const bad_weak_ptr& other)

   Replaces the bad_weak_ptr error 

   :param other: Another bad_weak_ptr object

Methods
-------

.. function:: const char* what() const noexcept

   Retrieves the error message associated with the exception.

   :returns: A constant character pointer to the error message.

.. _bad_alloc:

cslt::bad_alloc
===============
The ``bad_alloc`` class defines the type of exception thrown by the standard 
definition of the operator new and the operator new[] when they fail to 
allocate the requested storage.

The ``bad_alloc`` class inherits the :ref:`exception <exception_class>` class.

.. graphviz::

   digraph inheritance {
       node [shape=box];
       edge [color=black, arrowhead=onormal];
       "exception" [label="exception Class"];
       "bad_alloc" [label="bad_alloc Class"];
       "bad_alloc" -> "exception";
   }


Constructors
------------

.. function:: bad_alloc(const char* msg = "Memory Allocation Error Raised!")

   Constructs an exception with a specified error message. If no message is provided, a default message is used.

   :param const char* msg: The error message for the exception. Defaults to "Memory Allocation Error Raised!".
   :returns: An instance of ``bad_alloc``, and ``exception``.

Operator 
--------

.. function:: operator=(const bad_alloc& other)

   Replaces the bad_alloc error 

   :param other: Another bad_alloc object

Methods
-------

.. function:: const char* what() const noexcept

   Retrieves the error message associated with the exception.

   :returns: A constant character pointer to the error message.

.. code-block:: cpp 

   #include "io.hpp"
   #include "except.hpp"

   int main () {
       try {
           int* myarray= new int[10000];
       }
       catch (std::bad_alloc& ba) {
           cslt::cerr << ba.what() << '\n';
       }
       return 0;
   }

.. code-block:: bash 

   >> Memory Allocation Error Raised!

.. _bad_array_new_length:

cslt::bad_array_new_length
==========================
The ``bad_array_new_length`` class defines the type of exception thrown by these
new operator to report invalid array lengths.

The ``bad_array_new_length`` class inherits the :ref:`exception <exception_class>` class.

.. graphviz::

   digraph inheritance {
       node [shape=box];
       edge [color=black, arrowhead=onormal];
       "exception" [label="exception Class"];
       "bad_array_new_length" [label="bad_array_new_length Class"];
       "bad_array_new_length" -> "exception";
   }


Constructors
------------

.. function:: bad_array_new_length(const char* msg = "Bad Array New Length Error Raised!")

   Constructs an exception with a specified error message. If no message is provided, a default message is used.

   :param const char* msg: The error message for the exception. Defaults to "Bad Array New Length Error Raised!".
   :returns: An instance of ``bad_array_new_length``, and ``exception``.

Operator 
--------

.. function:: operator=(const bad_array_new_length& other)

   Replaces the bad_array_new_length error 

   :param other: Another bad_array_new_length object

Methods
-------

.. function:: const char* what() const noexcept

   Retrieves the error message associated with the exception.

   :returns: A constant character pointer to the error message.

.. code-block:: cpp 

   #include <new>
   #include "io.hpp"
   #include "except.hpp"
 
   int main() {
       try {
           int negative = -1;
           new int[negative];
       } catch (const cstl::bad_array_new_length& e) {
             std::cout << "1) " << e.what() << ": negative size\n";
       } try {
             int small = 1;
             new int[small]{1,2,3};
       } catch (const cslt::bad_array_new_length& e) {
             std::cout << "2) " << e.what() << ": too many initializers\n";
       } try {
             long large = LONG_MAX;
             new int[large][1000];
       } catch (const cslt::bad_array_new_length& e) {
             cslt::cout << "3) " << e.what() << ": too large\n";
       }
       cslt::cout << "End\n";
       return 0;
   } 

.. code-block:: bash 

   >> 1) Bad Array New Length: negative size 
   >> 2) Bad Array New Length: too many initializers 
   >> 3) Bad Array New Length: too large

.. _bad_exception:

cslt::bad_exception
===================
The ``bad_exception`` class defines the type

The ``bad_exception`` class inherits the :ref:`exception <exception_class>` class.

.. graphviz::

   digraph inheritance {
       node [shape=box];
       edge [color=black, arrowhead=onormal];
       "exception" [label="exception Class"];
       "bad_exception" [label="bad_exception Class"];
       "bad_exception" -> "exception";
   }


Constructors
------------

.. function:: bad_exception(const char* msg = "Bad Exception Error Raised!")

   Constructs an exception with a specified error message. If no message is provided, a default message is used.

   :param const char* msg: The error message for the exception. Defaults to "Bad Exception Error Raised!".
   :returns: An instance of ``bad_exception``, and ``exception``.

Operator 
--------

.. function:: operator=(const bad_exception& other)

   Replaces the bad_exception error 

   :param other: Another bad_exception object

Methods
-------

.. function:: const char* what() const noexcept

   Retrieves the error message associated with the exception.

   :returns: A constant character pointer to the error message.

.. code-block:: cpp 

   #include <new>
   #include "io.hpp"
   #include "except.hpp"
 
   void my_unexp() { throw;}
 
   void test()
       throw(cslt::bad_exception) // Dynamic exception specifications
                                 // are deprecated in C++11
   {
       throw cslt::runtime_error("test");
   }
 
   int main() {
       cslt::set_unexpected(my_unexp); // Deprecated in C++11, removed in C++17
 
       try {
           test();
       } catch (const cslt::bad_exception& e) {
             cslt::cerr << "Caught " << e.what() << '\n';
       }
       return 0;
   } 

.. code-block:: bash 

   >> Caught cstl::bad_exception
