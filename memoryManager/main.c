#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <bitset>

using namespace std;

class MemoryManager
{
    void *FreeStoreHead;
    unsigned long capacity;
    public:
        MemoryManager()
        {
            FreeStoreHead=0;
            capacity = 6400;
        }
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
            cout<<"Expand"<<endl;
            FreeStoreHead = malloc(capacity);
        }
        void free(void* pt)
        {}
};

MemoryManager gMM;

void* operator new(size_t size)
{
    cout<<"NEW "<<size<<endl;
    return gMM.allocate(size);
}

void operator delete(void* pt)
{
    gMM.free(pt);
}

template <typename T>
class myContainer
{
    public:
        typedef T value_type;
        typedef T &reference;
        typedef const T &const_reference;
        typedef int size_type;


        class iterator
        {
            private:
                value_type* address;
            public:
                iterator(): address((value_type*)0)
                {
                    cout<<"iterator Default Costructor"<<endl;
                }
                iterator(value_type* addr): address(addr)
                {
                    cout<<"iterator Costructor"<<endl;
                }
                reference operator* ()
                {
                    return *address;
                }
                void set(value_type* addr)
                {
                    address = addr;
                }
                iterator& next()
                {
                    address++;
                    return *this;
                }
                iterator& operator++ (int i)
                {
                    address++;
                    return *this;
                }
                iterator& operator++ ()
                {
                    ++address;
                    return *this;
                }
                bool operator!=(const iterator& it)
                {
                    return address!=it.address;
                }
                bool operator==(const iterator& it)
                {
                    return address==it.address;
                }
        };    
    
    private:
        value_type* val;
        size_type size_val;
        size_type reserved;
        iterator * it;

    public:
        void push_back(const_reference cr)
        {
            if(++size_val > reserved)
                ++reserved;

            value_type* val2 = (value_type*) calloc (sizeof(value_type),reserved);
            if(val)
            {
                for(int i=0; i<size_val-1; i++)
                {
                    val2[i]=val[i];
                }
                free(val);
                val2[size_val-1] = cr;
                val=val2;
            }
            else
            {
                val=val2;
                val[size_val-1] = cr;
            }
        }
        void pop_back(void)
        {
            --size_val;
        }

        bool empty(void) const
        {
            return !(bool)val;
        }

        size_type size(void) const
        {
            return size_val;
        }

        reference back(void)
        {
            return val[size_val-1];
        }

        myContainer(void)//: size_val(0), val((value_type*)0), reserved(0)
        {
            cout<<"Constructor"<<endl;
            it = new iterator();
            size_val=0;
            reserved=0;
            val = (value_type*)0;
        }

        myContainer(const myContainer & old)
        {
            cout<<"Copy constructor"<<endl;
            it = new iterator();
            size_val = old.size_val;
            reserved = old.reserved;
            val = (value_type*) calloc (sizeof(value_type),reserved);
            for(int i=0; i<size_val; i++)
            {
                    val[i]=old.val[i];
            }
        }

        ~myContainer(void)
        {
            if(val)
                free(val);
            if(it)
                delete it;
        }

        reference operator[](int i)
        {
            return val[i];
        }

        

        iterator& end(void)
        {
            it->set(val+size_val);
            return *(it);
        }
        iterator& begin(void)
        {
            it->set(val);
            return *(it);
        }

};

int main(int argc, char** argv)
{
    stack <int, myContainer<int> > stos;
    stos.push(12);
    stos.push(13);
    stos.push(14);
    cout<<stos.empty()<<endl;
    cout<<stos.size()<<endl;
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
    
    myContainer<int> *mc2=new myContainer<int>();
    myContainer<int> mc = *mc2;
    mc.push_back(1);
    mc.push_back(2);
    mc.push_back(3);
    mc.push_back(4);
    mc.push_back(5);
    mc.push_back(55);

    cout<<mc.back()<<endl;
    cout<<mc[2]<<endl;

    myContainer<int>::iterator i=mc.begin();

    for(;i!=mc.end();i.next())
        cout<<*i<<endl;

    return 0;
}


