#include<stdlib.h>
#include<stdio.h>


struct Array{
    int size;
    unsigned long int * data;
};

struct Array * createArray(int n, char *filename);
void printArray(struct Array* a);
void shiftElements(struct Array * a, int i, int j);
struct Array * copyArray(struct Array * A, int i, int j);
struct Array* insort(struct Array* a);
struct Array * merge(struct Array * a, int p, int q, int r);
struct Array * mergesortHelper(struct Array *a , int i, int j);
struct Array * mergesort(struct Array * a);
