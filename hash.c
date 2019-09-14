#include <stdio.h>
#include <stdlib.h>

typedef struct element{
    int key;
    int value;
}Element;

typedef struct hashtable{
    Element* table[11];
}Hash;


// func
Hash* create_table()
{
    Hash* new_table = (Hash*)malloc(sizeof(Hash));
    int i;
    for (i = 0; i < 11; i++) new_table->table[i] = NULL;
    return new_table;
}

void put(Hash* ht, int key, int value)
{
    int h = key % 11;
    while (ht->table[h] != NULL){
        if (ht->table[h]->key == key){
            ht->table[h]->value = value;
            break;
        }
        h = (h+1)%11;
    }

    if(ht->table[h] == NULL){
        Element* new_element = (Element*) malloc(sizeof(Element));
        new_element->key = key;
        new_element->value = value;
        ht->table[h] = new_element;
    }
}

int get(Hash* ht, int key)
{
    int h = key % 11;
    while (ht->table[h] != NULL){
        if (ht->table[h]->key == key) return ht->table[h]->value;
        h = (h+1)%11;
    }
    return -100;
}

void exclude(Hash* ht, int key)
{
    int h = key%11;
    while (ht->table[h] != NULL){
        if(ht->table[h]->key == key){
            ht->table[h]->key = -1;
        }
        h = (h+1)%11;
    }
}

int main()
{
    Hash* ht = create_table();
    put(ht, 3, 1000);
    put(ht, 14, 1);
    put(ht,15,200);
    return 0;
}