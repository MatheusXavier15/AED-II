#ifndef AVIAO_H_INCLUDED
#define AVIAO_H_INCLUDED
//=============================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//=============================================
typedef struct Aviao
{
    int id;
    char name[100];
    float combustivel;
    char carga[100];
} Aviao;
//=============================================
//Procedimento que imprime Aviao
void print_aviao(Aviao x)
{
    printf("\nCodigo: %d | Nome: %s | Combustivel: %f | Carga: %s", x.id, x.name, x.combustivel, x.carga);
}
//=============================================
//Função que cria nova Aviao
Aviao new_aviao()
{
    Aviao p;
    printf("\nDigite o nome do Aviao:\n");
    scanf("%[^\n]s\n", &p.name);
    fflush(stdin);
    printf("\nDigite a combustivel do Aviao:\n");
    scanf("%f", &p.combustivel);
    printf("\nDigite a carga do Aviao:\n");
    scanf("%[^\n]s\n", &p.carga);
    fflush(stdin);
    return p;
}
//=============================================
#endif