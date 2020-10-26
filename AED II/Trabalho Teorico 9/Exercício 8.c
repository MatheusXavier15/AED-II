// Faça um programa que leia um valor n e crie dinamicamente um vetor de n elementos. Preencha o vetor com n elementos aleatório e em seguida apresente a soma dos elementos do vetor.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//função que aloca o vetor dinamicamente
int *alocar(int n)
{
    int *vetor;
    vetor = (int *)malloc(n * sizeof(int));
    return vetor;
}

int main()
{
    int *vetor;
    int N, x;
    scanf("%d", &N);

    //aloca o vetor
    vetor = alocar(N);

    //função que gera numeros aleatorios a partir do tempo
    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
        //armazena valores aleatorios no vetor
        vetor[i] = rand() % 100;
    }

    int soma = 0;

    //soma o vetor
    for (int i = 0; i < N; i++)
    {
        soma += vetor[i];
    }
    
    printf("\nA soma dos elementos do vetor eh: %d", soma);
    
    //libera a alocação
    free(vetor);
    return 0;
}