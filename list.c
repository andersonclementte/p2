#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int item;
    struct node* next;
}Node;

//Headers
Node* createlist();
int isempty(Node* head);
Node* add(Node* head, int item);
void printL(Node* head);
Node* procura(Node* head, int item);
Node* remover(Node* head, int item);

//Funções
Node* createlist(){
    return NULL;
}

int isempty(Node* head){
    return (head == NULL);
}

Node* add(Node* head, int item){
    Node* novo_no = (Node*) malloc(sizeof(Node));
    novo_no->item = item;
    novo_no->next = head;
    return novo_no;
}

void printL(Node* head){
    while (head != NULL){
        printf("%d\n", head->item);
        head = head->next;
    }
}

Node* procura(Node* head, int item){

    while(head != NULL){
        if (head->item == item) return head;
        head = head->next;
    }
     return NULL;
}

Node* remover(Node* head, int item){

    Node* anterior = NULL;
    Node* atual = head;

    while (atual != NULL && atual->item != item){
        anterior = atual;
        atual = atual->next;
    }

    if (atual == NULL){
        return head;
        }
    if (anterior == NULL){
        head = atual->next;
    }
    else {
        anterior->next = atual->next;
    }
    free(atual);
    return head;
}


int main(void)
{
    Node* l = createlist();

    l = add(l, 3);
    l = add(l, 5);
    l = add(l, 12);
    l = add(l, 431);

    //printf("Lista: \n");
    //printL(l);

    printL(procura(l, 5));
    return 0;
}