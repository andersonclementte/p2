#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

typedef struct _deque deque_t;
typedef struct _node   node_t;

//Guarda um ponteiro pro node anterior, para o proximo node e o valor guardado
struct _node {
	node_t *prev;
  	node_t *next;
  	int    value;
};

//Guarda um ponteiro para o primeiro node, um ponteiro para o ultimo node, e o tamanho do deque
struct _deque {
  	node_t *front;
  	node_t  *rear;
  	int      size;
};

//Cria um node que guarda os valores que são enfileirados no deque
node_t*  node_new     (int value);

//Cria um deque dinamicamente e retorna seu endereço de memoria
deque_t* construct    ();
//Libera a memória do conteúdo e do próprio deque
void     destruct     (deque_t *deque);

//Retorna o tamanho do deque
int      size         (deque_t *deque);
//Retorna verdadeiro se o deque esta vazio, caso contrário, retorna falso
bool     empty        (deque_t *deque);

//Retorna o valor da frente da lista, retorna int_min quando a lista estiver vazia
int      front        (deque_t *deque);
//Retorna o valor do fim da lista, retorna int_min quando a lista estiver vazia
int      rear         (deque_t *deque);

//Cria um nó que guarda um valor e o adiciona ao fim do deque
void     enqueue_rear (deque_t *deque, int value);
//Cria um nó que guarda um valor e o adiciona ao inicio do deque
void     enqueue_front(deque_t *deque, int value);
//Retira o valor do final caso não esteja vazia
void     dequeue_rear (deque_t *deque);
//Retira o valor da frente caso não esteja vazia
void     dequeue_front(deque_t *deque);
//Limpa o conteudo do deque(deixa ele vazio)
void     erase        (deque_t *deque);

//Imprime o deque em uma unica linha, com os elementos separados por um espaço,
//terminando com um \n, lembrando de respeitar os conceitos de fila.
void     print        (deque_t *deque);

int main() {
 	int i, num;
  	scanf("%d", &num);
  
  	deque_t* deque = construct();
  
  	int vector[num];
  	for(i = 0; i < num; ++i)
      	scanf("%d", &vector[i]);
  
  	for(i = 0; i < num; ++i)
      	enqueue_rear(deque, vector[i]);
  
 	printf("%d\n", front(deque));
  	printf("%d\n", rear (deque));
  
  	if(!empty(deque))
  		printf("The size of the deque %d\n", size(deque));
  	else
       	printf("The deque is empty\n");
  	
    scanf("%d", &num);
    for(i = 0; i < num; ++i)
       enqueue_front(deque, i);
  	print(deque);
    dequeue_front(deque);
    print(deque);
    dequeue_rear (deque);
    print(deque);
    
  	erase(deque);
      //printf("Teste da erase:\n");
      //print(deque);
  	for(i = 0; i < 3; ++i)
  		enqueue_rear(deque, i);
  		
  	print(deque);
    destruct(deque);
       
	return 0;
}

node_t* new_node(int value)
{
    node_t* new_node = (node_t*) malloc(sizeof(node_t));
    new_node->value = value;
    new_node->next = NULL;
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
        node->prev = deque->rear;
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
        node->next = deque->front;
        deque->front->prev = node;
        deque->front = node;
    }

    else
    {
        deque->front =node;
        deque->rear = node;
    }

    deque->size++;
    
}

void dequeue_rear(deque_t* deque)
{
    if(!empty(deque))
    {
        node_t* temp;
        temp = deque->rear;
        deque->rear = deque->rear->prev;
        deque->rear->next = NULL;
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
    deque->front = NULL;
    deque->rear = NULL;
    deque->size = 0;
}

void print(deque_t* deque)
{
    node_t* temp = deque->front;
    while (temp != NULL)
    {
        if (temp == deque->rear) printf("%d\n", temp->value);
        else printf("%d ",temp->value);
        temp = temp->next;
    }
}