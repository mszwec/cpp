#include <iostream>
#include <stdlib.h>
#include <cstddef>
#include <climits>
 
using namespace std;
 
int g=1; //globalna
int h=1; //globalna


struct S
{
    unsigned int a : 4,
        b : 5;
    char cc;
};


int main(int argc, char* argv[])
{
    int a=10; //lokalna
    int b=10; //lokalna
    int* c=new int(1);  //sterta
    int* d =new int(1); //sterta
    static int e=1; //statyczna
    static int f=1; //statyczna
 
    cout<<"stos a : "<<&a<<endl;
    cout<<"stos b : "<<&b<<endl;
    cout<<"sterta c : "<<&(*c)<<endl;
    cout<<"sterta d : "<<&(*d)<<endl;
    cout<<"statyczna e : "<<&e<<endl;
    cout<<"statyczna f : "<<&f<<endl;
    cout<<"globalna g : "<<&g<<endl;
    cout<<"globalna h : "<<&h<<endl;

    S s;
    s.b = 0b111;
    
    cout << sizeof(S)<<endl;

    unsigned long xx= ULONG_MAX;

    cout << xx << endl;

    cout << &s << endl;
    cout << offsetof(S, cc)<<endl;

    cout << ("PAUSE") << endl;


    int num=-128;


    for(int i=8*sizeof(int)-1; i>=0; i--)
    {
        int x = (num>>i) ;
        cout << (x & 1);
    }

    cout << endl;

    int aa= 0b11111111111111111111111101000000;
    int bb= 0b11111111111111111111111111111101;

    cout << aa <<endl;
    cout << bb <<endl;

    int cc=5;

    cout<< (  (cc<<6) + (cc<<1) + cc     ) << endl;
    
    return 0;
}
