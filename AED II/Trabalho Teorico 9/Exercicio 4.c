// Usando somente ponteiros (sem indexação de matriz), escreva uma função para somar todos os números de uma matriz de inteiros.

#include <stdio.h>
#include <stdlib.h>

int somando_matriz(int **matriz, int M, int N)
{
    int soma = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; i++)
        {
            soma += *(*(matriz + i) + j);
        }
    }
    return soma;
}

