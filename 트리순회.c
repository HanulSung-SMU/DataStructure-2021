#include <stdio.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

//                   15(n6)
//           4(n2)              20(n5)
//        1(n1)           16(n3)      25(n4)      

TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6; //루트노드 = n6

//중위순회
inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);
		printf("[%d] ", root->data);
		inorder(root->right);
	}
}

//전위순회
preorder(TreeNode* root) {
	if (root) {
		printf("[%d] ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

//후위순회
postorder(TreeNode* root) {
	if (root) {
		postorder(root->left);
		postorder(root->right);
		printf("[%d] ", root->data);
	}
}

int main(void) {
	printf("중위순회=");
	inorder(root);
	printf("\n");

	printf("전위순회=");
	preorder(root);
	printf("\n");

	printf("후위순회=");
	postorder(root);
	printf("\n");
	return 0;
}



