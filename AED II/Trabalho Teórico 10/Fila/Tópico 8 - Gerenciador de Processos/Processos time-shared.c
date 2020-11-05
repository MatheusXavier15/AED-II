// Existem partes de sistemas operacionais que cuidam da ordem em que os programas devem ser executados. Por exemplo, em um sistema de computação de tempo-compartilhado (do inglês time-shared) existe a necessidade de manter um conjunto de processos em uma fila, esperando para serem executados.

// Escreva um programa que seja capaz de ler uma série de solicitações para:

// Incluir novos processos na fila de processos.
// Retirar da fila de processos o processo com o maior tempo de espera.
// Imprimir o conteúdo da lista de processos.
//=============================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//=============================================
#include "Processos.h"
//=============================================
//=============================================Fila Dinâmica=============================================//
typedef struct Celula
{
    struct Celula *prox;
    Processo Data;
} Celula;
typedef struct Fila
{
    Celula *start;
    Celula *end;
    int TAM;
} Fila;
//=============================================
//Método Booleano que cria a fila
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
//Método Booleano que adiciona elementos na fila
bool enqueue(Fila *queue, Processo x)
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
//Método que retira elementos da fila
Processo dequeue(Fila *queue)
{
    Celula *tmp = queue->start;
    queue->start = queue->start->prox;
    free(tmp);
    queue->TAM--;
    return queue->start->Data;
}
//=============================================
//Método que adiciona com prioridade elemento na fila
//Nesse caso, processos em prioridade com menos de 10ms de tempo de execução
bool enqueue_priority(Fila *queue, Processo x)
{
    Celula *aux = (Celula *)malloc(sizeof(Celula));
    if (aux == NULL)
    {
        return false;
    }
    aux->prox = NULL;
    aux->Data = x;
    Celula *ant = queue->start;
    while (ant->prox != NULL && ant->prox->Data.time <= 10)
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
//Método que clona uma fila em outra
Fila clone_queue(Fila *queue, Fila *clone)
{
    Fila aux;
    create_queue(&aux);
    Processo tmp = dequeue(queue);
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
//Método que concatena duas filas em uma terceira e retorna a terceira 
Fila concatenar_queue(Fila *queue, Fila *queue2)
{
    //queue [0,1,2,3,4] //queue2 [0,1,2,3,4]
    Fila aux, concatenada;
    create_queue(&aux);
    Processo tmp = dequeue(queue);
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
//Procedimento que inverte a fila
void invert_queue(Fila *queue)
{
    int tam = queue->TAM;
    Processo *tmp = (Processo *)malloc(sizeof(Processo));
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
//Procedimento que organiza a fila (bubble sort)
void sort_queue(Fila *queue)
{
    //bubble sort
    Processo aux;
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
//Método que acha o processo com maior tempo de execução
Processo MAIOR(Fila *queue)
{
    //celula maior auxiliar que receberá o maior elemento da queuea
    Celula maior = *queue->start->prox;
    //for passando por todos os elementos da queuea a partir do sentinela
    for (Celula *tmp = queue->start->prox; tmp != NULL; tmp = tmp->prox)
    {
        //se o elemento em tmp for maior que o ja armazenado em maior,
        if (tmp->Data.time > maior.Data.time)
        {
            //maior vira esse elemento
            maior = *tmp;
        }
    }
    //retorna a pessoa presente no maior
    return maior.Data;
}
//=============================================
//Procedimento que retira um processo específico da fila
void delete_element(Fila *queue, Processo x){
     bool changed = false;
    Celula *ant = queue->start;
    for (Celula *tmp = queue->start->prox; tmp != NULL; tmp = tmp->prox, ant = ant->prox)
    {
        if (tmp->Data.id == x.id)
        {
            ant->prox = tmp->prox;
            if (tmp->prox == NULL)
            {
                queue->end = ant;
            }
            free(tmp);
            queue->TAM--;
            changed = true;
            break;
        }
    }
}
//=============================================]
//Função que apresenta o menu
int menu()
{
    int op;
    printf("\n---------- LISTA DE PESSOAS ----------\n");
    printf("1 - Adicionar processo\n");
    printf("2 - Lista numero de processos\n");
    printf("3 - Listar todos os processos\n");
    printf("4 - Retirar processo com maior tempo\n");
    printf("0 - Sair\n");
    scanf("%d", &op);

    return op;
}
//=============================================
int main()
{
    int op;
    Fila queue;
    Processo p_aux;
    Processo maior;
    do
    {
    
    switch (op)
    {
        op = menu();
    case 1:
        printf("Adicionando processo a lista...\n");
        p_aux = new_process();
        enqueue(&queue, p_aux);
        break;

    case 2:
        printf("Listando numero de processos em fila...\n");
        printf("O numero de avioes na fila eh:%d", queue.TAM);
        break;

    case 3:
        printf("Listando todos os processos em fila...\n");
        print_queue(&queue);
        break;

    case 4:
        printf("Deletando elemento com maior tempo de execucao...\n");
        maior = MAIOR(&queue);
        delete_element(&queue, maior);
        break;

    case 0:
        return 0;
        break;

    default:
        break;
    }
    } while (op != 0);
}
