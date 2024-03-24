.. _util:

********
util.hpp
********

The ``cslt`` namespace implements an independend version of the 
`utilities.h <https://cplusplus.com/reference/utility/>`_ header file 
in the ``util.hpp`` file which can be accessed below.  This file provides
generic template functions and classes for important but unrelated functions 
that are useful in a wide variety of applications.

- :download:`util.hpp <../../../cppsalt/include/util.hpp>`

The attributes, functions and objects of the ``util.hpp`` header file are described 
below.

cslt::pair
==========
The ``pair`` template struct is implemented to pair values of like or different 
types.


Public Attributes 
-----------------

- first: The first data variable contained by ``pair``.
- second: The second data variable contained by ``pair``.

Constructors 
------------

.. function:: template <class A, class B> pair(const A &first_val, const B &second_val)

   Constructs the ``pair`` object with two values.

   :param A: The data type of ``first``.
   :param B: The data type of ``second``.
   :param const A &first_val: The first value to be stored in the struct.
   :param const B &second_val: The second value to be stored in the struct.

.. function:: pair(const pair &other)

   Copy constructor for the class.
   :param const pair &other: An object of type ``pair``.

Operator
--------

.. function:: pair pair& operator=(const pair &other)

   Overloads the ``=`` operator such that this class will become a deep copy of 
   the other object.  The data types must be the same between the two objects.

   :param const pair &other: An object of type ``pair``.

Methods 
-------

.. function:: void swap(pair &other)

   Swaps the data between this and other objects.  The data types must be the same
   between the two classes.

   :param pair &other: An object of type ``pair``.

Example 
-------

.. code-block:: cpp 

   #include "io.hpp"
   #include "util.hpp"

   int main() {
       cslt::pair<int, float> a(2, 32.1);
       cslt::cout << "First Value: " << a.first << cslt::endl;
       cslt::cout << "Second Value: " << a.second << cslt::endl;
       return 0;
   }

.. code-block:: bash 

   >> First Value: 2
   >> Second Value: 32.10000

cslt::make_pair
===============
The ``make_pair`` function provides a convenient way to instantiate a 
``pair`` object.

.. function:: pair <A, B> template<class A, class B> make_pair(const A &first_val, const B &second_val)

   Instantiates a ``pair`` object and returns it to the user.

   :param A: The data type associated with the first variable.
   :param B: The data type associated with the second variable.
   :param first_val: The first value to be stored by the struct.
   :param second_val: The second value to be stored by the struct.
   :returns pair: An object of type ``pair``.

Example 1 
---------
This example demonstrates how to use ``make_pair`` to instantiate an object, 
and the overloaded = operator.

.. code-block:: cpp 

   #include "io.hpp"
   #include "util.hpp"

   int main() {
       cslt::pair <float,int> planet, homeplanet;
       planet = cslt::make_pair(37.1f,6371);

       // If variable not defined, you can implement the auto keyword for data types.
       // auto new_planet = cslt::make_pair(12.1, 3);
       planet = cslt::make_pair(37.1f,6371);

       homeplanet = planet;

       cslt::cout << homeplanet.first << cslt::endl;
       cslt::cout << homeplanet.second << cslt::endl;
       return 0;
   }

.. code-block:: cpp 

   >> 37.10000
   >> 6371 

Example 2 
---------
This example demonstrates the use of the swap method

.. code-block:: cpp 

   #include "io.hpp"
   #include "util.hpp"

   int main() {
        cslt::pair<int, int> one = cslt::make_pair(1, 2);
        cslt::pair<int, int> two = cslt::make_pair(3, 4);
        one.swap(two);
        cslt::cout << "one.first: " << one.first << cslt::endl;
        cslt::cout << "one.second: " << one.second << cslt::endl;
        cslt::cout << "two.first: " << two.first << cslt::endl;
        cslt::cout << "two.second: " << two.second << cslt::endl;
       return 0;
   }

.. code-block:: cpp 

   >> one.first: 3
   >> one.second: 4
   >> two.first: 1
   >> two.second: 2

cslt::move
==========

.. cpp:function:: template<typename T> typename remove_reference<T>::type&& move(T&& arg)

   The ``move`` function template is used to cast its argument to an rvalue 
   reference. This enables the use of move semantics in C++, allowing for 
   efficient transfer of resources from one object to another.

   The function takes a universal reference (also known as a forwarding reference) 
   as its parameter, allowing it to accept both lvalue and rvalue references. 
   The return type is an rvalue reference to the type of `arg`, with any reference 
   qualifiers removed, facilitating the move operation.

   **Template Parameters**

   - **T** : The type of the argument. The actual type is deduced from the argument passed to the function.

   **Function Parameters**

   - **arg** : A universal reference to the object that is to be moved.

   **Return Value**

   - The function returns an rvalue reference to `arg` after casting.

   **Usage Example**

Example 
-------

.. code-block:: cpp

   #include "util.hpp"
   #include "io.hpp"

   class TestClass {
   public:
      int value = 5;
   }

   int main() {
        cslt::TestClass obj;
        cslt::cout << "Data in obj: " << obj.a << cslt::endl;
        cslt::TestClass moved_obj = cslt::move(obj);
        // At this point move_obj contains data and obj is in an unspecified state
        cslt::cout << "Data now in moved_obj: " << moved_obj.a << cslt::endl;
        return 0;
    }
    
.. code-block:: bash 

   >> Data in obj: 5 
   >> Data now in moved_obj: 5


In this example, an object of `TestClass` is moved using the `move` function. After the move, `obj` is in a moved-from state, and `moved_obj` has taken ownership of the resources originally held by `obj`.

.. note:: The actual moving of resources is performed by the move constructors and move assignment operators of the types involved. The `move` function only enables these operations by casting its argument to an rvalue reference.

cslt::move_if_noexcept 
======================
This function is a wrapper around the C++ Standard Library's ``std::move_if_noexcept``. 
It conditionally casts its argument to an rvalue reference, enabling move semantics 
if the move operation is declared ``noexcept``. Otherwise, it falls back to copy 
semantics to avoid throwing exceptions during move operations.

The purpose of this wrapper is to integrate ``std::move_if_noexcept`` seamlessly 
within the ``cslt`` namespace, allowing users of the library to utilize 
standard move semantics optimizations while maintaining consistent namespace usage.

.. cpp:function:: template<typename T> constexpr auto cslt::move_if_noexcept(T& x) noexcept


Template Parameters
-------------------

- **T**: The type of the argument to be conditionally moved.

Parameters
----------

- **x**: A reference to the object of type ``T`` that will be moved or copied, depending on its noexcept guarantee.

Return Value 
------------

- Returns an rvalue reference to ``T`` if the move operation of ``T`` is noexcept; otherwise, returns ``x`` as is, promoting copy semantics.

Example 
-------
In this example, ``cslt::move_if_noexcept`` is used to conditionally move 
``myPair``. The actual operation (move or copy) depends on the noexcept guarantee 
of the move constructor for ``cslt::pair<int, std::string>``.

.. code-block:: cpp

      cslt::pair<int, std::string> myPair(42, "example");
      auto movedPair = cslt::move_if_noexcept(myPair);
   
      // Use movedPair as needed...

cslt::forward
=============
This function is a custom implementation of the C++ Standard Library's ``std::forward``. 
It is designed to perfectly forward a function argument to another function, preserving 
the argument's value category (lvalue or rvalue). This enables the efficient use of resources 
and optimizations, such as move semantics, without inadvertently altering the original 
semantic intentions of the passed arguments.

The ``cslt::forward`` function is pivotal in template programming, especially when creating 
generic functions or classes that need to forward arguments to constructors or other functions 
with perfect fidelity. It is a cornerstone of perfect forwarding, allowing developers to 
write more generic, efficient, and safe code by ensuring that resources are moved only when 
it is safe to do so.

.. cpp:function:: template<typename T> T&& cslt::forward(typename std::remove_reference<T>::type& arg) noexcept

   .. cpp:function:: template<typename T> T&& cslt::forward(typename std::remove_reference<T>::type&& arg) noexcept


Template Parameters
-------------------

- **T**: The type of the argument to be forwarded. This type includes both lvalue 
  and rvalue reference qualifiers to enable perfect forwarding.

Parameters
----------

- **arg**: A reference to the object of type ``T``. Depending on the invocation context, 
  ``arg`` can be an lvalue reference (if an lvalue is passed) or an rvalue reference 
  (if an rvalue is passed), enabling the function to forward it appropriately.

Return Value 
------------

- Returns the argument cast to an rvalue reference of type ``T`` if called with an rvalue, 
  otherwise returns the argument itself, preserving its lvalue reference category. This 
  allows the caller function or constructor to utilize the argument as intended, with 
  move semantics applied only where permissible.

Example 
-------
In this example, ``cslt::forward`` is used to forward arguments to a constructor of 
``MyClass``. This demonstrates how ``cslt::forward`` enables perfect forwarding, allowing 
the constructor to utilize move semantics when possible.

.. code-block:: cpp

      template<typename... Args>
      MyClass createMyClass(Args&&... args) {
          return MyClass(cslt::forward<Args>(args)...);
      }

      MyClass myObj = createMyClass(10, "example");

In this usage, arguments passed to ``createMyClass`` are perfectly forwarded to 
``MyClass``'s constructor, preserving their original value categories (lvalue or rvalue).


