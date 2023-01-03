// Spanish lesson: Prueba = Test :)

#include <iostream>
#include "../transcript"

using namespace std;

bool T(int a)
{
    return true;
}

void test(AssocFn<int, string> f)
{
    return;
}

int main(int argc, char** argv)
{
    Syntax<char, string> numToWord({
        Pattern(
            TokenList('a', 'b'),
            AssocFn([](char a){return string("doce");})
        )
    });
    
    AssocFn<char, string> a([](char a){ return string("h"); });
}