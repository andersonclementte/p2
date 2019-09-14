#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int item;
    int altura;
    struct tree* left;
    struct tree* right;
}Tree;

Tree* treeinit()
{
    return NULL;
}

Tree* newleaf(int item, Tree* left, Tree* right)
{
    Tree* nova_folha = (Tree*) malloc(sizeof(Tree));
    nova_folha->item = item;
    nova_folha->altura = 1;
    return newleaf;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(Tree* node)
{
    if ()
}