#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED
//------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//------------------------------------------------
typedef struct Product
{
    int cod;
    char name[100];
    float price;
    int qtd;
} Product;
//-----------------------------------------------
//Procedimento de imprimir o produto
void print_product(Product x)
{
    printf("\nCodigo: %d | Nome: %s | Preco: %.2f | Quant.: %d", x.cod, x.name, x.price, x.qtd);
}
//Procedimento que cria um produto
Product new_product()
{
    Product p;
    printf("\nDigite o nome do produto:\n");
    scanf("%s", p.name);
    fflush(stdin);
    printf("\nDigite o preco do produto:\n");
    scanf("%f", &p.price);
    fflush(stdin);
    printf("\nDigite a quantidade do produto:\n");
    scanf("%d", &p.qtd);
    fflush(stdin);
    return p;
}
/*----Procedimento que cria aleatoriamente produtos----*/
/*Product new_product(){
    srand(time(NULL));
    Product p;
    p.cod = rand()%100;
    sprintf(p.name, "Produto %d", p.cod);
    p.price = rand()%100;
    p.qtd = rand()%100;
    return p;
}*/
#endif