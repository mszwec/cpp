#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>


using namespace std;
int y;
class MyClass
{
//    public:
        int value;

/*        MyClass(): value(0)
        {
            cout<<"MyClass ctor"<<endl;
        }

        ~MyClass()
        {
            cout<<"destoy"<<endl;
        }
*/};

void fun()
{
    int i;
    int j=1;
    static int x=2;
    char c[5] = {'5'};
    char str[5] = "abcd";
    char* str2 = (char*) malloc (sizeof(char)*5);
    int* p_j = &j;
    int& r_j = j;

    MyClass obj;
    MyClass* obj2 = new MyClass();

    cout<< y   <<endl;
    cout<< p_j <<endl;
    cout<< r_j <<endl;
    cout<< x   <<endl;
    cout<< c   <<endl;
    cout<< str <<endl;
    cout<< str+2 <<endl;
    cout<< str2 <<endl;


    cout << "===c5===" << endl;
    for(int ii=0; ii<5; ii++)
    {
        cout << c+ii << endl;
    }
}

class A
{
    public:
        int cos;
        A()
        {
            cout<< " A";
            cos=1;
        }
        ~A()
        {
            cout << " a";
        }
        void printcos()
        {
            cout<< cos << " ";
        }
};
class B: public A
{
    public:
        int cos;
        B()
        {
            cout<<" B";
            cos=2;
        }
        ~B()
        {
            cout<<" b";
        }
        void virtual printcos()
        {
            cout<< cos << " ";
        }
};

class C: public  B
{
    public:
        int cos;
        string mess;
        C()
        {
            cout<< " C";
            cos=3;
        }
        ~C()
        {
            cout<<" c "<<mess<<endl;
        }
        C(const C& c)
        {
            cout<<"\n copy constr....\n";    
        }
        void printcos()
        {
            cout<< cos << " ";
        }
};

int f(int a)
{
    static int i=0;
    static int b=a;
    i++;
    if(i>66)
        return a;
    else
        return f(a+b);
}

char* encode(char* s)
{
    char prev;
    prev=0;
    int count=0;

    char* buf = (char*)calloc(100, sizeof(char));
    buf[0]=0;
    char buf2[100] = {0};


    for(int i=0; s[i]!=0; i++)
    {
        if(prev==0 || prev == s[i])
        {
            count++;
        }else
        {
            sprintf(buf2, "%d,%c,", count, prev);
            strcat(buf, buf2);
            count=1;
        }
        prev  = s[i];
    
    }
    if(count>0 && prev)
    {
        sprintf(buf2, "%d,%c,", count, prev);
        strcat(buf, buf2);
    }


    return buf;
}

void foo(C c)
{
    cout<<"\nfoo "<<endl;
    c.mess="foo";
}

void foo1(int)
{
    cout<<"\nfoo1\n";
}
void foo1(char*)
{
    cout<<"\nfoo char\n";
}

/*void doo(int i)
{
cout << "int"<<endl;
}*/

void doo(int &i)
{
cout << "amp"<<endl;
i++;
}

void tab( int t[] )
{

    cout << "\n\n ====TAB[[[[\n"<<endl;
    cout << sizeof(t) << endl;
    cout << "\n\n ]]]]TAB====\n"<<endl;
}

int main(int argc, char** argv)
{

    cout << "" << endl;
    C oC;
    B oB;
    A oA;
    cout << " \n \n ";
    A * wskA;
    B * wskB;

    cout<<"Start\n";
    C oC2 = C();
    cout<<"End\n";
    
    wskA = &oA;
    wskA->printcos();
    wskA= &oB;
    wskB= &oB;
    wskA->printcos();
    wskB->printcos();
    wskA = &oC; wskB= &oC;
    wskA->printcos();
    wskB->printcos();
    cout<<" \n"<<endl;

    cout<< f(1) << endl;
    char str[]="aaabbbccdd";
    char* en = encode(str);
    cout << en <<endl;
    free(en);

    vector<C> vc;
    vc.reserve(3);
    vc.push_back(oC);
    vc.push_back(oC);
    vc.push_back(oC);

    cout<<"\nfor_each\n";
    for_each(vc.begin(), vc.end(), foo);

    int x=int(5);
    cout<<"\n "<<x<<endl;
    foo1((char*)0);

    int aa=0b101;

    doo(aa);


    cout<<"\n\n\n\n "<<aa<<endl;
    cout<<"\n\n\n\n FUN:"<<endl;
    fun();
    cout<<"\n\n\n\n FUN END"<<endl;

    char *ptr = {"abc"};
    char ptr2[] = {"abce"};
    int liczba[10] = {3,4,5};
    int * pliczba = new int[10];
    cout<< sizeof(ptr) << endl;
    cout<< sizeof(ptr2) << endl;
    cout<< sizeof(liczba) << endl;
    cout<< sizeof(pliczba) << endl;
    cout<< sizeof(char) << endl;
    cout<< sizeof(char*) << endl;

    tab(liczba);

    return 0;
}
struct a
{
    int c;
    int e;
};
struct a b = {
    c: 1,
    e: 2
};

