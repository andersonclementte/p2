#include <stdio.h>
#include <stdlib.h>
#define HEAPSIZE 1000

typedef struct heap{
    int size;
    int data[HEAPSIZE];
}Heap;

Heap* heapinit()
{
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->size = 0;
    return heap;
}

int get_parent_index(Heap* heap, int i)
{
    return i >> 1;
}

int get_left_index(Heap* heap, int i)
{
    return i << 1;
}

int get_right_index(Heap* heap, int i)
{
    return (i << 1) + 1;
}

void swap(int a, int b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

int is_empty(Heap* heap)
{
    if (heap->size == 0) return 1;
    else return 0;
}

void max_heapify(Heap* heap, int i)
{
    int largest;
    int left_index = get_left_index(heap, i);
    int right_index = get_right_index(heap, i);

    if (left_index <= heap->size && heap->data[left_index] > heap->data[i])
        largest = left_index;
    else largest = left_index;

    if (right_index <= heap->size && heap->data[right_index] > heap->data[largest])
        largest = right_index;

    if (heap->data[i] != heap->data[largest]) {
        swap(&heap->data[i], &heap->data[largest]);
        max_heapify(heap, largest);
    }    
}

void enqueue(Heap* heap, int item)
{
    if (heap->size >= HEAPSIZE) printf("Heap overflow\n");
    else {
        heap->data[++heap->size] = item;

        int key_index = heap->size;
        int parent_index = get_parent_index(heap, heap->size);

        while (parent_index >= 1 && heap->data[key_index] > heap->data[parent_index]){
            swap(&heap->data[key_index], &heap->data[parent_index]);
            
            key_index = parent_index;

            parent_index = get_parent_index(heap, key_index);
        }
    }
}

int dequeue (Heap* heap)
{
    if (is_empty(heap)) {
        printf("Heap underflow\n");
        return -1;
    }

    else {
        int item = heap->data[1];
        heap->data[1] = heap->data[heap->size];
        heap->size--;
        max_heapify(heap, 1);
        return item;
    }
}