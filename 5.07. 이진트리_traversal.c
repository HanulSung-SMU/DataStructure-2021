#include<stdio.h>
typedef struct TreeNode {
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;
void preorder(TreeNode* node) {
	if (node) {
		printf("%d ", node->data);
		preorder(node->left);
		preorder(node->right);
	}
}
void inorder(TreeNode* node) {
	if (node) {
		inorder(node->left);
		printf("%d ", node->data);
		inorder(node->right);
	}
}
void postorder(TreeNode* node) {
	if (node) {
		postorder(node->left);
		postorder(node->right);
		printf("%d ", node->data);
	}
}
int main(void)
{
	TreeNode n1 = { 4, NULL, NULL };
	TreeNode n2 = { 2, &n1, NULL };
	TreeNode n3 = { 5, NULL, NULL };
	TreeNode n4 = { 6, NULL, NULL };
	TreeNode n5 = { 3, &n3, &n4 };
	TreeNode n6 = { 1, &n2, &n5 };
	TreeNode* root = &n6;

	printf("이진트리형태\n");
	printf("     1\n");
	printf("  2     3\n");
	printf("4     5   6\n");

	printf("전위 순회\n");
	preorder(root);
	printf("\n");

	printf("중위 순회\n");
	inorder(root);
	printf("\n");

	printf("후위 순회\n");
	postorder(root);
	printf("\n");
	return 0;
}