#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Armazena o primeiro item da fila

//Armazena o conteudo do no e um ponteiro para o proximo no da fila

typedef struct _stack
{
    NODE* head;
}STACK;

typedef struct _node
{
    int element;
    NODE* next;
}NODE;

//Cria uma stack com o a head NULL
STACK* Create_stack();

//Recebe um elemento e cria e retorna um novo node
// com o elemento passado
NODE* create_node(int element);

//Verifica se a pilha esta vazia
int IS_EMPTY(STACK* stack);

//Recebe uma pilha e Retorna o elemento que esta no topo da fila
int POP(STACK* stack);

//Recebe uma pilha e um inteiro e retorna a nova pilha
//Adiciona um novo node no topo da pilha
void PUSH(STACK* stack, int element);

//Recebe a pilha e a operacao a ser feita
//faz a operacao da calculadora
void result(STACK* stack, char operation);

//Recebe uma pilha vazia e quantas strings serao lidas
//Le as n strings que vao seguir e resolve as expressoes
void Calculadora(STACK* calculadora, int size);

int main()
{
    STACK* calculadora = Create_stack();
    int k;
    scanf("%d", &k);
    Calculadora(calculadora, k);
    printf("Coordenada 1: %d\n", POP(calculadora));
    scanf("%d", &k);
    Calculadora(calculadora, k);
    printf("Coordenada 2: %d\n", POP(calculadora));

}
//Insira o código aqui
STACK* Create_stack()
{
    STACK* new_stack = (STACK*) malloc(sizeof(STACK));
    new_stack->head = NULL;
    return new_stack;
}

NODE* create_node(int element)
{
    NODE* new_node = (NODE*) malloc(sizeof(NODE));
    new_node->element = element;
    new_node->next = NULL;
    return new_node;
}

int IS_EMPTY(STACK* stack)
{
    if (stack->head == NULL) return 1;
    else return 0;
}

void PUSH(STACK* stack, int element)
{
    //Recebe uma pilha e um inteiro e retorna a nova pilha
    //Adiciona um novo node no topo da pilha
    NODE* no = create_node(element);
    if(IS_EMPTY(stack)) stack->head = no;
    else
    {
        NODE* temp = stack->head;
        stack->head = no;
        no->next = temp;
        //free(temp);
    }
    
}

int POP(STACK* stack)
{
    int n;

    if(IS_EMPTY(stack))
    {
        printf("pilha vazia man\n");
        return 0;
    }

    else
    {
        NODE* temp = stack->head;
        n = temp->element;
        stack->head = stack->head->next;
        free(temp);
        //free(temp);
        return n;
    }
    
}

void result(STACK* stack, char operation)
{
    int cache1, cache2;

    if(operation == '+')
    {
        cache1 = POP(stack);
        cache2 = POP(stack);
        PUSH(stack, cache2+cache1);
    }
    else if(operation == '-')
    {
        cache1 = POP(stack);
        cache2 = POP(stack);
        PUSH(stack, cache2-cache1);
    }
    else if(operation == '*')
    {
        cache1 = POP(stack);
        cache2 = POP(stack);
        PUSH(stack, cache2*cache1);
    }
    else
    {
        cache1 = POP(stack);
        cache2 = POP(stack);
        PUSH(stack, cache2/cache1);
    }

}

void Calculadora(STACK* calculadora, int size)
{
    int i, n;
    char cache[size+1];
    for (i = 0; i < size; i++)
    {
        scanf("%s", cache);
        getchar();
        if(cache[0] >= '0') PUSH(calculadora,atoi(cache));
        else result(calculadora,cache[0]);
    }
    
}