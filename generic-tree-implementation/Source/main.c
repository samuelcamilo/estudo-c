#include "arvore.c"

int main()
{
    Arvore* arv = MontaArvore();

    printf("Total de Nos: %d\n", ContagemNos(arv->raiz));
    printf("Altura da Arvore: %d\n", AlturaArvore(arv->raiz));
    ExibirArvore(arv->raiz);

    printf("\n");
}