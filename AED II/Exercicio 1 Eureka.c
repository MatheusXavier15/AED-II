#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(void)
{
    int N;
    scanf("%d", &N);
    int array[N];
    srand(time(NULL));
    int pares[N];
    int impares[N];
    int tmp;
    int par = 0;
    int impar = 0;
    for (int i = 0; i < N; i++)
    {
        array[i] = rand() % 100;
    }
    for (int i = 0; i < N; i++)
    {
        if (array[i] % 2 == 0)
        {
            pares[par] = array[i];
            par++;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (array[i] % 2 != 0)

        {
            impares[impar] = array[i];
            impar++;
        }
    }

    for (int i = 1; i < par; i++)
    {
        tmp = pares[i];
        int j = i - 1;
        while ((j >= 0) && (pares[j] > tmp))
        {
            pares[j + 1] = pares[j];
            j--;
        }
        pares[j + 1] = tmp;
    }
    for (int i = 1; i < impar; i++)
    {
        tmp = impares[i];
        int j = i - 1;
        while ((j >= 0) && (impares[j] < tmp))
        {
            impares[j + 1] = impares[j];
            j--;
        }
        impares[j + 1] = tmp;
    }
    for (int i = 0; i < par; i++)
    {
        printf("\n%d", pares[i]);
    }
    for (int i = 0; i < impar; i++)
    {
        printf("\n%d", impares[i]);
    }

    return 0;
}
