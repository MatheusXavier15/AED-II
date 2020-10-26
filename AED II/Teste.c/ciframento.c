/*Neste exercício, suponha a chave de ciframento três. Implemente um programa para executar sua função que receba várias linhas contendo strings e, para cada string, imprimir a a mensagem criptografada. A entrada termina com a leitura da palavra FIM. Você deve cifrar somente letras do alfabeto  (A até Z, a até z), os demais caracteres não serão cifrados. Se a chave é igual a 3,  'a' é substituído por 'd', então 'z' é substituído por 'c', pois o algoritmo anda de forma circular sobre o alfabeto (A até Z, a até z).*/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

//funcao que realiza o ciframento da string, com uma chave de valor 3
//recebe um ponteiro que aponta para a string e retorna a string cifrada
char *ciframento(char *c)
{
    int N = strlen(c);//strlen determina o tamanho do vetor de caracteres
    for (int i = 0; i < N - 1; i++)//for que cifra a string
    {
        if (c[i] == ' ')//espa??o continua espa??o
        {
            c[i] = ' ';
        }
        else if (c[i] == 'z')//especifica as ultimas letras (minusculas)
        {
            c[i] = 'c';
        }
        else if (c[i] == 'y')
        {
            c[i] = 'b';
        }
        else if (c[i] == 'x')
        {
            c[i] = 'a';
        }
        else if (c[i] == 'Z')//especifica as ultimas letras (maiusculas)
        {
            c[i] = 'C';
        }
        else if (c[i] == 'Y')
        {
            c[i] = 'B';
        }
        else if (c[i] == 'X')
        {
            c[i] = 'A';
        }
        else
        {
            c[i] = c[i] + 3;//cifra as outras
        }
    }
    return c;//retorna a string
}

//procedimento que executa a leitura da string e armazena no vetor de caracteres
void leitura(char *c)
{
    for (int i = 0; i < 100; i++)
    {
        scanf("%c", &c[i]);
        //se encontra a palavra "FIM", finaliza a string e para o for
        if (c[i - 3] == '\n' && c[i - 2] == 'F' && c[i - 1] == 'I' && c[i] == 'M')
        {
            c[i - 3] = '\0';
            return;
        }
    }
}

int main()
{
    //declara vetor de caracteres
    char c[100];
    //executa procedimento
    leitura(c);
    //imprime tudo
    printf("%s\n", ciframento(c));
    return 0;
}