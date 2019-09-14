#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int item;
    struct node* next;
}Node;

//headers
Node* createlist();
void add(Node** head, int item);
void printL(Node* head);
Node* search(Node* head, int item);
Node* remover(Node* head, int item);

//fun��es

Node* createlist(){
    return NULL;
}

void add(Node** head, int item){
    Node* new_node = (Node*) malloc(sizeof(Node));
    Node* last = *head;
    new_node->item = item;
    new_node->next = NULL;
    
    if(*head == NULL){
        *head = new_node;
        return;
    }

    while (last->next != NULL){
        last = last->next;
    }
    last->next = new_node;
}

void printL(Node* head){
    while (head != NULL){
        printf("%d ", head->item);
        head = head->next;
    }
}

Node* search(Node* head, int item){

    while(head != NULL){
        if (head->item == item) return head;
        head = head->next;
    }
     return NULL;
}

Node* remover(Node* head, int item){

    Node* previous = NULL;
    Node* current = head;

    while (current != NULL && current->item != item){
        previous = current;
        current = current->next;
    }

    if (current == NULL){
        return head;
        }
    if (previous == NULL){
        head = current->next;
    }
    else {
        previous->next = current->next;
    }
    free(current);
    return head;
}

void reverse(Node** head_ref){

    Node* prev = NULL;
    Node* current = *head_ref;
    Node* next;

    while(current != NULL){
        next  = current->next;   
        current->next = prev;    
        prev = current; 
        current = next; 
    }
    *head_ref = prev;
}

//main
int main()
{
    Node* A = createlist();

    int lA, item, i;
    while ((scanf("%d", &item) != EOF)){
        add(&A, item);
        getchar();
    }

    //printf("Lista dada:\n");
    //printL(A);
    //printf("\nLista invertida\n");
    reverse(&A);
    printL(A);
    return 0;
}
