#include "../Headers/tree.h"
#include "../Utilities/readdata.c"

Tree* InitializationTree()
{
    Tree* tree = (Tree*) malloc(sizeof(Tree));
    tree->root = NULL;

    printf("Tree Initialized!\n");

    return tree;
}

Node* InsertTree(Node* root, char* n) {
	
    if (root != NULL) {

		int result = strcmp(n, root->name);
		if (result < 0) {
			root->left = InsertTree(root->left, n);
		}
		if (result > 0) {
			root->right = InsertTree(root->right, n);
		}

	} else {

		root = malloc(sizeof(Node));
        strcpy(root->name, n);
		root->left = NULL;
		root->right = NULL;

	}

	return root;
}

void Insert(Tree* tree, char * n) {
	tree->root = InsertTree(tree->root, n);
}

void InsertDataListInTree(List* list, Tree* tree)
{   
    int cont = 0;
    Node* node = list->head;

    while (node != NULL)
    {
        Insert(tree, node->name);
        node = node->next;
    }
}

void SaveData(Node* root)
{
	if (root != NULL) {	

		SaveData(root->left);
		SaveDataTxt(root->name);
		SaveData(root->right);

	}
}

void ShowInOrderNewLine(Node* root) {
    
	if (root != NULL) {	

		ShowInOrderNewLine(root->left);
		printf("%s\n", root->name);
		ShowInOrderNewLine(root->right);

	}
}