#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct binary_tree{
    int item;
    struct binary_tree* left;
    struct binary_tree* right;
}Tree;

Tree* startemptytree()
{
    return NULL;
}

Tree* newleaf(int item, Tree* left, Tree* right)
{
    Tree* new_tree = (Tree*) malloc(sizeof(Tree));
    new_tree->item = item;
    new_tree->left = left;
    new_tree->right = right;
    return new_tree;
}

Tree* construct_binary_tree(char *str, int *pos, int* x) {
 
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
        (*x)++;
 
        btree = newleaf(numInt, NULL, NULL);
        btree->left = construct_binary_tree(str, pos, x); 
        btree->right = construct_binary_tree(str, pos, x);
    }
 
    *pos += 1;
    return btree;
}

int maxDepth(Tree* node)  
{ 
   if (node==NULL) return -1; 
   else 
   { 
       
       int lDepth = maxDepth(node->left); 
       int rDepth = maxDepth(node->right); 
  
       if (lDepth > rDepth) return(lDepth+1); 
       else return(rDepth+1); 
   } 
}

void notcomplete(Tree* root,int lista[], int* pont)
{
    if(root!= NULL){
        notcomplete(root->left,lista, pont);
        if((root->left == NULL) && (root->right != NULL) || (root->left != NULL) && (root->right == NULL))
        {
            lista[*pont] = root->item;
            (*pont)++;
        }
        notcomplete(root->right,lista, pont);
    }
}

int main()
{
    Tree* arvore = startemptytree();
    int k;
    int p = 0;
    int nos = 0;
    char* str;
    str = malloc(sizeof(char)*400);
    fgets(str, 400, stdin);
    arvore = construct_binary_tree(str, &p, &nos);
    int pot = pow(2,(maxDepth(arvore)+1))-1;
    int lista[nos];
    int kalker =0;
    if (pot == nos){
        printf("completa\n");
        printf("total de nos: %d\n", pot);
    }
    else{
        notcomplete(arvore, lista, &kalker);
        printf("nao completa\nnos com um filho: ");
        for(k = 0; k < kalker; k++){
            if (k == kalker - 1) printf("%d\n", lista[k]);
            printf("%d ", lista[k]);

        }

    }
    return 0;
}