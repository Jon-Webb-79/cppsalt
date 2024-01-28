.. _dtypes:

*******
dtype.h
*******
The ``dtype.h`` header file defines several specific data types and aliases 
to support cross-platform and generic operations.

The definitions in this description can be accessed through the file below.

- :download:`except.hpp <../../../cppsalt/include/dtype.hpp>`

cslt::size_t
============
The ``cslt::size_t`` data type is an alias for the standard C++ ``std::size_t`` type. 
It represents an unsigned integer type that is large enough to contain the size 
of the largest object your program will ever handle. Typically, it's used for array 
indexing and loop counting. By aliasing this type in the ``cslt`` namespace, compatibility 
with the standard C++ library (``std``) is maintained, ensuring consistent behavior 
across different platforms.

Example
-------
An example of ``cslt::size_t`` in a for loop iterating over a C-style array.

.. code-block:: cpp

   #include "io.hpp"
   #include "dtype.hpp"

   int main() {

       int a[5] = {1, 2, 3, 4, 5};
       cslt::cout << "[ ";
       for (cslt::size_t i = 0; i < 5; i++)  // Corrected boundary
           cslt::cout << a[i] << (i < 4 ? ", " : " ");
       cslt::cout << "]" << cslt::endl;
       return 0;
   }

.. code-block:: bash

   >> [ 1, 2, 3, 4, 5 ]

.. note:: While `cslt::size_t` is consistent across platforms, its underlying type may vary. On 32-bit systems, it's typically an `unsigned int`, while on 64-bit systems, it's often an `unsigned long` or `unsigned long long`. This variance ensures that `size_t` can represent the size of the largest possible object on any given platform.

cslt::ssize_t
=============
The ``cslt::ssize_t`` data type is a signed integer type used to represent sizes 
or counts that can potentially be negative. This type is particularly useful in 
scenarios where functions return a size or a count but may also need to indicate 
an error or negative condition using a negative number. 

Unlike ``cslt::size_t``, ``ssize_t`` is not part of the standard C++ library. 
It is commonly found in POSIX-compliant systems such as Unix-like operating systems. 
In the ``cslt`` namespace, ``ssize_t`` is defined to provide similar functionality, 
enabling its use across different platforms, including those where it is not 
natively available.

Example
-------
An example usage of ``cslt::ssize_t`` could be for a function that returns the size 
of an array or an error code.

.. code-block:: cpp

   #include "dtype.hpp"

   cslt::ssize_t getArraySize(int* array) {
       if (array == nullptr) {
           return -1;  // Error code indicating a null pointer was passed
       }
       // Assuming a fixed size array for demonstration purposes
       return 5;  // Size of the array
   }

   int main() {
       int a[5] = {1, 2, 3, 4, 5};
       cslt::ssize_t size = getArraySize(a);
       if (size < 0) {
           cslt::cerr << "Error: Null pointer passed to getArraySize" << cslt::endl;
       } else {
           cslt::cout << "Array size: " << size << cslt::endl;
       }
       return 0;
   }

.. code-block:: bash

   >> Array size: 5

.. note:: The implementation of `cslt::ssize_t` varies depending on the platform. On POSIX-compliant systems, it is typically defined as a signed counterpart to `size_t` (e.g., `signed long` or `signed long long`). In non-POSIX environments like Windows, `cslt::ssize_t` is explicitly defined in the `cslt` namespace to ensure its availability.


