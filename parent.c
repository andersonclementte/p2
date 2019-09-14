#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack{
    char items[128];
    int top;
}Stack;

typedef struct stack {
    int current_size;
    char items[128];
}Stack;

