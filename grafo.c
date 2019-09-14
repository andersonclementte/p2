#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50000

typedef struct queue
{
    int current_size;
    int head;
    int tail;
    int items[MAX_SIZE];
}Queue;

typedef struct adj_list
{
    int item;
    struct adj_list* next;
}Adj_list;

typedef struct graph
{
    Adj_list* vertices[MAX_SIZE];
    int visited[MAX_SIZE];
}Graph;

//functions
Queue* create_queue()
{
    Queue* new_queue = (Queue*) malloc(sizeof(Queue));
    new_queue->current_size = 0;
    new_queue->head = 0;
    new_queue->tail = MAX_SIZE - 1;
    return new_queue;
}

int is_empty(Queue* queue)
{
    if (queue->current_size == 0) return 1;
    else return 0;
}

void enqueue(Queue* queue, int item)
{
    if (queue->current_size >= MAX_SIZE) printf("Queue overflwo\n");
    else
    {
        queue->tail = (queue->tail + 1) % MAX_SIZE;
        queue->items[queue->tail] = item;
        queue->current_size++;
    }
}

int dequeue(Queue* queue)
{
    if (is_empty(queue))
    {
        printf("Queue underflow\n");
        return -1;
    }
    else
    {
        int dequeued =  queue->items[queue->head];
        queue->head = (queue->head + 1) % MAX_SIZE;
        queue->current_size--;
        return dequeued;
    }
}

Adj_list* create_adj_list(int item)
{
    Adj_list* new = (Adj_list*) malloc(sizeof(Adj_list));
    new->item = item;   
    new->next = NULL;
    return new;
}

Graph* creatgraph()
{
    Graph* grafo = (Graph*) malloc(sizeof(Graph));
    int i;
    for (i = 1; i <= MAX_SIZE-1; i++)
    {
        grafo->vertices[i] = NULL;
        grafo->visited[i] = 0;
    }
    return grafo;
}

void add_edge(Graph* grafo, int v1, int v2) // perguntar isso
{
    Adj_list* vertex = create_adj_list(v2);
    vertex->next = grafo->vertices[v1];
    grafo->vertices[v1] = vertex;
    //Undirected graph. Edge to the other direction as well
    vertex = create_adj_list(v1);
    vertex->next = grafo->vertices[v2];
    grafo->vertices[v2] = vertex;
}

void bfs(Graph* graph, int source)
{
    int dequeued;
    Queue* q = create_queue();
    Adj_list* adjl = graph->vertices[source];
    graph->visited[source] = 1;
    enqueue(q, source);

    while(!is_empty(q))
    {
        dequeued = dequeue(q);
        adjl = graph->vertices[dequeued];
        while (adjl != NULL)
        {
            if (!graph->visited[adjl->item])
            {
                printf("%d\n", adjl->item);
                graph->visited[adjl->item] = 1;
                enqueue(q, adjl->item);
            }
            adjl = adjl->next;
        }
    }
}

void dfs(Graph* graph, int source)
{
    graph->visited[source] = 1;
    printf("%d\n", source);
    Adj_list* adjl = graph->vertices[source];
    while (adjl != NULL)
    {
        if (!graph->visited[adjl->item])
        {
            dfs(graph, adjl->item);
        }
        adjl = adjl->next;
    }
}

int main()
{
    Graph* grafo = creatgraph();
    int vertices, i, fonte, u, v;
    scanf("%d %d", &vertices, &fonte);
    while(scanf("%d %d", &u, &v) != EOF)
    {
        add_edge(grafo, u, v);
    }
    

    bfs(grafo,fonte);
}