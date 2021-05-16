#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode {
	int key;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode* search(TreeNode* node, int key)
{
	if (node == NULL)return NULL;
	if (key == node->key)return node;
	else if (key < node->key)
		return search(node->left, key);
	else
		return search(node->right, key);
}
TreeNode* new_node(int item)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}
TreeNode* insert_node(TreeNode* node, int key)
{
	if (node == NULL) return new_node(key);

	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);

	return node;
}
TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;

	while (current->left != NULL)
		current = current->left;

	return current;
}
TreeNode* delete_node(TreeNode* root, int key)
{
	if (root == NULL) return root;

	if (key < root->key)
		root->left = delete_node(root->left, key);
	else if (key > root->key)
		root->right = delete_node(root->right, key);
	else {
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}

		TreeNode* temp = min_value_node(root->right);

		root->key = temp->key;
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}

void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);
		printf("[%d] ", root->key);
		inorder(root->right);
	}
}

int main(void)
{
	TreeNode* root = NULL;

	root = insert_node(root, 27);
	root = insert_node(root, 18);
	root = insert_node(root, 9);
	root = insert_node(root, 10);
	root = insert_node(root, 19);
	root = insert_node(root, 32);
	root = insert_node(root, 44);

	printf("���� Ž�� Ʈ�� ���� ��ȸ ���\n");
	inorder(root);
	printf("\n\n");

	root = insert_node(root, 28);
	printf("[28] ���� ���� �� ���� Ž�� Ʈ�� ���� ��ȸ ���\n");
	inorder(root);
	printf("\n\n");

	root=delete_node(root, 18);
	printf("[18] ���� ���� �� ���� Ž�� Ʈ�� ���� ��ȸ ���\n");
	inorder(root);
	printf("\n\n");

	if (search(root, 9) != NULL)
		printf("���� Ž�� Ʈ������ 9�� �߰���\n");
	else
		printf("���� Ž�� Ʈ������ 9�� �߰� ����\n");

	if (search(root, 30) != NULL)
		printf("���� Ž�� Ʈ������ 30�� �߰���\n");
	else
		printf("���� Ž�� Ʈ������ 30�� �߰� ����\n");

	return 0;
}
