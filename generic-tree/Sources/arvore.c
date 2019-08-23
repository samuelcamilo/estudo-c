#include "../Headers/arvore.h"

struct no {
    
    char info;
    No *pai;
    No *filho;
    No *irmao;

};

struct arvore{
    
    No *raiz;

};

No *nos[8];

void alocaNos()
{
    int i;
    for(i = 0; i < 8; i++)
    {
        nos[i] = (No *) malloc(sizeof(No));
        nos[i]->info = 'A' + i;
        nos[i]->pai = NULL;
        nos[i]->irmao = NULL;
        nos[i]->filho = NULL;
    }
}

No *indiceNo(char c)
{
    return nos[c - 'A'];
}

Arvore *criar()
{
    Arvore *arv = malloc(sizeof(Arvore));

    alocaNos();

    indiceNo('A')->filho = indiceNo('B');
    indiceNo('B')->irmao = indiceNo('D');
    indiceNo('D')->irmao = indiceNo('E');
    indiceNo('B')->filho = indiceNo('C');
    indiceNo('E')->filho = indiceNo('F');
    indiceNo('F')->irmao = indiceNo('G');
    indiceNo('G')->irmao = indiceNo('H');

    arv->raiz = indiceNo('A');

    return arv;
}

void exibir(Arvore *arv)
{
    //camPreOrdem(arv->raiz);
    //camInOrdem(arv->raiz);
    camPosOrdem(arv->raiz);
    printf("\n");
}

void camPreOrdem(No *raiz)
{
    if(raiz == NULL)
        return;
    
    printf("%c ", raiz->info);
    camPreOrdem(raiz->filho);
    camPreOrdem(raiz->irmao);

}

void camInOrdem(No *raiz)
{
    if(raiz == NULL)
        return;
    
    camInOrdem(raiz->filho);
    printf("%c ", raiz->info);
    camInOrdem(raiz->irmao);

}

void camPosOrdem(No *raiz)
{
    if(raiz == NULL)
        return;

    camPosOrdem(raiz->filho);
    camPosOrdem(raiz->irmao);
    printf("%c ", raiz->info);

}






