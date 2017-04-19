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

void selectionsort(int n, sort_t tab[])
{
    int start=0, index;
    do{
        index=start;
        for (int i=start+1; i<n; i++)
        {
            if(tab[i]<tab[start])
                index=i;
        }
            if(index!=start)
                swap(tab+start, tab+index);
    }
    while(++start<n);
}

int main()
{
    sort_t tab[]={6,3,2,9,6,4,3,1,0,9,7};
    int n=sizeof(tab)/sizeof(sort_t);
    
    selectionsort(n, tab);

        for(int i=n-1; i>=0; i--)
        {
            cout << (int)tab[i] << endl;
        }

}
