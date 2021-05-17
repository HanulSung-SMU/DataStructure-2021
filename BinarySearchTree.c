#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
	int key;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

TreeNode n1 = { 10, NULL, NULL };
TreeNode n2 = { 9, NULL, &n1};
TreeNode n3 = { 19, NULL, NULL };
TreeNode n4 = { 44, NULL, NULL };
TreeNode n5 = { 32, NULL, &n4 };
TreeNode n6 = { 18, &n2, &n3 };
TreeNode n7 = { 27, &n6, &n5 };
TreeNode* root = &n7;

// search �Լ�
TreeNode* search(TreeNode* node, int key)
{
	if (node == NULL)
	{
		return NULL;
	}
	if (key == node->key)
	{
		return node;
	}
	else if (key < node->key)
	{
		return search(node->left, key);
	}
	else
	{
		return search(node->right, key);
	}
}

TreeNode* new_node(int item)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode* node, int key)
{
	if (node == NULL)
	{
		return new_node(key);
	}
	if (key < node->key)
	{
		node->left = insert_node(node->left, key);
	}
	else if (key > node->key)
	{
		node->right = insert_node(node->right, key);
	}
	return node; // ����� ��Ʈ ������ ��ȯ
}


TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;

	while (current->left != NULL)
	{
		current = current->left;
	}
	return current;
}


TreeNode* delete_node(TreeNode* root, int key)
{
	if (root == NULL)
	{
		return root;
	}

	if (key < root->key)
	{
		root->left = delete_node(root->left, key);
	}
	else if (key > root->key)
	{
		root->right = delete_node(root->right, key);
	}
	else
	{
		if (root->left == NULL)
		{
			TreeNode* temp = root->right;
			//free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			TreeNode* temp = root->left;
			/////free(root);
			return temp;
		}
		TreeNode* temp = min_value_node(root->right);
		root->key = temp->key;
		root->right = delete_node(root->right, temp->key);
		
	}
	return root;
}

// ���� ��ȸ
inorder(TreeNode* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("[%d] ", root->key);
		inorder(root->right);
	}
}

int main(void)
{
	//TreeNode* temp = NULL;
	TreeNode* insertNode = NULL;
	TreeNode* deleteNode = NULL;

	printf("����Ž��Ʈ�� ���� ��ȸ ���\n");
	inorder(root);
	printf("\n\n");

	if (search(root, 32) != NULL)
	{
		printf("����Ž��Ʈ������ 32�� �߰���\n\n");
	}
	else
	{
		printf("����Ž��Ʈ������ 32�� �߰����� ����\n\n");
	}

	insertNode = insert_node(root, 28);
	deleteNode = delete_node(root, 18);

	printf("���Ե� ����Ž��Ʈ�� ���� ��ȸ ���\n");
	inorder(insertNode);
	printf("\n\n");

	printf("������ ����Ž��Ʈ�� ���� ��ȸ ���\n");
	inorder(deleteNode);
	printf("\n\n");

	return 0;
}