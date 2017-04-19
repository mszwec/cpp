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

int main()
{
    unsigned char didAction;

    sort_t tab[]={6,3,2,9,6,4,3,1,0,9,7};
    
    do
    {
        didAction=0;
        for(int i=sizeof(tab)/sizeof(sort_t)-1; i>0; i--)
        {
            if(tab[i] < tab[i-1])
            {
                swap(tab[i], tab[i-1]);
                didAction=1;
            }
        }
    }while(didAction);

        for(int i=sizeof(tab)/sizeof(sort_t)-1; i>=0; i--)
        {
            cout << (int)tab[i] << endl;
        }

}
