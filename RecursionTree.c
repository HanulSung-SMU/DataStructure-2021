#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
} TreeNode;

void InitTree(TreeNode** node)
{
	*node = (TreeNode*)malloc(sizeof(TreeNode));
	if (*node == NULL)
	{
		fprintf(stderr, "메모리가 부족합니다.\n");
		exit(1);
	}
}

void PreOrder(TreeNode* root)
{
	if (root != NULL)
	{
		printf("[%d] ", root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

void InOrder(TreeNode* root)
{
	if (root != NULL)
	{
		InOrder(root->left);
		printf("[%d] ", root->data);
		InOrder(root->right);
	}
}

void PostOrder(TreeNode* root)
{
	if (root != NULL)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		printf("[%d] ", root->data);
	}
}

int main(void)
{
	TreeNode* root, * n1, * n2, * n3, * n4, * n5;

	InitTree(&root);
	InitTree(&n1);
	InitTree(&n2);
	InitTree(&n3);
	InitTree(&n4);
	InitTree(&n5);

	root->data = 15;
	root->left = n1;
	root->right = n2;

	n1->data = 4;
	n1->left = n3;
	n1->right = NULL;
	
	n2->data = 20;
	n2->left = n4;
	n2->right = n5;

	n3->data = 1;
	n3->left = NULL;
	n3->right = NULL;

	n4->data = 16;
	n4->left = NULL;
	n4->right = NULL;

	n5->data = 25;
	n5->left = NULL;
	n5->right = NULL;

	printf("전위 순회 : ");
	PreOrder(root);
	printf("\n");

	printf("중위 순회 : ");
	InOrder(root);
	printf("\n");

	printf("후위 순회 : ");
	PostOrder(root);

	free(root);
	free(n1);
	free(n2);
	free(n3);
	free(n4);
	free(n5);

	return 0;
}