#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct tree{
    int item;
    int heigth;
    struct tree* left;
    struct tree* right; 
}Tree;


//headers
Tree* starttree();
Tree* newleaf(int item, Tree* left, Tree* right);
int is_empty(Tree* root);
int max(int a, int b);
int height(Tree* root);
Tree* smallervaluenode(Tree* root);
int is_balanced_avl(Tree* root);
Tree* rotate_right(Tree* root);
Tree* rotate_left(Tree* root);
void print_pre_order(Tree* root);
Tree* addavl(Tree* root, int key, int* flag, Tree* aux);


int main()
{
    Tree* arvore = starttree();
    Tree* aux;
    int item = 0;

    while (scanf("%d", &item) != EOF)
    {
        int flag = 0;
        printf("----\nAdicionando %d\n", item);
        arvore = addavl(arvore, item, &flag, aux);
        aux = arvore;

        if (flag == 0)
        {
            printf("Continuou AVL...\n  ");
            print_pre_order(arvore);
            printf("\n");
        }
        else
        {
            printf("Depois de ajustar balanceamento...\n  ");
            print_pre_order(arvore);
            printf("\n");
        }
    }
    printf("----");
    return 0;
}

Tree* starttree(){
    return NULL;
}

Tree* newleaf(int item, Tree* left, Tree* right){
    Tree* new_tree = (Tree*) malloc(sizeof(Tree));
    new_tree->item = item;
    new_tree->heigth = 1;
    new_tree->left = NULL;
    new_tree->right = NULL;
    return new_tree;
}

int is_empty(Tree* root){
    return root == NULL;
    //if (root == NULL) return 1;
    //else return 0;
}

int max(int a, int b){
    return (a > b) ? a : b;
    /*
    ? expression mean:
    if (a > b) return a;
    else return b; */
    
}

int height(Tree* root)
{
    if (root == NULL) return -1;
    else return 1 + max(height(root->left), height(root->right));
}

int is_balanced_avl(Tree* root){
    if (root == NULL) return 0;
    return height(root->left) - height(root->right);
}

Tree* rotate_right(Tree* root){
    Tree* target = root->left;
    Tree* right_son = target->right;

    //perform rotation
    target->right = root;
    root->left = right_son;

    //update height avls
    root->heigth = max(height(root->left), height(root->right)) + 1;
    target->heigth = max(height(target->left), height(target->right)) + 1;

    //return new bt
    return target;
}

Tree* rotate_left(Tree* root){
    Tree* target = root->right;
    Tree* left_son = target->left;

    //peform rotation
    target->left = root;
    root->right = left_son;

    //update height avls
    root->heigth = max(height(root->left), height(root->right)) + 1;
    target->heigth = max(height(target->left), height(target->right)) + 1;

    //return new bt
    return target;
}

void print_pre_order(Tree* root) {
	if(!is_empty(root)){
        
        printf(" ( ");
        printf("%d ", root->item);


        if(root->left == NULL) printf(" () ");
        else print_pre_order(root->left);

        if(root->right == NULL) printf(" () ");
        else print_pre_order(root->right);

        printf(") ");
    }
}
// TEM UM ERRO AQUI FERA
Tree* addavl(Tree* root, int key, int* flag, Tree* aux){
    if (root == NULL)
        return (newleaf(key, NULL, NULL));
    
    if (key < root->item)
        root->left = addavl(root->left, key, flag, aux);

    else if(key >= root->item)
        root->right = addavl(root->right, key, flag, aux);
    
    root->heigth = max(height(root->left), height(root->right)) + 1;

    int balance = is_balanced_avl(root);
    if (balance > 1 || balance < -1 && *flag == 0){
        *flag = 1;
        printf("Antes de ajustar balanceamento...\n  ");
        print_pre_order(aux);
        printf("\n");
    }

    if (balance > 1 && key < root->left->item){
        return rotate_right(root);
    }

    if (balance < -1 && key >= root->right->item){
        return rotate_left(root);
    }

    if(balance > 1 && key >= root->left->item){
        root->left = rotate_left(root->left);
        return rotate_right(root);
    }

    if (balance < -1 && key < root->right->item){
        root->right = rotate_right(root->right);
        return rotate_left(root);
    }

    return root;
}
