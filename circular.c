#include <stdio.h>
#include <stdlib.h>


typedef struct Treenode{
	int data;
	struct Treenode *left, *right;
}Treenode;

Treenode n1 = {1, NULL, NULL};
Treenode n2 = {4, &n1, NULL};
Treenode n3 = {16, NULL, NULL};
Treenode n4 = {25, NULL, NULL};
Treenode n5 = {20, &n3, NULL};
Treenode n6 = {15, &n2, &n5};
Treenode *root = &n6;

void inorder(Treenode *root){
	if (root != NULL)
	{
		inorder(root->left);
		printf("[%d] ", root->data);
		inorder(root->right);
	}
}

void preorder(Treenode *root){
	if(root != NULL)
	{
		printf("[%d] ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(Treenode *root){
	if(root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("[%d] ", root->data);
	}
}

int main()
{
	printf("중위순회");
	inorder(root);
	printf("\n");

	printf("전위순회");
	preorder(root);
	printf("\n");
	
	printf("후위순회");
	postorder(root);
	printf("\n");
	return 0;
}
