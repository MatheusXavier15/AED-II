#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
//=======================
#include "Pessoa.h"
//=======================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
//=======================
//=======================CRIAÇÃO DINÂMICA DA LISTA=======================
//Cria o tipo celula que armazena os dados de pessoa e a proxima celula
typedef struct Celula
{
    Pessoa dado;
    struct Celula *prox;
} Celula;
//Cria o tipo lista que tem o inicio, o fim e seu tamanho
typedef struct Lista
{
    Celula *start;
    Celula *end;
    int TAM;
} Lista;
//Cria dinamicamente uma lista, com tamanho limitado pela memória
bool create_lista(Lista *list)
{
    //aloca uma celula temporaria
    Celula *tmp = (Celula *)malloc(sizeof(Celula));
    if (tmp == NULL)
    {
        //memória cheia
        return false;
    }
    //a proxima celula não existe ainda, então recebe null
    tmp->prox = NULL;
    //tanto o inicio quanto o fim recebe a celula temporaria (Ou seja, inicio e fim no mesmo ponto)
    list->start = tmp;
    list->end = tmp;
    //a lista começa com tamanho 0
    list->TAM = 0;
    return true;
}
//=======================

void print_list(Lista *x)
{
    setlocale(LC_ALL, " ");
    Celula *tmp = x->start->prox;
    while (tmp != NULL)
    {
        print_person(tmp->dado);
        tmp = tmp->prox;
    }
}

//Adiciona uma nova pessoa à lista
bool add_person_at_list(Lista *list, Pessoa x)
{
    //aloca uma celula para receber o novo elemento na lista
    Celula *cell = (Celula *)malloc(sizeof(Celula));
    if (cell == NULL)
    {
        //memória cheia
        return false;
    }
    //O dado em questão recebe as informações do parâmetro
    cell->dado = x;
    // o valor apontado na celula cell é nulo
    cell->prox = NULL;
    //A proxima recebe o que esta armazenado no proxima da cell
    list->end->prox = cell;
    //O fim recebe o valor do dado da cell
    list->end = cell;
    //aumenta o tamanho da lista
    list->TAM++;
    return true;
}
// Implemente um procedimento CLONAR para a Lista, que retorna uma lista exatamente igual à variável sobre a qual o método foi invocado. Implemente um para a versão usando arranjos e outro para a versão usando ponteiros.

void clone_list(Lista *list, Lista *x)
{
    setlocale(LC_ALL, " ");
    //cria a nova lista que será clonada
    create_lista(x);
    //celula auxiliar que recebe o sentinela e servirá de "guia" dentro do for
    Celula *ant = list->start;
    //tmp aponta pra prox celula depois do sentinela, e tanto tmp quanto ant vão incrementando, passando assim por toda a lista
    for (Celula *tmp = list->start->prox; tmp != NULL; tmp = tmp->prox, ant = ant->prox)
    {
        //A lista x receberá o dado que está na lista original que está sendo apontado por tmp
        add_person_at_list(x, tmp->dado);
        x->TAM++;
    }
    if (x->end != NULL) //se no final a lista não for nula,
    {
        printf("Lista clonada com sucesso."); //ela foi clonada com sucesso
    }
}

// Implemente um procedimento CONCATENAR para a lista, recebe como parâmetro duas listas e retorne uma terceira contendo a concatenação das duas. Implemente uma para a versão usando arranjos e outra para a versão usando ponteiros.

Lista concatena_listas(Lista *x, Lista *y)
{
    setlocale(LC_ALL, " ");
    //Se uma das listas foram nulas, retorna a outra lista (não tem com o que concatenar)
    if (x == NULL)
    {
        printf("Não é possível concatenar por não haver dados!\n");
        return;
    }
    //mesmo loop for para percorrer toda a lista a ser concatenada
    //a "lista mãe" já está no final, então basta adicionar os elementos da outra lista nela, o que pode ser feito com o método ja implementado de adicionar elementos.
    //Para isso o loop abaixo percorre cada célula da lista y colocando na lista x.
    Celula *ant = y->start;
    for (Celula *tmp = y->start->prox; tmp != NULL; tmp = tmp->prox, ant = ant->prox)
    {
        add_person_at_list(x, tmp->dado);
        x->TAM++;
    }
    int i = 1;
    for (Celula *aux = x->start->prox; aux != NULL; aux = aux->prox, i++)
    {
        aux->dado.id = i;
    }
    Lista *z;
    create_lista(z);
    clone_list(x, z);
    return *z;
}
//Deleta um item da lista
bool delete_list(Lista *x, int id)
{
    bool changed = false;
    Celula *ant = x->start;
    for (Celula *tmp = x->start->prox; tmp != NULL; tmp = tmp->prox, ant = ant->prox)
    {
        if (tmp->dado.id == id)
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
        aux->dado.id = i;
    }
}
// Implemente um procedimento INVERTER para a lista, recebe como parâmetro uma lista e inverte a ordem dos dados que estão na fila. Seu procedimento deve alterar os dados da lista recebida como parâmetro usando passagem por referência. Implemente uma para a versão usando arranjos e outra para a versão usando ponteiros.
void inverteElementos(Celula *e, Celula *ant)
{
    if (e->prox != NULL)
        inverteElementos(e->prox, e);
    e->prox = ant;
}

void invert_list(Lista *p)
{
    inverteElementos(p->start, NULL);

    //Inverte inicio com fim
    Pessoa *aux = p->start->prox;
    p->start->prox = p->end;
    p->end = aux;

    Celula *tmp = p->start->prox;
    int i = 0;
    while (i != p->TAM)
    {
        print_person(tmp->dado);
        tmp = tmp->prox;
        i++;
    }
}

// Implemente um procedimento INSERIR_ORDENADO para a lista, que deve inserir os dados de forma ordenada na lista. Seu procedimento não deve chamar um método de ordenação, mas sim garantir que cada dado inserido já fique na posição de ordenação. Implemente uma para a versão usando arranjos e outra para a versão usando ponteiros.

void INSERIR_ORDENADO(Lista *list, Pessoa x)
{
    Celula *cell = (Celula *)malloc(sizeof(Celula));
    Celula aux;
    if (cell == NULL)
    {
        return;
    }
    Celula *ant = list->start;
    for (Celula *tmp = list->start->prox; tmp != NULL; tmp->prox)
    {
        if (x.id < tmp->dado.id)
        {
            aux = *tmp;
            x.id = list->TAM + 1;
            tmp->dado = x;
            tmp->prox = cell;
            *cell = aux;
            list->TAM++;
            return;
        }
        tmp = tmp->prox;
    }
    x.id = list->TAM + 1;
    cell->dado = x;
    cell->prox = NULL;
    list->end->prox = cell;
    list->end = cell;
    list->TAM++;
}

// Implemente um procedimento MAIOR para a Lista, que retorne o maior elemento presente na lista. Implemente um para a versão usando arranjos e outro para a versão usando ponteiros.

Pessoa MAIOR(Lista *list)
{
    //celula maior auxiliar que receberá o maior elemento da lista
    Celula maior = *list->start->prox;
    //for passando por todos os elementos da lista a partir do sentinela
    for (Celula *tmp = list->start->prox; tmp != NULL; tmp = tmp->prox)
    {
        //se o elemento em tmp for maior que o ja armazenado em maior,
        if (tmp->dado.age > maior.dado.age)
        {
            //maior vira esse elemento
            maior = *tmp;
        }
    }
    //retorna a pessoa presente no maior
    return maior.dado;
}

bool update(Lista *x, Pessoa y)
{
    bool changed = false;
    for (Celula *tmp = x->start->prox; tmp != NULL; tmp = tmp->prox)
    {
        if (tmp->dado.id == y.id)
        {
            tmp->dado = y;
            changed = true;
            break;
        }
    }
}
// Escreva um procedimento Pesquisar para a Lista do tipo Pessoa que receba como parâmetro o nome de uma Pessoa e retorne seu código caso a Pessoa esteja na lista, caso contrário retorne -1. Implemente uma para a versão usando arranjos e outra para a versão usando ponteiros.

int pesquisar_pessoa(Lista *x, char *name)
{
    //variavel booleana para auxiliar o retorno da função
    bool find = false;
    //tmp aponta pro primeiro elemento
    Celula *tmp = x->start->prox;
    //for percorrendo toda a lista
    for (*tmp; tmp != NULL; tmp = tmp->prox)
    {
        //se achar a pessoa:
        if (strcmp(tmp->dado.name, name) == 0)
        {
            //variavel vira true e quebra o for
            find = true;
            break;
        }
    }
    //retorna a função
    if (find == true)
    {
        return tmp->dado.id;
    }
    else
    {
        return -1;
    }
}

// Utilizando a Lista do tipo Pessoa, implemente dois procedimentos que sejam capazes de ordenar a lista, um procedimento ordenando pelo código em ordem crescente e outro procedimento ordenando pelo nome em ordem alfabética. Implemente uma para a versão usando arranjos e outra para a versão usando ponteiros.
void quicksort(Pessoa *Dado, int left, int right)
{
    int i = left;
    int j = right;
    int pivo = Dado[(i + j) / 2].id;
    while (i <= j)
    {
        while (Dado[i].id < pivo)
        {
            i++;
        }
        while (Dado[j].id < pivo)
        {
            j--;
        }
        if (i <= j)
        {
            Pessoa aux = Dado[i];
            Dado[i] = Dado[j];
            Dado[j] = aux;
            i++;
            j--;
        }
    }
    if (left < j)quicksort(Dado, left, j);
    if (right > i)quicksort(Dado, i, right);
}
void crescent_sort(Lista *list)
{
    Pessoa aux;
    Celula *ant = list->start;
    Celula *tmp = ant->prox;
    while (tmp != NULL)
    {
        if (tmp->dado.id < ant->dado.id)
        {
            aux = ant->dado;
            ant->dado = tmp->dado;
            tmp->dado = aux;
        }
        ant = ant->prox;
        tmp = tmp->prox;
    }
}

void alphabetic_sort(Lista *list)
{
    //usar strncmp para retornar a ordem alfabética
    Celula *ant = list->start;
    Celula *tmp = ant->prox;
    //while percorrendo toda a lista
    while (tmp != NULL)
    {
        //strncmp compara caracteres e retorna se for alfabeticamente anterior
        if (strncmp(tmp->dado.name, ant->dado.name, 100) < 0)
        {
            //swap com os elementos
            Pessoa aux = tmp->dado;
            tmp->dado = ant->dado;
            ant->dado = aux;
        }
        //avança a posição da lista
        ant = ant->prox;
        tmp = tmp->prox;
    }
}

#endif