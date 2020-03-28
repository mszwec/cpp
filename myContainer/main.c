#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <bitset>

#include "MyContainer.h"

using namespace std;


int main(int argc, char** argv)
{
    stack <int, MyContainer<int> > stos;
    stos.push(12);
    stos.push(13);
    stos.push(14);
    cout<< std::boolalpha << stos.empty()<<endl;
    cout<< stos.size() <<endl;
    stos.pop();
    stos.pop();
    stos.pop();
    cout<<stos.size()<<endl;
    stos.push(1001);
    stos.push(1002);
    stos.push(1003);
    stos.push(1004);
    stos.push(1005);
    stos.pop();
    stos.push(1005);
    stos.push(1006);
    cout<<stos.top()<<endl;
    cout<<stos.size()<<endl;
    
    MyContainer<int> mc;
    mc.push_back(1);
    mc.push_back(2);
    mc.push_back(3);

    mc.pop_back();

    mc.push_back(4);
    mc.push_back(5);

    mc.pop_back();
    mc.pop_back();

    mc.push_back(55);

    cout<<mc.back()<<endl;
    cout<<mc[2]<<endl;

    MyContainer<int>::iterator i=mc.begin();

    for(;i!=mc.end();i.next())
        cout<<*i<<endl;

    return 0;
}


