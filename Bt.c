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

int tree_level(binary_tree *bt, int item, int p)
{
  
  if(bt==NULL)
    return 0;

  else if(bt->item==item)
    return p;

  int level = tree_level(bt->left,item,p+1);
  if(level!=0)
    return level;

  level= tree_level(bt->right,item,p+1);
  //return in_tree(bt->left,item,p) || in_tree(bt->right,item,p);
}

int tree_height(binary_tree *bt)
{
  if(bt==NULL)
    return 0;

  else
  {
    int hleft=tree_height(bt->left);
    int hright=tree_height(bt->right);

    if(hleft > hright)
      return hleft+1;
    else
      return hright+1;
  }
}

void max__min_value(binary_tree *bt, int max[], int min[], int level)
{
  if(bt==NULL)
    return;
  if(max[level] < bt->item)
  {
    max[level]=bt->item;
  }
  if(min[level] > bt->item)
  {
    min[level]=bt->item;
  }

  max__min_value(bt->right,max,min,level+1);
  max__min_value(bt->left,max,min,level+1);


}

void print_tree(binary_tree *bt)
{
  if (bt!=NULL) 
  {
    printf(" ( %d ", bt->item);
    print_tree(bt->left);
    print_tree(bt->right);
  }
 /* else 
  {
    printf(" (");
    printf(") ");
  }*/
}


int main()
{
  char *s;
  int k=0, item, p=1, level;
  int *i=&k;
  s=read_tree();
  binary_tree *bt=construct_tree(s,i);
  scanf("%d", &item);
  level=tree_level(bt, item,p);
  if(level)
  {
    printf("ESTA NA ARVORE\n%d", level-1);
  }
  else
  {
    printf("NAO ESTA NA ARVORE\n-1");
  }
  return 0;
} 
