#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
typedef struct arvore Arvore;

void AlocaNos();
No *IndiceNo(char c);
Arvore* MontaArvore();

void PreOrdem(No* raiz);
void InOrdem(No* raiz);
void PosOrdem(No* raiz);

int ContagemNos(No* raiz);
int AlturaArvore(No* raiz);

void ExibirArvore(No* raiz);