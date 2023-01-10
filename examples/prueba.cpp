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
            TokenList('1', '2'),
            AssocFn<char, string>([](char a){ return string("doce"); })
        ),
        Pattern(
            TokenList('1', '4'),
            AssocFn<char, string>([](char a){return string("catorce");})
        ),
        Pattern(
            TokenList(TokenList('2', '1') | TokenList('2', '0')),
            AssocFn<char, string>([](char a){return string("veinte o veintiuno");})
        )
    });
    
    TokenList testOr(TokenList('2', '1') | TokenList('2', '0'));
    
    cout << "numToWord: " << numToWord.countPatterns() << "\n"
        << "testOr: " << testOr.size();
}