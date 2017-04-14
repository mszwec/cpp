#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    char c;
    int a,b = 0;
    cout << "Ile maja jablek RAZEM? ";
    cin >> a;
    cout << "O ile wiecej ma Kasia? ";
    cin >> b;

    int j,k=0;

    if((a+b)%2 != 0)
    {
        cout << "Impossible!" << endl;
        return 0;
    }


    j= (a-b)/2;
    k= j+b;

    cout << "Julka: " << j << endl;
    cout << "Kasia: " << k << endl;
    cout << "Razem: " << k+j << endl;
    return 0;
}
