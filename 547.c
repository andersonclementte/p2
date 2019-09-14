#include <stdio.h>
#include <stdlib.h>

typedef struct binary_tree{
    int item;
    struct binary_tree* left;
    struct binary_tree* right;
}Tree;

Tree* newleaf(int item, Tree* left, Tree* right)
{
    Tree* new_tree = (Tree*) malloc(sizeof(Tree));
    new_tree->item = item;
    new_tree->left = left;
    new_tree->right = right;
    return new_tree;
}
 
Tree* construct_binary_tree(char *str, int *pos) {
 
    Tree *btree = NULL; 
    int i = 0;
    int numInt;       
    char numStr[100];  
 
    while(str[*pos] == '(') {
        *pos += 1;
    }
 
    if(str[*pos] == ')') { 
        *pos += 1;
        return NULL;
    }
    else {
        while(str[*pos] != '(') {   
            numStr[i++] = str[*pos];
            *pos += 1;
        }
        numStr[i] = '\0';
        numInt = atoi(numStr);
 
        btree = newleaf(numInt, NULL, NULL); 
        btree->left = construct_binary_tree(str, pos); 
        btree->right = construct_binary_tree(str, pos); 
    }
 
    *pos += 1;
    return btree;
}

int ifNodeExists(Tree* node, int key) 
{ 
    if (node == NULL) return 0;
  
    if (node->item == key) return 1;
  
    int res1 = ifNodeExists(node->left, key); 
  
    int res2 = ifNodeExists(node->right, key); 
  
    return res1 || res2; 
}

int leveltool (Tree* bt, int item, int level)
{
    if (bt == NULL) return 0;
    if (bt->item == item) return level;
    int downlevel = leveltool(bt->left, item, level+1);
    if (downlevel != 0) return downlevel;
    downlevel = leveltool (bt->right, item, level+1);
    return downlevel;
}

int getlevel (Tree* bt, int numero)
{
    return leveltool(bt,numero,0);
}

int main()
{
    Tree* arvore;
    int p=0;
    char* str;
    str = malloc(sizeof(char)*400);
    fgets(str, 400, stdin);
    arvore = construct_binary_tree(str, &p);
    int k;
    scanf("%d", &k);
    if (ifNodeExists(arvore, k))
    {
        printf("ESTA NA ARVORE\n");
        printf("%d\n", getlevel(arvore,k));
    }
    else printf("NAO ESTA NA ARVORE\n-1");
}