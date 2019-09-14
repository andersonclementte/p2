#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int numero;
    struct tree* left;
    struct tree* right;
}Tree;

Tree* startemptytree()
{
    return NULL;
}

Tree* newtree(int item)
{
    Tree* new_tree = (Tree*)malloc(sizeof(Tree));
    new_tree->numero = item;
    new_tree->left = NULL;
    new_tree->right = NULL;
    return new_tree;
}

Tree* linktrees(Tree* root, Tree* left, Tree* right)
{
    Tree* new_tree = root;
    new_tree->left = left;
    new_tree->right = right;
    return new_tree;
}

int maxDepth(Tree* node)  
{ 
   if (node==NULL) return 0; 
   else 
   { 
       
       int lDepth = maxDepth(node->left); 
       int rDepth = maxDepth(node->right); 
  
       if (lDepth > rDepth) return(lDepth+1); 
       else return(rDepth+1); 
   } 
}

void maxmin(Tree* root, int max[], int min[], int lvl)
{
    if (root != NULL)
    {
        maxmin(root->left,max,min,lvl+1);
        if (root->numero < min[lvl]) min[lvl] = root->numero;
        if (root->numero > max[lvl]) max[lvl] = root->numero;
        maxmin(root->right,max,min,lvl+1);
    }
}

void maxmintool(Tree* root)
{
    int i, n = maxDepth(root);
    int min[n], max[n];
    for (i = 0; i < n; i++)
    {
        min[i] = 1<<20;
        max[i] = 0;
    }

    maxmin(root, max, min, 0);
    for( i = 0 ; i < n ; ++i )
		printf("Nivel %d: Maior = %d, Menor = %d\n", i+1 , max[i] , min[i] );
}

int is_empty (Tree *tree) {
    if (tree == NULL) return 1;
    else return 0;
}

void generate_parenthesis_btree(Tree *bt) {
    printf("(");
    if(!is_empty(bt)) {
        printf("%d", bt->numero);
        generate_parenthesis_btree(bt->left);
        generate_parenthesis_btree(bt->right);
    }
    printf(")");
}


int main()
{
    Tree* arvore = startemptytree();
    Tree* aux = startemptytree();
    int nodes;
    scanf("%d", &nodes);

    Tree* arvorelist[nodes];
    int esquerda[nodes], direita[nodes], digito, i;

    for (i = 0; i < nodes; i++)
    {
        scanf("%d%d%d", &digito, &esquerda[i], &direita[i]);
        arvorelist[i] = newtree(digito);
    }

    for (i = 0; i < nodes; i++)
    {
        if (esquerda[i] == -1 && direita[i] == -1) arvore = linktrees(arvorelist[i], NULL, NULL);
        else if (esquerda[i] == -1) arvore = linktrees(arvorelist[i], NULL, arvorelist[direita[i]]);
        else if (direita[i] == -1) arvore = linktrees(arvorelist[i], arvorelist[esquerda[i]], NULL);
        else arvore = linktrees(arvorelist[i], arvorelist[esquerda[i]], arvorelist[direita[i]]);
        if (i == 0) aux = arvore;
    }

    maxmintool(aux);
    //printf("profundidade da arvore: %d\n", maxDepth(arvore));
}