#include <stdio.h>
#include <stdlib.h>

typedef struct treenode
{
	int key;
	struct treenode *left, *right;
} treenode;

treenode *search(treenode *node, int key)
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

treenode *new_node (int item)
{
	treenode *temp = (treenode *)malloc(sizeof(treenode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

treenode *insert_node (treenode *node, int key)
{
	if (node == NULL)
		return new_node(key);
	if (search (node, key) != NULL) 
		printf ("�� ���� �̹� �ִ�.\n"); 
	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);
		
	return node;
}

treenode *min_value_node (treenode *node)
{
	treenode *current = node;
	
	while (current->left != NULL)
		current = current->left;
		
	return current;
}

treenode *delete_node(treenode *root, int key)
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
			treenode *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			treenode *temp = root->left;
			free(root);
			return temp;
		}
		treenode *temp = min_value_node(root->right);
		
		root->key = temp->key;
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}

void inorder (treenode *root)
{
	if (root)
	{
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

int main (void)
{
	treenode *root = NULL;
	treenode *temp = NULL;
	
	root = insert_node (root, 27);
	root = insert_node (root, 18);
	root = insert_node (root, 9);
	root = insert_node (root, 10);
	root = insert_node (root, 19);
	root = insert_node (root, 32);
	root = insert_node (root, 44);
	
	printf ("����Ž��Ʈ�� ������ȸ \n");
	inorder (root);
	printf("\n\n");
/*	if (search(root,30) != NULL)
		printf("����Ž��Ʈ������  30�� �߰��� \n");
	else
		printf("����Ž��Ʈ������ 30�� �߰߸��� \n");
	printf("\n\n");
*/	
	root = insert_node (root, 28);
	printf ("����Ž��Ʈ�� ������ȸ \n");
	inorder (root);
	printf("\n\n");
	
	root = delete_node (root,18);
	printf ("����Ž��Ʈ�� ������ȸ \n");
	inorder (root);
	return 0;
}
