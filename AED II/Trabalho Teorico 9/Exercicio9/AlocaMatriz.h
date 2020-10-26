#ifndef ALOCAMATRIZ_H_INCLUDED
#define ALOCAMTRIZ_H_INCLUDED
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
//Aloca dinamicamente a matriz
float **Alocar_matriz(int M, int N)
{
    //Verifica a condição de existência da matriz
    if(M <= 0|| N <= 0){
        printf("Parametros invalidos para matriz.");
        return 0;
    }
    float **p;
    //aloca as linhas da matriz
    p = (float **)malloc(M * sizeof(float *));
    if (p == NULL)//Verifica se foi alocado
    {
        printf("Memoria Cheia");
        return 0;
    }
    for (int i = 0; i < M; i++)
    {
        //aloca as colunas da matriz
        p[i] = (float *)malloc(N * sizeof(float));
        if (p[i] == NULL)//Verifica se foi alocado
        {
            printf("Memoria Cheia");
            return 0;
        }
    }
    return (p);//retorna a matriz alocada
}

float **free_matriz(int M, int N, float **p)
{
    //Verifica a condição de existência da matriz
    if(M <= 0|| N <= 0){
        printf("Parametros invalidos para matriz.");
        return 0;
    }
    if (p == NULL)//Se a matriz estiver NULL não precisa dar Free
    {
        return 0;
    }
    for (int i = 0; i < M; i++)
    {
        free(p[i]);//Desaloca cada coluna
    }
    free(p);//Desaloca todas as linhas
    return 0;
}

#endif
