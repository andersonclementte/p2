#include <stdio.h>
#include <string.h>

int main()
{
    int testes, i;
    scanf("%i", &testes);

    for (i = 0; i < testes; i++) //pega os testes
    {
        int strings, entradas, letra, tam, soma = 0;
        scanf("%i", &strings);
        getchar();
        
        for (entradas = 0; entradas < strings; entradas++)
        {
            char chave[50];
            scanf("%s", chave);
            tam = strlen(chave);

            for(letra = 0; letra < tam; letra++) soma += ((int)chave[letra] - 65) + entradas + letra;
        }
        printf("%i\n", soma);
    }

    return 0;
}