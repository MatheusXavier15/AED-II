// Crie um programa para gerenciar o acesso a páginas web. Considere uma coleção de nomes de sites da web e seus respectivos links na Internet armazenados através de uma lista. Escreva um programa que contenha um método que, dado o nome de um site, busque o seu link correspondente na lista e ao mesmo tempo mova o nó que contém o nome buscado para o início da lista, de forma que ele possa ser encontrado mais rapidamente na próxima vez que for buscado. O seu programa deve retornar a quantidade de acessos realizados na lista para retornar a página solicitada, ou seja, a quantidade de elementos visitados na lista até encontrar a página web desejada. Implemente todos os métodos que julgar necessário para o problema proposto. Sua implementação deve considerar o uso dinâmico de memória usando ponteiros.

#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
//================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//================================
#include "PagWeb.h"
//================================
typedef struct Celula
{
    Site data;
    struct Celula *prox;
    struct Celula *ant;
} Celula;

typedef struct Double_List
{
    Celula *start;
    Celula *end;
    int TAM;
} Double_List;
//================================
bool create_list(Double_List *List)
{
    Celula *tmp = (Celula *)malloc(sizeof(Celula));
    if (tmp == NULL)
    {
        return false;
    }
    tmp->ant = NULL;
    tmp->prox = NULL;

    List->start = tmp;
    List->end = tmp;
    List->TAM = 0;
}
//================================
bool add_element(Double_List *List, Site x)
{
    Celula *cell = (Celula *)malloc(sizeof(Celula));

    if (cell == NULL)
    {
        return false;
    }

    cell->data = x;
    cell->prox = NULL;

    List->end->prox = cell;
    cell->ant = List->end;
    List->end = cell;
    List->TAM++;

    return true;
}
//================================
bool delete_element(Double_List *x, int id)
{
    bool changed = false;
    Celula *ant = x->start;
    for (Celula *tmp = x->start->prox; tmp != NULL; tmp = tmp->prox, ant = ant->prox)
    {
        if (tmp->data.id == id)
        {
            ant->prox = tmp->prox;
            if (tmp->prox == NULL)
            {
                x->end = ant;
            }
            free(tmp);
            x->TAM--;
            changed = true;
            break;
        }
    }
    printf("Item excluido com sucesso!\n");
}
//================================
void print_list(Double_List *List)
{
    Celula *tmp = List->start->prox;
    while (tmp != NULL)
    {
        print_Site(tmp->data);
        tmp = tmp->prox;
    }
}
//================================
// Escreva um programa que contenha um método que, dado o nome de um site, busque o seu link correspondente na lista e ao mesmo tempo mova o nó que contém o nome buscado para o início da lista, de forma que ele possa ser encontrado mais rapidamente na próxima vez que for buscado.

void find_page(Double_List *List, char *nome)
{
    Celula *ant = List->start;
    Celula *tmp = ant->prox;
    for (int acess; tmp != NULL; tmp = tmp->prox, acess)
    {
        if (strcmp(tmp->data.name, nome) == 0)
        {
            if (List->end == tmp)
            {
                List->end = ant;
            }
            ant->prox = tmp->prox;      
            tmp->prox = List->start->prox; 
            List->start->prox = tmp;    
            printf("\n URL acessada: %s \n Acessos na lista ate encontrar url: %d\n", tmp->data.url, acess);   
            return;
        }
        ant = tmp; 
    }
}
//================================
Celula search_element (Double_List *List, int cod){

     for (Celula *tmp = List->start->prox; tmp != NULL; tmp = tmp->prox)
    {
        if (tmp->data.id == cod)
        {
            printf("Elemento encontrado!\n");
            print_Site(tmp->data);
            return *tmp;
        }
    }
    return;
}
//================================
bool verify_list (Double_List *list, int N){
    if(list->TAM==NULL){
        printf("A lista não existe");
        return false;
    }
    if(list->TAM == N){
        printf("A quantidade de elementos da lista e: %d", list->TAM);
        printf("A lista está do tamanho correto!\n");
        return true;
    } else
    {
        printf("A lista está com o tamanho incorreto!\n");
        return false;
    }
}
//================================

//================================
#endif