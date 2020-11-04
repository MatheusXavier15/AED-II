//=======================
#include "Pessoa.h"
#include "Lista.h"
//=======================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
//=======================
int menu();
//CRUD -> CREATE, READ, UPDATE, DELETE

int main()
{
    setlocale(LC_ALL, "portuguese");
    int result;
    char name[100];
    int op = 1;
    Pessoa maior;
    Lista people;
    Lista aux;
    create_lista(&people);
    Pessoa p_aux;
    do
    {
        int op = menu(), id;
        switch (op)
        {
        case 0:
            return 0;
            break;

        case 1:
            print_list(&people);
            break;

        case 2:
            p_aux = new_people();
            p_aux.id = people.TAM + 1;
            add_person_at_list(&people, p_aux);
            break;

        case 3:
            clone_list(&people, &aux);
            printf("Imprimindo lista clonada:\n\n");
            print_list(&aux);
            break;

        case 4:
            concatena_listas(&people, &aux);
            printf("Imprimindo lista concatenada:\n\n");
            print_list(&people);
            break;

        case 5:
            printf("Imprimindo lista invertida:\n\n");
            invert_list(&people);
            break;

        case 6:
            printf("Inserir elemento na lista:\n\n");
            p_aux = new_people();
            INSERIR_ORDENADO(&people, p_aux);
            break;

        case 7:
            printf("maior elemento presente na lista:\n\n");
            printf("Criterio escolhido: idade\n\n");
            maior = MAIOR(&people);
            print_person(maior);
            break;

        case 8:
            printf("Digite o nome a ser pesquisado:\n");
            scanf("%s", name);
            fflush(stdin);
            result = pesquisar_pessoa(&people, name);
            if (id == -1)
            {
                printf("A pessoa não consta na lista.\n");
            }
            else
            {
                printf("O ID da pessoa na lista é:%d\n", result);
            }

            break;

        case 9:
            printf("Ordenando em ordem alfabética...\n\n");
            alphabetic_sort(&people);
            print_list(&people);
            break;

        case 10:
            printf("Ordenando por ID...\n\n");
            crescent_sort(&people);
            print_list(&people);
            break;
        default:
            break;
        }
    } while (op != 0);
}

int menu()
{
    setlocale(LC_ALL, " ");
    int op;
    printf("\n---------- LISTA DE PESSOAS ----------\n");
    printf("1 - Listar Pessoas\n");
    printf("2 - Inserir Pessoa\n");
    printf("3 - Clonar lista\n");
    printf("4 - Concatenar listas\n");
    printf("5 - Inverter lista\n");
    printf("6 - Inserir Pessoa Ordenadamente\n"); //problem
    printf("7 - Maior elemento da lista\n");
    printf("8 - Pesquisar pessoa\n");
    printf("9 - Ordenar em ordem alfabética a lista\n");
    printf("10- Ordenar a lista por id\n");
    printf("0 - Sair\n");
    scanf("%d", &op);

    return op;
}