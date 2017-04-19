#include <iostream>
#include <stdio.h>

typedef char sort_t;
using namespace std;

inline void swap (sort_t *a, sort_t *b)
{
    sort_t tmp = *a;
    *a=*b;
    *b=tmp;
}
void insertionsort(int n, sort_t tab[])
{
    int val, j;

    for (int i=1; i<n; i++)
    {
        val=tab[i];
        for(j=i; j>0 && tab[j-1] > val; j--)
            tab[j]=tab[j-1];

        tab[j]=val;
    }
}

int main()
{
    sort_t tab[]={6,3,2,9,6,4,3,1,0,9,7};
    int n=sizeof(tab)/sizeof(sort_t);
    
    //insertionsort(n, tab, tab);
    insertionsort(n, tab);

        for(int i=n-1; i>=0; i--)
        {
            cout << (int)tab[i] << endl;
        }

}
