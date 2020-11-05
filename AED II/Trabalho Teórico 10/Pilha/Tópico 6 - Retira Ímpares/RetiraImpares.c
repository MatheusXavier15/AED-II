#ifndef RETIRAIMPAR_H_INCLUDED
#define RETIRAIMPAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Celula
{
    Celula *prox;
    int Data;
} Celula;

typedef struct Pilha
{
    Celula *Top;
    int TAM;
} Pilha;

void create_pilha(Pilha *stack)
{
    stack->Top = NULL;
    stack->TAM = 0;
}

bool PUSH(Pilha *stack, int dado)
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

int POP(Pilha *stack)
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
        printf("%d\n", tmp->Data);
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
            if (tmp->Data, tmp->prox->Data)
            {
                int aux = tmp->Data;
                tmp->Data = tmp->prox->Data;
                tmp->prox->Data = aux;
            }
            tmp = tmp->prox;
        }
    }
}

bool is_empty(Pilha *stack)
{
    return stack->TAM == 0;
}

void retira_impares(Pilha *stack)
{
    // stack [1,2,3,4,5,6,7,8,9]
    //stack sem impares [2,4,6,8]
    Pilha aux;
    if (is_empty(stack))
    {
        return;
    }
    char retorno = POP(stack);
    while (retorno != NULL)
    {
        if(retorno % 2 == 0){
        PUSH(&aux, retorno);
        }
        retorno = POP(stack);
    }
    retorno = POP(&aux);
    while (retorno != NULL)
    {
        PUSH(stack, retorno);
        retorno = POP(&aux);
    }
}

int main()
{
    
}

#endif