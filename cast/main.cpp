#include <iostream>

using namespace std;


class A
{
    public:
        int a;
        int *p;

        A(){ a=1; p=new int(11); };
        A(int a): a(a){};

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
            A * ret = new A();
            if(p && ret->p)
                *(ret->p) = *p;

            return ret;
        }

};

class B: public A
{
    public:
        int y;

        B(): A(){y=12;};

        ~B(){cout<<"dest B"<<endl;};

        virtual B* clone()
        {
            B * ret = new B();
            if(p && ret->p)
                *(ret->p) = *p;

            ret->y=y;

            return ret;
        }
};


int main()
{
    A *a = new B();
    cout << *(a->p)<<endl;

    A *b = a->clone();
    cout<<(dynamic_cast<B*>(b))->y << endl;
}
