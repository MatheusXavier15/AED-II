#ifndef DINAMICLIST_H_INCLUDED
#define DINAMICLIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//---------------------------
#include "Product.h"
//---------------------------
//espaços da lista dinâmica
typedef struct Celula
{
    Product dado;
    struct Celula *prox;
} Celula;
//---------------------------
//Lista Dinâmica
typedef struct DinamicList
{
    Celula *inicio;
    Celula *fim;
    int TAM;
} DinamicList;
//Cria a lista dinamicamente
bool create_list(DinamicList *x)
{
    Celula *tmp = (Celula *)malloc(sizeof(Celula));
    tmp->prox = NULL;
    x->inicio = tmp;
    x->fim = tmp;
    x->TAM = 0;
}
//Adiciona um novo produto na lista
bool add_list(DinamicList *x, Product y)
{
    Celula *nova = (Celula *)malloc(sizeof(Celula));
    if (nova == NULL)
    {
        return false;
    }
    nova->dado = y;
    nova->prox = NULL;
    x->fim->prox = nova;
    x->fim = nova;
    x->TAM++;
    return true;
}
//imprime a lista
void print_list(DinamicList *x)
{
    Celula *tmp = x->inicio->prox;
    while (tmp != NULL)
    {
        print_product(tmp->dado);
        tmp = tmp->prox;
    }
}
//atualiza a lista
bool update(DinamicList *x, Product y)
{
    bool changed = false;
    for (Celula *tmp = x->inicio->prox; tmp != NULL; tmp = tmp->prox)
    {
        if (tmp->dado.cod == y.cod)
        {
            tmp->dado = y;
            changed = true;
            break;
        }
    }
}
//Deleta um item da lista
bool delete_list(DinamicList *x, int id){
    bool changed = false;
    Celula *ant = x->inicio;
    for (Celula *tmp = x->inicio->prox; tmp != NULL; tmp = tmp->prox, ant=ant->prox)
    {
        if (tmp->dado.cod == id)
        {
            ant->prox = tmp->prox;
            if (tmp->prox == NULL)
            {
                x->fim = ant;
            }
            
            free(tmp);
            x->TAM--;
            changed = true;
            break;
        }
    }
    int i = 1;
    //reorganiza os códigos dos produtos após a exclusão
    for (Celula *aux = x->inicio->prox; aux != NULL; aux = aux->prox, i++)
    {
        aux->dado.cod = i;
    }
}
#endif