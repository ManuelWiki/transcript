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

# Intended functionality

You can initialize a ``Grammar`` object giving the types ``char`` and ``int`` as template arguments and then passing a set of Builder-AssocFunction pairs as arguments for the constructor as follows:
 
    Grammar<char, int> numbers(
        {
            Builder("one"),
            1
        },
        {
            Builder("two"),
            2
        },
        {
            Builder("three"),
            3
        }
    );

Calling its ``transcript`` method giving a string, a vector or an array of ``char``s (_a_), and an empty array or vector of ``int``s (_b_) as arguments will append a ``1`` for every time the string 'one' occurs, a ``2`` for every time the string 'two' occurs and a ``3`` for every time the string 'three' occurs, into _b_. Just like this:

    string s("three two onetwo three");
    std::vector v;
    numbers.transcript(words, nums);

    // Now v contains {3, 2, 1, 2, 3}

Note that transcript just matches the sequences of characters in the string to the ones provided as patterns (We call a pattern every string we provide to the constructor associetaed to a function or value). For that reason, ``transcript`` stores a ``1`` and a ``2`` for the 'onetwo' string, even if they're not separated.
``transcript`` ignores all information that cannot be matched, such as spaces
