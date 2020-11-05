// Alguns editores de texto permitem que algum caractere funcione como um "cancela-caractere", cujo efeito é o de cancelar o caractere anterior na linha que está sendo editada. Por exemplo, se '#' é o cancela-caractere, então a sequência de caracteres PEM##UB#C corresponde à sequência PUC. Outro comando encontrado em editores de texto é o "cancela-linha", cujo efeito é o de cancelar todos os caracteres anteriores na linha que está sendo editada. Neste exemplo vamos considerar '/' como o caractere cancela-linha. Finalmente, outro comando encontrado em editores de texto é o "salta-linha", cujo efeito é o de causar a impressão dos caracteres que pertencem à linha que está sendo editada, iniciando uma nova linha de impressão a partir do caractere imediatamente seguinte ao caractere salta-linha. Por exemplo, se `@' é o salta-linha, então a sequência de caracteres ICEI@PUCMINAS.@ corresponde às duas linhas abaixo:

// ICEI

// PUCMINAS.

// Implemente um Editor de Texto (ET) que aceite os três comandos descritos acima. O ET deverá ler um caractere de cada vez do texto de entrada e produzir a impressão linha a linha, cada linha contendo no máximo 70 caracteres de impressão.

// A seguir é sugerido um texto para testar o programa ET, cujas características permitem exercitar todas as partes importantes do programa.

// Este et# um teste para o ET, o extraterrestre em C.@Acabamos de testar a capacidade de o ET saltar de linha, utilizando seus poderes extras (cuidado, pois agora vamos estourar a capacidade máxima da linha de impressão, que é de 70 caracteres.)@O k#cut#rso dh#e Estruturas de Dados II et# h#um cuu#rsh#o #x# x?@!#?!#+.@ Como et# bom n#nt#ao### r#ess#tt#ar mb#aa#triz#cull#ado nn#x#ele!/ Sera que este funciona/// O sinal? não### deve ficar! ~

#ifndef RETIRAIMPAR_H_INCLUDED
#define RETIRAIMPAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Pilha.h"

// @ quebra linha
// / cancela linha
// # apaga caracter anterior

//void inverter_pilha(Pilha pilha);
void text_roll(char);


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

void print_linha(Pilha *stack)
{
  inverter_stack(stack);
  Celula *tmp = stack->Top;
  while (tmp != NULL)
  {
    printf("%c", tmp->Data);
    tmp = tmp->prox;
  }
}

void text_roll(char caracter)
{
  Pilha stack;
  create_pilha(&stack);
  int i = 0;
  for (int i = 0; i <= 70; i++)
  {
    scanf("%c", &caracter);
    if (caracter == '\n')
    {
      print_linha(&stack);
      return;
    }
    else if (caracter == '@')
    {
      PUSH(&stack, '\n');
      print_linha(&stack);
      return;
    }
    else if (caracter == '#')
    {
      POP(&stack);
    }
    else
    {
      PUSH(&stack, caracter);
    }
  }
  PUSH(&stack, '\n');
  print_linha(&stack);
}

int main()
{
  char letra;
  printf("digite o texto a ser editado:\n");
  do{
  text_roll(&letra);
  }while(letra != '\n');
}

#endif