#include <stdio.h>
#include <stdlib.h>
 
typedef struct binary_tree{
    int item;
    struct binary_tree* left;
    struct binary_tree* right;
}Tree;

typedef struct node{
    char item;
    struct node* next;
}Node;

Node* createlist()
{
    return NULL;
}

Tree* startemptytree()
{
    return NULL;
}

Node* addtolist(Node* node, int item)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->item = item;
    new_node->next = node;
    return new_node;
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

int empty(Tree* bt)
{
    if (bt == NULL) return 1;
    else return 0;
}

int iscomplete(Tree* root)
{
    Node* list = createlist();
    if(!empty(root)){
        if(root->left == NULL && root->right == NULL) return 1;
        else if((root->left == NULL) || (root->right == NULL))
        {
            addtolist(list, root->item);
            return 0;
        }
        else{
            iscomplete(root->left);
            iscomplete(root->right);
        }
    }
}

void printL(Node* head){

    if (head == NULL) printf("VAZIO");
    else{
        while (head != NULL){
        printf("%d\n", head->item);
        head = head->next;
    }
    }
}

int main()
{
    Tree* arvore = startemptytree();
    int p=0;
    char* str;
    str = malloc(sizeof(char)*400);
    fgets(str, 400, stdin);
    arvore = construct_binary_tree(str, &p);
    if (iscomplete(arvore))
    {
        printf("completa\n");
        //printf("total de nos: %d");
    }
    else{
        /*
        nao completa
        nos com um filho: 0 5 8 */
        printf("nao completa\n");
        printf("nos com filho: ");
    }

    return 0;
}