#ifndef FILAESTATICA_H_INCLUDED
#define FILAESTATICA_H_INCLUDED
//=============================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 10
//=============================================
#include "Pessoa.h"
//=============================================
typedef struct Fila
{
    Pessoa Data[MAX];
    int start;
    int end;
    int TAM;
} Fila;
//=============================================
void create_queue(Fila *queue)
{
    queue->start = 0;
    queue->end = 0;
    queue->TAM = 0;
}
//=============================================
bool enqueue(Fila *queue, Pessoa x)
{
    if (queue->TAM == MAX)
    {
        return false;
    }

    queue->end = (queue->end + 1) % MAX;
    queue->Data[queue->end] = x;
    queue->TAM++;

    return true;
}
//=============================================
void print_queue(Fila *queue)
{
    int pos = (queue->start + 1) % MAX;

    for (int i = 0; i < queue->TAM; i++)
    {
        print_person(queue->Data[pos]);
        pos = (pos + 1) % MAX;
    }
}
//=============================================
Pessoa dequeue(Fila *queue)
{

    if (queue->TAM == 0)
    {
        return;
    }

    queue->start = (queue->start + 1) % MAX;
    queue->TAM--;
    return queue->Data[queue->start];
}
//=============================================
bool enqueue_priority(Fila *queue, Pessoa x)
{
    int pos = (queue->start + 1) % MAX;
    for (int i = 0; i < queue->TAM; i++)
    {
        if (queue->Data[pos].age < 65)
        {
            int id, idade;
            char nome[100];

            Pessoa aux;

            aux = queue->Data[pos];

            queue->Data[pos] = x;

            queue->end = (queue->end + 1) % MAX;
            queue->TAM++;

            for (int i = pos + 1; i <= queue->end; i++)
            {
                x = queue->Data[i];
                queue->Data[i] = aux;
                aux = x;
            }
        }
        pos = (queue->start + 1) % MAX;
    }

    int id, idade;
    char nome[100];

    Pessoa aux;

    aux = queue->Data[pos];

    queue->Data[pos] = x;

    queue->end = (queue->end + 1) % MAX;
    queue->TAM++;

    for (int i = pos + 1; i <= queue->end; i++)
    {
        x = queue->Data[i];
        queue->Data[i] = aux;
        aux = x;
    }
}
//=============================================
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
    if (left < j)
        quicksort(Dado, left, j);
    if (right > i)
        quicksort(Dado, i, right);
}
//Procedimento que através do quicksort ordena a lista
void crescent_sort(Fila *queue)
{
    //quicksort
    quicksort(queue->Data, 0, queue->TAM);
}
//=============================================
#endif