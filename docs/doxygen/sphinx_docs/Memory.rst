.. _memory:

**********
memory.hpp
**********

The ``memory.hpp`` header file is a fundamental component of the C++ Standard 
Library Toolkit (CSLT), residing within the broader ``cslt`` namespace. This 
file encapsulates a suite of smart pointer classes, including ``unique_ptr``, 
``shared_ptr``, and the forthcoming ``array_ptr``. These classes are instrumental 
in managing dynamically allocated memory in C++, offering automatic memory 
management, resource control, and exception safety mechanisms. 

Purpose
=======

Memory management is a critical aspect of C++ programming. Manual memory management 
using raw pointers is error-prone, leading to issues like memory leaks, 
dangling pointers, and double frees. The ``memory.hpp`` file addresses these 
challenges by providing robust abstractions that automate memory lifecycle management, 
thus enhancing code safety, clarity, and reliability.

Classes
-------

- ``unique_ptr``: Manages a dynamically allocated object, ensuring unique ownership semantics. It automates resource deallocation upon going out of scope, and it supports move semantics to transfer ownership.

- ``shared_ptr``: Implements shared ownership over a dynamically allocated object. It uses reference counting to ensure that the object is deleted when the last ``shared_ptr`` owning the resource is destroyed or reset.

- ``array_ptr`` (planned): Will provide specialized management for dynamic arrays, extending the smart pointer paradigm to collections of objects, ensuring safe allocation and deallocation through automatic memory management.

Importance in C++
-----------------

The classes within ``memory.hpp`` reflect modern C++ practices, emphasizing safety, 
efficiency, and expressiveness. They abstract away the complexities of manual 
memory management, allowing developers to focus on application logic rather 
than the intricacies of resource management. By leveraging these smart pointers, 
programmers can write more robust and maintainable code, mitigate common memory 
management errors, and utilize modern C++ features like move semantics and automatic 
resource cleanup.

.. note:: The ``cslt`` namespace and its contents, including ``memory.hpp``, are designed to complement the C++ Standard Library, offering an intuitive and cohesive toolkit for C++ developers.

By integrating these smart pointer classes into their projects, developers harness 
the power of automatic memory management, leading to cleaner, safer, and more 
efficient C++ codebases.

.. _cslt_unique_ptr:

unique_ptr
==========

The ``unique_ptr`` class is a part of the ``cslt`` namespace's memory management 
toolkit, encapsulated within the ``memory.hpp`` header file. It is designed to 
manage the lifecycle of a dynamically allocated object, ensuring exclusive ownership 
and automatic deletion when the ``unique_ptr`` goes out of scope or is otherwise 
disposed of. This class is a cornerstone of resource management in modern C++, 
eliminating the risks associated with raw pointer usage, such as memory leaks 
and dangling pointers.

Purpose
-------

``unique_ptr`` offers a lightweight, efficient mechanism for managing dynamically 
allocated memory. It provides strict ownership semantics, meaning that at any 
given time, only one ``unique_ptr`` can own a particular resource. When the 
owning ``unique_ptr`` is destroyed or assigned a new resource, it automatically 
deletes the associated dynamically allocated object, ensuring proper resource cleanup.

Usage
-----

To use ``unique_ptr``, include the ``memory.hpp`` header and create an instance 
of ``unique_ptr`` by passing a pointer to a dynamically allocated object. 
``unique_ptr`` takes full ownership of this object, managing its lifecycle automatically.

.. code-block:: cpp

   #include "memory.hpp"
   
   cslt::unique_ptr<int> myPtr(new int(10));

Key Methods
-----------

- **Constructor**: Initializes a new ``unique_ptr`` instance, optionally taking a pointer to a dynamically allocated object.

- **Destructor**: Automatically deletes the managed object when the ``unique_ptr`` goes out of scope.

- **operator* and operator->**: Provides access to the underlying object.

- **get()**: Returns a pointer to the managed object.

- **release()**: Releases ownership of the managed object and returns a pointer to it, without deleting it.

- **reset()**: Deletes the managed object and optionally replaces it with a new one.

- **move constructor and move assignment operator**: Allows transfer of ownership between ``unique_ptr`` instances, utilizing C++ move semantics.

Example
-------

The following example demonstrates the basic usage of ``unique_ptr`` for 
managing a dynamically allocated integer:

.. code-block:: cpp

   cslt::unique_ptr<int> ptr(new int(42));
   std::cout << "Value: " << *ptr << std::endl;  // Output: Value: 42
   ptr.reset(new int(55));
   std::cout << "New Value: " << *ptr << std::endl;  // Output: New Value: 55

This example shows how to create a ``unique_ptr``, access the managed object, 
and replace it with a new dynamically allocated object using ``reset()``.

.. note:: ``unique_ptr`` is an essential tool for modern C++ developers, promoting safe and efficient memory management practices.

.. _cslt_make_unique:

make_unique
===========

The ``make_unique`` function is a utility within the ``cslt`` namespace, designed 
to simplify the creation of ``unique_ptr`` instances. It encapsulates the pattern 
of creating a dynamically allocated object and immediately transferring ownership 
to a ``unique_ptr``. This function is part of the ``memory.hpp`` header file and 
serves as a safer, exception-friendly alternative to directly using ``new`` 
with ``unique_ptr`` constructors.

Purpose
-------

``make_unique`` provides a convenient and safe way to create ``unique_ptr`` 
instances without exposing raw pointers, thereby reducing the risk of memory 
leaks and pointer-related errors. It also ensures that the object construction 
is exception-safe by handling allocation and construction in a single step, 
minimizing the chance of resource leaks in case of exceptions during object 
construction.

Usage
-----

To use ``make_unique``, include the ``memory.hpp`` header file and call the 
function with the desired object type and constructor arguments:

.. code-block:: cpp

   #include "memory.hpp"

   auto myUniquePtr = cslt::make_unique<MyClass>(arg1, arg2, arg3);

``make_unique`` automatically deduces the object type from the call and forwards 
the provided arguments to the constructor of the specified type, returning a 
``unique_ptr`` that takes ownership of the newly created object.

Parameters
----------

- **T**: The type of the object to be created and managed by the returned ``unique_ptr``.

- **Args**: A variadic template parameter pack representing the types of arguments to be forwarded to the constructor of ``T``.

- **args**: The actual arguments to be forwarded to the constructor of ``T``, preserving their lvalue or rvalue status.

Return Value
------------

- Returns a ``cslt::unique_ptr<T>`` instance that owns the newly created object of type ``T``.

Example
-------

The following example demonstrates how to create a ``unique_ptr`` to an instance 
of ``MyClass`` using ``make_unique``, passing constructor arguments directly:

.. code-block:: cpp

   auto myPtr = cslt::make_unique<MyClass>(10, "example");
   
   // myPtr now owns the dynamically allocated MyClass instance.

This example highlights the ease and safety of creating and managing dynamically 
allocated objects with ``make_unique``, promoting clean and exception-safe C++ code.

.. note:: Using ``make_unique`` is recommended over direct use of ``new`` for creating ``unique_ptr`` instances, as it encapsulates best practices for dynamic memory management.

