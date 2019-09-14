#include <stdio.h>
#include< stdlib.h>

#define MAX_SIZE 200

typedef struct heap
{
    int size;
    int data[MAX_SIZE];
}Heap;

Heap* create_heap()
{
    Heap* new = (Heap*)malloc(sizeof(Heap));
    new->size = 0;
    return new;  
}

void swap (int* a, int* b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

int getparentindex(Heap* hp, int i)
{
    return i/2;
}

int left_child(Heap* hp, int i)
{
    return i*2;
}

int rigth_child(Heap* hp, int i)
{
    return (i*2)+1;
}

int item_of(Heap* hp, int i)
{
    return hp->data[i];
}

void enqueue(Heap* hp, int item)
{
    if (hp->size >= MAX_SIZE) printf("overflow\n");
    else hp->data[++hp->size] = item;
}

void max_heapfy(Heap)

void max_heap(Heap* hp)
{
    int i;
    for (i = hp->size/2; i >= 1; i--) max_heapfy(hp, i);
}