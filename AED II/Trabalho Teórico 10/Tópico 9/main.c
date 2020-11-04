#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

#include "Lista.h"
#include "PagWeb.h"

int menu();

int main()
{
    setlocale(LC_ALL, "portuguese");
    char name[100];
    int op = 1, id, K;
    Site maior, s_aux;
    Celula result;
    Double_List pag;
    create_lista(&pag);
    do
    {
        int op = menu(), id;
        switch (op)
        {
        case 0:
            return 0;
            break;

        case 1:
            print_list(&pag);
            break;

        case 2:
            s_aux = NEW_SITE();
            s_aux.id = pag.TAM + 1;
            add_element(&pag, s_aux);
            break;

        case 3:
            printf("Digite o numero do id a ser deletado:\n");
            scanf("%d", &id);
            delete_element(&pag, id);
            break;

        case 4:
            printf("Digite o nome a ser buscado:\n");
            scanf("%[^\n]s\n", name);
            fflush(stdin);
            find_page(&pag, name);
            break;

        case 5:
            printf("Digite o nome a ser pesquisado:\n");
            scanf("%[^\n]s\n", name);
            fflush(stdin);
            result = search_element(&pag, name);
            if (result.data.id == NULL)
            {
                printf("A URL não existe na lista.");
            }
            print_Site(result.data);
            break;

        case 6:
            printf("Digita o tamanho da lista para verificar:\n");
            scanf("%d", &K);
            printf("Verificando tamanho da lista...\n\n");
            verify_list(&pag, K);
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
    printf("\n---------- LISTA DE SITES ----------\n");
    printf("1 - Listar Pessoas\n");
    printf("2 - Inserir Pessoa\n");
    printf("3 - Deletar um elemento\n");
    printf("4 - Buscar nome e mover no*\n");
    printf("5 - Verificar a existencia de um item\n");
    printf("6 - Verificar tamanho da lista\n");
    printf("0 - Sair\n");
    scanf("%d", &op);

    return op;
}