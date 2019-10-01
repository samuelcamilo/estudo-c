#include "../Source/structtree.c"
#include "../Source/tree.c"

void menu()
{   
    Tree* tree;
    List* list;
    int option;

    list = InitializationList();
    tree = InitializationTree();

    do
    {
        printf("----- MENU -----\n");
        printf("(1) Carregar dados. OK\n");
        printf("(2) Listagem em ordem alfabetica. OK\n");
        printf("(3) Listagem por substring. (Nao)\n");
        printf("(4) Inserir novo registro. OK\n");
        printf("(5) Remover nome. (Nao)\n");
        printf("(6) - (Nao)\n");
        printf("(7) - (Nao)\n");
        printf("(8) Salvar em arquivo. (Nao)\n");
        printf("(9) Tamanho da lista. \n");
        printf("(0) Sair. \n");
        printf("----------------\n");
        printf("Digite uma Opção: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                system("clear");
                printf("------- Carregando Dados -------\n");
                InsertDataTxtToList(list);
                InsertDataListInTree(list, tree);
                printf("Done...\n");
                getchar();
                printf("Pressione qualquer tecla para voltar...");
                getchar();
                system("clear");
                break;
            case 2:
                system("clear");
                printf("----- Listar por Ordem Alfabetica -----\n");
                ShowInOrderNewLine(tree->root);
                printf("Done...\n");
                getchar();
                printf("Pressione qualquer tecla para voltar...");
                getchar();
                system("clear");
                break;
            case 3:
                // system("clear");
                // printf("----- Calculo IMC -----\n");
                // calcularIMC(lista);
                // getchar();
                // printf("Pressione qualquer tecla para voltar...");
                // getchar();
                // system("clear");
                break;
            case 4:
                system("clear");
                printf("----- Cadastro -----\n");
                getchar();
                fflush(stdin);
                InsertDataInList(list);
                InsertDataListInTree(list, tree);
                printf("Done...\n");
                printf("Pressione qualquer tecla para voltar...");
                getchar();
                system("clear");
                break;
            case 5:
                // system("clear");
                // printf("----- Tamanho Lista -----\n");
                // printf("Tamanho lista de pacientes: %d\n", lista->qtd);
                // printf("-------------------------\n");
                // getchar();
                // printf("Pressione qualquer tecla para voltar...");
                // getchar();
                // system("clear");
                break;
            case 6:
                // system("clear");
                // printf("------- Exibindo Lista -------\n");
                // exibirListaPacientes(lista);
                // getchar();
                // printf("Pressione qualquer tecla para voltar...");
                // getchar();
                // system("clear");
                break;
            case 7:
                // system("clear");
                // printf("------- Exibindo Lista -------\n");
                // exibirListaPacientes(lista);
                // getchar();
                // printf("Pressione qualquer tecla para voltar...");
                // getchar();
                // system("clear");
                break;
            case 8:
                system("clear");
                printf("------- Salvar em arquivo -------\n");
                //SaveData(tree->root);
                //SaveDataTxt();
                printf("Done...\n");
                getchar();
                printf("Pressione qualquer tecla para voltar...");
                getchar();
                system("clear");
                break;
            case 9:
                // system("clear");
                // printf("----- Tamanho Lista -----\n");
                // printf("Tamanho lista de nomes: %d\n", list->countList);
                // printf("Done...\n");
                // getchar();
                // printf("Pressione qualquer tecla para voltar...");
                // getchar();
                // system("clear");
                break;
            default:
                //liberaLista(lista);
                break;
        }

    } while (option != 0);
    
}