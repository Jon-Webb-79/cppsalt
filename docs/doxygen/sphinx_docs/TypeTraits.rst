.. _type_traits:

***************
type_traits.hpp
***************

In order to explore the inner workings of the ``std`` namespace, this library
implemented a version of the `type_traits <https://cplusplus.com/reference/type_traits/>`_
header file in an identically named ``.hpp`` file titled ``type_traits.hpp``.
The reader can access the file below;

- :download:`type_traits.hpp <../../../cppsalt/include/type_traits.hpp>`

The following classes, function and constants are stored in the ``type_traits.hpp``
file, under the ``cslt`` namespace.

cslt::remove_reference
======================
.. cpp:struct:: template<class T> struct remove_reference

   The ``remove_reference`` template is a type trait that is used to obtain the 
   type referred to by a reference (either lvalue or rvalue reference). It 
   removes the reference part of a type, leaving just the original type.

   This template is useful in template metaprogramming and type manipulation, 
   where it is often necessary to work with raw types stripped of their reference 
   qualifiers.

   **Template Parameters**

   - **T** : The type from which the reference is to be removed. This can be any type, including fundamental types, user-defined types, and complex type constructions.

   **Member Types**

   - **type** : A member typedef `type` which is the type `T` without its reference part. If `T` is a reference type (either lvalue or rvalue), `type` is the referred type; otherwise, it is the same as `T`.

   **Usage Example**

   .. code-block:: cpp

      static_assert(std::is_same<remove_reference<int>::type, int>::value, "int");
      static_assert(std::is_same<remove_reference<int&>::type, int>::value, "int&");
      static_assert(std::is_same<remove_reference<int&&>::type, int>::value, "int&&");

   In these examples, `remove_reference` is applied to an int, an lvalue reference to an int, and an rvalue reference to an int. In all cases, the resulting `type` is the raw `int` type.

