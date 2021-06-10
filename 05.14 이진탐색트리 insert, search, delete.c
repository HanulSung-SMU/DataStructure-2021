#include<stdio.h>
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode* insert(TreeNode* root, int key) {
	if (root == NULL) {
		printf("insert\n");
		TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
		if (!node) {
			printf("memory assignment error");
			exit(1);
		}
		node->data = key;
		node->left = NULL;
		node->right = NULL;

		root = node;
		return root;
	}
	else {
		if (root->data < key) {
			root->right = insert(root->right, key);
			return root;
		}
		else if (root->data > key) {
			root->left = insert(root->left, key);
			return root;
		}
	}
}

int search(TreeNode* root, int key) {
	if (!root) return 0;
	else {
		if (root->data < key)
			return search(root->right, key);
		else if (root->data > key)
			return search(root->left, key);
		else 
			return 1;
	}
}

TreeNode* delete(TreeNode* root, int key) {
	if (!root)return;
	else {
		if (root->data < key) {
			root->right = delete(root->right, key);
			return root;
		}
		else if (root->data > key) {
			root->left = delete(root->left, key);
			return root;
		}
		else {
			if (root->right == NULL) {
				TreeNode* tmp = root->left;
				free(root);
				return tmp;
			}
			else if (root->left == NULL) {
				TreeNode* tmp = root->right;
				free(root);
				return tmp;
			}
			else {
				TreeNode* tmp = root->right;
				while (tmp->left != NULL) 
					tmp = tmp->left;
				root->data = tmp->data;
				if (tmp == root->right)
					root->right = NULL;
				else root->left = NULL;
				free(tmp);	
				return root;
			}
		}
	}
}

void preorder(TreeNode* root) {
	if (root) {
		printf("%d ", root->data); // 노드 방문
		preorder(root->left); // 왼쪽서브트리 순회
		preorder(root->right); // 오른쪽서브트리 순회
	}
}

int main() {
	TreeNode* root = NULL;
	int num;
	for (int i = 0; i < 6; i++) {
		scanf_s("%d", &num);
		root = insert(root, num);
	}
	preorder(root);
	printf("\n");

	if (search(root, 30))
		printf("true\n");
	else
		printf("false");

	root = delete(root, 30);
	preorder(root);
	printf("\n");
}