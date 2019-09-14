#include <stdio.h>
#include <stdlib.h>
 
typedef struct binary_tree{
    int item;
    struct binary_tree* left;
    struct binary_tree* right;
}Tree;
 
 //headers
 Tree* newleaf(int item, Tree* left, Tree* right);
 Tree* construct_binary_tree(char *str, int *pos);
 int isBST(Tree * root);
 //main

int main()
{
    Tree* arvore;
    int p=0;
    char* str;
    str = malloc(sizeof(char)*400);
    fgets(str, 400, stdin);
 
    arvore = construct_binary_tree(str, &p);
    if (isBST(arvore)) printf("verdadeiro\n");
    else printf("falso\n");
}
 
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
 
int isBST(Tree * root)
{
    static Tree *prev = NULL;
     
    if (root)
    {
        if (!isBST(root->left))
          return 0;
 
        if (prev != NULL && root->item <= prev->item)
          return 0;
 
        prev = root;
 
        return isBST(root->right);
    }
 
    return 1;
}
 
