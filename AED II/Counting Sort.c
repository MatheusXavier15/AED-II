#include <stdio.h>
#include <stdlib.h>

void countingsort(int *vetor, int n)
{
    int comp_f = 0;
    int mov_f = 0;
    int maior = vetor[0];
    int comp = 0;
    int mov = 0;

    mov_f++;
    printf("\n%d < > %d", mov, mov + 1);
    mov += mov + 1;
    for (int i = 0; i < n; i++)
    {
        comp_f++;
        printf("\n%d |--| %d", maior, vetor[i]);
        if (maior < vetor[i])
        {
            mov_f++;
            printf("\n%d < > %d", maior, vetor[i]);
            maior = vetor[i];
            mov_f++;
            printf("\n%d < > %d", mov, mov + 1);
            mov += mov + 1;
        }
    }

    int tamCount = maior;
    int count[tamCount];
    int ordenado[n];

    //Inicializar cada posicao do vet de contagem
    for (int i = 0; i < tamCount; count[i] = 0, i++, mov++)
    {
        // printf("\n[%d]> 0", i);
    }

    //Agora, o count[i] contem o numero de elemento iguais a i
    for (int i = 0; i < n; count[vetor[i]]++, i++)
    {
    }

    //Agora, o count[i] contem o numero de elemento menores ou iguais a i
    for (int i = 1; i < tamCount; count[i] += count[i - 1], i++)
    {
    }
    //Ordenando
    for (int i = n - 1; i >= 0; ordenado[count[vetor[i]] - 1] = vetor[i], count[vetor[i]]--, i--, mov_f++)
    {
        // printf("\n [%d] |--| [%d]",ordenado[count[vetor[i]]],vetor[i]);
        printf("\n[%d]<>[count[vetor[%d]]-1]", i, i);
    }
    //Copiando para o vetor original
    for (int i = 0; i < n; vetor[i] = ordenado[i], i++, mov_f++)
    {
        // printf("\n [%d] |--| [%d]",vetor[i],ordenado[i]);
        printf("\n[%d]<>[%d]", i, i + 1);
    }
    printf("movimentacoes: %d", mov_f);
    printf("Comparacoes: %d", comp_f);
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