#ifndef PESSOA_H_INCLUDED 
#define PESSOA_H_INCLUDED 
//=============================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//=============================================
typedef struct Pessoa
{
    int id;
    char name[100];
    int age;
}Pessoa;
//=============================================
//Procedimento que imprime pessoa
void print_person(Pessoa x){
    printf ("\nCodigo: %d | Nome: %s | Idade: %d", x.id, x.name, x.age);
}
//=============================================
//Função que cria nova pessoa
Pessoa new_people()
{
    Pessoa p;
    printf("\nDigite o nome da pessoa:\n");
    scanf("%s",&p.name);
    printf("\nDigite a idade da pessoa:\n");
    scanf("%d", &p.age);
    fflush(stdin);
    return p;
}
//=============================================
#endif