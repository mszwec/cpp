#include <iostream>

using namespace std;


class A
{
  public:
    int a       { 1 };
    int *valPtr { new int (11) };

    A() = default;

    A(int input)
      : a(input)
    {};

    virtual ~A()
    {
      cout<<"dest A"<<endl;  
    };

    operator int() const
    {
      return a;
    }

    virtual A* clone()
    {
      A* ret = new A();

      if(valPtr && ret->valPtr)
        *(ret->valPtr) = *valPtr;

      return ret;
    }

};

class B: public A
{
  public:
    int y { 12 };

    B() = default;

    B(int in)
    : y(in)
    {}

    ~B()
    {
      cout<<"dest B"<<endl;
    }

    virtual B* clone()
    {
      B * ret = new B();
      if(valPtr && ret->valPtr)
        *(ret->valPtr) = *valPtr;

      ret->y=y;

      return ret;
    }
};


int main()
{
  A* a = new B(69);
  cout << *(a->valPtr) << endl;

  A* b = a->clone();
  // IF above clone() was a B::clone() then b->y should be 69;
  cout << (dynamic_cast<B*>(b))->y << endl;
  cout << (static_cast<B*>(b))->y << endl;

  A& refC = *(a->clone());
  cout << (static_cast<B&>(refC)).y << endl;

}


