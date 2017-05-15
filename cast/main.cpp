#include <iostream>

using namespace std;


class A
{
    private:
        int a;
      //  double b;

    public:
        A(){};
        A(int a): a(a){};
      //  A(double a): b(a){};

        ~A()
        {
          cout<<"dest"<<endl;  
        };
        /*
        operator int() const
        {
            return a;
        }
        */
};

int main()
{
//    A ob;
  A  ob = 2;

    /*
    A ob2;
    ob2 = 4.;
*/
    int x;
    x = ob;

    cout<<x<<endl;
}
