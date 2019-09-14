#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int item;
    struct node* next;
}Node;

typedef struct stack{
    struct node* top;
}Stack;

//Node* top;

//headers
Stack* init();
void push(Stack* top, int item);
int pop(Node* top);
int peek(Node* top);
int isempty(Node* top);
void display(Stack* head);
//func
Stack* init()
{
    Stack* newstack = (Stack*)malloc(sizeof(Stack));
    newstack->top = NULL;
    return newstack;
}

void push(Stack* stack, int item)
{
    Node* newtop = (Node*) malloc(sizeof(Node));
    newtop->item = item;
    newtop->next = stack->top;
    stack->top = newtop;
}

int pop(Node* top)
{
    Node* temp;
    int n;
    temp = top;
    n = temp->item;
    top = top->next;
    free(temp);
    return n;
}

int peek(Node* top)
{
    return (top->item);
}

int isempty(Node* top)
{
    return top==NULL;
}

void display(Stack* head)
{
    if (head == NULL) printf("Empty");
    else
    {
        printf("%d\n", head->item);
        display(head->next);
    }
    
}

int main()
{
    Stack* pilha = init();
    push(pilha,10);
    push(pilha,20);
    push(pilha,30);
    //printf("The top is %d\n", peek(pilha));
    //pop(pilha);
    //printf("The top after pop is %d\n",peek(pilha));
    display(pilha);

    return 0;
}
