#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char entry[30000];
    int len;
    struct node* next;
}Node; 

typedef struct stack{
    Node* list[30000];
    int top;// top
}Stack;

//headers

//func
Stack* createstack()
{
    int i;
    Stack* new_stack = (Stack*) malloc(sizeof(Stack));
    new_stack->top = 0;
    for (i = 0; i < 30000; i++)
    {
        new_stack->list[i] = NULL;
    }
    return new_stack;
}

void push(Stack* stack, Node* node) //empurra para a pilha
{
    if (stack->top < 30000)
    {
        stack->list[stack->top++] = node;
    }
}

void peek(Stack* stack)
{
    if (stack->list[stack->top-1] != NULL)
    {
        printf("%s", stack->list[stack->top-1]->entry);
    }
}//printf("%s\n", stack->list[stack->top]->entry);
//printf("%s\n", stack->list[stack->top]->entry);//printf("%s\n", stack->list[stack->top]->entry);
Node* add(Node* head, char entered[], int tam) //cria o nó
{
    Node* novo_no = (Node*) malloc(sizeof(Node));
    strcpy(novo_no->entry, entered);
    novo_no->next = head;
    novo_no->len = tam;
    //printf("Entrada da add: %s\n", entered);
    //printf("entrou no no: %s\n", novo_no->entry);
    return novo_no;
}

int is_empty(Stack* stack)
{
    if (stack->top == 0) return 1;
    else return 0;
}

void pop(Stack* stack){
    int temp;
    if (is_empty(stack))
    {
        printf("EMPTY STACK\n");
    }
    //else stack->list[--stack->current_size];
    else
    {
        temp = stack->top-1;
        stack->top--;
        printf("%s\n", stack->list[temp]->entry);
        free(stack->list[temp]);
        stack->list[temp] = NULL;
    }
    
    
}


int main()
{
    char comando[15];
    int i;

    Stack* pilha = createstack();
    Node* entrada = NULL;

    while(scanf("%[^\n]s", comando) != EOF)
    {
        char string[30000];
        
        getchar();
        if (strcmp(comando, "PUSH") == 0) {
            scanf("%[^\n]s", string);
            getchar();
            
            entrada = add(entrada,string,strlen(string));
            push(pilha, entrada);
            //peek(pilha);
        }
        else
        {
            pop(pilha);
        }
        
        
        
    }
    return 0;
}