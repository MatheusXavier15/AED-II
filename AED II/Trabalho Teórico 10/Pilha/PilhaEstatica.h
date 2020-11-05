#define PILHAESTATICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

typedef struct Pilha
{
    char Data[MAX];
    int Top;
} Pilha;

void create_pilha(Pilha *stack){
    stack->Top = 0;
}

bool PUSH (Pilha*stack, char dado){
    if(stack->Top == MAX){
        return false;
    }
    stack->Data[stack->Top] = dado;
    stack->Top++;
    return true;
}

char POP(Pilha *stack){
    if(stack->Top==0){
        return NULL;
    }
    stack->Top--;
    return stack->Data[stack->Top];
}

void print_stack(Pilha *stack){
    if(stack->Top == NULL){
        printf("Pilha vazia!\n");
        return;
    }
    for (int i = 0; i < stack->Top; i++)
    {
        printf("%c\n",stack->Data[i]);
    }
    return;
}

bool is_empty(Pilha *stack){
    return stack->Top==NULL;
}