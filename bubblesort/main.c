#include <iostream>
#include "bubblesort.h"

using namespace std;

int main()
{
  sort_t tab[]={6,3,2,9,6,4,3,1,0,9,7};
  int size = sizeof(tab)/sizeof(sort_t);

  bubblesort(tab, size);

  for(int i = size - 1; i >= 0; --i)
  {
    cout << (int)tab[i] << endl;
  }

}
