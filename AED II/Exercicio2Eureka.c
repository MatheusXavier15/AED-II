#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//conta os espaços
int qtd_espacos(char *str)
{
    int espacos = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ')
        {
            espacos++;
        }
    }
    return espacos;
}

int main()
{
    int n;
    scanf("%i\n", &n);
    int aux = 0;
    for (int y = 0; y < n; y++)
    {
        
        char str[10000];
        scanf(" %[^\n]s\n", str);

        //quebra a string
        int qtd_strings = qtd_espacos(str) + 1, i = 0;
        char strings[qtd_strings][strlen(str)];
        char *pch = strtok(str, " ");
        while (pch != NULL)
        {
            strcpy(strings[i++], pch); //copiar cada string para a posição correta
            pch = strtok(NULL, " ");
        }
        int j, min;
        char aux[qtd_strings][strlen(str)];

        //método de ordenação (selection sort)
        for (i = 0; i < (qtd_strings - 1); i++)
        {
            min = i;
            for (j = (i + 1); j < qtd_strings; j++)
            {
                if (strlen(strings[j]) > strlen(strings[min]))
                    min = j;
            }
            if (strlen(strings[i]) == strlen(strings[j])){
                strcpy(strings[i], strings[j]);
            }            
            if (strlen(strings[i]) != strlen(strings[min]))
            {
                strcpy(aux[i], strings[i]);
                strcpy(strings[i], strings[min]);
                strcpy(strings[min], aux[i]);
            }
        }

        //imprime
        for (int k = 0; k < qtd_strings; ++k)
        {
            for (int z = 0;; z++)
            {
                if (strings[k][z] != '\n' && strings[k][z] != '\r' && (strings[k][z] >= 65 && strings[k][z] <= 90) || (strings[k][z] >= 97 && strings[k][z] <= 122))
                {
                    printf("%c", strings[k][z]);
                }
                else
                {
                    break;
                }
            }
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}