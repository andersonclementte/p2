#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct node
{
    int element;
    struct node* next;
}NODE;

typedef struct stack
{
    NODE* head;
}STACK;



//func
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

void printS(STACK* stack)
{
    NODE* temp = stack->head;
    if(IS_EMPTY(stack)) printf("ta vazia man\n");
    else
    {
        while(temp != NULL)
        {
            printf("%d\n", temp->element);
            temp = temp->next;
        }
    }
    
}

//Recebe a pilha e a operacao a ser feita
//faz a operacao da calculadora
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

//Recebe uma pilha vazia e quantas strings serao lidas
//Le as n strings que vao seguir e resolve as expressoes
void Calculadora(STACK* calculadora, int size)
{
    int i, n;
    char cache[size];
    //fgets(cache,size+1,stdin);
    for (i = 0; i < size; i++)
    {
        scanf("%s", cache);
        getchar();
        if(cache[0] >= '0') PUSH(calculadora,atoi(cache));
        else result(calculadora,cache[0]);
    }
    
}


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

    return 0;

}
//Insira o código aqui
