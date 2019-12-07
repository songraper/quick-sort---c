#include <stdio.h>
#include <stdlib.h>
#include "quick_sort.h"
#include <time.h>

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

void quick_sort(int *a, int low, int high)
{
  if (high <= low)
  {
    return;
  }

  if (high == low + 1)
  {
    if (a[low] > a[high])
    {
      swap(&a[low], &a[high]);
    }
  }

  else
  {
    srand(time(NULL));
    int i = 0, j = 0, k = 0;

    i = low;
    j = high;
    k = rand() % high + low;

    while (i < j)
    {
      while (a[k] > a[i])
      {
        i++;
      }

      while (a[k] < a[j])
      {
        j--;
      }

      if (i < j)
      {
        swap(&a[i], &a[j]);
        i++;
        j--;
      }
    }

    quick_sort(a, i, high);
    quick_sort(a, low, j);
  }
}
