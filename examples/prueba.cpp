// Spanish lesson: Prueba = Test :)

#include <iostream>
#include "../transcript"

using namespace std;

bool T(int a)
{
    return true;
}

int main(int argc, char** argv)
{
    Syntax<int, string> numsToWords({
        {
            Pattern<int>(1, 2),
            AssocFn<int, string>([](int a){ return "doce"; })
        },
        {
            Pattern<int>(1, 3),
            AssocFn<int, string>([](int a){ return "trece"; })
        }
    });

    cout << numsToWords.countPatterns();
}