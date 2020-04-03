#include <iostream>
#include "heapsort.h"

int main()
{
    sort_t tab[]={6,3,2,9,6,4,3,1,0,9,7};
    int n=sizeof(tab)/sizeof(sort_t);
    
    heapsort(tab, n);

        for(int i=n-1; i>=0; i--)
        {
          std::cout << (int)tab[i] << std::endl;
        }

}
