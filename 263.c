#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int item;
    struct node* next;
}Node;

//headers
Node* createlist();
int isempty(Node* head);
Node* add(Node* head, int item);
void printL(Node* head);
Node* search(Node* head, int item);
Node* remover(Node* head, int item);
Node* intersec(Node* headA, Node* headB);
void swap(Node* A, Node* B);
void bsortList(Node* head);
void tirarigual(Node* head);

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

    if (head == NULL) printf("VAZIO");
    else{
        while (head != NULL){
        printf("%d\n", head->item);
        head = head->next;
    }
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


Node* intersec(Node* headA, Node* headB){

    Node* result = NULL;
    Node* p;
    Node* q;

   for(p = headB; p != NULL; p = p->next){
        for (q = headA; q != NULL; q = q->next){
            if (q->item == p->item) result = add(result, q->item);
        }
    }

    //result = bsortList(result);
    return result;
   
}

void swap(Node* A, Node* B){

    int temp = A->item;
    A->item = B->item;
    B->item = temp;
}

void bsortList(Node* head){
    
    int i, trocado;
    Node* t1;
    Node* t2 = NULL;

    //checar lista vazia;
    if (head == NULL) return;

    do
    {
        /* code */
        trocado = 0;
        t1 = head;

        while (t1->next != t2){

            if (t1->item > t1->next->item){
                swap(t1, t1->next);
                trocado = 1;
            }
            t1 = t1->next;
            
        }
        t2 = t1;
    } while (trocado);
    
}

void tirarigual(Node* head){

    Node* current = head;
    Node* next_next;

    if (current == NULL) return;

    while (current->next != NULL){
        
        if (current->item == current->next->item)
        {
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }
        else{
        current = current->next;
    }
    }

    
}

//main
int main()
{
    Node* A = createlist();
    Node* B = createlist();
    Node* C;

    int lA, lB, item, i;
    for(i = 20; i > 0; i--){
        scanf("%d", &item);
        A = add(A, item);
    }
    for (i = 20; i > 0; i--){
        scanf("%d", &item);
        B = add(B, item);
    }

    C = intersec(A, B);
    printf("Intersec:\n");
    printL(C);
    printf("Ordenado:\n");
    bsortList(C);
    printL(C);
    printf("R. Final:\n");
    tirarigual(C);
    printL(C);
    
  

    /* printf("Lista 1\n");
    printL(A);
    printf("\n");
    printf("Lista 2\n");
    printL(B);
    */

    return 0;
}