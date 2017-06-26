#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

typedef struct myElem
{
    myElem *next;
    int var;
    myElem()
    {
        next=NULL;
        var=-1;
    };

    myElem(int x)
    {
        next=NULL;
        var=x;
    };
}mylist;
void print(mylist *head)
{    /*PRINT*/
    mylist *tmp = head;
    while(tmp->next)
    {
        tmp=tmp->next;
        cout<<tmp->var<<endl;
    }
    /**/
}

int insert(mylist *head, mylist *elem)
{
    mylist *tmp = head;
    mylist *prev;
    bool inserted = false;

    while(tmp->next)
    {
        prev = tmp;
        tmp = tmp->next;
        if(elem->var > tmp->var)
        {
            continue;
        }else
        {
            elem->next = tmp;
            prev->next = elem;
            inserted = true;
            break;
        }
    }

    if(!inserted)// First and last scenario
    {
        tmp->next = elem;
    }

    return 0;
}

int main(int argc, char** argv)
{
    mylist *head = new mylist();
    mylist *elem = new mylist();
    mylist *tmp = head;

    for (int i=0; i<4; i++)
    {
        elem = new mylist();
        elem->var = i+i*10;
        tmp->next=elem;        
        tmp = elem;
    }

    print(head);
    elem = new mylist(0);
    insert(head,elem);
    print(head);
    return 0;
}
