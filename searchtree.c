#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Treenode{
	element key;
	struct Treenode *left, *right;
}Treenode;

Treenode *search(Treenode *node, int key)
{
	if(node == NULL) return NULL;
	if(key == node->key) return node;
	else if(key < node->key)
		return search(node->left, key);
	else
		return search(node->right,key);
}	

Treenode *min_value_node(Treenode *node)
{
	Treenode *current = node;
	while(current->left != NULL)
		current = current->left;

	return current;
}
Treenode *delete(Treenode *root, int key)
{
	if (root == NULL) return root;

	if(key < root->key)
		root->left = delete(root->left, key);
	else if(key > root->key)
		root->right = delete(root->right, key);
	else{
		if(root->left == NULL){
			Treenode *temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL){
			Treenode *temp = root->left;
			free(root);
			return temp;
		}

		Treenode *temp = min_value_node(root->right);
		root->key = temp->key;
		root->right = delete(root->right, temp->key);
	}
	return root;
}

Treenode *new_node(int item)
{
	Treenode *temp = (Treenode*)malloc(sizeof(Treenode));
	temp->key = item;
	temp->left = temp->right = NULL;
	
	return temp;
}

Treenode *insert(Treenode *node, int key)
{
	if(node == NULL)
			return new_node(key);

	if(key < node->key)
		node->left = insert(node->left, key);
	else if(key > node->key)
		node->right = insert(node->right, key);

	return node;
}

void inorder(Treenode *root)
{
	if(root){
		inorder(root->left);
		printf("[%d] ",root->key);
		inorder(root->right);
	}
}

int main(void)
{
	Treenode *root = NULL;

	root = insert(root, 27);
	root = insert(root, 18);
	root = insert(root, 9);
	root = insert(root, 10);
	root = insert(root, 19);
	root = insert(root, 32);
	root = insert(root, 44);

	printf("중위 순회 결과\n");
	inorder(root);
	printf("\n\n");

	root = insert(root, 28);
	root = delete(root, 18);
	printf("중위 순회 결과\n");
	inorder(root);
	printf("\n\n");
	if (search(root, 30) != NULL)
		printf("30 발견.\n");
	else
		printf("30 발견하지 못함. \n");

	return 0;
}
