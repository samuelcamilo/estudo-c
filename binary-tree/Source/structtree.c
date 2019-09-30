#include "../Headers/tree.h"

struct node
{
    char name[30];
    Node* next;
    Node* left;
    Node* right;
};

struct tree
{
    Node* root; 
};
