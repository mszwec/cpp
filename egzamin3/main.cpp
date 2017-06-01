#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv)
{
    int row=10;
    int colcount=10;

    int ** tab = new int*[row];

    for(int i=0; i<row; i++)
    {
        tab[i] = new int[colcount];
    }
    cout << sizeof(tab[0]) << endl;

    for(int i=0; i<row; i++)
        delete [] tab[i];

    delete [] tab;

    return 0;
}
