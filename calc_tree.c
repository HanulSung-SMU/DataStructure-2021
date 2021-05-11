#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
	int data;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode n1 = { 10, NULL, NULL};
TreeNode n2 = { 20, NULL, NULL};
TreeNode n3 = { 30, NULL, NULL };
TreeNode n4 = { 40, NULL, NULL };
TreeNode n5 = {'+', &n1, &n2};
TreeNode n6 = { '*', &n2, &n3 };
TreeNode n7 = { '-', &n1, &n6};
TreeNode n8= { '<', &n1, &n2 };
TreeNode n9 = { '<', &n3, &n4 };
TreeNode n10 = { '||', &n8, &n9 };

TreeNode* root1 = &n5;
TreeNode* root2 = &n7;
TreeNode* root3 = &n10;


// ���� ��ȸ
preorder(TreeNode* root)
{
	if (root)
	{
		printf("[%d] ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

// ���� ��ȸ
inorder(TreeNode* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("[%d] ", root->data);
		inorder(root->right);
	}
}

// ���� ��ȸ
postorder(TreeNode* root)
{
	if (root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("[%d] ", root->data);
	}
}


// ���� ��ȸ�� ���
int evaluate(TreeNode* root)
{
	if (root->left == NULL && root->right == NULL)
	{
		return root->data;
	}
	else
	{
		int op1 = evaluate(root->left);
		int op2= evaluate(root->right);
		printf("%d %c %d�� ����մϴ�\n", op1, root->data, op2);

		switch (root->data)
		{
		case '+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case '*':
			return op1 * op2;
		case '/':
			return op1 / op2;
		case '<':
			return op1 < op2;
		case '||':
			return op1 || op2;
		}
	}
	return 0;
}


int main(void)
{
	printf("���� ��ȸ= ");
	preorder(root1);
	printf("\n");

	printf("���� ��ȸ= ");
	inorder(root1);
	printf("\n");

	printf("���� ��ȸ= ");
	postorder(root1);
	printf("\n");

	printf("���� ��ȸ= ");
	preorder(root2);
	printf("\n");

	printf("���� ��ȸ= ");
	inorder(root2);
	printf("\n");

	printf("���� ��ȸ= ");
	postorder(root2);
	printf("\n");

	printf("���� ��ȸ= ");
	preorder(root3);
	printf("\n");

	printf("���� ��ȸ= ");
	inorder(root3);
	printf("\n");

	printf("���� ��ȸ= ");
	postorder(root3);
	printf("\n");

	printf("\n");

	printf("1�� ���� ��� ���� %d\n", evaluate(root1));
	printf("\n\n");
	printf("2�� ���� ��� ���� %d\n", evaluate(root2));
	printf("\n\n");
	printf("3�� ���� ��� ���� %d\n", evaluate(root3));
	printf("\n\n");
	return 0;
}