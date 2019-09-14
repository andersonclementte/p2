#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct tree{
    int item;
    struct tree* left;
    struct tree* right;
}Tree;

Tree* new_leaf(int item, Tree* left, Tree* right)
{
    Tree* new_leaf = (Tree*) malloc(sizeof(Tree));
    new_leaf->item = item;
    new_leaf->left = left;
    new_leaf->right = right;
    return new_leaf;
}

int is_empty(Tree* root)
{
    return root == NULL;
}

Tree* buildtree(char* str, int* pos)
{
    Tree* bt = NULL; //ponteiro para a arvore
    int i = 0;
    int numInt;       //numero do no (inteiro)
    char numStr[50];  //numero do no (string)

    while(str[*pos] == '(') { //ignora os parenteses abrindo
        *pos += 1;
    }

    if(str[*pos] == ')') { //se encontrar parentese fechando, retorna null
        *pos += 1;         // pois o ponteiro eh nulo
        return bt;
    }
    else {
        while(str[*pos] != '(') {    //se for diferente de abre parenteses
            numStr[i++] = str[*pos]; //le o numero string
            *pos += 1;
        }
        numStr[i] = '\0'; //finalizando a string com '/0'
        numInt = atoi(numStr); //converte o numero string para inteiro

        bt = new_leaf(numInt, NULL, NULL); //cria um no com o numero inteiro
        bt->left = buildtree(str, pos);  //constroi a arvore para o no esquerdo
        bt->right = buildtree(str, pos); //constroi a arvore para o no direito
    }
    *pos += 1;
    return bt; //retorna o ponteiro para a arvore
}

Tree* find_sum(Tree* root, int item, int sum, int* p)
{
    if (root == NULL) {
        return root;
    }
    sum += root->item;
    if (root->left == NULL && root->right == NULL) {
        if (item == sum) {
            *p = 1;
        }
    }
    find_sum(root->left, item, sum, p); 
    find_sum(root->right, item, sum, p);
}


int main() {
    
    while (1) 
    {
        Tree* arvore = NULL;
        char str[10000] = {0};
        int i = 0, item = 0, cont = 0, pos = 0, pointer = 0;
        char caracter;
        scanf("%d", &item);
        if (item == -1000) {
            break;
        }
        while (1)
        {
            scanf(" %c", &caracter);
            
            if (caracter != ' ')
            {
                str[i] = caracter;
                i++;
                if (caracter == '(') cont += 1;
                else if (caracter == ')') cont -= 1;
            }
            if (cont == 0) break;
        }
        str[i] = '\0';
        arvore = buildtree(str, &pos);
        find_sum(arvore, item, 0, &pointer);
        
        //decision
        if (pointer == 1) printf("sim\n");
        else printf("nao\n");
    }
    
    
    return 0;
}