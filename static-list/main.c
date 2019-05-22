#include <stdio.h>
#include <stdlib.h>
#define TAM 5

typedef struct 
{
    int codigo;
    char nome[50];
    int idade;
    float altura;
    float peso;
} Cliente;

typedef struct 
{
    int qtd;
    Cliente cliente[TAM];
}Lista;

void menu();
Lista *inicializaLista();
void liberaLista();

int main()
{
    //Lista *lista;
    //lista = inicializaLista();
    //printf("%d\n", lista->qtd);
    //liberaLista(lista);
    menu();
}

void menu()
{   
    Lista *lista;
    int opcao;
    do
    {
        printf("----- MENU -----\n");
        printf("(1) Cadastrar Paciente\n");
        printf("(2) Buscar Paciente\n");
        printf("(3) Ordenar Por IMC\n");
        printf("(4) Tamanho Lista\n");
        printf("(0) Sair\n");
        printf("----------------\n");
        printf("Digite uma Opção: ");
        scanf("%d", &opcao);

        lista = inicializaLista();

        switch(opcao)
        {
            case 1:
                //lista = inicializaLista();
                //printf("Tamanho: %d\n", lista->qtd);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                system("clear");
                printf("----- Tamanho Lista -----\n");
                printf("Tamanho lista de pacientes: %d\n", lista->qtd);
                printf("-------------------------\n");
                break;
            default:
                break;
        }

    } while (opcao != 0);
    
}

Lista *inicializaLista()
{
    Lista *li;
    li = (Lista*) malloc(sizeof(Lista));

    if(li != NULL)
        li->qtd = 0;

    return li;
}

void liberaLista(Lista *li)
{
    free(li);
}