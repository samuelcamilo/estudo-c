#include <stdio.h>
#include <stdlib.h>
#define TAM 2

typedef struct 
{
    int codigo;
    char nome[50];
    int idade;
    float altura;
    float peso;
    float imc;
} Paciente;

typedef struct 
{
    int qtd;
    Paciente paciente[TAM];
}Lista;

void menu();
Lista *inicializaLista();
void cadastraPaciente();
void exibirListaPacientes();
void liberaLista();

int main()
{
    menu();
}

void menu()
{   
    Lista *lista;
    int opcao;
    char cond[5];

    lista = inicializaLista(lista);

    do
    {
        printf("----- MENU -----\n");
        printf("(1) Cadastrar Paciente\n");
        printf("(2) Buscar Paciente\n");
        printf("(3) Calcular IMC\n");
        printf("(4) Ordenar Por IMC\n");
        printf("(5) Tamanho Lista\n");
        printf("(6) Exibir Lista\n");
        printf("(0) Sair\n");
        printf("----------------\n");
        printf("Digite uma Opção: ");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                system("clear");
                printf("------- Cadastro -------\n");
                cadastraPaciente(lista);
                printf("Cadastro Realizado!!!\n");
                printf("------------------------\n");
                getchar();
                printf("Pressione qualquer tecla para voltar...");
                getchar();
                system("clear");
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                system("clear");
                printf("----- Tamanho Lista -----\n");
                printf("Tamanho lista de pacientes: %d\n", lista->qtd);
                printf("-------------------------\n");
                getchar();
                printf("Pressione qualquer tecla para voltar...");
                getchar();
                system("clear");
                break;
            case 6:
                system("clear");
                printf("------- Exibindo Lista -------\n");
                exibirListaPacientes(lista);
                getchar();
                printf("Pressione qualquer tecla para voltar...");
                getchar();
                system("clear");
                break;
            default:
                //liberaLista(lista);
                break;
        }

    } while (opcao != 0);
    
}

Lista *inicializaLista(Lista *li)
{
    li = (Lista*) malloc(sizeof(Lista));

    if(li != NULL)
        li->qtd = 0;

    return li;
}

void cadastraPaciente(Lista *li)
{
    if(li->qtd < TAM)
    {
        printf("------ Paciente %d ------\n", li->qtd+1);
        printf("Código de Registro: ");
        scanf("%d", &li->paciente[li->qtd].codigo);
        getchar();

        fflush(stdin);
        printf("Nome do Paciente: ");
        fgets(li->paciente[li->qtd].nome,50,stdin);

        printf("Idade do Paciente: ");
        scanf("%d", &li->paciente[li->qtd].idade);

        printf("Altura do Paciente: ");
        scanf("%f", &li->paciente[li->qtd].altura);

        printf("Peso do Paciente: ");
        scanf("%f", &li->paciente[li->qtd].peso);
        printf("------------------------\n");

        li->qtd++;
    }else
    {
        printf("Lista de Paciente está Cheia!!!\n");
    }
}

void exibirListaPacientes(Lista *li)
{
    int cont;
    for(cont = 0; cont < TAM; cont++)
    {
        printf("------- Paciente %d -------\n", cont+1);
        printf("Codigo Registro: %d\n", li->paciente[cont].codigo);
        printf("Nome Paciente: %s", li->paciente[cont].nome);
        printf("Idade Paciente: %d\n", li->paciente[cont].idade);
        printf("Altura Paciente: %.2f\n", li->paciente[cont].altura);
        printf("Peso Paciente: %.2f\n", li->paciente[cont].peso);
        printf("IMC Paciente: %.2f\n", li->paciente[cont].imc);
        printf("--------------------------\n");
    }
}

void liberaLista(Lista *li)
{
    free(li);
}