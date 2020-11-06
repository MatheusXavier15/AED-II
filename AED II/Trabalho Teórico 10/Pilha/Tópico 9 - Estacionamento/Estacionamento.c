#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100
//==================================================
//Criação do tipo carro para a estrutura
typedef struct Carro
{
    char nome[100];
    int placa;
    int movimentos;

} Carro;
//==================================================
//Metodo que cria um novo carro
Carro new_car()
{
    Carro car;
    printf("Digite o nome do carro:\n");
    scanf(" %[^\n]s\n", car.nome);
    fflush(stdin);
    printf("Digite o numero da placa: \n");
    scanf("%d", &car.placa);
    car.movimentos = 0;
    return car;
}
//==================================================
//Criação do tipo pilha para a estrutura
typedef struct Pilha
{
    Carro dados[MAX];
    int Top;
} Pilha;
//==================================================
//Procedimento que cria a pilha do estacionamento
void create_pilha(Pilha *stack)
{
    stack->Top = 0;
}
//==================================================
//Método booleano que insere dados na pilha
bool PUSH(Pilha *p, Carro dado)
{

    if (p->Top == MAX)
    {
        printf("\ngaragem Cheia!\n");
        return false;
    }

    p->dados[p->Top] = dado;
    p->Top++;
    printf("\nentrou carro!");
    return true;
}
//==================================================
//Método que retira um carro do estacionamento (elemento da pilha)
Carro POP(Pilha *p)
{

    if (p->Top == 0)
    {
        Carro carro;
        carro.placa = -1;
        printf("Garagem Vazia\n");
        return carro;
    }

    p->Top--;
    return p->dados[p->Top];
}
//==================================================
//Método que lista os carros no estacionamento
void print_stack(Pilha *p)
{

    printf("Quantidade de carros: %d\n", p->Top);
    for (int i = p->Top - 1; i >= 0; i--)
    {
        printf("%s", p->dados[i].nome);
        printf("%d\n", p->dados[i].placa);
    }
}
//==================================================
//Procedimento que tira um carro específico do estacionamento
void car_out(Pilha *p, Carro *carro)
{
    Carro aux;
    Pilha aux_pilha;

    int movimentos;

    create_pilha(&aux_pilha);

    int placa;
    printf("Digite o numero da placa a ser retirada:\n");
    scanf("%d", &placa);

    aux = POP(p);
    while (aux.placa != -1 && aux.placa != placa)
    {
        PUSH(&aux_pilha, aux);
        aux = POP(p);
    }

    movimentos = carro->movimentos;

    if (aux.placa == -1)
    {
        printf("Carro nao existente.\n");
        aux = POP(&aux_pilha);
        while (aux.placa != -1)
        {
            PUSH(p, aux);
            aux = POP(&aux_pilha);
        }
        return;
    }

    printf("O carro foi movimentado %d vezes.\n", movimentos);

    aux = POP(&aux_pilha);
    while (aux.placa != -1)
    {
        aux.movimentos++;
        PUSH(p, aux);
        aux = POP(&aux_pilha);
    }
}
//==================================================
//Método que verifica se a pilha está vazia
bool is_empty(Pilha *stack){
    return stack->Top==NULL;
}
//==================================================
//Função menu 
int menu(int op)
{
    printf("\n--------------Estacionamento--------------\n");
    printf("1 - Listar todos os carros \n");
    printf("2 - Adicionar novo carro\n");
    printf("3 - Retirar o ultimo carro\n");
    printf("4 - Retirar carro especifico do estacionamento");
    scanf("%d", &op);
    return op;
}
//==================================================
int main(void)
{
    Pilha stack;
    Carro Car;
    int aux;
    int op;
    create_pilha(&stack);
    while (op != 0)
    {
        op = menu(op);
        switch (op)
        {
        case 1:
            //Imprime os carros no estacionamento
            print_stack(&stack);
            break;

        case 2:
            //Adiciona um novo carro no estacionamento
            Car = new_car();
            PUSH(&stack, Car);
            break;

        case 3:
            //Tira carro do estacionamento
            POP(&stack);
            break;

        case 4:
            //Pesquisa carro por placa e retira ele
            print_stack(&stack);
            car_out(&stack, &Car);
            print_stack(&stack);
            break;

        default:
            break;
        }
    }

    return 0;
}