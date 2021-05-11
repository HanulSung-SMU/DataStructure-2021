#include<stdio.h>
#include<stdlib.h>

//Ʈ�����
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

//ù��° ����
TreeNode r1_n1= { 10,NULL,NULL };
TreeNode r1_n2 = { 20,NULL,NULL };
TreeNode r1_n3 = { '+',&r1_n1,&r1_n2 };
TreeNode* root1 = &r1_n3;

//�ι�° ����
TreeNode r2_n1 = { 10,NULL,NULL };
TreeNode r2_n2 = { 20,NULL,NULL };
TreeNode r2_n3 = { 30,NULL,NULL };
TreeNode r2_n4 = { '*',&r2_n2,&r2_n3 };
TreeNode r2_n5 = { '-',&r2_n1,&r2_n4 };
TreeNode* root2 = &r2_n5;

//����° ����
TreeNode r3_n1 = { 10,NULL,NULL };
TreeNode r3_n2 = { 20,NULL,NULL };
TreeNode r3_n3 = { '<', &r3_n1, &r3_n2 };
TreeNode r3_n4 = { 30,NULL,NULL };
TreeNode r3_n5 = { 40,NULL,NULL };
TreeNode r3_n6 = { '>',&r3_n4,&r3_n5};
TreeNode r3_n7 = { '|',&r3_n3,&r3_n6 };
TreeNode* root3 = &r3_n7;

//���� ��ȸ
inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);
		if (root->left == NULL && root->right == NULL)
			printf("%d ", root->data);
		else
			printf("%c ", root->data);
		inorder(root->right);
	}
}
//���� ��ȸ
preorder(TreeNode* root) {
	if (root) {
		if (root->left == NULL && root->right == NULL)
			printf("%d ", root->data);
		else
			printf("%c ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
//���� ��ȸ
postorder(TreeNode* root) {
	if (root) {
		postorder(root->left);
		postorder(root->right);
		if (root->left == NULL && root->right == NULL)
			printf("%d ", root->data);
		else
			printf("%c ", root->data);
	}
}
//����ؼ� �� ���
int calculate(TreeNode* root)
{
	int res;
	int op1, op2;
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return root->data;
	else {
		op1 = calculate(root->left);
		op2 = calculate(root->right);
		
		switch (root->data) {
		case '+':
			return op1 + op2;
		case'-':
			return op1 - op2;
		case'*':
			return op1 * op2;
		case'/':
			if (op2 == 0) {
				printf("0�� ���� �� �����ϴ�");
				break;
			}
			return op1 / op2;
		case'<':
			return op1 < op2;
		case'>':
			return op1 > op2;
		case'|':
			return op1 | op2;
		}
	}
	
	return 0;
}
	
int main(void) {
	int res1, res2, res3;

	printf("���� ��ȸ=");
	printf("\n");
	inorder(root1);
	printf("\n");
	inorder(root2);
	printf("\n");
	inorder(root3);
	printf("\n");

	printf("���� ��ȸ=");
	printf("\n");
	preorder(root1);
	printf("\n");
	preorder(root2);
	printf("\n");
	preorder(root3);
	printf("\n");

	printf("���� ��ȸ=");
	printf("\n");
	postorder(root1);
	printf("\n");
	postorder(root2);
	printf("\n");
	postorder(root3);
	printf("\n");
	printf("\n");

	printf("���\n");
	printf("1��° ����:");
	res1=calculate(root1);
	inorder(root1);
	printf("= %d\n", res1);

	printf("2��° ����:");
	res2 = calculate(root2);
	inorder(root2);
	printf("= %d\n", res2);

	printf("3��° ����:");
	res3 = calculate(root3);
	inorder(root3);
	printf("= %d\n", res3);

	return 0;
}