#ifndef DOUBLE_LIST_H_INCLUDED
#define DOUBLE_LIST_H_INCLUDED

// Um problema que pode surgir na manipulação de listas usando ponteiros é o de voltar atrás na lista, ou seja, percorrê-la no sentido inverso ao dos apontadores. A solução geralmente adotada é a incorporação à célula de um apontador para o seu antecessor. Listas deste tipo são chamadas duplamente encadeadas.

// Escreva a definição do ListaDupla, com todos os tipos necessários e implemente os seguintes procedimentos:

// Criar uma lista
// Inserir um novo elemento
// Remover um elemento
// Verificar o tamanho da lista
// Pesquisar um elemento na lista
// Imprimir o conteúdo da lista

//=================================
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
//=================================
#include "Pessoa.h"
//=================================
typedef struct Celula
{
    Pessoa data;
    struct Celula *prox;
    struct Celula *ant;
}Celula;

typedef struct Double_List
{
    Celula *start;
    Celula *end;
    int TAM;
}Double_List;
//=================================
bool create_list (Double_List *List){
    Celula *tmp = (Celula *)malloc(sizeof(Celula));
    if(tmp == NULL){
        return false;
    }
    tmp->ant = NULL;
    tmp->prox = NULL;

    List->start = tmp;
    List->end = tmp;
    List->TAM = 0;
}
//=================================
bool add_element (Double_List *List, Pessoa x){
    Celula *cell = (Celula *)malloc(sizeof(Celula));

    if(cell == NULL){
        return false;
    }

    cell->data = x;
    cell->prox = NULL;

    List->end->prox=cell;
    cell->ant = List->end;
    List->end = cell;
    List->TAM ++;

    return true;
}
//=================================
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
    int i = 1;
    //reorganiza os códigos dos produtos após a exclusão
    for (Celula *aux = x->start->prox; aux != NULL; aux = aux->prox, i++)
    {
        aux->data.id = i;
    }
}
//=================================
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
//=================================
Celula search_element (Double_List *List, int cod){

     for (Celula *tmp = List->start->prox; tmp != NULL; tmp = tmp->prox)
    {
        if (tmp->data.id == cod)
        {
            printf("Elemento encontrado!\n");
            print_person(tmp->data);
            return *tmp;
        }
    }
}
//=================================
void print_list(Double_List *List){
    Celula *tmp = List->start->prox;
    while (tmp != NULL)
    {
        print_person(tmp->data);
        tmp = tmp->prox;
    }
    
}
//=================================
#endif