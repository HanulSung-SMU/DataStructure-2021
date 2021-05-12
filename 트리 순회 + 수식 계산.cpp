#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct treenode
{
	int data_int;
	char data_char;
	struct treenode *left, *right;
} treenode;

treenode n2 = {10, NULL, NULL, NULL};
treenode n3 = {20, NULL, NULL, NULL};
treenode n1 = {NULL,'+', &n2, &n3};
treenode *root1 = &n1;


treenode m2 = {10, NULL, NULL, NULL};
treenode m4 = {20, NULL, NULL, NULL};
treenode m5 = {30, NULL, NULL, NULL};
treenode m3 = {NULL, 'x', &m4, &m5};
treenode m1 = {NULL, '-', &m2, &m3};
treenode *root2 = &m1;


treenode o4 = {10, NULL, NULL, NULL};
treenode o5 = {20, NULL, NULL, NULL};
treenode o6 = {30, NULL, NULL, NULL};
treenode o7 = {40, NULL, NULL, NULL};
treenode o2 = {NULL, '<', &o4, &o5};
treenode o3 = {NULL, '>', &o6, &o7};
treenode o1 = {NULL, '|', &o2, &o3};
treenode *root3 = &o1;


void preorder (treenode *root)
{
	if (root != NULL)
	{
		if (root->data_int != NULL)
			printf("%d ", root->data_int);
		else
			printf("%c ", root->data_char);
		preorder (root->left);
		preorder (root->right);
	}
}

void inorder (treenode *root)
{
	if (root != NULL)
	{
		inorder (root->left);
		if (root->data_int != NULL)
			printf("%d ", root->data_int);
		else
			printf("%c ", root->data_char);
		inorder (root->right);
	}
}

void postorder (treenode *root)
{
	if (root !=NULL)
	{
		postorder (root->left);
		postorder (root->right);
		if (root->data_int != NULL)
			printf("%d ", root->data_int);
		else
			printf("%c ", root->data_char);
	}
}

int evaluate (treenode *root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right ==NULL)
		return root->data_int;
	else
	{
		int op1 = evaluate(root->left);
		int op2 = evaluate(root->right);
		printf("%d %c %d을 계산.\n", op1, root->data_char, op2);
		switch (root->data_char)
		{
		case '+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case 'x':
			return op1 * op2;
		case '|':
			return op1 || op2;
		case '<':
			return op1 < op2;
		case '>':
			return op1 > op2;
		}
	}
	return 0;
}

int main (void)
{
	printf("(a) 전위 순회 : ");
	preorder(root1);
	printf("\n");
	
	printf("(a) 중위 순회 : ");
	inorder(root1);
	printf("\n");
	
	printf("(a) 후위 순회 : ");
	postorder(root1);
	printf("\n");
	
	printf("10 + 20 의 값은 %d\n", evaluate(root1));
	printf("\n\n");
	
	
	printf("(b) 전위 순회 : ");
	preorder(root2);
	printf("\n");
	
	printf("(b) 중위 순회 : ");
	inorder(root2);
	printf("\n");
	
	printf("(b) 후위 순회 : ");
	postorder(root2);
	printf("\n");
	
	printf("10 - 20 x 30 의 값은 %d\n", evaluate(root2));
	printf("\n\n");
	
	
	printf("(c) 전위 순회 : ");
	preorder(root3);
	printf("\n");
	
	printf("(c) 중위 순회 : ");
	inorder(root3);
	printf("\n");
	
	printf("(c) 후위 순회 : ");
	postorder(root3);
	printf("\n");
	
	printf("(10<20) or (30>40) 의 값은 %d\n", evaluate(root3));
	printf("\n\n");
	
	
	
}
