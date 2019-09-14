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

Tree* addleaf(int item, Tree* left, Tree* right)
{
    Tree* newleaf = (Tree*) malloc(sizeof(Tree));
    newleaf->item = item;
    newleaf->left = left;
    newleaf->right = right;
    return newleaf;
}

int is_empty(Tree* root)
{
    return root == NULL;
}


Tree* add(Tree* bt, int raiz[], int left[], int right[], int i)
{
    if (i == -1) return NULL;
    else
    {
        bt = addleaf(raiz[i], NULL, NULL);
    }

    bt->left = add(bt->left, raiz, left, right, left[i]);
    bt->right = add(bt->right, raiz, left, right, right[i]);
    return bt;
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

void pre_order(Tree* bt, int height)
{
    if (bt != NULL)
    {
        int i;
        for (i = 0; i < height; i++)
        {
            printf("\t");
        }
        printf("%4d\n", bt->item);
        pre_order(bt->left, height+1);
        pre_order(bt->right, height+1);
    }
    
}

void in_order(Tree* bt, int height)
{
    if (bt != NULL)
    {
        int i;
        in_order(bt->left, height+1);
        for (i = 0; i < height; i++)
        {
            printf("\t");
        }
        printf("%4d\n", bt->item);
        in_order(bt->right, height+1);
        
    }
    
}

void post_order(Tree* bt, int height)
{
    if (bt != NULL)
    {
        int i;
        post_order(bt->left, height+1);
        post_order(bt->right, height+1);
        for (i = 0; i < height; i++)
        {
            printf("\t");
        }
        printf("%4d\n", bt->item);
        
    }
    
}



int main()
{
    int nodes, lines;
    scanf("%d %d", &nodes, &lines);

    int i, raiz[nodes], left[nodes], right[nodes];
    for (i = 0; i < nodes; i++)
    {
        raiz[i] = i;
        left[i] = -1;
        right[i] = -1;
    }

    for(i = 0; i < lines; i++)
    {
        scanf("%d %d %d", &raiz[i], &left[i], &right[i]);
    }

    Tree* arvore = NULL;
    arvore = add(arvore, raiz,left,right,0);
    //print_tree(arvore);
    printf("Preorder print:\n");
    pre_order(arvore, 1);
    printf("Inorder print:\n");
    in_order(arvore, 1);
    printf("Postorder print::\n");
    post_order(arvore, 1);



    return 0;
}