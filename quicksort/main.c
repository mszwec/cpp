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
int divide(sort_t tab[], int n, int m)
{
    int pos = n+(m-n)/2;
    int val = tab[pos];
    int i=n;
    int j=m;

            for(int ii=n; ii<=m; ii++)
            {   
                if(ii==pos)
                    printf("_%d_ ", tab[ii]);
                else
                    printf("%d ", tab[ii]);
            }
            cout<<endl;

    while(1)
    {
        while(tab[i]<val)
            i++;

        while(tab[j]>val)
            j--;

        if(i>=j)
            return j;
        else
        {
            swap(tab[i++], tab[j--]);

            for(int ii=n; ii<=m; ii++)
            {   
                if(ii==pos)
                    printf("_%d_ ", tab[ii]);
                else if(ii==i-1 || ii==j+1)
                    printf("=%d= ", tab[ii]);
                else
                    printf("%d ", tab[ii]);
            }
            cout<<endl;
        }
    }
    /*
    else
        {
            swap(tab[i], tab[j]);
            return divide(tab, n+1, m-1);
        }*/
}

void quicksort(sort_t tab[], int n, int m)
{
    if(n<m)
    {
        int i = divide(tab, n,m);   
        quicksort(tab,n,i);
        quicksort(tab, i+1, m);
    }
}


int main()
{
    sort_t tab[]={6,3,2,9,6,4,3,1,0,9,7};
    int n=sizeof(tab)/sizeof(sort_t);
    
    quicksort(tab, 0 , n-1);

        for(int i=n-1; i>=0; i--)
        {
            cout << (int)tab[i] << endl;
        }

}
