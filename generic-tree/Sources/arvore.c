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
    // printf("%c\n", arv->raiz->filho->irmao->irmao->filho->irmao->irmao->info);
    camPreOrdem(arv->raiz);
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