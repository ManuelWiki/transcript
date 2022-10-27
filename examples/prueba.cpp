#include <iostream>
#include "../transcript"

using namespace std;

bool T(int a)
{
    return true;
}

int main(int argc, char** argv)
{
    Builder<int> Pattern(1, 1, 3, [](int a){return true;});
    PredBuilder p = 1;

    cout << Pattern.countPreds();
}