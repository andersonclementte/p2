#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 200

typedef struct heap heap;

struct heap{
  int size;
  int data[MAX_SIZE]; 
};

heap* create_heap()
{
  heap *new=(heap*) malloc(sizeof(heap));
  new->size=0;
  return new;
}

void swap(int *a, int *b)
{
  int aux = *a;
  *a = *b;
  *b = aux;
}

int get_parent_index(heap* hp,int i)
{
  return i/2;
}
 
int get_left_index(heap *hp,int i)
{
  return i*2;
}

int get_right_index(heap *hp,int i)
{
  return (i*2)+1;
}

int item_of(heap *hp,int i)
{
  return hp->data[i];
}

void enqueue(heap *hp, int item)
{
  if(hp->size >=MAX_SIZE)
  {
    printf("overflow");
  }
  else
  {
    hp->data[++hp->size]=item;
  }
}

void max_heap(heap *hp)
{
  int i;
  for(i=hp->size/2;i>=1;i--)
  {
    max_heapfy(hp,i);
  }
}


void max_heapfy(heap *hp, int i)
{
  int largest;
  int left_index = get_left_index(hp,i);
  int right_index = get_right_index(hp,i);

  if(left_index <= hp->size && hp->data[left_index] > hp->data[i])
  {
    largest = left_index;
  }
  else
  {
    largest = i;
  }

  if(right_index <= hp->size && hp->data[right_index] > hp->data[largest])
  {
    largest= right_index;
  }

  if(hp->data[i] != hp->data[largest])
  {
    swap(&hp->data[i], &hp->data[largest]);
    max_heapfy(hp,largest);
  }
}

void heapsort(heap *hp)
{
  int i,j;
  max_heap(hp);
  for(i=hp->size;i>=2;i--)
  {
    printf("Estado Atual da Heap:");
    for(j=1;j<hp->size+1;j++)
    {
      if(j<hp->size)
      {
        printf(" %d |", hp->data[j]);
      }
      else
      {
        printf(" %d", hp->data[j]);
      }
      
    }
    printf("\nMaior elemento neste passo: %d\n", hp->data[1]);

    swap(&hp->data[1], &hp->data[i]);

    hp->size--;
    max_heapfy(hp,1);
  }
  printf("Estado Atual da Heap: %d\n", hp->data[1]);
}

int main()
{
  heap *hp=create_heap();
  int i=1, size_i,n;
  while(scanf("%d", &n) != EOF)
  {
    enqueue(hp,n);
  }

  size_i=hp->size;
  printf("Estado inicial:");
  for(i=1;i<size_i+1;i++)
  {
    if(i<size_i)
    {
      printf(" %d |", hp->data[i]);
    }
    else
    {
      printf(" %d", hp->data[i]);
    }
  }
  printf("\n");
  heapsort(hp);
  printf("Resultado Final:");
  for(i=1;i<size_i+1;i++)
  {
    if(i<size_i)
    {
      printf(" %d |", hp->data[i]);
    }
    else
    {
      printf(" %d", hp->data[i]);
    }
    
  }

  return 0;
}