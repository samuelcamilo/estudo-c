#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Tree* InitializeTree()
{
    Tree* tree = (Tree*) malloc(sizeof(Tree));

    if(tree == NULL)
        exit(-1);
    tree->root = NULL;

    return tree;
}

void DestroyTreeRec(Node* root)
{
    if(root != NULL)
    {
        DestroyTreeRec(root->left);
        DestroyTreeRec(root->right);
        free(root);
    }
}

void DestroyTree(Tree* tree)
{
    DestroyTreeRec(tree->root);
    free(tree);
}

Node* InsertTreeRec(Node* root, int value)
{
    if(root != NULL)
    {
        if(root->value > value)
            root->left = InsertTreeRec(root->left, value);
        else
            if(root->value < value)
                root->right = InsertTreeRec(root->right, value);
    }
    else
    {
        root = (Node*) malloc(sizeof(Node));
        root->value = value;
        root->left = NULL;
        root->right = NULL;
    }

    return root;
}

void InsertTree(Tree* tree, int value)
{
    tree->root = InsertTreeRec(tree->root, value);
}

Node* RemoveBigger(Node* root)
{
    if(root != NULL)
    {
        if(root->right != NULL)
        {
            root->right = RemoveBigger(root->right);
        }
        else
        {
            Node* aux = root;
            root = root->left;
            free(aux);
        }
    }

    return root;
}

Node* RemoveSmaller(Node* root)
{
    if(root != NULL)
    {
        if(root->left != NULL)
        {
            root->left = RemoveSmaller(root->left);
        }
        else
        {
            Node* aux = root;
            root = root->right;
            free(aux);
        }
    }

    return root;
}

int HeightTreeRec(Node* root)
{
    if(root != NULL)
    {
        int hl = HeightTreeRec(root->left);
        int hr = HeightTreeRec(root->right);

        return (hl > hr ? hl : hr) + 1;
    }

    return -1;
}

int HeightTree(Tree* tree)
{
    return HeightTreeRec(tree->root);
}

void ShowTreePreOrder(Node* root)
{
    if(root != NULL)
    {
        printf("%d\n", root->value);
        ShowTreePreOrder(root->left);
        ShowTreePreOrder(root->right);
    }
}

void ShowTreeInOrder(Node* root)
{
    if(root != NULL)
    {
        ShowTreeInOrder(root->left);
        printf("%d\n", root->value);
        ShowTreeInOrder(root->right);
    }
}

void ShowTreePosOrder(Node* root)
{
    if(root != NULL)
    {
        ShowTreePosOrder(root->left);
        ShowTreePosOrder(root->right);
        printf("%d\n", root->value);
    }
}

int CountNodeInTree(Node* root)
{
    if(root != NULL)
    {
        return CountNodeInTree(root->left) + CountNodeInTree(root->right) + 1;
    }
}
