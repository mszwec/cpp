#include <iostream>
#include <stdio.h>

typedef int sort_t;
using namespace std;

inline void swap (sort_t *a, sort_t *b)
{
    sort_t tmp = *a;
    *a=*b;
    *b=tmp;
}

void heapify(sort_t *tab, int n , int root)
{

    int left = root*2;
    int right = root*2+1;
    int greater=root;

    if(left < n && tab[left] > tab[root])
        greater=left;

    if(right < n && tab[right] > tab[greater])
        greater=right;

    if(greater != root)
    {
        swap(tab[root], tab[greater]);
        heapify(tab, n, greater);
    }
}

void heapsort(sort_t tab[], int n)
{
    for(int i =n/2; i>=0; i--)
        heapify(tab, n, i);

    for (int i=n-1; i>0; i--)
    {
        swap(tab[i], tab[0]);
        n--;
        heapify(tab,n,0);
    }
}


int main()
{
    sort_t tab[]={6,3,2,9,6,4,3,1,0,9,7};
    int n=sizeof(tab)/sizeof(sort_t);
    
    heapsort(tab, n);

        for(int i=n-1; i>=0; i--)
        {
            cout << (int)tab[i] << endl;
        }

}
