#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode
{
	element key;
	struct TreeNode* left;
	struct TreeNode* right;
} TreeNode;

TreeNode* CreateNode(TreeNode* node, element key)
{
	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
	if (newNode == NULL)
	{
		fprintf(stderr, "�޸𸮰� �����ؼ� �Ҵ� �� �� �����ϴ�.\n");
		exit(1);
	}
	newNode->key = key;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

TreeNode* SearchNode(TreeNode* node, element key)
{
	if (node == NULL) return NULL;
	if (key == node->key) return node;
	else if (key < node->key)
	{
		return SearchNode(node->left, key);
	}
	else
	{
		return SearchNode(node->right, key);
	}
}

TreeNode* InsertNode(TreeNode* node, element key)
{
	if (node == NULL) return CreateNode(node, key);

	if (key < node->key)
	{
		node->left = InsertNode(node->left, key);
	}
	else if (key > node->key)
	{
		node->right = InsertNode(node->right, key);
	}
	return node;
}

TreeNode* MinValueNode(TreeNode* node)
{
	TreeNode* current = node;

	while (current->left != NULL)
	{
		current = current->left;
	}
	return current;
}

TreeNode* DeleteNode(TreeNode* root, element key)
{
	if (root == NULL) return root;

	if (key < root->key)
	{
		root->left = DeleteNode(root->left, key);
	}
	else if (key > root->key)
	{
		root->right = DeleteNode(root->right, key);
	}
	else
	{
		if (root->left == NULL)
		{
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		
		TreeNode* temp = MinValueNode(root->right);
		root->key = temp->key;
		root->right = DeleteNode(root->right, temp->key);
	}
	return root;
}

void Inorder(TreeNode* root)
{
	if (root != NULL)
	{
		Inorder(root->left);
		printf("[%d] ", root->key);
		Inorder(root->right);
	}
}

int main(void)
{
	TreeNode* root = NULL;
	TreeNode* temp = NULL;

	root = InsertNode(root, 30);
	root = InsertNode(root, 20);
	root = InsertNode(root, 10);
	root = InsertNode(root, 40);
	root = InsertNode(root, 50);
	root = InsertNode(root, 60);

	printf("���� Ž�� Ʈ�� ������ȸ ���\n");
	Inorder(root);
	printf("\n\n");

	if (SearchNode(root, 40) != NULL)
	{
		printf("���� Ž�� Ʈ������ 40�� ã�ҽ��ϴ�.\n");
	}
	else
	{
		printf("���� Ž�� Ʈ������ 40�� �� ã�ҽ��ϴ�.\n");
	}

	return 0;
}