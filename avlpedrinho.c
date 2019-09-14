#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
//AVL
 
typedef struct binary_tree binary_tree;
 
struct binary_tree{
  int item;
  int h;
  binary_tree *left;
  binary_tree *right;
};
 
binary_tree* create_empty_tree()
{
  return NULL;
}
 
binary_tree* create_binary_tree(int item,binary_tree *left, binary_tree *right)
{
  binary_tree *new=(binary_tree*)malloc(sizeof(binary_tree));
  new->item=item;
  new->left=left;
  new->right=right;
  return new;
}
 
void print_tree(binary_tree *bt)
{
  if (bt!=NULL)
  {
    printf(" ( %d ", bt->item);
    print_tree(bt->left);
    print_tree(bt->right);
    printf(") ");
  }
  else
  {
    printf(" (");
    printf(") ");
  }
}
 
int max(int a ,int b)
{
  return (a>b) ? a: b;
}
 
int h(binary_tree *bt)
{
  if(bt == NULL)
    return -1;
  else
  {
    return 1+max(h(bt->left),h(bt->right));
  }
}
 
int is_balanced(binary_tree *bt)
{
  int bf = h(bt->left) - h(bt->right);
  return((-1 <= bf) && (bf <=1));
}
 
int balance_factor(binary_tree *bt)
{
  if (bt==NULL)
    return 0;
 
  else if((bt->left != NULL) && (bt->right != NULL))
  {
    return(bt->left->h - bt->right->h);
  }
  else if((bt->left != NULL) && (bt->right == NULL))
  {
    return(1+bt->left->h);
  }
  else
    return(-bt->right->h - 1);
}
 
binary_tree* rotate_left(binary_tree *bt)
{
  binary_tree *subtree = NULL;
  if(bt!= NULL && bt->right != NULL)
  {
    subtree=bt->right;
    bt->right = subtree->left;
    subtree->left=bt;
  }
 
  subtree->h=h(subtree);
  bt->h=h(bt);
  return subtree;
}
 
binary_tree* rotate_right(binary_tree *bt)
{
  binary_tree *subtree = NULL;
  if(bt!= NULL && bt->left != NULL)
  {
    subtree=bt->left;
    bt->left = subtree->right;
    subtree->right=bt;
  }
 
  subtree->h=h(subtree);
  bt->h=h(bt);
  return subtree;
}
 
binary_tree* add(binary_tree *bt, int item,int *flag,binary_tree *aux)
{
  if(bt == NULL)
  {
    return create_binary_tree(item,NULL,NULL);
  }
  else if(bt->item > item)
  {
    bt->left = add(bt->left,item,flag,aux);
  }
  else
  {
    bt->right = add(bt->right, item,flag,aux);
  }
 
  bt->h= h(bt);
  binary_tree *child;
 
  if(balance_factor(bt) == 2 || balance_factor(bt) == -2)
  {
    (*flag)++;
    printf("Antes de ajustar balanceamento...\n  ");
    print_tree(aux);
    printf("\n");
    if(balance_factor(bt) == 2)
    {
      child = bt->left;
      if(balance_factor(child) == -1)
      {
        bt->left = rotate_left(child);
      }
      bt=rotate_right(bt);
    }
    else if(balance_factor(bt) == -2)
    {
      child = bt->right;
      if(balance_factor(child) == 1)
      {
        bt->right = rotate_right(child);
      }
      bt=rotate_left(bt);
    }
  }
  return bt;
}
 
int main()
{
    int n,i,flag=0;
    binary_tree *bt=create_empty_tree();
    scanf("%d", &n);
    printf("----\n");
    printf("Adicionando %d\n", n);
    bt=add(bt,n,&flag,bt);        
    printf("Continuou AVL...\n  ");
    print_tree(bt);
    printf("\n");
 
    while(scanf("%d", &n) != EOF)
    {  
        printf("----\n");
        printf("Adicionando %d\n", n);
        bt=add(bt,n,&flag,bt);
        if(flag > 0)
        {
            printf("Depois de ajustar balanceamento...\n  ");
            print_tree(bt);
            printf("\n");
        }
        else
        {
            printf("Continuou AVL...\n  ");
            print_tree(bt);
            printf("\n");
        }
        flag=0;
    }
    printf("----");
}