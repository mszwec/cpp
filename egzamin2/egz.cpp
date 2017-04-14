#include <iostream>

using namespace std;

class A
{
    public:
        int cos;
        int sin;
        A()
        {
            cout<< " A";
            cos=1;
            sin=1;
        }
        A(int x):cos(1), sin(x)
        {
            cout<< " A";
        }
        ~A()
        {
            cout << " a";
        }
        void printCos()
        {
            cout<< cos << " ";
        }
        void printSin()
        {
            cout<< sin << " ";
        }
};
class B: public A
{
    public:
        int cos;
        B(): A(2) 
        {
            cout<<" B";
            cos=2;
        }
        ~B()
        {
            cout<<" b";
        }
        virtual void printCos()
        {
            cout<< cos << " ";
        }
        virtual void printSin()
        {
            cout<< sin << " ";
        }
};

class C: public  B
{
    public:
        int cos;
        C()
        {
            cout<< " C";
            cos=3;
        }
        ~C()
        {
            cout<<" c";
        }
        
        void printCos()
        {
            cout<< cos << " ";
        }
        void printSin(int x)
        {
            cout<< sin+x << " ";
        }
};

int main()
{
	cout << " " << endl;
	C oC; B oB; A oA;
	cout << " \n \n ";
	A * wskA; B * wskB;
	
	wskA = &oA;
	wskA->printCos();
	
	wskA = &oB; wskB = &oB;
	wskA->printCos();
	wskB->printCos();
	
	wskA = &oC; wskB = &oC;
	wskA->printCos();
	wskB->printCos();

    wskB->printSin();

    cout<<"\nzad11:"<<endl;
	wskB->printCos();
    wskB->B::printCos();
	
	cout << "\n" << endl;
	
	return 0;
}

