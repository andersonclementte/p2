#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct dataNode{
    int id;
}DataNode;

typedef struct node{
    DataNode data;
    struct node* next;
}Node;

typedef struct list{
    int size;
    Node* head;
}List;

//Headers
List* createList();
void push(List* list, DataNode data);
void printList(List* list);
void pop(List* list);
bool isEmpty(List* list);
void pop(List* list);
Node* atPos(List* list, int index);
int indexOf(List* list, Node* node);
void erase(List* list, int index);
void insert(List* list, DataNode data, int index);
void xchgNodes(List* list, Node* nodeA, Node* nodeB);

//Funções
List* createList(){
    List* list = (List*) malloc(sizeof(List));

    list->size = 0;
    list->head = NULL;

    return list;
}

void push(List* list, DataNode data){
    Node* node = (Node*)malloc(sizeof(Node));

    node->data = data;
    node->next = list->head;
    list->head = node;
    list->size++;
}

void printList(List* list){
    
    if(isEmpty(list)){
         printf("Lista Vazia");
         return;
    }
    Node* pointer = list->head;
    while(pointer != NULL){
        printf("%d ", pointer->data.id);
        pointer = pointer->next;
    }
    printf("\n");
}

bool isEmpty (List* list){
    return (list->size == 0);
}

void pop(List* list){
    if (!isEmpty(list)){
        Node* pointer = list->head; 
        list->head = pointer->next;
        free(pointer);
        list->size--;
    }
}

Node* atPos(List* list, int index){
    
    if(index >= 0 && index < list->size){
        Node* node = list->head;
        int i;
        for(i = 0; i < index; i++){
            node = node->next;

            return node;
        }
    }
    printf("Indice invalido\n");
    return NULL;
}

int indexOf(List* list, Node* node){
    if (node != NULL){
        Node* pointer = list->head;

        int index = 0;
        while (pointer != node && pointer != NULL){
            pointer = pointer->next;
            index++;
        }
        if(pointer != NULL) return index;
    }
    printf("No nao pertencente a lista\n");
    return -1;
}

void erase(List* list, int index){

    if (index == 0){
        pop(list);
    }

    else{
        Node* current = atPos(list, index);

        if (current != NULL){ 
            Node* previous = atPos(list, index-1);
            previous->next = current->next;
            free(current);
            list->size--;
        }
        
    }
}

void insert(List* list, DataNode data, int index){

    if( index == 0){
        push(list, data);
    }
    else {
        Node* current = atPos(list, index);
            if(current != NULL){
                Node* previous = atPos(list, index-1);
                Node* newNode = (Node*) malloc(sizeof(Node));
                newNode->data = data;
                previous->next = newNode;
                newNode->next = current;
                list->size++;
            }
    }
}

void xchgNodes(List* list, Node* nodeA, Node* nodeB){

    if(nodeA == nodeB) return;

    int indexA = indexOf(list, nodeA);
    int indexB = indexOf(list, nodeB);

    if(indexA > indexB) {
        nodeA = nodeB;
        nodeB = atPos(list, indexA);

        indexA = indexB;
        indexB = indexOf(list, nodeB);

    }

    Node* pb = atPos(list, indexB - 1);

    if(nodeA == list->head){
        list->head = nodeB;
    }

    else {
        Node* pa = atPos(list, indexA - 1);
        pa->next = nodeB;
    }

    pb->next = nodeA;
    Node* pointer = nodeA->next;
    nodeA->next = nodeB->next;
    nodeB->next = pointer;
    

}

int main()
{
    List* l = createList();
    
    DataNode data;
    data.id = 5;
    push(l, data);

    data.id = 9;
    push(l, data);

    data.id = 8;
    push(l, data);

    data.id = 10;
    push(l, data);

    printList(l);

    
    return 0;
}