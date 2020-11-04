// #ifdef ESTATIC_LIST_H_INCLUDED
#define Lista_LIST_H_INCLUDED
//=======================================================================
#include "Pessoa.h"
//=======================================================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//=======================================================================
//=======================CRIAÇÃO ESTÁTICA DA LISTA=======================
//Criação do tipo Lista para armazenar a estrutura dos dados
typedef struct Lista
{
    Pessoa *dados;
    int TAM;
    int MAX;
} Lista;
//=======================================================================
//método booleano que cria e aloca a lista e retorna false caso a memória alocada esteja cheia
bool create_list(Lista *list, int X)
{
    list->MAX = X;
    list->dados = (Pessoa *)malloc(sizeof(Pessoa));//Aloca a memória criando a lista
    if (list == NULL)
    {
        return false;
    }
    list->TAM = 0;//Começa a lista com tamanho 0
    return true;
}
//=======================================================================
//Método booleano que adiciona um elemento à lista, caso a lista esteja cheia ele retorna false
bool add_element(Lista *list, Pessoa x)
{
    if (list->TAM == list->MAX)//Verifica o tamanho da lista
    {
        return false;
    }
    list->dados[list->TAM++] = x;//armazena o dado na lista na posição final (Ou seja, o tamanho)
    return true;
}
//=======================================================================
//Procedimento que imprime a lista chamando a função print_person
void print_list(Lista *list)
{
    for (int i = 0; i < list->TAM; i++)//For passando pela lista imprimindo os elementos
    {
        print_person(list->dados[i]);
    }
    return;
}
//=======================================================================
//Procedimento que inverte a ordem da lista
void invert_list(Lista *list)
{
    Lista aux;
    create_lista(&aux);//cria a lista auxiliar
    clone_list(list, &aux);//Clona a lista para auxiliar
    for (int i = 0; i < list->TAM; i++)//For passando pela lista
    {
        //inverte a lista
        aux.dados[list->TAM - i - 1].id = i + 1;
        list->dados[i] = aux.dados[list->TAM - i - 1];
    }
}
//=======================================================================
//Método booleano que deleta um elemento da lista - caso esse elemento exista
bool delete_list(Lista *list, int id)
{
    //Verifica a existencia do elemento
    if (id <= 0 || id > list->TAM)
    {
        printf("Produto nao encontrado na lista");
        return false;
    }
    //Delete a lista
    for (int i = id; i < list->TAM; i++)
    {
        list->dados[i - 1] = list->dados[i];
        list->dados[i - 1].id--;
    }
    //Diminui o tamanho
    list->TAM--;
    return true;
}
//=======================================================================
//Método booleano que atualiza elemento na lista - caso ele exista
bool update_lista(Lista *list, Pessoa p)
{
    //Verifica a existencia do elemento
    if (p.id <= 0 || p.id > list->TAM)
    {
        printf("Produto nao encontrado na lista");
        return false;
    }
    //Atualiza as informações com as ja inseridas
    list->dados[p.id - 1] = p;
    return true;
}
//=======================================================================
//Procedimento que clona a lista em outra lista
void clone_list(Lista *list, Lista *x)
{
    //Cria a lista
    create_lista(x);
    Pessoa aux; //cria uma pessoa auxiliar
    //For passando por toda a lista
    for (int i = 0; i < list->TAM; i++)
    {
        //clona as listas  
        aux = list->dados[i];
        add_element(x, aux);
    }
}
//=======================================================================
//Procedimento que concatena as listas inseridas
void concatenar_list(Lista *list, Lista *x, Lista *y)
{  
    //cria a lista 
    create_lista(x);
    Pessoa aux; //cria a pessoa auxiliar
    clone_list(list, x);//clona a lista para concatenar
    //for passando por toda a lista e concatenando duas em uma
    for (int i = 0; i < list->TAM; i++)
    {
        aux = y->dados[i];
        add_element(x, aux);
    }
}
//=======================================================================
//Método que retorna o maior elemento da lista (pessoa mais velha)
Pessoa MAIOR(Lista *list)
{
    Pessoa maior = list->dados[0];//Criação da auxiliar maior ocupando o primeiro lugar de dados
    int aux_maior = maior.age;//Declara a maior idade como a primeira
    //For passando por toda a lista comparando os dados e armazenando o maior
    for (int i = 0; i < list->TAM; i++)
    {
        if (list->dados[i].age > aux_maior)
        {
            maior = list->dados[i];
            aux_maior = maior.id;
        }
    }
    //retorna o maior
    return maior;
}
//=======================================================================
//Método que retorna o ID de um elemento a ser pesquisado na lista - retorna -1 caso não exista na lista 
int pesquisar_pessoa(Lista *x, char *name)
{
    //criação de variaveis
    int i = 0;
    bool find = false;
    for (i; i < x->TAM; i++)
    {
        //utiliza o strcmp para comparar as strings e achar a string correta
        if (strcmp(x->dados[i].name, name) == 0)
        {
            find = true;
            break;
        }
    }
    if (find == true)
    {
        return x->dados[i].id;
    }
    else
    {
        return -1;
    }
}
//=======================================================================
//Procedimento que coloca a lista em ordem alfabética
void alphabetic_sort(Lista *list)
{
    for (int i = 0; i < list->TAM; i++)
    {
        for (int j = 1; i < list->TAM; j++)
        {
            //utiliza o strncmp para comparar os caracteres alfabeticamente
            if (strcmp(list->dados[i].name, list->dados[j].name) < 0)
            {
                //swap
                Pessoa aux = list->dados[i];
                list->dados[i] = list->dados[j];
                list->dados[j] = aux;
            }
        }
    }
}
//=======================================================================
//implementação do quicksort para ordenação da lista
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
//Procedimento que através do quicksort ordena a lista
void crescent_sort(Lista *list)
{
    quicksort(list->dados, 0,list->TAM);
}
//=======================================================================