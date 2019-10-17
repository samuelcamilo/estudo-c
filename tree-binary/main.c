#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main()
{
    Tree* tree;

    tree = InitializeTree();

    InsertTree(tree, 12);
    InsertTree(tree, 4);
    InsertTree(tree, 2);
    InsertTree(tree, 10);
    InsertTree(tree, 15);
    InsertTree(tree, 25);
    InsertTree(tree, 5);
    InsertTree(tree, 6);
    InsertTree(tree, 9);

    /// Caminhamentos...
    //ShowTreePreOrder(tree->root);
    //ShowTreeInOrder(tree->root);
    //ShowTreePosOrder(tree->root);
    ///-----------------

    printf("Quantidade de Nodes: %d\n", CountNodeInTree(tree->root));
    printf("Altura: %d\n", HeightTree(tree));
    DestroyTree(tree);
    //printf("Quantidade de Nodes: %d\n", CountNodeInTree(tree->root));

    return 0;
}
