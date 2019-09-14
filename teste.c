int i = 0, j;
while (i < n)
{
    int cont = 1;
    for (j = i+1; j <= n; j++)
    {
        if (string[i]==string[j]) cont++;
        else
        {
            head = add(h, frase[i], cont);
            i = j;
            break;
        }
    }
}


//brincadeira
int i, freq = 0;
    char j = string[0];
    
    for (i = 0; i < tam; i++)
    {
        
        if (string[i] == j)  freq++;

        else
        {
            head = add(head, string[i-1], freq);
            j = string[i];
            freq = 0;

        }
        
    }

// pedro
Node* new (Node* head, char k, int x)
{
    k->item = z;
    k->frequencia = x;
    k->prox = NULL;
    return head;
}

Node* add(Node* head, char item, int x)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode = new(newnode, item, x);
    newnode->next = head;
    return newnode;
}

//meu
Node* add(Node* head, char item, int frequencia)
{
    Node* new_node =(Node*) malloc(sizeof(Node));
    new_node->item = item;
    new_node->frequencia = frequencia;
    new_node->next = head;
    return new_node;
}