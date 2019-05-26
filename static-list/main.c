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
void buscarPaciente();
void calcularIMC();
void ordenandoPorIMC();
void liberaLista();

int main()
{
    menu();
}

void menu()
{   
    Lista *lista;
    int opcao;

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
                getchar();
                printf("Pressione qualquer tecla para voltar...");
                getchar();
                system("clear");
                break;
            case 2:
                system("clear");
                printf("----- Busca de Pacientes -----\n");
                buscarPaciente(lista);
                getchar();
                printf("Pressione qualquer tecla para voltar...");
                getchar();
                system("clear");
                break;
            case 3:
                system("clear");
                printf("----- Calculo IMC -----\n");
                calcularIMC(lista);
                getchar();
                printf("Pressione qualquer tecla para voltar...");
                getchar();
                system("clear");
                break;
            case 4:
                system("clear");
                printf("----- Ordenação -----\n");
                ordenandoPorIMC(lista);
                getchar();
                printf("Pressione qualquer tecla para voltar...");
                getchar();
                system("clear");
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
        printf("Cadastro Realizado!!!\n");
        printf("------------------------\n");

        li->qtd++;
    }else
    {
        printf("Lista de Paciente está Cheia!!!\n");
        printf("------------------------\n");
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

void calcularIMC(Lista *li)
{
    int cont;
    if(li->qtd > 0)
    {
        for(cont = 0; cont < li->qtd;cont++)
        {
            li->paciente[cont].imc = li->paciente[cont].peso / 
                            (li->paciente[cont].altura * li->paciente[cont].altura); 
        }

        printf("Calculo realizado com sucesso!!!\n");
        printf("-----------------------\n"); 
    }
    else
    {
        printf("Lista de pacientes está fazia!!!\n");
        printf("-----------------------\n");
    }
    
}

void buscarPaciente(Lista *li)
{
    int cont;
    int cod;

    printf("Buscar por código: ");
    scanf("%d", &cod);

    for(cont = 0; cont < TAM; cont++)
    {
        if(li->paciente[cont].codigo == cod){

            printf("-------- Resultado -------\n");
            printf("Codigo Registro: %d\n", li->paciente[cont].codigo);
            printf("Nome Paciente: %s", li->paciente[cont].nome);
            printf("Idade Paciente: %d\n", li->paciente[cont].idade);
            printf("Altura Paciente: %.2f\n", li->paciente[cont].altura);
            printf("Peso Paciente: %.2f\n", li->paciente[cont].peso);
            printf("IMC Paciente: %.2f\n", li->paciente[cont].imc);
            printf("--------------------------\n");

        }
    }
}

void ordenandoPorIMC(Lista *li)
{
    int i,j,pos;
    Paciente pacien_aux;

    if(li->qtd > 0)
    {
        pos = 1;
        for(i = 0; i < li->qtd; i++)
        {
            for(j = pos; j < li->qtd; j++)
            {
                if(li->paciente[i].imc <= li->paciente[j].imc)
                {
                    pacien_aux = li->paciente[i];
                    li->paciente[i] = li->paciente[j];
                    li->paciente[j] = pacien_aux;
                }
            }
            pos++;
        }

        printf("Ordenação realizada com sucesso!!!\n");
        printf("-----------------------\n");

    }
    else
    {
        printf("Lista de pacientes está fazia!!!\n");
        printf("-----------------------\n");
    }
    
}

void liberaLista(Lista *li)
{
    free(li);
}