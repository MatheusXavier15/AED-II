#ifndef PROCESSO_H_INCLUDED 
#define PROCESSO_H_INCLUDED 
//=============================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//=============================================
typedef struct Processo
{
    int id;
    char name[100];
    int time;
}Processo;
//=============================================
//Procedimento que imprime Processo
void print_processo(Processo x){
    printf ("\nCodigo: %d | Nome: %s | Tempo: %d", x.id, x.name, x.time);
}
//=============================================
//Função que cria novo Processo
Processo new_process()
{
    Processo p;
    printf("\nDigite o nome do Processo:\n");
    scanf("%[^\n]s\n",&p.name);
    fflush(stdin);
    printf("\nDigite o tempo de espera do Processo:\n");
    scanf("%d", &p.time);
    return p;
}
//=============================================
#endif