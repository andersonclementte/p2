#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int item;
    struct tree* left;
    struct tree* right;
}Tree;

Tree* treeinit()
{
    return NULL;
}

Tree* addfolha(int item, Tree* left, Tree* right)
{
    Tree* nova_folha = (Tree*)malloc(sizeof(Tree));
    nova_folha->item = item;
    nova_folha->left = left;
    nova_folha->right = right;
    return nova_folha;
}

int is_empty(Tree* root)
{
    return root == NULL;
}

Tree* montaarvore(Tree* root, int left[], int right[], int i)
{
    if (i == -1) return NULL;
    else
    {
        root = addfolha(i, NULL, NULL);
    }

    root->left = montaarvore(root->left, left, right, left[i]);
    root->right = montaarvore(root->right, left, right, right[i]);
    return root;   
}

void print_tree(Tree* bt)
{
  if (bt!=NULL) 
  {
    printf(" ( %d ", bt->item);
    print_tree(bt->left);
    print_tree(bt->right);

    printf(" )");
  }

  else 
  {
    printf(" (");
    printf(") ");
  }
}

int is_leaf(Tree* root)
{
    if(root->left == NULL && root->right == NULL) return 1;
    else return 0;
}

int dadyofleaf(Tree* root)
{
    if (is_leaf(root->left) || is_leaf(root->right))
        return 1;
    else return 0;
}

void listresult(Tree* root)
{
    if (is_leaf(root)) return;
    if(dadyofleaf(root)){
        printf("%d\n", root->item);
        //array[*indice] = root->item;
        //(*indice)++;
    }
    
    listresult(root->right);
    listresult(root->left);
    
}

int main()
{
    int nodes, i;
    scanf("%d", &nodes);
    int esquerda[nodes], direita[nodes];
    for (i = 0; i < nodes; i++)
    {
        scanf("%d %d", &esquerda[i], &direita[i]);
    }

    Tree* arvore = NULL;
    arvore = montaarvore(arvore, esquerda, direita, 0);
    print_tree(arvore);
    printf("\n");
    int array[nodes];
    int indice = 0;
    listresult(arvore);
    //for(i = 0; i < indice; i++){
      //  printf("%d\n", array[i]);
    //}
    //printf("%d\n", indice);
    return 0;
}