#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int current_size;
    int items[70];
}Stack;


//headers
Stack* createstack();
void push(Stack* stack, int item);
int is_empty(Stack* stack);
int pop(Stack* stack);
int peek (Stack* stack);
void printS(Stack* stack);
int size(Stack* stack);
int delete(Stack* stack);
//func
Stack* createstack()
{
    Stack* newstack = (Stack*) malloc(sizeof(Stack));
    newstack->current_size = 0;
    return newstack;
}

void push(Stack* stack, int item)
{
    if (stack->current_size == 70) printf("Stack overflow\n");
    else stack->items[stack->current_size++] = item;
}

int is_empty(Stack* stack)
{
    if (stack->current_size == 0) return 1;
    else return 0;
}

int pop(Stack* stack)
{
    if (is_empty(stack))
    {
        printf("Stack underflow\n");
        return -1;
    }
    else return stack->items[--stack->current_size];
}

int peek (Stack* stack)
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

int is_full(Stack* stack)
{
    if (stack->current_size == 70) return 1;
    else return 0;
}

int size(Stack* stack)
{
    return (stack->current_size);
}

int delete(Stack* stack)
{
    while (!is_empty) pop(stack);
    free(stack);
}

int main()
{
    char set[20];
    int current = 0;
    Stack* back = createstack();
    Stack* forward = createstack();
    
    while (scanf("%s ", set) != EOF)
    {
        if (set[0] == 'E') //se for enter
        {
            if (current == 0) current++; //e se for a primeira nao tem back
            else push(back, 1); //do contrario tem 1
            while (!is_empty(forward)) pop(forward); //se entrou não tem forward
        }

        else if (set[0] == 'B')
        {
            if (!is_empty(back)) //se não vazio
            {
                pop(back); //tira 1 do back
                push(forward, 1); //add 1 no forward
            }
            else current = 0; //do contrario é a primeira pagina
        }

        else
        {
            if(!is_empty(forward)) //se n vazio
            {
                pop(forward);
                push(back, 1);
            }
        }
        
    }
    printf("BACK: %d\nFORWARD: %d\n", size(back), size(forward));
    delete(back);
    delete(forward);

    return 0;
}