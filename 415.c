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
void balance(Stack *pilha, char s[], int tam, int k);
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
    else{
        Stack* temp = stack->items[--stack->current_size];
        free(stack->items[stack->current_size + 1]);
        return temp;
    }
        //return stack->items[--stack->current_size];

}

char peek(Stack* stack)
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

void balance(Stack *pilha, char s[], int tam, int k)
{
    int i; char l;
    
    for (i = 0; i < tam; i++)
    {
       
        if (s[0] == ' ' && tam == 1)
        {
            //goto vazio;
            break;
        }
        
        else if (s[i] == '(' || s[i] == '[') push(pilha,s[i]); //se for abertura entra na pilha

        else if (s[i] == ')') // se for um fechamento testa
        {
            if (is_empty(pilha)) //se pilha vazia para
            {
                k++;
                
                break;
            }
            else if (peek(pilha) == '(') // se for correspondente
            {
                pop(pilha); // tira
            }

            else if (peek(pilha) == '[') //se nao for correspondente
            {
                k++;
                break;
            }
        }

        else if (s[i] == ']')// se for um fechamento testa
        {
             //printS(pilha);
            if (is_empty(pilha)) //se for vazia para
            {
                k++;
                break;
            }
            else if (peek(pilha) == '[') // se for correspondente
            {
                pop(pilha); // tira
            }
            else if (peek(pilha) == '(')
            {
                k++;
                break;
            }
        }
    }

    //printS(pilha);
    vazio:
    if (is_empty(pilha) && k == 0) printf("Yes\n");
    else
    {
        //vazio:
        //printf("%d\n", is_empty(pilha));
        //printf("%d\n", k);
        printf("No\n");
    }

}

int main()
{
    
    int entradas, i, n;
    char s[256];
    Stack *pilha;
    scanf("%d ", &entradas);
    for (i = 0; i < entradas; i++)
    {
        pilha = createstack();
        gets(s);
        n = strlen(s);
        balance(pilha, s, n, 0);
        while (!is_empty)
        {
            pop(pilha);
        }
        printS(pilha);

               
        
    }
    
    

    return 0;
}