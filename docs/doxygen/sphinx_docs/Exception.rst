.. _Exception:

*********
Exception
*********

The prototypes in the ``except.hpp`` header file can be used by developers 
to identify possible errors in code that can be identified in the classic
``try``, ``throw``, ``catch`` architecture, like that shown below.  In this 
example, a custom exception is developed from the base class of ``exception``.

.. code-block:: cpp

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
           std::cout << e.what() << std::endl;
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

       int main()
       try {
           throw cslt::exception("An error occurred");
       } catch (const cslt::exception& e) {
           std::cerr << e.what() << std::endl;
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
            std::cerr << e.what() << std::endl;
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
   :returns: An instance of ``exception``.

Methods
-------

.. function:: const char* what() const noexcept

   Retrieves the error message associated with the exception.

   :returns: A constant character pointer to the error message.
