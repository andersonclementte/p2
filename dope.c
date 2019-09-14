#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int nota;
    struct node *next;
}Node;

typedef struct queue
{
    int nodes;
    Node* front;
    Node* rear;
}Queue;

Queue* startQ()
{
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->nodes = 0;
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int isempty(Queue* q)
{
    return (q->rear == NULL);
}

void enqueue(Queue* q, int x)
{
    Node* temp = malloc(sizeof(Node));
    temp->nota = x;
    temp->next = NULL;
    if(!isempty(q))
    {
        q->rear->next = temp;
        q->rear = temp;
    }
    else
    {
        q->front = q->rear = temp;
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
    return(n);
}

void display(Node* head)
{
    if(head == NULL)
    {
        printf("NULL\n");
    }
    else
    {
        printf("%d\n", head -> nota);
        display(head->next);
    }
}

int main()
{
    Queue* q = startQ();
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    printf("Queue before dequeue\n");
    display(q->front);
    dequeue(q);
    printf("Queue after dequeue\n");
    display(q->front);
    return 0;
}