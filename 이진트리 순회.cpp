#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct treenode
{
	int data;
	struct treenode *left, *right;
} treenode;

treenode n1 = {1, NULL, NULL};
treenode n2 = {4, &n1, NULL};
treenode n3 = {16, NULL, NULL};
treenode n4 = {25, NULL, NULL};
treenode n5 = {20, &n3, &n4};
treenode n6 = {15, &n2, &n5};
treenode *root = &n6;

void inorder (treenode *root)
{
	if (root != NULL)
	{
		inorder (root->left);
		printf ("[%d] ", root->data);
		inorder (root->right);
	}
}

void preorder (treenode *root)
{
	if (root != NULL)
	{
		printf("[%d] ", root->data);
		preorder (root->left);
		preorder(root->right);
	}
}

void postorder (treenode *root)
{
	if (root !=NULL)
	{
		postorder (root->left);
		postorder (root->right);
		printf("[%d] ", root->data);
	}
}

int main (void)
{
	printf("���� ��ȸ = ");
	inorder(root);
	printf("\n");
	
	printf("���� ��ȸ = ");
	preorder(root);
	printf("\n");
	
	printf("���� ��ȸ = ");
	postorder(root);
	printf("\n");
	return 0;
}
