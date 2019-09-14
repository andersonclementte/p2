#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int item;
    struct no *proximo;
}NODE;

typedef struct grafo
{
    NODE **elementos;
    int *visitados, *distancia;
}GRAFO;

typedef struct fila
{
    int *items;
    int tam_atual, cabeca, cauda;
}FILA;

GRAFO *cria_grafo(int ilhas)
{
    GRAFO *novo_grafo = malloc(sizeof(GRAFO));
    novo_grafo->elementos = malloc(sizeof(NODE*) * ilhas+1);
    novo_grafo->visitados = malloc(sizeof(int) * ilhas+1);
    novo_grafo->distancia = malloc(sizeof(int) * ilhas+1);

    int i;
    for (i = 1; i <= ilhas; i++)
    {
        novo_grafo->elementos[i] = NULL;
        novo_grafo->visitados[i] = 0;
        novo_grafo->distancia[i] = -1;
    }
    return novo_grafo;

}
FILA *cria_fila(int ilhas)
{
    FILA *nova_fila = malloc(sizeof(FILA));
    nova_fila->items = malloc(sizeof(int) * ilhas);
    nova_fila->cabeca = 0;
    nova_fila->tam_atual = 0;
    nova_fila->cauda = ilhas-1;
    return nova_fila;
}

NODE *cria_vertice(int valor)
{
    NODE *novo_no = malloc(sizeof(NODE));
    novo_no->item = valor;
    novo_no->proximo = NULL;
    return novo_no;
}

void add_aresta(GRAFO *grafo, int vertice1, int vertice2)
{
    NODE *novo_vertice2 = cria_vertice(vertice2);
    novo_vertice2->proximo = grafo->elementos[vertice1];
    grafo->elementos[vertice1] = novo_vertice2;

    NODE *novo_vertice1 = cria_vertice(vertice1);
    novo_vertice1->proximo = grafo->elementos[vertice2];
    grafo->elementos[vertice2] = novo_vertice1;
}

void enfileira(FILA *fila, int valor, int ilhas)
{
    if (fila->tam_atual <= ilhas)
    {
        fila->cauda = (fila->cauda + 1) % ilhas;
        fila->items[fila->cauda] = valor;
        fila->tam_atual++;
    }
}

int desenfileira(FILA *fila, int ilhas)
{
    if (fila->tam_atual != 0)
    {
        int desenfileirado = fila->items[fila->cabeca];
        fila->cabeca = (fila->cabeca + 1) % ilhas;
        fila->tam_atual--;
        return desenfileirado;
    }
}

void bfs(GRAFO *grafo, int inicio, int ilhas)
{
    FILA *fila = cria_fila(ilhas);
    int desenfileirado,i;
    NODE *vertice = grafo->elementos[inicio];
    grafo->visitados[inicio] = 1;
    grafo->distancia[inicio] = 0;
    enfileira(fila, inicio, ilhas);
    while(fila->tam_atual > 0)
    {
        desenfileirado = desenfileira(fila, ilhas);
        vertice = grafo->elementos[desenfileirado];
        while (vertice != NULL)
        {
            if (!grafo->visitados[vertice->item])
            {
                grafo->visitados[vertice->item] = 1;
                grafo->distancia[vertice->item] = 1 + grafo->distancia[desenfileirado];
                enfileira(fila, vertice->item, ilhas);
            }
            vertice = vertice->proximo;
        }
    }
    free(fila);
}

void main()
{
    int casos, i, n, m, vertice1, vertice2, j;
    GRAFO *grafo;
    scanf("%d", &casos);

    for (i = 0; i < casos; i++)
    {
        scanf("%d%d", &n, &m);
        grafo = cria_grafo(n);
        for (j = 0; j < m; j++)
        {
            scanf("%d%d", &vertice1, &vertice2);
            add_aresta(grafo, vertice1, vertice2);
        }
        bfs(grafo, 1, n);   
        printf("%d\n", grafo->distancia[n]);
        free(grafo);
    }
}