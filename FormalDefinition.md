# Formal Definition

This is the formal definition of the library, which will be used both as a guide for its development and as a provitional documentation. 

***

## Main types:

After the user defines provides a type a type ``T`` and a type ``Target``, the library provides the following datatypes:

- **Predicate:** A function of which return type is ``bool`` and has 1 parameter of type ``std::vector<T>`` or ``T``, an ``unsigned`` N, an ``unsigned`` M, and a label called 'classification' that can be either:
    - ``N``
    - ``N or M``
    - ``N to M``
    - ``N or more``
- **Pattern:** A vector of Predicates and an AssocFunction associated to them.
    - **AssocFunction:** A function that has a parameter of type ``std::vector<T>`` or ``T`` and return type ``Target``.
- **Grammar:** A set of Patterns

## Functionality:

The library provides the following functionalities to the user:

- **Define Grammars** by providing
    - The types to assign ``T`` and ``Target`` to
    - A set of Patterns
- **Define Patterns** inside of each Grammar by providing:
    - A set of predicates of the same type as the Grammar
        - If the Pattern belongs to a Grammar for which ``T = char`` or ``T = wchar``, it can (optionally) be defined providing a string with regex formatting. In that case, a predicate will be defined for every atom of the regular expression
    - An AssocFunction
- **Define Predicates** inside of each pattern by providing
    - The desired classification and values of N and M.
        - If not given, the Predicate will be classified as ``N`` and N and M will be set to ``1``, by default
        - If the provided classification is ``N`` or ``N or More``, only N needs to be provided
        - Else, Both N and M must be provided, and M must be greater than N
    - Either a callable object of which return type is ``bool`` and accepts 1 argument of type ``T``
        - or a value of type ``T``, which would be the same as providing a callable object that returns ``true`` if its parameter is equal to that value, and ``false`` otherwise
- **Define AssocFunctions:** by providing a callable object of which return type is ``Target`` and accepts an argument of type ``T``   

**Note:** There are no plans to support removing or modifying Patterns or Predicates at runtime. This may change if some evidence that it is a commonly needed or a useful feauture is reported on the Issues section

- **Translate Containers:** Translating a container ``A`` is the action of iterating through its members and, every time a match happens, executing the associated function of the matched pattern and storing its return value in a container ``B``.
    - **Match:** A match ocurres when, given a sequence of values ``S`` contained in ``A``, the following is true:

            for(auto v = S.begin(); it != S.end(); v++) {
                for(auto p = P.begin(); p != P.end(); p++) {
                    for(unsigned i = 1; i != p.M; i++, v++) {
                        if (!p(v)) {
                            if (p.isN() and i != p.N) return false;
                            if (p.isNtoM and i < p.N or i > p.M) return false;
                            if (p.isNorM and i != N and i != M) return false;
                            if (p.isNorMore and i < N)
                        }
                    }
                }
            }

- **Scan Containers:** Translating a container without storing the return values of the AssocFunctions called. Only 1 container needs to be specified. In Grammars where ``Target = void`` no return values are stored and hence only scanning can be performed 
        