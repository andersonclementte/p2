#include <stdio.h>
#include <stdlib.h>
//fila com listas e prioridades
typedef struct node{
    int nota;
    struct node* next;
}Node;

typedef struct queue{
    struct node* front;
    struct node* rear;
}Queue;

//headers

//func
Queue* createQ()
{
    Queue* new_queue = (Queue*) malloc(sizeof(Queue));
    new_queue->front = new_queue->rear = NULL; // ambos recebem NULL
    return new_queue;
}

void enqueue(Queue* pq, int numero)
{
    Node* new_node = (Node*) malloc(sizeof(Node)); /* Cria um novo nó */
    new_node->nota = numero;
    new_node->next = NULL;

    if(pq->rear == NULL) //se a fila ta vazia, o novo nó é a cabeça e o pé da fila
    {
        pq->front = pq->rear = new_node;
        return;
    }

    //adiciona o novo no ao final da fila
    pq->rear->next = new_node;
    pq->rear = new_node;
}

void printQ(Queue* queue) 
{
   Queue* temp = queue;
   if ((temp->front == NULL) && (temp->rear == NULL)) {
      printf("Pilha vazia man\n");
      return;
   }
   printf("Os elementos sao: ");
   while (temp != NULL) {
      printf("%d ",temp->front->nota);
      temp->front = temp->front->next;
   }
}


int main()
{
    Queue* fila = createQ();
    enqueue(fila, 100);
    enqueue(fila, 200);
    enqueue(fila, 50);
    printQ(fila);

    return 0;
}