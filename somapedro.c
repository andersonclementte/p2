#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
 
 
typedef struct binary_tree binary_tree;
 
struct binary_tree{
  int item;
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
 
char* read_tree()
{
  char c;
  char *s=(char*)malloc(500*sizeof(char));
  int op=0, cl=0, i=0;
  scanf("%c", &c);
  for(;;)
  {
    if(c != ' ' && c != '\n')
    {
      s[i++] = c;
    }
 
    if(c == '(')
      op++;
    else if(c==')')
      cl++;
 
    if(op==cl)
      break;
 
    scanf("%c", &c);
  }
  s[i] = '\0';
  return s;
}
 
binary_tree* construct_tree(char *s, int *i)
{
  binary_tree *bt=create_empty_tree();
  if(s[(*i)++] == '(')
  {
    if(s[*i] == ')')
    {
      (*i)++;
      return NULL;
    }
 
    char num[100];
    int j=0, x;
    while(s[*i] != '(')
    {
      num[j++] = s[(*i)++];
    }
 
    num[j]='\0';
    x=atoi(num);
  
    bt=create_binary_tree(x,NULL,NULL);
    bt->left=construct_tree(s,i);
    bt->right=construct_tree(s,i);
  }
  (*i)++;
  return bt;
}
 
void print_tree(binary_tree *bt)
{
  if (bt!=NULL)
  {
    printf("%d ", bt->item);
    print_tree(bt->left);
    print_tree(bt->right);
  }
}
 
void soma_nivel(binary_tree *bt, int n, int *soma, int level)
{
  if(bt==NULL)
    return;
  if(level == n)
  {
    (*soma)+=bt->item;
  }
  soma_nivel(bt->right,n,soma,level+1);
  soma_nivel(bt->left,n,soma,level+1);
 
 
}
 
int main()
{
  char *s;
  int k=0, n;
  int soma=0;
  scanf("%d", &n);
  getchar();
  binary_tree *bt=create_empty_tree();
  s=read_tree();
  bt=construct_tree(s,&k);
  print_tree(bt);
  soma_nivel(bt,n,&soma,0);
  printf("\n%d", soma);
 
  return 0;
}