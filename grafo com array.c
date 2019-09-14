#include <stdio.h>
#include <stdlib.h>

#define MAX 50000

typedef struct queue{
    int current_size;
    int head;
    int tail;
    int item[MAX];
}Queue;

typedef struct node{
    int item;
    struct node* next;
}Node;

typedef struct graph{
    Node* vertices[MAX];
    int visitado[MAX];
}Graph;

//##################FILA########################
Queue* fila_init()
{
    Queue* nova_fila = (Queue*) malloc(sizeof(Queue));
    nova_fila->current_size = 0;
    nova_fila->head = 0;
    nova_fila->tail = MAX - 1;
    return nova_fila;
}

int is_empty(Queue* fila)
{
    if (fila->current_size == 0) return 1;
    else return 0;
}

void enfileira(Queue* fila, int item)
{
    if (fila->current_size >= MAX) printf("Queue overflow\n");
    else{
        fila->tail = (fila->tail + 1) % MAX;
        fila->item[fila->tail] = item;
        fila->current_size++;
    }
}

int desenfileira(Queue* fila)
{
    if (is_empty(fila)){
        printf("Queue underflow\n");
        return -1;
    }
    else {
        int desenfileirado = fila->item[fila->head];
        fila->head = (fila->head + 1) % MAX;
        fila->current_size--;
        return desenfileirado;
    }
}

//################ para o grafo #############
Graph* graph_init()
{
    Graph* grafo = (Graph*)malloc(sizeof(Graph));
    int i;
    for (i = 1; i <= MAX - 1; i++){
        grafo->vertices[i] = NULL;
        grafo->visitado[i] = 0;
    }
    return grafo;
}

Node* novo_vertice(int item)
{
    Node* novo_node = (Node*)malloc(sizeof(Node));
    novo_node->item = item;
    novo_node->next = NULL;
    return novo_node;
}

void add_aresta(Graph* grafo, int v1, int v2)
{
    Node* vertice = novo_vertice(v2);
    vertice->next = grafo->vertices[v1];
    grafo->vertices[v1] = vertice;

    //undirected graph below
    vertice = novo_vertice(v1);
    vertice->next = grafo->vertices[v2];
    grafo->vertices[v2] = vertice;
}

void dfs(Graph* grafo, int source)
{
    grafo->visitado[source] = 1;
    printf("%d\n", source);
    Node* vertice = grafo->vertices[source];

    while(vertice != NULL){
        if (!grafo->visitado[vertice->item]){
            dfs(grafo, vertice->item);
        }
        vertice = vertice->next;
    }
}

void bfs(Graph* grafo, int source, int dist[])
{
    Queue* fila = fila_init();
    int desenfileirado;
    Node* vertice = grafo->vertices[source];
    grafo->visitado[source] = 1;
    dist[source] = 0;
    enfileira(fila, source);

    while (!is_empty(fila)){
        desenfileirado = desenfileira(fila);
        vertice = grafo->vertices[desenfileirado];

        while(vertice != NULL){
            if (!grafo->visitado[vertice->item]){
                //printf("%d\n", vertice->item);
                grafo->visitado[vertice->item] = 1;
                dist[vertice->item] = 1 + dist[desenfileirado];
                enfileira(fila, vertice->item);
            }
            vertice = vertice->next;
        }
    }
}



int main()
{
    int testes, n, m, u, v, i, j;
    int dist[MAX];

    scanf("%d", &testes);
    for (i = 0; i < testes; i++)
    {
        scanf("%d %d", &n, &m);
        for(j = 0; j < n; j++)
        {
            dist[j] = -1;
        }
        Graph* grafo = graph_init();
        for (j = 0; j < m; j++)
        {
            scanf("%d %d", &u, &v);
            add_aresta(grafo, u, v);
        }
        bfs(grafo, 1, dist);
        if (dist[n] == -1) printf("-1\n");
        else printf("%d\n", dist[n]);
    }

    return 0;
}