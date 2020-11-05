#define PILHA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Celula
{
    struct Celula *prox;
    char Data;
} Celula;

typedef struct Pilha
{
    struct Celula *Top;
    int TAM;
}Pilha;

void create_pilha(Pilha *stack)
{
    stack->Top = NULL;
    stack->TAM = 0;
}

bool PUSH(Pilha *stack, char dado)
{
    Celula *cell = (Celula *)malloc(sizeof(Celula *));
    if (cell == NULL)
    {
        return false;
    }
    cell->Data = dado;
    cell->prox = stack->Top;
    stack->Top = cell;
    stack->TAM++;
    return true;
}

char POP(Pilha *stack)
{
    if (stack->TAM == 0)
    {
        return NULL;
    }
    int dado = stack->Top->Data;
    Celula *tmp = stack->Top;
    stack->Top = stack->Top->prox;
    free(tmp);
    stack->TAM--;
    return dado;
}

void print_stack(Pilha *stack)
{
    Celula *tmp = stack->Top;
    while (tmp != NULL)
    {
        printf("%c\n", tmp->Data);
        tmp = tmp->prox;
    }
}

void sort_stack(Pilha *stack)
{
    for (int i = 0; i < stack->TAM; i++)
    {
        Celula *tmp = stack->Top;
        for (int j = 0; j < stack->TAM - 1; j++)
        {
            if (strncmp(tmp->Data,tmp->prox->Data,1)<0)
            {
                int aux = tmp->Data;
                tmp->Data = tmp->prox->Data;
                tmp->prox->Data = aux;
            }
            tmp = tmp->prox;
        }
    }
}

bool is_empty(Pilha *stack){
  return stack->TAM == 0;
}
