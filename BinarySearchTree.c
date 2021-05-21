#include <stdio.h>
#include <stdlib.h>

typedef struct treenode
{
	int key;
	struct treenode* left, * right;
} treenode;

treenode* search(treenode* node, int key)
{
	if (node == NULL)
		return NULL;
	if (key == node->key)
		return node;
	else if (key < node->key)
		return search(node->left, key);
	else
		return search(node->right, key);
}

treenode* new_node(int item)
{
	treenode* temp = (treenode*)malloc(sizeof(treenode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

treenode* insert_node(treenode* node, int key)
{
	if (node == NULL)
		return new_node(key);
	if (search(node, key) != NULL)
		printf("그 값은 이미 존재함\n"); // 이미 그 값이 존재할 경우
	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);

	return node;
}

treenode* min_value_node(treenode* node)
{
	treenode* current = node;

	while (current->left != NULL)
		current = current->left;

	return current;
}

treenode* delete_node(treenode* root, int key)
{
	if (root == NULL)
		return root;

	if (key < root->key)
		root->left = delete_node(root->left, key);
	else if (key > root->key)
		root->right = delete_node(root->right, key);
	else
	{
		if (root->left == NULL)
		{
			treenode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			treenode* temp = root->left;
			free(root);
			return temp;
		}
		treenode* temp = min_value_node(root->right);

		root->key = temp->key;
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}

void inorder(treenode* root)
{
	if (root)
	{
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

int main(void)
{
	treenode* root = NULL;
	treenode* temp = NULL;

	root = insert_node(root, 20);
	root = insert_node(root, 18);
	root = insert_node(root, 9);
	root = insert_node(root, 10);
	root = insert_node(root, 33);
	root = insert_node(root, 77);
	root = insert_node(root, 44);

	printf("이진탐색트리 중위순회 \n");
	inorder(root);
	printf("\n\n\n\n");

	printf("이진탐색트리에서 77검색\n");
	printf("-----------------------\n");	
	if (search(root,77) != NULL)
			printf("이진탐색트리에서 77을 발견함 \n");
		else
			printf("이진탐색트리에서 77을 발견못함 \n");
		printf("\n\n");
	
	root = insert_node(root, 28);
	printf("이진탐색트리 중위순회 (28 삽입) \n");
	inorder(root);
	printf("\n\n");

	root = insert_node(root, 66);
	printf("이진탐색트리 중위순회 (66 삽입) \n");
	inorder(root);
	printf("\n\n");

	root = delete_node(root, 66);
	printf("이진탐색트리 중위순회 (66 삭제)\n");
	inorder(root);
	printf("\n\n");

	root = delete_node(root, 18);
	printf("이진탐색트리 중위순회 (18 삭제)\n");
	inorder(root);
	printf("\n\n");
	return 0;
}