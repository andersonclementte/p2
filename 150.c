#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct arvore{
    int item;
    struct arvore* esquerda;
    struct arvore* direita;
}Tree;

Tree* cria_arvore(int item)
{
    Tree* nova_arvore = (Tree*) malloc(sizeof(Tree*));
    nova_arvore->item = item;
    nova_arvore->esquerda = nova_arvore->direita = NULL;
    return nova_arvore;
}

int f_esquerda(int i)
{
    return 2*i;
}

int f_direita(int i)
{
    return (2*i) + 1;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int retornaP(Tree* arvore)
{
    if (arvore->esquerda == NULL && arvore->direita == NULL) 
        return arvore->item;
    else
        return max((arvore->item*retornaP(arvore->direita)), (arvore->item*retornaP(arvore->esquerda)));
}

int main()
{
    int h, array[MAX], i = 1, j;
    Tree* nos[MAX];

    scanf("%d", &h);

    while (scanf("%d", &array[i]) != EOF)
    {
        nos[i] = cria_arvore(array[i]);
        i++;
    }

    for(j = 1; j <= i; j++)
    {
        if (nos[j] != NULL)
        {
            nos[j]->esquerda = nos[f_esquerda(j)];
            nos[j]->direita = nos[f_direita(j)];
        }
    }
    printf("%d", retornaP(nos[1]));
    return 0;
}