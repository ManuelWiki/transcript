#include <iostream>
#include "../transcript"

using namespace std;

bool T(int a)
{
    return true;
}

int main(int argc, char** argv)
{
    Pattern<int> pattern(1, Pattern<int>(1, 2), 3, [](int a){return true;});

    cout << pattern.countPreds();
}