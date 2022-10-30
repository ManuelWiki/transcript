# Predicate Builder (class ``PredBuilder<class T>``)

## Type Aliases
- Pred = std::function< T>

This class is necessary to declare predicates, as the actual Predicates are going to be initialized only after a Grammar object has been made and its member function ``setGrammar`` has been called, because they need information regarding the object they will belong to, to be initialized.
    ``PredBuilder``s are a way to declare Predicates independently of the object they will belong to.
    As Predicates can be initialized providing either a value of type ``Src`` or ``std::function<bool(Src)>``, this class has 2 constructors. One for ``Src`` and one for ``std::function<bool(Src)>``.

## Data Members

- **Pred eval:** 
- **unsigned jumpSrc:**
- **unsigned jumpPattern:**

## Methods

- **constructor (2 overloads):**
    - **(T, unsigned, unsigned):** Constructor overload for a given T value. Useful for passing literals
    - **(Pred< T>, unsigned, unsigned):** Constructor overload for a given ``std::function<T >`` value. Helpful to pass conditions that the current value should meet
        - Both overloads can receive 2 extra arguments. One for the number of positions the user program should move on the src, and the other for the number of positions it should move in the pattern

# Pattern Builder (class ``Builder<class Src>``)

## Data Members

- **preds:** a vector of the Predicates the pattern contains 

## Methods

- **append (private, 4 overloads):** Receives a variable number of arguments that are allowed to be of type ``Src`` or ``std::function(bool<Src>)`` (and proximately ``Builder<Src>``, too) and constructs a PredBuilder from each argument and then appends it to the ``preds`` member of the Builder being constructed
    - **(Src first, Args... rest)**

- **constructor (2 overloads):**
    - f


