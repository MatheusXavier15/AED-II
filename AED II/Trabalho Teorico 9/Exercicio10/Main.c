// Crie um programa para gerenciar o cadastro de produtos. Cada produto deve ser armazenado em uma estrutura com as informações de código, descrição e valor. Seu programa deve ser capaz de armazenar n produtos, sendo que o valor n deve ser informado pelo usuário. Seu programa deve usar funções e ponteiros para executar as seguintes operações:
// Cadastrar um novo produto
// Editar os dados de um produto
// Excluir um produto
// Exibir todos os produtos cadastrados
// Exibir a quantidade total de produtos
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//------------------------------------------------------
#include "Product.h"
#include "DinamicList.h"
//------------------------------------------------------
int menu();
//CRUD -> CREATE, READ, UPDATE, DELETE

int main()
{
    int op = 1;
    //criação de uma variavel de lista de produtos
    DinamicList Produtos;
    //criação da lista
    create_list(&Produtos);
    //variavel de produtos auxiliar
    Product p_aux;
    do
    {
        int op = menu(), id;
        switch (op)
        {
        case 0:
            return 0;
            break;
        case 1:
        //imprime lista
            print_list(&Produtos);
            break;
        case 2:
        //cria novo produto
            p_aux = new_product();
            p_aux.cod = Produtos.TAM + 1;
            add_list(&Produtos, p_aux);
            break;
        case 3:
        //Edita o produto
            printf("\nDigite o codigo do produto: ");
            scanf("%d", &id);
            p_aux = new_product();
            p_aux.cod = id;
            update(&Produtos, p_aux);
            break;
        case 4:
        //Deleta o produto
            printf("\nDigite o codigo do produto: ");
            scanf("%d", &id);
            delete_list(&Produtos, id);
            break;
        default:
            break;
        }
    } while (op != 0);
}
int menu()
{
    int op;
    printf("\n---------- ESTOQUE DE PRODUTOS ----------\n");
    printf("1 - Listar Produtos\n");
    printf("2 - Criar Produto\n");
    printf("3 - Editar Produto\n");
    printf("4 - Apagar Produto\n");
    printf("0 - Sair\n");
    scanf("%d", &op);

    return op;
}