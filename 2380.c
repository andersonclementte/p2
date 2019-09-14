#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/*########################################*/
typedef struct node{
    int item;
    struct node* next;
}Node;

typedef struct queue{
    int nodes;
    Node* front;
    Node* rear;
}Queue;

typedef struct graph{
    Node* elements[MAX];
    int visited[MAX];
}Graph;

/*#################PARA A FILA#######################*/
Queue* fila_init()
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->nodes = 0; //tamanaho
    q->front = NULL; //primeiro
    q->rear = NULL; //ultimo
    return q;
}

int is_empty(Queue* q)
{
    if (q->nodes <= 0) return 1;
    else return 0;
}

void enfileira(Queue* q, int x)
{
    Node* newnode = (Node*) malloc(sizeof(Node));
    newnode->item = x;
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

int desenfileira(Queue* q)
{
    if (q->nodes <= 0) printf("Queue underflow\n");
    else
    {
        Node* temp;
        int n = q->front->item;
        temp = q->front;
        q->front = q->front->next;
        q->nodes--;
        free(temp);
        return n;
    }
    
}
/*###################PARA O GRAFO#####################*/
Node* add_vertice(int item)
{
    Node* new_vertex = (Node*) malloc(sizeof(Node));
    new_vertex->item = item;
    new_vertex->next = NULL;
    return new_vertex;
}

Graph* graph_init()
{
    Graph* new_graph = (Graph*) malloc(sizeof(Graph));
    int i;

    for(i == 0; i < MAX; i++)
    {
            new_graph->elements[i] = NULL;
            new_graph->visited[i] = 0;
    }

    return new_graph;
}

void add_aresta(Graph* graph, int vertex1, int vertex2)
{
    Node* new_vertex = add_vertice(vertex2);
    new_vertex->next = graph->elements[vertex1];
    graph->elements[vertex1] = new_vertex;

    //uses the following lines if the graph is undirected
    new_vertex = add_vertice(vertex1);
    new_vertex->next = graph->elements[vertex2];
    graph->elements[vertex2] = new_vertex;
}

void dfs(Graph* graph, int source)
{
    graph->visited[source] = 1;
    printf("%d\n", source);

    Node* edge = graph->elements[source];

    while (edge != NULL)
    {
        if (!graph->visited[edge->item])
        {
            dfs(graph, edge->item);
        }
        edge = edge->next;
    }
}

void bfs(Graph* graph, int source)
{
    Queue* queue = fila_init();
    int dequeued;
    Node* vertice = graph->elements[source];
    graph->visited[source] = 1;
    enfileira(queue, source);
    printf("%d\n", source);

    while(!is_empty(queue))
    {
        dequeued = desenfileira(queue);
        vertice = graph->elements[dequeued];

        while(vertice != NULL)
        {
            if (!graph->visited[vertice->item])
            {
                printf("%d\n",vertice->item);
                graph->visited[vertice->item] = 1;
                enfileira(queue, vertice->item);
            }
            vertice = vertice->next;
        }
    }

    free(queue);
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
    

    dfs(grafo,fonte);
    return 0;
}
