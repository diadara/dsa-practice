#include<stdio.h>
#include<stdlib.h>
#include "array.h"

int main(int argc, char **argv)
{
  struct Array *c = createArray(10000, "data");
  //struct Array *t1 = createArray(16, "test1");

  //merge(t1,0,7,15);
  //  printArray(t1);
  //insort(c);
   mergesort(c); 
   printArray(c);
  return 0;
}
