#include <stdio.h>
#include <stdlib.h>

typedef struct binary_tree{
    int item;
    struct binary_tree* left;
    struct binary_tree* right;
}Tree;

Tree* startemptytree()
{
    return NULL;
}
Tree* newtree(int item, Tree* left, Tree* right)
{
    Tree* new_tree = (Tree*)malloc(sizeof(Tree));
    new_tree->item = item;
    new_tree->left = left;
    new_tree->right = right;
    return new_tree;
}

int empty(Tree* bt)
{
    if (bt == NULL) return 1;
    else return 0;
}

Tree* add(Tree* bt, int item)
{
    if (bt == NULL){
        bt = newtree(item, NULL, NULL);
    }

    else if (bt->item > item){
        bt->left = add(bt->left, item);
    }

    else{
        bt->right = add(bt->right, item);
    }

    return bt;
    
}

void inorder(Tree* bt)
{
    if (!empty(bt))
    {
        inorder(bt->left);
        printf("%d", bt->item);
        inorder(bt->right);
    }
}

void preorder(Tree* bt)
{
    if(!empty(bt))
    {
        printf("( %d ", bt->item);
        preorder(bt->left);
        preorder(bt->right);
        printf(") ");
    }
    else
    {
        printf(" () ");
    }
    
}

void postorder(Tree* bt)
{
    if (!empty(bt))
    {
        preorder(bt->left);
        preorder(bt->right);
        printf("%d", bt->item);
    }
}


int main()
{
    int i;
    Tree* arvore = startemptytree();
    while (scanf("%d", &i) != EOF)
    {
        arvore = add(arvore, i);
        printf("----\n");
        printf("Adicionando %d\n   ", i);
        preorder(arvore);
        
    }
    printf("----\n");
    return 0;
}