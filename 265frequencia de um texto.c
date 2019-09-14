#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char item;
    int frequencia;
    struct node* next;
}Node;


//Headers
Node* createlist();
Node* new (Node* head, char k, int x);
Node* add(Node* head, char item, int frequencia);
void printl(Node* head);
void bubble_array(char string[], int tam);
void brincadeira(char string[], int tam, Node* head);

//Funções
Node* createlist()
{
    return NULL;
}

Node* new (Node* head, char k, int x)
{
    head->item = k;
    head->frequencia = x;
    head->next = NULL;
    return head;
}

Node* add(Node* head, char item, int x)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode = new(newnode, item, x);
    newnode->next = head;
    return newnode;
}


void printL(Node* head)
{
    while (head != NULL){
        printf("%c %d\n", head->item, head->frequencia);
        head = head->next;
    }
}

void bubble_array(char string[], int tam)
{
    int n = tam;
    int i, j;
    char temp;
    for (i = 0; i < n-1; i++) {
      for (j = i+1; j < n; j++) {
         if (string[i] > string[j]) {
            temp = string[i];
            string[i] = string[j];
            string[j] = temp;
         }
      }
   }
}

void brincadeira(char string[], int tam, Node* head)
{
    int i = 0;
    int j, cont;
    //printf("%s\n", string);
    //printf("tamanho: %d\n", tam);
    while (i < tam)
    {
        cont = 1;
        for (j = i + 1; j <= tam; j++)
        {
            if (string[i]==string[j]) cont++;
            else
            {
                head = add(head, string[i], cont);
                i = j;
                break;
            }
        }
    }

    printL(head);
}



//Main
int main()
{
    char frase[256];
    scanf("%[^\n]", frase);
    int n = strlen(frase);

    Node* list = createlist();
   // printf("%s", frase);


    //printf("Frase ordenada\n");
    bubble_array(frase, n);
    brincadeira(frase, n, list);
    //printL(list);
    //printf("%s", frase);
    

    return 0;
}