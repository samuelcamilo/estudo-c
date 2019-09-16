#include "../Headers/arvore.h"

struct no
{
    char info;
    No* irmao;
    No* filho;
};

struct arvore
{
    No* raiz;
};

No* nos[8];

void AlocaNos()
{
    int cont;

    for(cont = 0; cont <= 8; cont++)
    {
        nos[cont] = (No*) malloc(sizeof(No));
        nos[cont]->info = 'A' + cont;
        nos[cont]->irmao = NULL;
        nos[cont]->filho = NULL;
    }
}

No* IndiceNo(char c)
{
    return nos[c - 'A'];
}

Arvore* MontaArvore()
{
    Arvore* arvore = (Arvore*) malloc(sizeof(Arvore));

    AlocaNos();

    IndiceNo('A')->filho = IndiceNo('B');
    IndiceNo('B')->irmao = IndiceNo('D');
    IndiceNo('D')->irmao = IndiceNo('E');
    IndiceNo('E')->filho = IndiceNo('F');
    IndiceNo('F')->irmao = IndiceNo('G');
    IndiceNo('G')->irmao = IndiceNo('H');
    IndiceNo('B')->filho = IndiceNo('C');
    
    arvore->raiz = IndiceNo('A');

    return arvore;
}

void PreOrdem(No* raiz)
{
    if(raiz == NULL)
        return;

    printf("%c ", raiz->info);
    PreOrdem(raiz->filho);
    PreOrdem(raiz->irmao);
}

void InOrdem(No* raiz)
{
    if(raiz == NULL)
        return;

    InOrdem(raiz->filho);
    printf("%c ", raiz->info);
    InOrdem(raiz->irmao);
}

void PosOrdem(No* raiz)
{
    if(raiz == NULL)
        return;
    
    PosOrdem(raiz->filho);
    PosOrdem(raiz->irmao);
    printf("%c ", raiz->info);
}

int ContagemNos(No* raiz)
{
    if(raiz == NULL)
        return 0;

    return ContagemNos(raiz->filho) + ContagemNos(raiz->irmao) + 1;
}

int AlturaArvore(No* raiz)
{
    if(raiz == NULL)
        return -1;

    int af = AlturaArvore(raiz->filho) + 1;
    int ai = AlturaArvore(raiz->irmao);

    return af > ai ? af : ai;
}

void ExibirArvore(No* raiz)
{
    //printf("%c ", raiz->filho->filho->info);
    //PreOrdem(raiz);
    //InOrdem(raiz);
    PosOrdem(raiz);
}