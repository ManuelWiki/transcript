#include <iostream>
#include "../transcript"

using namespace std;
using namespace transcript;

int main(int argc, char** argv)
{
    // By now, you can initialize Grammars this way.
    // For a given specialization of Grammar, only arguments of type T for `group` are supported
    Grammar<char, char> cli;
    cli.setGrammar({
        cli.pattern(
            group('6', 'b', 'z', group('a')),
            [](char a){ return '7'; }
        ),
        cli.pattern(
            group('5', 'l'),
            [](char a){ return '8'; }
        ),
    });

    cout << cli.countPatterns();
}