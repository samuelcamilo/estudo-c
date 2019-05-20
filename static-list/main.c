#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define TAM 2

typedef struct {
    char nome[50];
    int idade;
    float altura;
    float peso;
    float imc;
}Pessoa;

Pessoa pessoa;

void menu();
void inicializar();
void cadastraPessoa();
void calculaIMC();
void exibeLista();

int main()
{
    setlocale(LC_ALL, "portuguese");
    menu();
    return 0;
}

void menu()
{
    int opcao;
    Pessoa pessoa[TAM];

    do
    {
        printf("===== Menu =====\n");
        printf("1 - Inicializar\n");
        printf("2 - Cadastrar Pessoa\n");
        printf("3 - Calcular Imc\n");
        printf("4 - Exibir Lista\n");
        printf("0 - Sair\n");
        printf("==================\n");
        printf("Digite uma opção: ");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                system("clear");
                printf("Lista Inicializada!...\n");
                inicializar(pessoa);
                break;
            case 2:
                system("clear");
                printf("===== Cadastro =====\n");
                cadastraPessoa(pessoa);
                system("clear");
                break;
            case 3:
                system("clear");
                printf("===== Calculo IMC =====\n");
                calculaIMC(pessoa);
                break;
            case 4:
                system("clear");
                printf("===== Exibindo =====\n");
                exibeLista(pessoa);
                printf("====================\n");
                break;
            case 0:
                system("clear");
                printf("Saindo!\n");
                break;
            default:
                system("clear");
                printf("Opção Inválida!\n");
                break;
        }

    } while (opcao != 0);   
}

void inicializar(Pessoa lista[])
{
    int cont;

    for(cont = 0; cont < TAM; cont++)
    {
        strcpy(lista[cont].nome, "NULL");
        lista[cont].idade = 0;
        lista[cont].altura = 0.0;
        lista[cont].peso = 0.0;
        lista[cont].imc = 0.0;    
    }
    
}

void cadastraPessoa(Pessoa lista[])
{
    int cont;

    for(cont = 0; cont < TAM; cont++)
    {
        printf("Digite Seu Nome: ");
        scanf("%s", lista[cont].nome);
        getchar();

        printf("Digite Sua Idade: ");
        scanf("%d", &lista[cont].idade);

        printf("Digite Sua Altura: ");
        scanf("%f", &lista[cont].altura);

        printf("Digite Seu Peso: ");
        scanf("%f", &lista[cont].peso);
    }
}

void calculaIMC(Pessoa lista[])
{
    int cont;

    for(cont = 0; cont < TAM; cont++)
    {
        lista[cont].imc = (lista[cont].peso / (lista[cont].altura * lista[cont].altura));
        printf("IMC do %s Calculado com Sucesso!\n", lista[cont].nome);
    }
    
}

void exibeLista(Pessoa lista[])
{
    int cont;

    for(cont = 0; cont < TAM; cont++)
    {
        printf("Nome: %s\n", lista[cont].nome);
        printf("Idade: %d\n", lista[cont].idade);
        printf("Altura: %.2f\n", lista[cont].altura);
        printf("Peso: %.2f\n", lista[cont].peso);
        printf("IMC: %.2f\n", lista[cont].imc);
        printf("====================\n");
    }
    
}