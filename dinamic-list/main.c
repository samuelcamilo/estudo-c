#include <stdio.h>
#include <stdlib.h>

typedef struct paciente
{
    int codigo;
    char nome[50];
    int idade;
    float altura;
    float peso;
    float imc;

} Paciente;

typedef struct node
{
    Paciente paciente;
    struct Node *prox;
    
} Node;

typedef struct lista
{
    int qtd;
    Node *head;

} Lista;

void menu();
Lista *inicializaLista();
void cadastraPaciente();
void inserirPaciente();
void exibirListaPacientes();
void calcularIMC();
void buscarPaciente();

int main()
{
    menu();
}

void menu()
{   
    Lista *lista;
    int opcao;

    lista = inicializaLista();

    do
    {
        printf("----- MENU -----\n");
        printf("(1) Cadastrar Paciente\n");
        printf("(2) Buscar Paciente (Não)\n");
        printf("(3) Calcular IMC (Não)\n");
        printf("(4) Ordenar Por IMC (Não)\n");
        printf("(5) Tamanho Lista (Não)\n");
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
                //ordenandoPorIMC(lista);
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

Lista *inicializaLista()
{
    Lista *li = (Lista*) malloc(sizeof(Lista));

    if(li != NULL)
    {
        li->qtd = 0;
        li->head = NULL;
    }

    return li;
}

void cadastraPaciente(Lista *li)
{
    Paciente paciente;

    printf("----- Cadastro -----\n");

    printf("Código do paciente: ");
    scanf("%d", &paciente.codigo);
    getchar();

    fflush(stdin);
    printf("Escreva seu nome: ");
    fgets(paciente.nome,50,stdin);

    printf("Digite sua idade: ");
    scanf("%d", &paciente.idade);

    printf("Digite sua altura: ");
    scanf("%f", &paciente.altura);

    printf("Digite seu peso: ");
    scanf("%f", &paciente.peso);

    printf("--------------------\n");

    inserirPaciente(li, paciente);

}

void inserirPaciente(Lista *li, Paciente paciente)
{
    Node *node = (Node*) malloc(sizeof(Node));

    node->paciente = paciente;
    node->prox = li->head;
    li->head = node;
    li->qtd++;
}

void exibirListaPacientes(Lista *li)
{   
    int cont = 0;
    Node *pointer = li->head;

    while (pointer != NULL)
    {
        printf("------- Paciente %d -------\n", cont+1);
        printf("Codigo Registro: %d\n", pointer->paciente.codigo);
        printf("Nome Paciente: %s", pointer->paciente.nome);
        printf("Idade Paciente: %d\n", pointer->paciente.idade);
        printf("Altura Paciente: %.2f\n", pointer->paciente.altura);
        printf("Peso Paciente: %.2f\n", pointer->paciente.peso);
        printf("IMC Paciente: %.2f\n", pointer->paciente.imc);
        printf("--------------------------\n");
        pointer = pointer->prox;
        cont++;
    }
}

void calcularIMC(Lista *li)
{
    Node *pointer = li->head;

    while(pointer != NULL)
    {
        pointer->paciente.imc = pointer->paciente.peso 
                            / (pointer->paciente.altura * pointer->paciente.altura);
        pointer = pointer->prox;
    }

    printf("Calculo realizado com sucesso!!!\n");
    printf("-----------------------\n");

}

void buscarPaciente(Lista *li)
{
    Node *pointer = li->head;
    int cont;
    int cod;

    printf("Buscar por código: ");
    scanf("%d", &cod);

    while(pointer != NULL)
    {
        if(pointer->paciente.codigo == cod)
        {
            printf("------- Resultado -------\n");
            printf("Codigo Registro: %d\n", pointer->paciente.codigo);
            printf("Nome Paciente: %s", pointer->paciente.nome);
            printf("Idade Paciente: %d\n", pointer->paciente.idade);
            printf("Altura Paciente: %.2f\n", pointer->paciente.altura);
            printf("Peso Paciente: %.2f\n", pointer->paciente.peso);
            printf("IMC Paciente: %.2f\n", pointer->paciente.imc);
            printf("--------------------------\n");
        }
        pointer = pointer->prox;
    }
}