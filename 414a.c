#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int nota;
    struct  node* next;
}Node;

typedef struct queue{
    int nodes;
    struct node* front;
    struct node* rear;
}Queue;

//func
Queue* startQ()
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->nodes = 0; //tamanaho
    q->front = NULL; //primeiro
    q->rear = NULL; //ultimo
    return q;
}

int is_empty(Queue* q)
{
    return (q->rear == NULL);
}

void enqueue(Queue* q, int x)
{
    Node* newnode = (Node*) malloc(sizeof(Node));
    newnode->nota = x;
    newnode->next = NULL;

    if(!is_empty(q))
    {
        q->rear->next = newnode;
        q->rear = newnode;
    }

    else
    {
        q->front = newnode;
        q->rear = newnode;
    }
    q->nodes++;
}

int dequeue(Queue* q)
{
    Node* temp;
    int n = q->front->nota;
    temp = q->front;
    q->front = q->front->next;
    q->nodes--;
    free(temp);
    return n;
}

void printQ(Queue* q)
{
    Node* aux = q->front;
    if (is_empty(q)) printf("Ta vazio man\n");
    else
    {
        while(aux->next != NULL)
        {
            printf("%d->", aux->nota);
        aux = aux->next;
        }
    }
    printf("%d\n", q->rear->nota);
    
}

void swap(Node* a, Node* b) 
{ 
    int temp = a->nota; 
    a->nota = b->nota; 
    b->nota = temp; 
}

void bubbleSort(Node* start) 
{ 
    int swapped, i; 
    Node* ptr1; 
    Node* lptr = NULL; 
  
    /* Checking for empty list */
    if (start == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = start; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->nota < ptr1->next->nota) 
            {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 
  
void comparafila(Queue* a, Queue* b)
{
    
    int flag = 0;
    Node* aux1 = a->front; //recebe o head da fila A
    Node* aux2 = b->front; //recebe o head da fila B
    while(aux1 != NULL)
    {
        if (aux1->nota == aux2->nota)
        {
            //printf("Fila A %d\n", aux1->nota);
            //printf("Fila B %d\n", aux2->nota);
            flag++;
        }

        aux1 = aux1->next;
        aux2 = aux2->next;
    }
    
    printf("%d\n", flag);
}
 
int main()
{
    int testes, nalunos, nota, i, j;

    scanf("%d", &testes);// quantos testar

    for(i = 0; i < testes; i++)
    {
        Queue* filaa = startQ();
        Queue* filab = startQ();
        scanf("%d", &nalunos);// n de alunos
        for(j = 0; j < nalunos; j++)
        {
            scanf("%d", &nota);
            getchar();
            enqueue(filaa, nota);
            enqueue(filab,nota);
            bubbleSort(filab->front);
            
        }
        //printQ(filaa);
        //printQ(filab);
        comparafila(filaa,filab);

    }


    return 0;
}