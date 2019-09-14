#include <stdio.h>

// iterative binary search
// only for ordered arrays
int binary_search(int *a, int size, int element) {

	int begin = 0; 
	int end = size - 1;
	int middle;

	while(begin <= end) {
		middle = (begin + end) / 2; // calculates the half of the array
		if(a[middle] < element) {
			begin = middle + 1;
		}
		else if (a[middle] > element) {
			end = middle - 1;
		}
		else { // a[middle] == element
			return middle;
		}
	}
	return -1; // not found!
}

int main() {
	
	int a[10] = {0, 7, 12, 34, 41, 43, 54, 67, 88, 99};

	printf("99 --> index = %d\n", binary_search(a, 10, 99));
	printf("0 --> index = %d\n", binary_search(a, 10, 0));
	printf("100 --> index = %d\n", binary_search(a, 10, 100));
	printf("12 --> index = %d\n", binary_search(a, 10, 12));

	return 0;
}

#include <stdio.h>

// recursive binary search
// only for ordered arrays
int binary_search(int *a, int begin, int end, int element) {

	if(begin > end) {
		return -1; // not found!
	}
	
	int middle = (begin + end) / 2;
	if(a[middle] > element) {
		binary_search(a, begin, middle - 1, element);
	}
	else if(a[middle] < element) {
		binary_search(a, middle + 1, end, element);
	}
	else { 
		return middle; // a[middle] == element
	}
}

int main() {
	
	int a[10] = {0, 7, 12, 34, 41, 43, 54, 67, 88, 99};

	printf("0 --> index = %d\n", binary_search(a, 0, 9, 0));
	printf("99 --> index = %d\n", binary_search(a, 0, 9, 99));
	printf("100 --> index = %d\n", binary_search(a, 0, 9, 100));
	printf("43 --> index = %d\n", binary_search(a, 0, 9, 43));

	return 0;
}

/*
 * Essa função recebe a string com a arvore em notacao de parenteses
 * e um ponteiro para inteiro para construir a arvore binaria a 
 * partir da string
 */
bt* construct_binary_tree(char *str, int *pos) {

	bt *btree = NULL; //ponteiro para a arvore
	int i = 0;
	int numInt;       //numero do no (inteiro)
	char numStr[50];  //numero do no (string)
 
	while(str[*pos] == '(') { //ignora os parenteses abrindo
		*pos += 1;
	}

	if(str[*pos] == ')') { //se encontrar parentese fechando, retorna null
		*pos += 1;         // pois o ponteiro eh nulo
		return NULL;
	}
	else {
		while(str[*pos] != '(') {    //se for diferente de abre parenteses
			numStr[i++] = str[*pos]; //le o numero string
			*pos += 1;
		}
		numStr[i] = '\0'; //finalizando a string com '/0'
		numInt = atoi(numStr); //converte o numero string para inteiro

		btree = create_binary_tree(numInt, NULL, NULL); //cria um no com o numero inteiro
		btree->left = construct_binary_tree(str, pos);  //constroi a arvore para o no esquerdo
		btree->right = construct_binary_tree(str, pos); //constroi a arvore para o no direito
	}

	*pos += 1;
	return btree; //retorna o ponteiro para a arvore
}

//codigo 2
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

void generate_parenthesis_btree(btree *bt) {
    printf("(");
    if(!is_empty(bt)) {
        printf("%d", bt->item);
        generate_parenthesis_btree(bt->left);
        generate_parenthesis_btree(bt->right);
    }
    printf(")");
}
