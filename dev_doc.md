# Predicate Builder (class ``PredBuilder``)

This class is necessary to declare predicates, as the actual Predicates are going to be initialized only after a Grammar object has been made and its member function ``setGrammar`` has been called, because they need information regarding the object they will belong to, to be initialized.
    ``PredBuilder``s are a way to declare Predicates independently of the object they will belong to.
    As Predicates can be initialized providing either a value of type ``Src`` or ``std::function<bool(Src)>``, this class has 2 constructors. One for ``Src`` and one for ``std::function<bool(Src)>``.

## Members

- eval
- jumpSrc
- jumpPattern

# Pattern Builder (class ``Builder``)
