#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

typedef struct _node {
	struct _node *prev;
  	struct _node *next;
  	int    value;
}node_t;

typedef struct _deque {
  	node_t *front;
  	node_t  *rear;
  	int      size;
}deque_t;

node_t* new_node(int value)
{
    node_t* new_node = (node_t*) malloc(sizeof(node_t));
    new_node->value = value;
    new_node->next =NULL;
    new_node->prev = NULL;
    return new_node;
}

deque_t* construct()
{
    deque_t* new_deck = (deque_t*)malloc(sizeof(deque_t));
    new_deck->front = NULL;
    new_deck->rear = NULL;
    new_deck->size = 0;
    return new_deck;
}

void destruct(deque_t* deque)
{
    free(deque);
}

int size(deque_t* deque)
{
    return deque->size;
}

bool empty(deque_t* deque)
{
    if (deque->size == 0) return true;
    else return false;
}

int front(deque_t* deque)
{
    if (empty(deque)) return INT_MIN;
    else return deque->front->value;
}

int rear(deque_t* deque)
{
    if (empty(deque)) return INT_MAX;
    else return deque->rear->value;
}

void enqueue_rear(deque_t* deque, int value)
{
    node_t* node = new_node(value);
    if (!empty(deque))
    {
        deque->rear->next = node;
        deque->rear = node;
    }

    else
    {
        deque->front = node;
        deque->rear = node;
    }

    deque->size++;
    
}

void enqueue_front(deque_t* deque, int value)
{
    node_t* node = new_node(value);
    if (!empty(deque))
    {
        deque->front->prev = node;
        deque->front = node;
    }

    else
    {
        deque->front = deque->rear = node;
    }

    deque->size ++;
    
}

void dequeue_rear(deque_t* deque)
{
    if(!empty(deque))
    {
        node_t* temp;
        temp = deque->rear;
        deque->rear = deque->rear->prev;
        deque->size--;
        free(temp);
    }
}

void dequeue_front(deque_t* deque)
{
    if (!empty(deque))
    {
        node_t* temp;
        temp = deque->front;
        deque->front = deque->front->next;
        deque->size--;
        free(temp);
    }
}

void erase(deque_t* deque)
{
    deque_t* temp = deque;
    deque->front = NULL;
    deque->rear = NULL;
    deque->size = 0;
    free(temp);
}

void print(deque_t* deque)
{
    node_t* temp = deque->front;
    while (temp->next != NULL)
    {
        printf("%d ",temp->value);
        temp = temp->next;
    }
    printf("%d\n",deque->rear->value);
}
