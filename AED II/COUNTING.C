#include <stdio.h>
#include <stdlib.h>


void countingsort(int *vetor, int n)
{
    int mov = 0;
    int comp = 0;

    int maior = vetor[0];
    mov += mov + 1;
    for (int i = 0; i < n; i++)
    {
        comp++;
        printf("\n%d |--| %d", maior, vetor[i]);
        if (maior < vetor[i])
        {
            printf("\n%i < > (Maior)", i);
            maior = vetor[i];
            mov += mov + 1;
        }
    }

    int tamCount = maior + 1;
    int count[tamCount];
    int ordenado[n];
    printf("\nZERANDO O VETOR");
    //Inicializar cada posicao do vet de contagem
    for (int i = 0; i < tamCount; count[i] = 0, i++)
    {
        printf("\n[%i]> 0", i);
    }

    //Agora, o count[i] contem o numero de elemento iguais a i
    for (int i = 0; i < n; count[vetor[i]]++, i++)
    {
        printf("\n[%i]< >[%i]", vetor[i], count[i]);
    }

    //Agora, o count[i] contem o numero de elemento menores ou iguais a i
    for (int i = 1; i < tamCount; count[i] += count[i - 1], i++)
    {
        printf("\n[%i] recebeu count[%i] + count[%i]", count[i], count[i], count[i - 1]);
    }
    //Ordenando
    for (int i = n - 1; i >= 0; ordenado[count[vetor[i]] - 1] = vetor[i], count[vetor[i]]--, i--, mov++)
    {
        printf("\n[%i]< >[count[vetor[%i]]-1]", i, i);
    }
    //Copiando para o vetor original
    for (int i = 0; i < n; vetor[i] = ordenado[i], i++)
    {
        printf("\n[%i]< >[%i]", i, i + 1);
    }
    printf("\nMovimentacao = %i\n", mov);
    printf("Comparacao = %i\n",comp);
}

int main()
{
    int vetor[18] = {12, 4, 8, 2, 14, 17, 6, 18, 10, 16, 15, 5, 13, 9, 1, 11, 7, 3};
    countingsort(vetor, 18);
    for (int i = 0; i < 18; i++)
    {
        printf("%d ", vetor[i]);
    }

    return 0;
}