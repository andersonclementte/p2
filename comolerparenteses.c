//questão soma em nivel
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree{
    int item;
    struct tree* left;
    struct tree* right;
}Tree;

Tree* novafolha(int item, Tree* left, Tree* right)
{
    Tree* new = (Tree*)malloc(sizeof(Tree));
    new->item = item;
    new->left = left;
    new->right = right;
    return new;
}

char* load_tree() //formata string para arvore e retorna a tring
{
    char caracter;
    char* string = (char*) malloc(sizeof(char)*500);
    int open = 0, close = 0, i = 0;
    scanf("%c", &caracter);
    while(1)
    {
        if (caracter != ' ' && caracter != '\n'){
            string[i++] = caracter;
        }

        if(caracter == '(') open++;
        else if(caracter == ')') close++;
        
        if(open == close) break;

        scanf("%c", &caracter);
    }
    string[i] = '\0';
    return string;
}

Tree* build_tree(char* string, int* i)
{
    Tree* arvore = NULL;

    if(string[(*i)++] == '('){
        if(string[*i] == ')'){
            (*i)++;
            return NULL;
        }

        char num[100];
        int x, j = 0;
        while (string[*i] != '(')
        {
            num[j++] = string[(*i)++];
        }

        num[j] = '\0';
        x = atoi(num);

        arvore = novafolha(x, NULL, NULL);
        arvore->left = build_tree(string, i);
        arvore->right = build_tree(string, i);
    }
    (*i)++;
    return arvore;
}

void print_tree(Tree* bt)
{
  if (bt!=NULL)
  {
    printf("%d ", bt->item);
    print_tree(bt->left);
    print_tree(bt->right);
  }
}

void somanivel(Tree* root, int* soma, int alvo, int lvl)
{
    if (root == NULL) return;
    if (lvl == alvo) (*soma) += root->item;
    somanivel(root->left,soma,alvo,lvl+1);
    somanivel(root->right,soma,alvo,lvl+1);
}

int main()
{
    char* s;
    int target, aux = 0, soma = 0;
    scanf("%d", &target);
    getchar();

    Tree* arvore = NULL;
    s = load_tree();
    arvore = build_tree(s,&aux);
    print_tree(arvore);

    somanivel(arvore,&soma,target,0);
    printf("\n%d", soma);

    return 0;
}