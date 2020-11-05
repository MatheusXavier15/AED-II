#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Pilha.h"

void verify_parentesis()
{
    //Cria um pilha para armazenar a contagem de parenteses
    Pilha stack;
    create_pilha(&stack);
    //variavel que armazena a sentença matematica
    char expression[100];
    printf("Digite a expressao matematica a ser verificada:\n");
    scanf("%s", expression);
    //string_tam recebe através do strlen o tamanho da string
    int string_tam = strlen(expression);
    if (expression[0] == ')')
    {
        //retorna se for )(5+2) por ex
        printf("Expressao incorreta!\n");
        return;
    }
    else if (expression[string_tam] == '(')
    {
        //retorna se for (5+2)( por ex
        printf("Expressao incorreta!\n");
        return;
    }
    for (int i = 0; i < string_tam; i++)
    {
        //verifica que para cada '(' exista um ')'
        if (expression[i] == '(')
        {
            //push para todo '('
            PUSH(&stack, expression[i]);
        }
        else if (expression[i] == ')')
        {
            //pop para todo ')'
            if (POP(&stack) == NULL)
            {
                printf("Expressao incorreta!\n");
                return;
            }
        }
    }
    //confere se os parenteses bateram e a pilha esta vazia
    if (is_empty(&stack))
    {
        printf("Expressao correta!\n");
    }
    else
    {
        printf("Expressao incorreta!\n");
    }
}

int main(){
    verify_parentesis();
    return 0;
}