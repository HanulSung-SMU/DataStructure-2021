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

// search 함수
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
	return node; // 변경된 루트 포인터 반환
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

// 중위 순회
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

	printf("이진탐색트리 중위 순회 결과\n");
	inorder(root);
	printf("\n\n");

	if (search(root, 32) != NULL)
	{
		printf("이진탐색트리에서 32를 발견함\n\n");
	}
	else
	{
		printf("이진탐색트리에서 32를 발견하지 못함\n\n");
	}

	insertNode = insert_node(root, 28);
	deleteNode = delete_node(root, 18);

	printf("삽입된 이진탐색트리 중위 순회 결과\n");
	inorder(insertNode);
	printf("\n\n");

	printf("삭제된 이진탐색트리 중위 순회 결과\n");
	inorder(deleteNode);
	printf("\n\n");

	return 0;
}