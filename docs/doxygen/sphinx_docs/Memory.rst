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

.. _cslt_shared_ptr:

shared_ptr
==========

The ``shared_ptr`` class within the ``cslt`` namespace is a smart pointer that 
maintains shared ownership of an object through a pointer. Multiple ``shared_ptr`` 
instances can own the same object, and the object is destroyed automatically 
once the last ``shared_ptr`` owning it is destroyed or reset.

Purpose
-------

``shared_ptr`` is designed to facilitate advanced memory management in C++, 
eliminating the need for manual memory management while avoiding common pitfalls 
such as memory leaks, dangling pointers, and double frees. It is especially 
useful in scenarios involving shared ownership, cyclic references, and polymorphism.

Usage
-----

To use ``shared_ptr``, include the ``memory.hpp`` header file and instantiate a 
``shared_ptr`` object with a dynamically allocated object. The ``shared_ptr`` 
takes ownership of this object and manages its lifetime automatically.

.. code-block:: cpp

   #include "memory.hpp"
   
   cslt::shared_ptr<MyClass> mySharedPtr(new MyClass());
   cslt::shared_ptr<MyClass> anotherSharedPtr = mySharedPtr; // Both now own the object.

Key Methods
-----------

- **Constructor**: Initializes a new ``shared_ptr`` instance, optionally with a pointer to a dynamically allocated object.

- **Destructor**: Automatically deletes the managed object if this is the last ``shared_ptr`` owning it.

- **Copy Constructor**: Allows one ``shared_ptr`` instance to be initialized with another, sharing ownership of the object.

- **Copy Assignment Operator**: Assigns one ``shared_ptr`` to another, sharing ownership of the object and properly managing reference counting.

- **Move Constructor and Move Assignment Operator**: Transfers ownership from one ``shared_ptr`` to another, leaving the moved-from ``shared_ptr`` empty.

- **reset()**: Replaces the managed object with another or resets the ``shared_ptr`` to empty, managing reference counting appropriately.

- **swap()**: Swaps the contents of two ``shared_ptr`` instances.

- **operator* and operator->**: Provide access to the underlying object.

- **get()**: Returns a pointer to the managed object.

- **explicit operator bool()**: Checks if the ``shared_ptr`` is non-null.

Example
-------

.. code-block:: cpp

   cslt::shared_ptr<int> ptr(new int(10));
   cslt::shared_ptr<int> copy = ptr; // Copy constructor shares ownership.
   cslt::shared_ptr<int> moved = std::move(ptr); // Move constructor transfers ownership.
   // ptr is now empty, moved and copy share ownership of the int.

.. note:: ``shared_ptr`` ensures that dynamically allocated objects are deleted when no longer needed, simplifying memory management in C++ applications.

This smart pointer is a critical component of modern C++ memory management, 
encouraging safe and efficient practices by automating the management of dynamic 
memory and shared ownership.

.. _cslt_make_shared:

make_shared
===========

The ``make_shared`` function is a utility within the ``cslt`` namespace designed 
to create a ``shared_ptr`` instance while directly initializing the managed 
object. This function provides an efficient way to allocate and initialize 
dynamic objects and their associated control block (which includes the reference 
counter) in a single operation.

Purpose
-------

Using ``make_shared`` not only simplifies the syntax for creating a ``shared_ptr`` 
but also optimizes memory usage by combining the allocation of the object and its 
control block into a single memory allocation. This results in fewer dynamic 
allocations, reduced memory overhead, and potential performance improvements in 
applications that frequently create and destroy shared objects.

Usage
-----

To use ``make_shared``, include the ``memory.hpp`` header file. Then, call 
``make_shared`` with the type of the object you wish to create and any arguments 
needed for its constructor.

.. code-block:: cpp

   #include "memory.hpp"
   
   // Creates a shared_ptr managing a MyClass instance.
   cslt::shared_ptr<MyClass> mySharedPtr = cslt::make_shared<MyClass>(arg1, arg2);

Key Function Signature
----------------------

.. code-block:: cpp

   template <typename T, typename... Args>
   cslt::shared_ptr<T> make_shared(Args&&... args);

- **T**: The type of the object to be managed by the returned ``shared_ptr``.
- **Args...**: A variadic template parameter pack representing the types of arguments to be forwarded to the constructor of ``T``.

Parameters
----------

- **args...**: Arguments to be forwarded to the constructor of the managed object.

Return Value
------------

- Returns a ``cslt::shared_ptr<T>`` managing a new instance of ``T`` initialized with the provided arguments.

Example
-------

.. code-block:: cpp

   auto sharedPtr = cslt::make_shared<std::string>("Hello, make_shared!");
   std::cout << *sharedPtr << std::endl;  // Output: Hello, make_shared!

.. note:: ``make_shared`` is particularly useful in scenarios where an object is immediately intended to be managed by a ``shared_ptr``, as it streamlines object creation and initialization into a single expressive statement.

This function is a fundamental part of the ``cslt`` memory management utilities, 
reflecting modern best practices in C++ for creating shared ownership semantics 
around dynamically allocated objects.

.. _cslt_array_ptr:

array_ptr
=========

The ``array_ptr`` class within the ``cslt`` namespace provides a smart pointer 
abstraction for managing dynamic arrays in C++. It encapsulates a pointer to a 
dynamically allocated array of objects, ensuring automatic deallocation upon 
destruction. This class is designed to facilitate memory management tasks, 
offering mechanisms for array reallocation, and safe access patterns.

Purpose
-------

Managing dynamic arrays in C++ requires careful handling of memory allocation and 
deallocation to avoid memory leaks and undefined behavior. The ``array_ptr`` 
class automates these tasks, providing a convenient and safer interface for working 
with dynamically allocated arrays. It supports operations such as resizing the 
array, releasing ownership of the array, and resetting the array with a new allocation.

Usage
-----

To use ``array_ptr``, include the header file where it is defined, and instantiate 
an ``array_ptr`` object with the desired array size:

.. code-block:: cpp

   #include "memory.hpp"  // Adjust the include path as necessary

   cslt::array_ptr<int> myArray(10);  // Creates an array_ptr managing an array of 10 integers

Key Features and Methods
------------------------

- **Constructor**: Initializes a new ``array_ptr`` instance with a specified array size. Allocates memory for the array accordingly.

- **Destructor**: Automatically deallocates the managed array, ensuring no memory leaks.

- **Copy Constructor and Assignment**: Creates a deep copy of another ``array_ptr``, allocating a new array and copying the elements.

- **Move Constructor and Assignment**: Transfers ownership of the managed array from one ``array_ptr`` to another, leaving the source ``array_ptr`` empty.

- **realloc**: Resizes the managed array, potentially allocating a new array and copying elements from the old array.

- **reset**: Replaces the managed array with a new array, optionally of a different size.

- **release**: Releases ownership of the managed array, returning a pointer to the array and leaving the ``array_ptr`` empty.

- **operator[]**: Provides access to elements of the managed array, with bounds checking to ensure safe access.

- **operator bool**: Checks if the ``array_ptr`` is managing an array (non-empty).

Example
-------

The following example demonstrates basic usage of ``array_ptr``, including 
instantiation, element access, and resizing:

.. code-block:: cpp

   cslt::array_ptr<int> arr(5);  // Manages an array of 5 integers
   for (std::size_t i = 0; i < arr.size(); ++i) {
       arr[i] = static_cast<int>(i * 10);  // Access and assign values to array elements
   }

   arr.realloc(10);  // Resize the array to 10 elements

.. note:: The ``array_ptr`` class simplifies dynamic array management in C++, automating memory allocation and deallocation while providing safe access and modification mechanisms.

This documentation outlines the `array_ptr` class's purpose, usage, key methods, 
and provides an example to help users understand how to utilize the class in 
their projects. Make sure to adjust paths and namespaces according to your 
project's structure.

