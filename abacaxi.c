#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50000

typedef struct adj_list adj_list;
typedef struct queue queue;
typedef struct graph graph;

struct queue{
  int current_size;
  int head;
  int tail;
  int items[MAX_SIZE];
};

struct adj_list
{
  int item;
  adj_list *next;  
};

struct graph{
  adj_list *vertices[MAX_SIZE];
  int visited[MAX_SIZE];
};

queue* create_queue()
{
  queue *new_queue = (queue*) malloc(sizeof(queue));
  new_queue->current_size = 0;
  new_queue->head = 0;
  new_queue->tail = MAX_SIZE - 1;
  return new_queue;
}

int is_empty(queue *queue)
{
  if(queue->current_size==0)
    return  1;
  else
    return 0;
}

void enqueue(queue *queue, int item)
{
  if (queue->current_size >= MAX_SIZE) 
  {
    printf("Queue overflow");
  } 
  else 
  {
    queue->tail = (queue->tail + 1) % MAX_SIZE;
    queue->items[queue->tail] = item;
    queue->current_size++;
  }
}

int dequeue(queue *queue)
{
  if (is_empty(queue))
  {
    printf("Queue underflow");
    return -1;
  } 
  else 
  {
    int dequeued = queue->items[queue->head];
    queue->head = (queue->head + 1) % MAX_SIZE;
    queue->current_size--;
    return dequeued;
  }
}

adj_list* create_adj_list(int item)
{
  adj_list *new=(adj_list*)malloc(sizeof(adj_list));
  new->item=item;
  new->next=NULL;
  return new;
}

graph* create_graph()
{
  graph *grafo = (graph*) malloc(sizeof(graph));
  int i;
  for(i=1;i<=MAX_SIZE-1;i++)
  {
    grafo->vertices[i]=NULL;
    grafo->visited[i]=0;
  }
  return grafo;
}

void add_edge(graph *graph,int v1,int v2)
{
  adj_list *vertex = create_adj_list(v2);
  vertex->next =graph->vertices[v1];
  graph->vertices[v1]=vertex;
  //Undirected graph. Edge to the other direction as well.
  vertex = create_adj_list(v1);
  vertex->next = graph->vertices[v2];
  graph->vertices[v2] = vertex;
}

void bfs(graph *graph, int source)
{
  queue *q=create_queue();
  int dequeued;
  adj_list *adj_l= graph->vertices[source];
  graph->visited[source]=1;
  enqueue(q,source);

  while(!is_empty(q))
  {
    dequeued=dequeue(q);
    adj_l = graph->vertices[dequeued];
    while(adj_l != NULL)
    {
      if(!graph->visited[adj_l->item])
      {
        printf("%d\n", adj_l->item);
        graph->visited[adj_l->item] = 1;
        enqueue(q,adj_l->item);
      }
      adj_l=adj_l->next;
    }
  }
}

void dfs(graph *graph, int source)
{
  graph->visited[source] = 1;
  printf("%d\n", source);
  adj_list *adj_list = graph->vertices[source];
  while (adj_list != NULL) 
  {
    if (!graph->visited[adj_list->item]) 
    {
      dfs(graph, adj_list->item);
    }
    adj_list = adj_list->next;
  }
}


int main()
{
    graph* grafo = create_graph();
    int vertices, i;
    int fonte, u, v;
    scanf("%d %d", &vertices, &fonte);
    while(scanf("%d %d", &u, &v) != EOF)
    {
        add_edge(grafo, u, v);
    }
    

    bfs(grafo,fonte);
}