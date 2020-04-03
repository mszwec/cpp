#ifndef BUBBLESORT_H
#define BUBBLESORT_H

typedef int sort_t;

inline void swap (sort_t* a, sort_t* b)
{
  sort_t tmp = *a;
  *a=*b;
  *b=tmp;
}

void bubblesort(sort_t* tab, int size)
{
  bool didAction;

  do
  {
    didAction = false;
    for(int i = size - 1; i > 0; --i)
    {
      if(tab[i] < tab[i-1])
      {
        swap(tab + i, tab + i - 1);
        didAction = true;
      }
    }
  }while(didAction);
}

#endif
