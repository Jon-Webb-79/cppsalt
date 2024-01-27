.. _Exception:

*********
Exception
*********

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

Other types of errors that are derived from ``runtime_error`` are ``range_error`,
``overflow_error``, ``underflow_error`, ``regex_error``, and ``system_error``.

The ``runtime_error`` class inherits the :ref:`exception <exception_class>` class.

.. graphviz::

   digraph inheritance {
       node [shape=box];
       edge [color=black, arrowhead=onormal];
       "exception" [label="exception Class"];
       "logic_error" [label="logic_error Class"];
       "runtime_error" [label="runtime_error Class"];
       "runtime_error" -> "logic_error" -> "exception";
   }


Constructors
------------

.. function:: runtime_error(const char* msg = "Runtime Error Raised!")

   Constructs an exception with a specified error message. If no message is provided, a default message is used.

   :param const char* msg: The error message for the exception. Defaults to "Runtime Error Raised!".
   :returns: An instance of ``out_of_range``, ``logic_error``, and ``exception``.

Methods
-------

.. function:: const char* what() const noexcept

   Retrieves the error message associated with the exception.

   :returns: A constant character pointer to the error message.

