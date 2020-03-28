#include <iostream>
#include <stdlib.h>
#include <cstddef>
#include <climits>
#include <bitset>

using namespace std;

int g=1; //globalna
int h=1; //globalna


struct S
{
  unsigned int a : 8,
               b : 3;
  char cc;
};

void multiplyByBitShift()
{
  int cc=5;
  cout << "cc: " << cc << endl;
  cout << "cc: " << bitset<32>(cc) << endl;
  int cc2 = (cc<<3);// + (cc<<1) + cc;
  cout << "cc2: " << cc2 << endl;
  cout << "cc2: " << bitset<32>(cc2) << endl;
}

template <class T> void printAsBinary(T num)
{
  static_assert(is_integral<T>::value, "Must be integral!");

  cout << to_string(num) << ": 0b";
  for(int i=8*sizeof(T)-1; i>=0; --i)
  {
    T x = (num>>i) ;
    cout << (x & 1);
  }
  cout << endl;

  //easier:
  cout << to_string(num) << ": 0b" << std::bitset<8*sizeof(T)>(num) << endl;		    
}

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
  s.b = 0b011;

  cout << "sizeof(S): " << sizeof(S) << endl;
  cout << "sizeof(S s): " << sizeof(s) << endl;
  cout << "sizeof(int): " << sizeof(int) << endl;
  int intVar = 0;
  cout << "sizeof(intVar): " << sizeof(intVar) << endl;

  unsigned long xx= ULONG_MAX;

  cout << "xx(ulong max): " << xx << endl;

  cout << "addr of s: " << &s << endl;
  cout << "offsetof S.cc: " << offsetof(S, cc)<<endl;

  cout << ("PAUSE") << endl;


  printAsBinary(-129);

  int aa= 0b11111111111111111111111101000000;
  int bb= 0b11111111111111111111111111111101;
  int dd= 0b01111111111111111111111111111111;

  cout << "s.b = " << s.b << endl;
  cout << "binary int: " << aa <<endl;
  cout << "binary int: " << bb <<endl;
  cout << "binary int: " << dd <<endl;

  multiplyByBitShift();

  return 0;
}
