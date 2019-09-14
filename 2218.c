#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int number;
    struct tree* left;
    struct tree* right;
}Tree;

Tree* startemptytree()
{
    return NULL;
}

Tree* newleaf(int item, Tree* left, Tree* right)
{
    Tree* new_tree = (Tree*)malloc(sizeof(Tree));
    new_tree->number = item;
    new_tree->left = left;
    new_tree->right = right;
    return new_tree;
}

int is_empty(Tree* root){
    return root == NULL;
}

void print_tree(Tree* bt)
{
  if (bt!=NULL) 
  {
    printf(" ( %d ", bt->number);
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

Tree* add(Tree* bt, int matriz[][2], int number)
{
    if (number == -1) return NULL;
    else
    {
        bt = newleaf(number, NULL, NULL);
        bt->left = add(bt, matriz, matriz[number][0]);
        bt->right = add(bt, matriz, matriz[number][1]);
        return bt;
    }
}


int main()
{
    int i, j, nodes, root;
    scanf("%d", &nodes);
    int matriz[nodes][2];

    for (i = 0; i < nodes; i++){
        for (j = 0; j < 2; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    scanf("%d", &root);

    Tree* arvore = startemptytree();
    arvore = add(arvore, matriz, root);
    

    return 0;
}