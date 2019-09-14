#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int item;
    struct tree* left;
    struct tree* right;
}Tree;

Tree* add_folha(int item, Tree* left, Tree* right)
{
    Tree* nova_folha = malloc(sizeof(Tree));
    nova_folha->item = item;
    nova_folha->left = left;
    nova_folha->right = right;
    return nova_folha;
}

char* ler_tree()
{
    char caracter;
    int open = 0, close = 0, i = 0;
    char* string = (char*) malloc(sizeof(char)* 500);
    scanf("%c", &caracter);
    while (1)
    {
        if(caracter != '\n' && caracter != ' ')
            string[i++] = caracter;

        if (caracter == '(') open++;
        else if(caracter == ')') close++;

        if (open == close) break;

        scanf("%c", &caracter);
    }
    string[i] = '\0';
    return string;
}

Tree* buil_tree(char* string, int* p)
{
    Tree* arvore = NULL;

    if(string[(*p)++] == '('){
        
        if(string[*p] == ')'){
            (*p)++;
            return NULL;
        }

        int k, j = 0;
        char item[100];


        while (string[*p] != '('){
            item[j++] = string[(*p)++];
        }

        item[j] = '\0';
        k = atoi(item);

        arvore = add_folha(k, NULL, NULL);
        arvore->left = buil_tree(string, p);
        arvore->right = buil_tree(string, p);
    }
    (*p)++;
    return arvore;
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

void soma_horizontal(Tree* bt, int* soma, int targetlvl, int lvl)
{
    if (bt == NULL) return;
    if (targetlvl == lvl)
        (*soma) += bt->item;

    soma_horizontal(bt->left,soma,targetlvl, lvl+1);
    soma_horizontal(bt->right,soma,targetlvl,lvl+1);
}

int main()
{
    int level, aux = 0, result = 0;
    scanf("%d", &level);
    getchar();
    char* string;
    string = ler_tree();
    Tree* arvore = NULL;
    arvore = buil_tree(string,&aux);
    //print_tree(arvore);
    soma_horizontal(arvore,&result,level,0);
    printf("%d\n", result);
    return 0;
}