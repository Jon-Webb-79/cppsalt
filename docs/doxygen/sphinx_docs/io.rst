.. _io:

******
io.hpp
******

The ``io.hpp`` header file in the ``cslt`` library serves as a comprehensiveinterface
interface to the I/O functionalities provided by the C++ Standard Library. 
By wrapping key classes from the 
`iostream <https://en.cppreference.com/w/cpp/header/iostream>`_, 
`sstream <https://cplusplus.com/reference/sstream/>`_, 
`fstream <https://cplusplus.com/reference/fstream/fstream/>`_, 
and `streambuf <https://cplusplus.com/reference/streambuf/streambuf/>`_ headers, 
this library allows users to access robust I/O functionalities within the 
``cslt`` namespace.

The ``io.hpp`` file can be accessed below.

- :download:`io.hpp <../../../cppsalt/include/io.hpp>`
- :download:`except.hpp <../../../cppsalt/io.cpp>`

Wrapped Classes
===============

The following classes from the standard library are wrapped in the ``cslt`` namespace:

- ``cslt::istream``: An input stream class, analogous to ``std::istream``. It is used for reading data from various sources like console input, files, or strings.
- ``cslt::ostream``: An output stream class, similar to ``std::ostream``. It is used for writing data to various destinations like console output, files, or strings.
- ``cslt::ifstream``: A file input stream class, equivalent to ``std::ifstream``. It allows for reading data from files.
- ``cslt::ofstream``: A file output stream class, corresponding to ``std::ofstream``. It is used for writing data to files.
- ``cslt::stringstream``: A string stream class, mirroring ``std::stringstream``, which provides string-based stream functionalities.
- ``cslt::istringstream``: An input string stream class, similar to ``std::istringstream``. It is specifically for reading data from strings.
- ``cslt::ostringstream``: An output string stream class, akin to ``std::ostringstream``. It is used for writing data into strings.
- Additional classes for wide character support such as ``cslt::wifstream``, ``cslt::wofstream``, ``cslt::wstringstream``, etc.

Functionality
=============

Each wrapped class in the ``cslt`` namespace retains the same functionality 
and interface as its standard library counterpart, ensuring ease of use and 
familiarity for those accustomed to the standard C++ I/O streams. This design 
choice facilitates a seamless transition for developers from using standard I/O 
classes to their `cslt` equivalents, while also ensuring compatibility and 
interoperability with existing C++ codebases.

Usage
=====

To utilize these wrapped I/O classes, include the `io.h` header in your C++ 
source files and use the `cslt` namespace. 

Example 1
---------
For example:

.. code-block:: cpp

   #include "io.h"
   using namespace cslt;

   int main() {
       ofstream file("example.txt");
       if (file.is_open()) {
           file << "Hello, world!" << std::endl;
       }
       file.close();
       return 0;
   }

This code snippet demonstrates the use of `cslt::ofstream` to write text to a file.

Example 2
---------
This example shows how to use cout 

.. code-block:: cpp 

   #include "io.hpp"

   int main() {
       cslt::cout << "Hello, World!" << cslt::endl;
       return 0;
   }

.. code-block:: bash 

   >> Hello, World! 

Example 3 
---------

An example showing how to use the ``io.hpp`` header to redirect a buffer.

.. code-block:: cpp 

   #include "io.hpp"
   #include <sstream>

   int main() {
       cslt::ostringstream tempStream;
       auto originalBuffer = cslt::cout.rdbuf();  // Save the original buffer

       cslt::cout.rdbuf(tempStream.rdbuf());  // Redirect cout to tempStream

       cslt::cout << "This is a test.";

       cslt::cout.rdbuf(originalBuffer);  // Restore the original buffer

       std::string output = tempStream.str();
       cslt::cout << "The redirected output is: " << output << cslt::endl;

       return 0;
   }

.. code-block:: bash 

   >> The redirected output is: This is a test.

Example 4
---------

An example showing how to use ``io.hpp`` to overload the ``cout`` to print 
the contents of a class.

.. code-block:: cpp 

   #include "io.h"
   #include <iostream>

   class MyClass {
   public:
       int value;
       MyClass(int v) : value(v) {}

       friend std::ostream& operator<<(std::ostream& os, const MyClass& obj) {
           os << "MyClass value: " << obj.value;
       return os;
       }
   };

   int main() {
       MyClass myObject(10);
       cslt::cout << myObject << std::endl;
       return 0;
   }

.. code-block:: bash 

   >> MyClass value: 10


Additional Notes
================

- Ensure proper inclusion of the `io.h` header file in your project to access these functionalities.
- The library is designed to be fully compatible with the C++ Standard Library, making it suitable for a wide range of applications.

