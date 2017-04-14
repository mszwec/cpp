#include <stdio.h>
#include <iostream>

using namespace std;

extern int kapitalizacja(
    int a,
    int b,
    char k,
    float p,
    float belka
    );


int main(int argc, char** argv)
{
    int a,b = 0;
    char k = 0;
    float p = 0.0;
    float belka = 0.19;

    cout << "Kapital START? ";
    cin >> a;
    cout << "Kapital END? ";
    cin >> b;
    cout << "Roczna stopa procentowa? ";
    cin >> p;
    cout << "Kapitalizacja? (m,r)";
    cin >> k;


kapitalizacja(
    a,
    b,
    k,
    p,
    belka);
 




    return 0;
}
