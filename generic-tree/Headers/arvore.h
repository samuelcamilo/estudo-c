#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
typedef struct arvore Arvore;

Arvore *criar();
No *indiceNo(char c);
void alocaNos();
void exibir(Arvore *arv);

void camPreOrdem(No *raiz);
void camInOrdem(No *raiz);
void camPosOrdem(No *raiz);