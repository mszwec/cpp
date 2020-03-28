#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <bitset>

#include "../myContainer/MyContainer.h"

using namespace std;

class MemoryManager
{
  void          *FreeStoreHead  { nullptr };
  unsigned long capacity        { 64000 };

public:
  void* allocate(size_t size)
  {
    if(FreeStoreHead==0)
      expandPoolSize();

    void* head = FreeStoreHead;
    FreeStoreHead = (char*)FreeStoreHead + size;
    return head;
  }

  void expandPoolSize()
  {
    cout << "MemoryManager::Expand" << endl;
    FreeStoreHead = malloc(capacity);
  }

  void free(void* pt)
  {
    //pt = 0;
    
//    uintptr_t bits = reinterpret_cast<uintptr_t>(pt);

//    cout << std::bitset<8*sizeof(pt)>(pt) << endl;
//    memset(pt, '\0', sizeof(*pt));
//    pt = (void*)0;
  }
};

MemoryManager gMM;

void* operator new(size_t size)
{
  cout<<"new called: "<< size <<endl;
  return gMM.allocate(size);
}

void operator delete(void* pt)
{
  cout << "delete called" << endl;
  gMM.free(pt);
}

int main(int argc, char** argv)
{
  stack <int, MyContainer<int> > stos;
  stos.push(12);
  stos.push(13);
  stos.push(14);
  cout<< "main:: stos.empty: " << stos.empty()<<endl;
  cout<< "main:: stos.size: " << stos.size()<<endl;
  stos.pop();
  stos.pop();
  stos.pop();
  cout<< "main:: stos.size: " << stos.size()<<endl;
  stos.push(1001);
  stos.push(1002);
  stos.push(1003);
  stos.push(1004);
  stos.push(1005);
  stos.pop();
  stos.push(1005);
  stos.push(1006);
  cout<< "main:: stos.top: " << stos.top()<<endl;
  cout<< "main:: stos.size: " << stos.size()<<endl;

  MyContainer<int> *mc2 = new MyContainer<int>();
  MyContainer<int> mc = *mc2;
  mc.push_back(1);
  mc.push_back(2);
  mc.push_back(3);
  mc.push_back(4);
  mc.push_back(5);
  mc.push_back(55);

  cout<<mc.back()<<endl;
  cout<<mc[2]<<endl;

  auto print = [](auto& mc)
  {
    for(auto i = mc.begin(); i != mc.end(); i.next())
    {
      cout<<*i<<endl;
    }
  };


  delete mc2;

  if (mc2)
  {
    mc2->push_back(56);
    cout << "main:: mc2 not freed" << endl;
    print(*mc2);
  }
  else
    cout << "main:: mc2 freed" << endl;

  return 0;
}


