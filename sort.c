#include "array.h"
#include <string.h>

/* Inserts an element into the correct position in the list. Time
   complexity is of the order of n^2.
*/
struct Array* insort(struct Array* a)
{
  int n = a->size;
  int i, j;
  for(i=1;i<n;i++) {
    j = i-1;
    unsigned long temp = a->data[i];
    while(j >= 0 && a->data[j] > temp){
      a->data[j+1] = a->data[j];
      j--;
    }
    a->data[j+1] = temp; 
  }
  return a;  
}



/* Merge the two arrays p-q and q+1 - r into a single array p-r when
   the indices are inclusive */
struct Array * merge(struct Array * a, int p, int q, int r)
{
  if(p==r)
    return a;
  
  struct Array *R = copyArray(a,p,q);
  struct Array *L = copyArray(a,q+1,r);
  unsigned long int *Rd = R->data, *Ld = L->data;

  int n1 = q - p + 1;
  int n2 = r - q;
  int n = n1+n2;
  
  unsigned long int * d = a->data;

  int i = 0, j = 0, k = 0;

  while( i < n1 && j < n2)
    {
      if(Rd[i] < Ld[j]) {
        d[p+k] = Rd[i];
        i++;
      }
      else {
        d[p+k] = Ld[j];
        j++;
      }
      k++;
    }
  
  if(i == n1) {
    for(;k<n;k++,j++) {
      d[p+k] = Ld[j];
    }
  }
  else {
    for(;k<n;k++,i++) {
      d[p+k] = Rd[i];
    }
  }
  
  free(Rd);
  free(Ld);

  return a;
}

struct Array * mergesortHelper(struct Array *a , int i, int j)
{
  if(i==j)
    return a;
  int middle = (i + j)/2;
  mergesortHelper(a, i, middle);
  mergesortHelper(a, middle+1, j);
  merge(a, i, middle, j);
  return a;
}

/* Based on recursively dividing the problem and the applying merge
   sort algorithm for creating a sorted array from two sorted
   arrays. */
struct Array * mergesort(struct Array * a)
{
  return mergesortHelper(a, 0, a->size -1);
}



