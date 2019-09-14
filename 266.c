#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    /* data */
    int item;
    struct node* next;
}Node;

//headers
Node* createlist();
Node* add(Node* head, int item);
void printL(Node* head);
Node* swap(Node* t1, Node* t2);
int bubblesort(Node** head, int count);
int size(Node* head);

//funções
Node* createlist(){
    return NULL;
}

Node* add(Node* head, int item){

    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->item = item;
    new_node->next = head;
    return new_node;
}

void printL(Node* head){

    while (head != NULL){
        printf("%d ", head->item);
        head = head->next;
    }
}

Node* swap(Node* t1, Node* t2){

    Node* temp = t2->next;
    t2->next = t1;
    t1->next = temp;
    return t2;
}

int bubblesort(Node** head, int count){

    int i, j, trocado;
    Node** h;
    
    for (i = 0; i <= count; i++){

        h = head;
        trocado = 0;

        for (j = 0; j < count - i - 1; j++){

            Node* p1 = *h;
            Node* p2 = p1->next;

            if (p1->item > p2->item){
                //atualiza o link dps de trocar
                *h = swap(p1, p2);
                trocado = 1;
            }

            h = &(*h)->next;
        }

        //para se o loop termina sem trocar
        if (trocado == 0) break;


    }
}

int size(Node* head){
    int count = 0;
    Node* current = head;

    while(current != NULL){
        count++;
        current = current->next;
    }
    return count;
}

int main()
{
    Node* A = createlist();

    int item, tam;
    while (scanf("%d", &item) != EOF){
        A = add(A, item);
        getchar();
    }

    tam = size(A);
    bubblesort(&A, tam);
    printL(A);

    return 0;
}