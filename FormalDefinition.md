# Formal Definition

This is the formal definition of the library, which will be used both as a guide for its development and as a provitional documentation. 

***

## Main types:

The library is based on the following template datatypes. For a given datatype ``T``, the library provides: 
The expression "Predicate of type _SomeType_" refers to the specialization of Predicate for ``T = SomeType``. Same for Pattern, AssocFunction and Language Specification

- **Predicate:** A function of which return type is ``bool`` and has 1 parameter of type ``std::vector<T>`` or ``T``. Also, a Predicate can be classified as:
    - N
    - N or M
    - N to M
    - N or More 
    - (Being N and M positive integer numbers or 0)
- **Pattern:** A vector of Predicates of the same type, which may have different classifications, and an AssocFunction associated to them. A Pattern of type _SomeType_ has Predicates of type _SomeType_ and its AssocFunction is of type _SomeType_ too
    - **AssocFunction:** A ``void`` function that has a parameter of type ``std::vector<T>``.
- **Language Specification:** A set of Patterns of the same type

## Functionality:

The library provides the following functionalities to the user:

- **Declare Language Specifications**
- **Define Patterns** inside of each language specification by providing:
    - A set of predicates of the same type as the Language Specification
    - A function or lambda expression of type AssocFunction for the pattern's associated pointer to point to
- **Define Predicates** inside of each pattern by providing
    - The desired classification. If not given, the Predicate would be classified as 1 by default
    - Either a Predicate of the same type as the Language Specification 
    - or a value of the same type as the Language Specification, in which case the Predicate would return ``true`` if the argument given when called is equal to that value, and ``false`` otherwise 

**Note:** There are no plans to support removing or modifying Patterns or Predicates at runtime. This may change if some evidence that it is a commonly needed or useful feauture is reported on the Issues section

- **Scan Containers:** Scanning a container is the action of iterating through its members and, every time there's a sequence of consecutive values for which all Predicates of some Pattern return ``true``, executing such Pattern's associated function
- **Translate Containers:** Scanning a container, but everytime an associated function is called, its return value is stored in another container specified by the user