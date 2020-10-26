#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//-----------------------------------------------
#include "AlocaMatriz.h"
//-----------------------------------------------
int main()
{
    float **matriz;
    int M, N;
    printf("Digite o numero de linhas: ");
    scanf("%d", &M);
    fflush(stdin);
    printf("Digite o numero de colunas: ");
    scanf("%d", &N);
    //aloca dinamicamente a matriz
    matriz = Alocar_matriz(M, N);
    srand(time(NULL));
    //-------------------------------------------
    //Guarda valores aleatórios de 0 a 100 na matriz
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matriz[i][j] = rand() % 100;
        }
    }
    //-------------------------------------------
    //Acha maior e menor elemento dentro da matriz
    float maior = matriz[0][0];
    float menor = matriz[0][0];
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (matriz[i][j] > maior)
            {
                maior = matriz[i][j];
            }

            if (matriz[i][j] < menor)
            {
                menor = matriz[i][j];
            }
        }
    }
    //-------------------------------------------
    //Imprime toda a matriz
    printf("\n");
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%.0f ", matriz[i][j]);
        }
        printf("\n");
    }
    //-------------------------------------------
    //Achando a posição do menor e maior elemento
    int mx, my, mi, mj;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (menor == matriz[i][j])
            {
                mx = i;
                my = j;
                break;
            }
             if (maior == matriz[i][j])
            {
                mi = i;
                mj = j;
                break;
            }
        }
    }
    
    printf("\nMenor elemento: %.0f", menor);
    printf("\nPosicao do menor elemento: matriz[%d][%d]\n", mx, my);
    printf("\nMaior elemento: %.0f", maior);
    printf("\nPosicao do maior elemento: matriz[%d][%d]\n", mi, mj);

    //-------------------------------------------
    printf("\n");
    //-------------------------------------------
    matriz = free_matriz(M, N, matriz);
    return 0;
}