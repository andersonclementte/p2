#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack {
    int current_size;
    char items[128];
}Stack;

//headers
Stack* createstack();
void push(Stack* stack, char item);
char pop(Stack* stack);
char peek(Stack* stack);
int is_empty(Stack* stack);
void printS(Stack* stack);

//functions
Stack* createstack()
{
    Stack* new_stack = (Stack*) malloc(sizeof(Stack));
    new_stack->current_size = 0;
    return new_stack;
}

void push(Stack* stack, char item)
{
    if (stack->current_size == 128) printf("Stack overflow\n");
    else stack->items[stack->current_size++] = item;
}

int is_empty(Stack* stack)
{
    if (stack->current_size == 0) return 1;
    else return 0;
}

char pop(Stack* stack)
{
    if (is_empty(stack))
    {
        printf("Stack underflow\n");
        return -1;
    }
    else return stack->items[--stack->current_size];
}

char peek (Stack* stack)
{
    if (is_empty(stack))
    {
        printf("this: Stack underflow\n");
        return -1;
    }

    else return stack->items[stack->current_size - 1];
}

void printS(Stack* stack)
{
    int i;
    
    for (i = 0; i < stack->current_size; i++)
     {
        if (stack->current_size == 0) printf("Empty Stack\n");    
        else if (i == stack->current_size - 1)  printf("%c\n", stack->items[i]);
        else printf("%c ", stack->items[i]);
    }
}

int main()
{
    
    int entradas, i, j, n, k;
    char s[256];
    Stack* pilha = createstack();

    scanf("%d ", &entradas);
    for (i = 0; i < entradas; i++)
    {
        scanf("%[^\n]s", s);
        n = strlen(s);
        k = 0;

        for (j = 0; j < n; j++)
    {
        if (s[j] == '(' || s[j] == '[') push(pilha,s[i]); //se for abertura entra na pilha

 //       if (s[i] == ' ') continue;

        else if (s[j] == ')') // se for um fechamento testa
        {
            if (is_empty(pilha)) //se pilha vazia para
            {
                //goto vazio;
                k++;
                break;
            }
            else if (peek(pilha) == '(') // se for correspondente
            {
                pop(pilha); // tira
            }

            else if (peek(pilha) == '[') //se nao for correspondente
            {
                //goto vazio
                k++;
                break;
            }
        }

        else if (s[j] == ']')// se for um fechamento testa
        {
            if (is_empty(pilha)) //se for vazia para
            {
                //goto vazio
                k++;
                break;
            }
            else if (peek(pilha) == '[') // se for correspondente
            {
                pop(pilha); // tira
            }
            else if (peek(pilha) == '(')
            {
                //goto vazio
                k++;
                break;
            }
        }

        //else continue;
        
        
    }

    //printS(pilha);
    if (is_empty(pilha) && k == 0) printf("Yes\n");
    else
    {
        //vazio:
        printf("No\n");
    }

    
    while (!is_empty(pilha))
    {
        pop(pilha);
    }
        
    } // fim do while
    
    

    return 0;
}