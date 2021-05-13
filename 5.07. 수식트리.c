#include<stdio.h>
typedef struct TreeNode {
	int data;
	char operator;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

void preorder(TreeNode* node) {
	if (node) {
		if(node->operator)
			printf("%c ", node->operator);
		else
			printf("%d ", node->data);
		preorder(node->left);
		preorder(node->right);
	}
}

void inorder(TreeNode* node) {
	if (node) {
		inorder(node->left);
		if (node->operator)
			printf("%c ", node->operator);
		else
			printf("%d ", node->data);
		inorder(node->right);
	}
}

void postorder(TreeNode* node) {
	if (node) {
		postorder(node->left);
		postorder(node->right);
		if (node->operator)
			printf("%c ", node->operator);
		else
			printf("%d ", node->data);
	}
}

void print_Tree(TreeNode* root) {
	printf("전위 순회\n");
	preorder(root);
	printf("\n");

	printf("중위 순회\n");
	inorder(root);
	printf("\n");

	printf("후위 순회\n");
	postorder(root);
	printf("\n");
}

int cal_Tree(TreeNode* root) {
	if (!root) {
		printf("there is no data\n");
		return;
	}
	int result = 0;
	if (root->left == NULL && root->right == NULL)
		return root->data;
	int left_result = cal_Tree(root->left);
	int rigtht_result = cal_Tree(root->right);
	if (root->operator) {
		switch (root->operator) {
		case'+':
			result = left_result + rigtht_result;
			break;
		case'-':
			result = left_result - rigtht_result;
			break;
		case'/':
			result = left_result / rigtht_result;
			break;
		case'*':
			result = left_result * rigtht_result;
			break;
		case'<':
			result = left_result < rigtht_result;
			break;
		case'>':
			result = left_result > rigtht_result;
			break;
		case'|':
			result = left_result || rigtht_result;
			break;
		case'&':
			result = left_result && rigtht_result;
			break;
		}
		return result;
	}
}

int main(void)
{
	TreeNode* root1, * root2, * root3;
	TreeNode n1_1 = { 10, 0, NULL, NULL };
	TreeNode n1_2 = { 20, 0, NULL, NULL };
	TreeNode n1_3 = { 0, '+', &n1_1, &n1_2 };
	root1 = &n1_3;

	TreeNode n2_1 = { 10, 0, NULL, NULL };
	TreeNode n2_2 = { 20, 0, NULL, NULL };
	TreeNode n2_3 = { 30, 0, NULL, NULL };
	TreeNode n2_4 = { 0, '*', &n2_2, &n2_3 };
	TreeNode n2_5 = { 0, '-', &n2_1, &n2_4 };
	root2 = &n2_5;

	TreeNode n3_1 = { 10, 0, NULL, NULL };
	TreeNode n3_2 = { 20, 0, NULL, NULL };
	TreeNode n3_3 = { 30, 0, NULL, NULL };
	TreeNode n3_4 = { 40, 0, NULL, NULL };
	TreeNode n3_5 = { 0, '<', &n3_1, &n3_2 };
	TreeNode n3_6 = { 0, '<', &n3_3, &n3_4 };
	TreeNode n3_7 = { 0, '|', &n3_5, &n3_6 };
	root3 = &n3_7;

	printf("~~first tree~~\n");
	print_Tree(root1);
	printf("result : %d\n\n", cal_Tree(root1));

	printf("~~second tree~~\n");
	print_Tree(root2);
	printf("result : %d\n\n", cal_Tree(root2));

	printf("~~third tree~~\n");
	print_Tree(root3);
	printf("result : %d\n\n", cal_Tree(root3));
	return 0;
}