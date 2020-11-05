#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "Pilha.h"


Pilha clone_stack(Pilha *stack, Pilha *clone);
Pilha concatenar_stack(Pilha *stack, Pilha *stack2);
void inverter_stack(Pilha *stack);

int main()
{
}

Pilha clone_stack(Pilha *stack, Pilha *clone)
{
    Pilha aux;
    create_pilha(&aux);
    char retorno;
    retorno = POP(stack);
    while (retorno != NULL)
    {
        PUSH(&aux, retorno);
        retorno = POP(stack);
    }
    retorno = POP(&aux);
    while (retorno != NULL)
    {
        PUSH(clone, retorno);
        PUSH(stack, retorno);
        retorno = POP(&aux);
    }
    return *clone;
}

Pilha concatenar_stack(Pilha *stack, Pilha *stack2) //stack [A,B,C]
{
    Pilha aux, concatenada;
    //aux = [NULL] , stack2 = [NULL]
    create_pilha(&concatenada);
    if (is_empty(stack2))
    {
        clone_stack(stack, &stack2);
    }
    //stack [A,B,C] stack2 [A,B,C]
    create_pilha(&aux);
    char retorno = POP(&stack);
    while (retorno != NULL)
    {
        PUSH(&aux, retorno);
        //aux [C,B,A]
        retorno = POP(&stack);
    }
    retorno = POP(&aux);
    while (retorno != NULL)
    {
        //concatenada[A,B,C]
        PUSH(stack, retorno);
        PUSH(&concatenada,retorno);
        retorno = POP(&aux);
    }
    retorno = POP(&stack2);
    while (retorno != NULL)
    {
        PUSH(&aux, retorno);
        //aux [C,B,A]
        retorno = POP(&stack2);
    }
    retorno = POP(&aux);
    while (retorno != NULL)
    {
        //concatenada[A,B,C,A,B,C]
        PUSH(&concatenada,retorno);
        retorno = POP(&aux);
    }
    return concatenada;
}

void inverter_stack(Pilha *stack){
    Pilha aux, tmp;
    //aux = [NULL] , tmp = [NULL]
    create_pilha(&aux);
    create_pilha(&tmp);
    if (is_empty(stack))
    {
        return;
    }
    //stack [A,B,C]
    char retorno = POP(stack);
    while (retorno != NULL)
    {
        PUSH(&aux, retorno);
        //aux [C,B,A]
        retorno = POP(stack);
    }
    retorno = POP(&aux);
    while (retorno != NULL)
    {
        PUSH(&tmp, retorno);
        //tmp [A,B,C]
        retorno = POP(&aux);
    }
    retorno = POP(&tmp);
    while (retorno != NULL)
    {
        PUSH(stack, retorno);
        //stack [C,B,A]
        retorno = POP(&tmp);
    }
}
