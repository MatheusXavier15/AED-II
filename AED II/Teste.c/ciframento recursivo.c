/*Neste exercício, suponha a chave de ciframento três. Implemente um programa para executar sua função que receba várias linhas contendo strings e, para cada string, imprimir a a mensagem criptografada. A entrada termina com a leitura da palavra FIM. Você deve cifrar somente letras do alfabeto  (A até Z, a até z), os demais caracteres não serão cifrados. Se a chave é igual a 3,  'a' é substituído por 'd', então 'z' é substituído por 'c', pois o algoritmo anda de forma circular sobre o alfabeto (A até Z, a até z).*/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char ciframento(char c[], int i);//declara ciframento

int main()
{
    char c[1500];
    scanf("\n%[^\n]s", &c);
    while (c[0] != 'F' && c[1] != 'I' && c[2] != 'M')//enquanto for diferente de 'FIM'
    {
        ciframento(c, 0);//chama a funcao ciframento
        scanf("\n%[^\n]s", &c);
    }
    return 0;
}
//funcao recursiva que recebe o vetor de caracter e um inteiro i
//recursivamente cifra a string
char ciframento(char c[], int i)
{
    //condicao de parada da recursividade
    if (c[i] == '\0')
    {
        printf("\n");
        return 0;
    }
    //ascii dos caracteres minusculos e maiusculos - somente letras
    if (c[i] >= 65 && c[i] <= 87 || c[i] >= 97 && c[i] <= 119)
    {
        printf("%c", c[i] + 3);//incrementa caso seja um caracter ente A - a e X - x
    }  
    else if ((c[i] >= 120 && c[i] <= 122) || (c[i] >= 88 && c[i] <= 90))
    {//caso chegue nas ultimas letras do alfabeto, troca as letras pelas seguintes:
        if (c[i] == 'X')
        {
            printf("A");
        }
        else if (c[i] == 'x')
        {
            printf("a");
        }
        else if (c[i] == 'Y')
        {
            printf("B");
        }
        else if (c[i] == 'y')
        {
            printf("b");
        }
        else if (c[i] == 'Z')
        {
            printf("B");
        }
        else if (c[i] == 'z')
        {
            printf("b");
        }
    }
    else{
    printf(" ");//imprime espacos em branco
    }
    return ciframento(c, ++i);//recursividade da funcao, executa ela novamente incrementando o i
}