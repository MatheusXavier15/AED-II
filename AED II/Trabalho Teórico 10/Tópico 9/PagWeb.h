#ifndef PAGWEB_H_INCLUDED
#define PAGWEB_H_INCLUDED
//================================
#include <stdio.h>
#include <stdlib.h>
//================================
typedef struct Site
{
    int id;
    char name[100];
    char url[100];
}Site;

//Procedimento que imprime pessoa
void print_Site(Site x){
    printf ("\nCodigo: %d | Nome: %s | url: %d", x.id, x.name, x.url);
}

//Função que cria nova pessoa
Site NEW_SITE()
{
    Site p;
    printf("\nDigite o nome da pessoa:\n");
    scanf("%[^\n]s\n", p.name);
    printf("\nDigite a idade da pessoa:\n");
    scanf("%[^\n]s\n", p.url);
    return p;
}
//================================
#endif 