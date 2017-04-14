#include <stdio.h>
#include <iostream>
using namespace std;

int kapitalizacja(
    int a,
    int b,
    char k,
    float p,
    float belka
    )

{
    //Miesieczna stopa procentowa
    float pm = p/12.0;
    float lokata = (float)a;

    float pp;
    if(k=='m')
        pp = pm;
    else
        pp = p;

    float odsetki=0.0;
    float podatek=0.0;
    int counter=0;

    while(lokata<(float)b)
    {
        //naliczanie miesiecznej kapitalizacji
        odsetki = lokata*pp;
        podatek = odsetki*belka;
        lokata += odsetki - podatek;
        ++counter;
        cout << "Okres: " << counter << endl;
        cout << "Odsetki :" << odsetki << endl;
        cout << "Podatek :" << podatek << endl;
        cout << "Lokata :" << lokata << endl;
        cout << "==============================" << endl;

    }
return 0;
}

