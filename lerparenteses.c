
btree* construct_btree(char* str, int *i) {

    btree *bt = create_empty_binary_tree();

    if(str[(*i)++] == '(') {
        if(str[*i] == ')') {
            (*i)++;
            return NULL;
        }

        char str_num[10];
        int j = 0;
        int num;

        while(str[*i] != '(') {
            str_num[j++] = str[(*i)++];
        }

        str_num[j] = '\0';
        num = atoi(str_num);

        bt = create_binary_tree(num, NULL, NULL);
        bt->left = construct_btree(str, i);
        bt->right = construct_btree(str, i);
    }

    (*i)++;
    return bt;
}


char* read_parenthesis_btree() {
    char character;
    char *str = (char*)malloc(BTREE_STR_MAX_SIZE * sizeof(char));
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