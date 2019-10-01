#include "../Headers/tree.h"

struct list
{
    int countItem;
    Node* head;
};

FILE* OpenDataTxt()
{
    FILE *arq;

    arq = fopen("Base/database.txt", "r");

    if(arq != NULL)
        return arq;
}

void SaveDataTxt()
{
    int num;
    FILE *fptr;
    // use appropriate location if you are using MacOS or Linux
    fptr = fopen("Base/database.txt","w");
    if(fptr == NULL)
    {
        printf("Error!");   
        exit(1);             
    }
    printf("Enter num: ");
    scanf("%d",&num);
    fprintf(fptr,"%d",num);
    fclose(fptr);

    // arq = fopen("Base/database1.txt", "w");

    // if(arq == NULL)
    // {
    //     printf("Error in open txt!\n");
    // }
    // else
    // {
    //     printf("Aqui: %s\n", name);
    //     fprintf(arq, "%s\n", name);
    // }
    
    // fclose(arq);
}

List* InitializationList()
{
    List* list = (List*) malloc(sizeof(List));

    if(list != NULL)
    {
        printf("List Initialized!\n");
        list->countItem = 0;
        list->head = NULL;
    }

    return list;
}

void InsertDataTxtToList(List* list)
{
    FILE* arq;
    char line[30];
    char* result;
    int countLines = 0;

    arq = OpenDataTxt();
    while (!feof(arq))
    {
        result = fgets(line, 100,arq);

        if(result)
        {
            Node* node = (Node*) malloc(sizeof(Node));

            strcpy(node->name, result);
            node->next = list->head;
            list->head = node;
            list->countItem++;
        }
            
    }

    fclose(arq);
}

void InsertDataInList(List* list)
{
    Node node;

    fflush(stdin);
    printf("Escreva seu nome: ");
    fgets(node.name, 30, stdin);

    InsertData(list, node);

}

void InsertData(List* list, Node newNode)
{
    Node* node = (Node*) malloc(sizeof(Node));

    strcpy(node->name, newNode.name);
    node->next = list->head;
    list->head = node;
    list->countItem++;
}

void ShowListData(List* list)
{   
    int cont = 0;
    Node* node = list->head;

    while (node != NULL)
    {
        printf("------- Name %d -------\n", cont+1);
        printf("Name: %s\n", node->name);

        node = node->next;
        cont++;
    }
}