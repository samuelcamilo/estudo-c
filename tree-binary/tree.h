#include <stdio.h>
#include <stdlib.h>

typedef struct tree Tree;
typedef struct node Node;

struct node
{
    int value;
    Node* left;
    Node* right;
};

struct tree
{
    Node* root;
};

Tree* InitializeTree();
Node* InsertTreeRec(Node* root, int value);
void InsertTree(Tree* tree, int value);
void ShowTreePreOrder(Node* root);
void ShowTreeInOrder(Node* root);
void ShowTreePosOrder(Node* root);
int CountNodeInTree(Node* root);
void DestroyTreeRec(Node* root);
void DestroyTree(Tree* tree);
int HeightTreeRec(Node* root);
int HeightTree(Tree* tree);
Node* RemoveBigger(Node* root);
Node* RemoveSmaller(Node* root);
