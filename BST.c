#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    int item;
    struct tree*left;
    struct tree*right;
}Tree;

Tree* treeinit()
{
    return NULL;
}

Tree* novafolha(int item, Tree* left, Tree* right)
{
    Tree* nova_folha = (Tree*)malloc(sizeof(Tree));
    nova_folha->item = item;
    nova_folha->left = left;
    nova_folha->right = right;
    return nova_folha;
}

int is_empty(Tree* root)
{
    return root == NULL;
}

Tree* node_menor_valor(Tree* root)
{
    Tree* current = root;

    //loop down to find the leftmost leaf//
    while ( current->left != NULL){
        current = current->left;
    }
    return current;
}

Tree* search(Tree* root, int item, int* contador)
{
    if ((root->item == item)|| (root == NULL))
        return root;
    
    (*contador)++;
    if (root->item > item) search(root->left, item, contador);
    else search(root->right,item,contador);
}

Tree* search_larger(Tree* root, int item, int* contador)
{
    if (root == NULL) return root;

    if (root->item > item) *contador += 1;

    search_larger(root->left,item,contador);
    search_larger(root->right,item,contador);
}

Tree* search_biggest(Tree* root, int item, int* cont, int* i)
{
    if (root == NULL) return root;
    if (*i == item) *cont = root->item;
    (*i)++;
    search_biggest(root->left, item, cont, i);
    search_biggest(root->right, item, cont, i);
}

Tree* deleta_node(Tree* root, int item)
{
    //Passo 1
    if (root == NULL) return root;

    /*Se o item a ser apagado é menor que o item da root
    então está na subarvore esquerda*/
    if (item < root->item)
        root->left = deleta_node(root->left, item);
    
    /*Se o item a ser apagado é maior que o item da root,
    então está na subarvore direita*/
    else if (item > root->item)
        root->right = deleta_node(root->right, item);

    /*Se a chave é igual, entao deve ser a deletada*/
    else{
        if(root->left == NULL){
            Tree* aux = root->right;
            free(root);
            return aux;
        }
        else if (root->right == NULL){
            Tree* aux = root->left;
            free(root);
            return aux;
        }

        Tree* aux = node_menor_valor(root->right);
        root->item = aux->item;
        root->right = deleta_node(root->right, aux->item);
    }

    return root;
}

Tree* add_bst(Tree* root, int item)
{
    if (root == NULL)
        return (novafolha(item, NULL, NULL));
    
    if (item < root->item)
        root->left = add_bst(root->left, item);
    else
        root->right = add_bst(root->right, item);

    return root;
}

void brincadeira(int x)
{
    int i, comando, numero;
    Tree* arvore = NULL;

    for (i = 0; i < x; i++)
    {
        int flag = 0;
        scanf("%d %d", &comando, &numero);
        printf("comando-> %d numero-> %d\n", comando, numero);
        if (comando == 1){
            if(!search(arvore,numero,&flag)){
                arvore = add_bst(arvore, numero);
                printf("%d\n", flag);
            }
            else printf("%d\n", flag);

        }
        else if(comando == 2){
            if (!search(arvore,numero,&flag)) printf("-1\n");
            else{
                arvore = deleta_node(arvore, numero);
                printf("%d\n", flag);
            }
        }

        else if(comando == 3){
            search_larger(arvore,numero,&flag);
            printf("%d\n", flag);
        }

        else if(comando == 4){
            int m;
            if (arvore->left == NULL && arvore->right == NULL) printf("%d\n", arvore->item);
            else{
                search_biggest(arvore,numero, &flag,&m);
                printf("%d\n", flag);
            }
        }

    }
}

int main()
{
    int testes, i;
    scanf("%d", &testes);
    for (i = 0; i < testes; i++)
    {
        int operation;
        scanf("%d", &operation);
        brincadeira(operation);
    }
    return 0;
}