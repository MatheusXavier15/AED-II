#ifndef FILADINAMICA_H_INCLUDED
#define FILADINAMICA_H_INCLUDED
//=============================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//=============================================
#include "Pessoa.h"
//=============================================
//Definição dos tipos de variáveis
typedef struct Celula
{
    struct Celula *prox;
    Pessoa Data;
} Celula;
typedef struct Fila
{
    Celula *start;
    Celula *end;
    int TAM;
} Fila;
//=============================================
//Método booleano que cria a fila
bool create_queue(Fila *queue)
{
    Celula *cell = (Celula *)malloc(sizeof(Celula));
    if (cell == NULL)
    {
        return false;
    }
    cell->prox = NULL;
    queue->start = cell;
    queue->end = cell;
    queue->TAM = 0;
    return true;
}
//=============================================
//Método booleano que adiciona elementos à fila
bool enqueue(Fila *queue, Pessoa x)
{
    Celula *cell = (Celula *)malloc(sizeof(Celula));
    if (cell == NULL)
    {
        return false;
    }
    cell->prox = NULL;
    cell->Data = x;
    queue->end = cell;
    queue->end->prox = cell;
}
//=============================================
//Procedimento que imprime a fila
void print_queue(Fila *queue)
{
    Celula *aux = queue->start->prox;
    while (aux != NULL)
    {
        print_person(aux->Data);
        aux = aux->prox;
    }
}
//=============================================
//Método que desenfila elementos
Pessoa dequeue(Fila *queue)
{
    Celula *tmp = queue->start;
    queue->start = queue->start->prox;
    free(tmp);
    queue->TAM--;
    return queue->start->Data;
}
//=============================================
//Método booleano que adiciona elementos à fila com certa prioridade
bool enqueue_priority(Fila *queue, Pessoa x)
{
    Celula *aux = (Celula *)malloc(sizeof(Celula));
    if (aux == NULL)
    {
        return false;
    }
    aux->prox = NULL;
    aux->Data = x;
    Celula *ant = queue->start;
    while (ant->prox != NULL && ant->prox->Data.age >= 65)
    {
        ant = ant->prox;
    }
    aux->prox = ant->prox;
    ant->prox = aux;
    if (aux->prox == NULL)
    {
        queue->end = aux;
    }
    queue->TAM++;
    return true;
}
//=============================================
//Método que clona uma fila na outra
Fila clone_queue(Fila *queue, Fila *clone)
{
    Fila aux;
    create_queue(&aux);
    Pessoa tmp = dequeue(queue);
    while (tmp.id != NULL)
    {
        enqueue(&aux, tmp);
        tmp = dequeue(queue);
    }
    tmp = dequeue(&aux);
    while (tmp.id != NULL)
    {
        enqueue(clone, tmp);
        enqueue(queue, tmp);
        tmp = dequeue(queue);
    }
    return *clone;
}
//=============================================
//Método que concatena duas filas e retorna uma terceira
Fila concatenar_queue(Fila *queue, Fila *queue2)
{
    //queue [0,1,2,3,4] //queue2 [0,1,2,3,4]
    Fila aux, concatenada;
    create_queue(&aux);
    Pessoa tmp = dequeue(queue);
    while (tmp.id != NULL)
    {
        //aux [0,1,2,3,4] 
        //queue [NULL]
        enqueue(&aux, tmp);
        tmp = dequeue(queue);
    }
    tmp = dequeue(queue2);
    while (tmp.id != NULL)
    {
        //aux [0,1,2,3,4,0,1,2,3,4]
        //queue [0,1,2,3,4]
        enqueue(&aux, tmp);
        enqueue(queue, tmp);
        tmp = dequeue(queue);
    }
    tmp = dequeue(&aux);
    while (tmp.id != NULL)
    {
        //concatenada [0,1,2,3,4,0,1,2,3,4]
        //aux [NULL]
        enqueue(&concatenada, tmp);
        tmp = dequeue(queue);
    }
    return concatenada;
}
//=============================================
//Método que inverte uma fila
void invert_queue(Fila *queue)
{
    int tam = queue->TAM;
    Pessoa *tmp = (Pessoa *)malloc(sizeof(Pessoa));
    // queue [0,1,2,3,4]
    for (int i = 0; i < tam; i++)
    {
        tmp[i] = dequeue(queue);
        // tmp [0,1,2,3,4]
        // queue [ NULL ]
    }
    for (int i = tam - 1; i > 0; i++)
    {
        // queue[4,3,2,1,0]
        // tmp [NULL]
        enqueue(queue, tmp[i]);
    }
}
//=============================================
//Método que ordena uma fila (Bubble Sort)
void sort_queue(Fila *queue){
    //bubble sort
    Pessoa aux;
    Celula *ant = queue->start;
    Celula *tmp = ant->prox;
     while (tmp != NULL)
    {
        if (tmp->Data.id < ant->Data.id)
        {
            aux = ant->Data;
            ant->Data = tmp->Data;
            tmp->Data = aux;
        }
        ant = ant->prox;
        tmp = tmp->prox;
    }
}
//=============================================
#endif
