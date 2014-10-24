#include "array.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Array * createArray(int n, char *filename)
{
  struct Array *a = malloc(sizeof *a);
  a->size = n;
  a->data = malloc(sizeof(unsigned long int)*n);
  int i;
  FILE *f = fopen(filename, "r");
  for(i=0;i<n;i++)
    {
      fscanf(f,"%lu", &a->data[i]);
    }
  return a;  
}

void printArray(struct Array* a)
{
  int i;
  for(i=0;i<a->size;i++)
    printf("%d. %lu\n", i, a->data[i]);
}

void shiftElements(struct Array * a, int i, int j)
{
  unsigned long int temp = a->data[i];
  a->data[i] = a->data[j];
  a->data[j] = temp;
}

/* Copy an array from indices i to j inclusive into a new array. */
struct Array * copyArray(struct Array * A, int i, int j)
{
  int n = j - i + 1;
  unsigned long int * start = A->data +i;
  struct Array *B = malloc(sizeof *B);
  B->size = n;
  B->data =  malloc(n * sizeof(unsigned long int));
  memcpy(B->data, start, n * sizeof(unsigned long int));
  return B;
}
