#include <stdio.h>
#include <stdlib.h>

typedef struct binary_tree{
    int item;
    struct binary_tree* left;
    struct binary_tree* right;
}Tree;

//headers
Tree* newtree(int item, Tree* left, Tree* right);
Tree* newbinarytree(char* string, int* pos);
char* read_parenthesis_btree();
Tree* findMaximum(Tree* root);
Tree* findMinimum(Tree* root);
int isBST(Tree* node);
// main //
int main()
{
    Tree* arvore;
    int* x;
    arvore = newbinarytree(read_parenthesis_btree(),x);
    if(isBST(arvore)) printf("VERDADEIRO\n");
    else printf("FALSO\n");
}

//func
Tree* newtree(int item, Tree* left, Tree* right)
{
    Tree* new_tree = (Tree*) malloc(sizeof(Tree));
    new_tree->item = item;
    new_tree->left = left;
    new_tree->right = right;
    return new_tree;
}

Tree* newbinarytree(char* string, int* pos)
{
    Tree* arvore = NULL;
    int i = 0;
    int node;
    char s[100];

    while(string[*pos] == '(') *pos += 1;

    if (string[*pos] == ')'){
        *pos += 1;
        return NULL;
    }
    else {
        while(string[*pos] != '('){
            s[i++] = string[*pos];
            *pos += 1;
        }
        s[i] = '\0';
        node = atoi(s);

        arvore = newtree(node, NULL, NULL);
        arvore->left = newbinarytree(string, pos);
        arvore->right = newbinarytree(string,pos);
    }

    *pos += 1;
    return arvore;
}

char* read_parenthesis_btree() {
    char character;
    char *str = (char*)malloc(1024 * sizeof(char));
    int open_par = 0;
    int close_par = 0;
    int i = 0;

    scanf("%c", &character);
    while(1) {
        if(character != ' ' && character != '\n') {
            str[i++] = character;
        }

        if(character == '(') {
            open_par++;
        }
        else if(character == ')') {
            close_par++;
        }

        if(open_par == close_par) break;
        scanf("%c", &character);
    }

    str[i] = '\0';
    return str;
}


Tree* findMaximum(Tree* root){
    if( !root ) return root;
    while( root->right ){
        root = root->right;
    }
    return root;
}

Tree* findMinimum(Tree* root){
    if( !root ) return root;
    while( root->left ){
        root = root->left;
    }
    return root;
}

int isBST(Tree* node){
 
    if(!node)
        return 1;
     
    if( ! ( node->left || node->right ) ) return 1;   
    int isLeft  = isBST(node->left);
    int isRight = isBST(node->right);
 
    if(isLeft && isRight){
        /* Since we already know that left sub tree and
        right sub tree are Binary search tree, finding min and max in them would be easy */
     
        Tree* max  =  NULL;
        Tree* min  =  NULL;
        if( node->left )
            max = findMaximum(node->left);
        if( node->right )
            min = findMinimum(node->right);
 
        //Case 1 : only left sub tree is there
        if(max && !min)
            return node->item > max->item;
        //Case 2 : Only right sub tree is there
        if(!max && min)
            return node->item < min->item;
        //Case 3 : Both left and right sub tree are there
        return (node->item > max->item && node->item < min->value);
   }
   return 0;
}