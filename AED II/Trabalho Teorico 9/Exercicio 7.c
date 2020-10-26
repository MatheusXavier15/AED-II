// Usando ponteiro para função, crie um programa que simule uma calculadora com as operações de soma, subtração, divisão e multiplicação. A operação deve ser executada em dois números inteiros e deve ser alocada dinamicamente em um ponteiro após o usuário definir qual operação deseja executar.
#include <stdio.h>
#include <stdlib.h>
//------------------------------------------------
int soma();
int subtracao();
int multiplicacao();
int divisao();
int menu();
//------------------------------------------------
int main(void)
{
    int *p;
    int op;
    int resultado;
    do
    {
        //aloca dinamicamente
        p = (int *)malloc(2 * sizeof(int));
        printf("\nDigite o primeiro numero:");
        scanf("%d", p);
        printf("\nDigite o segundo numero:");
        scanf("%d", p + 1);

        op = menu();
        switch (op)
        {
        case 0:
            return 0;
            break;
        case 1:
            //Soma
            resultado = soma(p, p + 1);
            printf("Resultado da soma: %d", resultado);
            free(p);//libera o espaço alocado
            break;
        case 2:
            //Subtracao
            resultado = subtracao(p, p + 1);
            printf("Resultado da subtracao: %d", resultado);
            free(p);//libera o espaço alocado
            break;
        case 3:
            //multiplicacao
            resultado = multiplicacao(p, p + 1);
            printf("Resultado da multiplicacao: %d", resultado);
            free(p);//libera o espaço alocado
            break;
        case 4:
            //divisao
            resultado = divisao(p, p + 1);
            printf("Resultado da divisao: %d", resultado);
            free(p);//libera o espaço alocado
            break;
        default:
            break;
        }

    } while (op != 0);
    return 0;
}

//Funções utilizadas

//soma os elementos
int soma(int *x, int *y)
{
    int resultado;
    resultado = *x + *y;
    return resultado;
}

//subtrai os elementos
int subtracao(int *x, int *y)
{
    int resultado;
    resultado = *x - *y;
    return resultado;
}

//multiplica os elementos
int multiplicacao(int *x, int *y)
{
    int resultado;
    resultado = *x * *y;
    return resultado;
}

//divide os elementos
int divisao(int *x, int *y)
{
    int resultado;
    resultado = (float)*x / *y;
    return resultado;
}

//Função que abriga o menu
int menu()
{
    int op;
    printf("Digite 1 para soma\n");
    printf("Digite 2 para subtracao\n");
    printf("Digite 3 para multiplicacao\n");
    printf("Digite 4 para divisao\n");
    printf("Digite 0 para sair\n");
    scanf("%d", &op);
    return op;
}