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

.. function:: explicit unique_ptr(T* p)

   Initializes a new ``unique_ptr`` instance, optionally taking a pointer to a dynamically allocated object. ``unique_ptr`` takes full ownership of this object, managing its lifecycle automatically.

   :param T* p: A pointer to a dynamically allocated object of type ``T``, or ``nullptr`` to indicate that the ``unique_ptr`` does not initially manage any object.

.. function:: unique_ptr(std::nullptr_t)

   Initializes a new ``unique_ptr`` instance that does not manage any object initially.

   :param std::nullptr_t: A ``nullptr`` indicating that the ``unique_ptr`` does not manage any object.

.. function:: ~unique_ptr()

   Automatically deletes the managed object when the ``unique_ptr`` goes out of scope, ensuring proper resource cleanup.

.. function:: T& operator*() const

   Provides access to the underlying object.

   :return: A reference to the managed object of type ``T``.

.. function:: T* operator->() const

   Provides access to the member functions of the managed object, behaving as if the ``unique_ptr`` was a pointer to ``T``.

   :return: A pointer to the managed object of type ``T``.

.. function:: const T* get() const

   Returns a pointer to the managed object, or ``nullptr`` if no object is being managed.

   :return: A pointer to the managed object of type ``T``, or ``nullptr`` if no object is being managed.

.. function:: T* release()

   Releases ownership of the managed object and returns a pointer to it. The ``unique_ptr`` will no longer manage the object and will not delete it when destroyed.

   :return: A pointer to the previously managed object of type ``T``, or ``nullptr`` if there was no managed object.

.. function:: void reset(T* p = nullptr)

   Deletes the currently managed object, if any, and takes ownership of a new object.

   :param T* p: A pointer to a new dynamically allocated object of type ``T``, or ``nullptr`` to make the ``unique_ptr`` not manage any object.

.. function:: unique_ptr(unique_ptr&& move) noexcept

   Move constructor that transfers ownership of the managed object from another ``unique_ptr``.

   :param unique_ptr&& move: An rvalue reference to another ``unique_ptr`` object of the same type.

.. function:: unique_ptr& operator=(unique_ptr&& move) noexcept

   Move assignment operator that transfers ownership of the managed object from another ``unique_ptr`` and deletes the currently managed object, if any.

   :param unique_ptr&& move: An rvalue reference to another ``unique_ptr`` object of the same type.
   :return: A reference to *this ``unique_ptr`` object.

.. function:: explicit operator bool() const

   Checks if the ``unique_ptr`` currently manages an object.

   :return: ``true`` if the ``unique_ptr`` manages an object, otherwise ``false``.


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

.. function:: template <typename T, typename... Args> unique_ptr<T> make_unique(Args&&... args)

   Creates a dynamically allocated object of type ``T``, wrapping it in a ``unique_ptr``. This function template simplifies the process of creating a ``unique_ptr``, ensuring safe, exception-friendly allocation and initialization of resources.

   :tparam T: The type of the object to be created and managed by the returned ``unique_ptr``.
   :tparam Args: A variadic template parameter pack representing the types of arguments to be forwarded to the constructor of ``T``.
   
   :param Args&&... args: The actual arguments to be forwarded to the constructor of ``T``, preserving their lvalue or rvalue nature through perfect forwarding.

   :return: A ``cslt::unique_ptr<T>`` managing the newly created object of type ``T``. This ``unique_ptr`` takes ownership of the object, ensuring its proper deletion when the ``unique_ptr`` goes out of scope or is otherwise disposed of.

Example
-------

The ``make_unique`` function can be used to instantiate objects of any class that requires arguments for its constructor, automatically managing the object's lifetime through a ``unique_ptr``. Here is an example of its use:

.. code-block:: cpp

   struct Example {
       Example(int x, const std::string& y) : num(x), str(y) {}
       int num;
       std::string str;
   };

   auto examplePtr = cslt::make_unique<Example>(42, "Hello World");

   // examplePtr is a unique_ptr<Example> that owns an Example object initialized with 42 and "Hello World".

.. note:: The use of ``make_unique`` is highly recommended for safely creating dynamically allocated objects in modern C++. It encapsulates the best practices of resource management, combining safe allocation with automatic resource cleanup, thereby reducing the risk of memory leaks and pointer-related errors.


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

.. function:: explicit shared_ptr(T* p = nullptr)

   Initializes a new ``shared_ptr`` instance, taking ownership of the dynamically allocated object pointed to by ``p``. If ``p`` is ``nullptr``, the ``shared_ptr`` is initialized to manage no object.

   :param T* p: A pointer to a dynamically allocated object of type ``T``, or ``nullptr``.

.. function:: shared_ptr(std::nullptr_t)

   Initializes a new ``shared_ptr`` instance that manages no object.

   :param std::nullptr_t: A ``nullptr`` indicating that the ``shared_ptr`` does not manage any object.

.. function:: ~shared_ptr()

   The destructor that automatically deletes the managed object if this ``shared_ptr`` is the last one owning it.

.. function:: shared_ptr(const shared_ptr& other)

   Copy constructor that creates a new ``shared_ptr`` instance which shares ownership of the object managed by ``other``.

   :param const shared_ptr& other: Another ``shared_ptr`` instance to share the ownership with.

.. function:: shared_ptr& operator=(const shared_ptr& other)

   Copy assignment operator that makes this ``shared_ptr`` share ownership of the object managed by ``other``, releasing any object previously managed by this instance.

   :param const shared_ptr& other: Another ``shared_ptr`` instance to share the ownership with.
   :return: A reference to this ``shared_ptr`` instance.

.. function:: shared_ptr(shared_ptr&& other) noexcept

   Move constructor that transfers ownership of the managed object from ``other`` to this instance. ``other`` is left managing no object.

   :param shared_ptr&& other: An rvalue reference to another ``shared_ptr`` instance.
   
.. function:: shared_ptr& operator=(shared_ptr&& other) noexcept

   Move assignment operator that transfers ownership of the managed object from ``other`` to this instance, releasing any object previously managed by this instance. ``other`` is left managing no object.

   :param shared_ptr&& other: An rvalue reference to another ``shared_ptr`` instance.
   :return: A reference to this ``shared_ptr`` instance.

.. function:: void reset(T* p = nullptr)

   Replaces the managed object with another dynamically allocated object ``p``, or resets this ``shared_ptr`` to manage no object if ``p`` is ``nullptr``.

   :param T* p: A pointer to a new dynamically allocated object of type ``T``, or ``nullptr``.

.. function:: void swap(shared_ptr& other) noexcept

   Swaps the managed object and the reference counter with another ``shared_ptr`` instance.

   :param shared_ptr& other: Another ``shared_ptr`` instance to swap with.

.. function:: T& operator*() const

   Provides dereferenced access to the managed object.

   :return: A reference to the managed object of type ``T``.

.. function:: T* operator->() const

   Provides pointer-like access to the managed object, allowing access to its members.

   :return: A pointer to the managed object of type ``T``.

.. function:: const T* get() const

   Returns a pointer to the managed object, or ``nullptr`` if no object is being managed.

   :return: A pointer to the managed object of type ``T``, or ``nullptr``.

.. function:: explicit operator bool() const

   Checks whether this ``shared_ptr`` instance is managing an object.

   :return: ``true`` if this ``shared_ptr`` is managing an object, otherwise ``false``.


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

.. function:: template <typename T, typename... Args> cslt::shared_ptr<T> make_shared(Args&&... args)

   Creates a dynamically allocated object of type ``T``, managed by a ``shared_ptr``, while efficiently combining the allocation of the object and its control block into a single memory allocation. This utility function is designed to simplify the creation of shared objects and optimize memory usage.

   :tparam T: The type of the object to be managed by the returned ``shared_ptr``.
   :tparam Args: A variadic template parameter pack representing the types of arguments to be forwarded to the constructor of ``T``.

   :param Args&&... args: The arguments to be forwarded to the constructor of ``T``, preserving their lvalue or rvalue status through perfect forwarding.

   :return: A ``cslt::shared_ptr<T>`` managing a new instance of ``T`` initialized with the provided arguments.

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

.. function:: explicit array_ptr(std::size_t buff = 0)

   Initializes a new ``array_ptr`` instance, optionally specifying the size of the array to allocate. This constructor allocates memory for an array of type ``T`` with ``buff`` elements.

   :param std::size_t buff: The size of the array to allocate. Defaults to 0, indicating no allocation.

.. function:: array_ptr(std::nullptr_t)

   Initializes a new ``array_ptr`` instance that does not manage any array, effectively pointing to ``nullptr``.

   :param std::nullptr_t: A ``nullptr`` indicating that the ``array_ptr`` does not manage any array.

.. function:: ~array_ptr()

   The destructor that automatically deallocates the managed array, ensuring proper resource cleanup.

.. function:: array_ptr(const array_ptr& other)

   Copy constructor that creates a new ``array_ptr`` instance which makes a deep copy of the array managed by ``other``, including allocating a new array and copying all elements.

   :param const array_ptr& other: Another ``array_ptr`` instance to copy from.

.. function:: array_ptr& operator=(const array_ptr& other)

   Copy assignment operator that assigns the current ``array_ptr`` instance to manage a deep copy of the array managed by ``other``, including allocating a new array and copying all elements. Any previously managed array is properly deallocated.

   :param const array_ptr& other: Another ``array_ptr`` instance to assign from.
   :return: A reference to this ``array_ptr`` instance.

.. function:: array_ptr(array_ptr&& other) noexcept

   Move constructor that transfers ownership of the managed array from ``other`` to this instance. ``other`` is left in a valid but empty state.

   :param array_ptr&& other: An rvalue reference to another ``array_ptr`` instance.

.. function:: array_ptr& operator=(array_ptr&& other) noexcept

   Move assignment operator that transfers ownership of the managed array from ``other`` to this instance, properly deallocating any previously managed array. ``other`` is left in a valid but empty state.

   :param array_ptr&& other: An rvalue reference to another ``array_ptr`` instance.
   :return: A reference to this ``array_ptr`` instance.

.. function:: void realloc(std::size_t buff, bool reduce_size = true)

   Resizes the managed array to a new size, potentially allocating a new array and copying elements from the old array. Can optionally prevent reducing the array size based on the ``reduce_size`` parameter.

   :param std::size_t buff: The new size for the array.
   :param bool reduce_size: Whether the function is allowed to reduce the array's size (default is true).

.. function:: void reset(T* p = nullptr, std::size_t newLen = 0)

   Replaces the managed array with a new array specified by ``p``, optionally of a different size specified by ``newLen``. The previously managed array is properly deallocated.

   :param T* p: A pointer to a new array of type ``T``, or ``nullptr``.
   :param std::size_t newLen: The size of the new array. Ignored if ``p`` is ``nullptr``.

.. function:: T* release()

   Releases ownership of the managed array and returns a pointer to it. The ``array_ptr`` instance is reset to manage no array.

   :return: A pointer to the previously managed array, or ``nullptr`` if no array was managed.

.. function:: T& operator[](std::size_t index) const

   Provides access to the element at the specified index in the managed array, with bounds checking.

   :param std::size_t index: The index of the element to access.
   :return: A reference to the element at the specified index.

.. function:: explicit operator bool() const

   Checks if the ``array_ptr`` is currently managing an array.

   :return: ``true`` if the ``array_ptr`` manages an array, otherwise ``false``.

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

