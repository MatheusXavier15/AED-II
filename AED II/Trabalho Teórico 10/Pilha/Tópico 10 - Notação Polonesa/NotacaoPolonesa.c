#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Pilha.h"

int main()
{
    char element;
    Pilha stack;
    int aux_x, aux_y;
    create_pilha(&stack);
    do
    {
        scanf("%c",&element); 
        if (element == '+')
        {
            aux_y = POP(&stack);
            aux_x = POP(&stack);
            PUSH(&stack, aux_x + aux_y);
        }
        else if (element == '-')
        {
            aux_y = POP(&stack);
            aux_x = POP(&stack);
            PUSH(&stack, aux_x - aux_y);
        }
        else if (element == '/')
        {
            aux_y = POP(&stack);
            aux_x = POP(&stack);
            PUSH(&stack, aux_x / aux_y);
        }
        else if (element == '*')
        {
            aux_y = POP(&stack);
            aux_x = POP(&stack);
            PUSH(&stack, aux_x * aux_y);
        }
        else
            PUSH(&stack, element - '0');

    } while (element != '\n');
    print_stack(&stack);
}