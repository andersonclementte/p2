#include <stdio.h>
#include <stdlib.h>

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
int compareset(Node* A, Node* B);//verifica A subconjunto de B

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

int compareset(Node* A, Node* B){
    Node* p;
    Node* q;

    for(p = B; p != NULL; p = p->next){
        for (q = A; q != NULL; q = q->next){
            if (q->item == p->item) break; // elemento encontrado sem necessidade de seguir adiante
        }
        if (q == NULL) return 0; //pelo menos um elemento de A não está em B
    }

    return 1;

}

int main()
{
    Node* list1 = createlist();
    Node* list2 = createlist();

    int l1, l2, item, i;

    scanf("%d", &l1); //tamanho da primeira
    for (i = 0; i < l1; i++){
        scanf("%d", &item); //coleta
        list1 = add(list1, item);
    }

    scanf("%d", &l2);//tamanho da segunda
    for(i = 0; i < l2;  i++){
        scanf("%d", &item);
        list2 = add(list2, item);
    }

    printf("%d", compareset(list1, list2));

    /*printf("Lista 1\n");
    printL(list1);
    printf("\n");
    printf("Lista 2\n");
    printL(list2);*/
    return 0;
}