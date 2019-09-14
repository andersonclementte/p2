#include <stdio.h>
#include <stdlib.h>

typedef struct Element{
    int key;
    int value;
    struct Element* next;
}Element;

typedef struct hashtable{
        Element* table[500];
    }Hash;


Hash* createtable(int h)
{
    Hash* new_table = (Hash*) malloc(sizeof(Hash));
    int i;
    for (i = 0; i < h; i++) new_table->table[i] = NULL;
    return new_table;

}

void put(Hash* ht, int value, int x)
{
    int h = value%x;
    Element* temp = ht->table[h];
    Element* new_element = (Element*) malloc(sizeof(Element));
    new_element->key = new_element->value = value;
    new_element->next = NULL;

    if (ht->table[h] == NULL)
    {
        ht->table[h] = new_element;
        return;
    } 
        while (temp->next != NULL) temp = temp->next;
        temp->next = new_element;
        return;
}

void printH(Hash* ht, int x)
{
   // printf("\n");
    int i;
    
    for (i = 0; i < x; i++)
    {
        if (ht->table[i] == NULL) printf("%d -> \\\n", i);
        else
        {
            Element* temp = (Element*) malloc(sizeof(Element));
            
            printf("%d -> ", i);
            temp = ht ->table[i];
            while (temp != NULL)
            {
                printf("%d -> ", temp->key);
                temp = temp->next;
            }
            printf("\\\n");
        }
    }
}

int main()
{
    int testes, hashs, entradas, key;
    int i;

    scanf("%d", &testes);
    for (i = 0; i < testes; i++)
    {
        scanf("%d %d", &hashs, &entradas);
        Hash* ht = createtable(hashs);
        int j;
        for (j = 0; j < entradas; j++)
        {
            scanf("%d", &key);
            put(ht,key,hashs);
        }
        printH(ht,hashs);

        printf("\n");
    }
    return 0;
}