#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
} TreeNode;

void InitTree(TreeNode** node)
{
	*node = (TreeNode*)malloc(sizeof(TreeNode));
	if (*node == NULL)
	{
		fprintf(stderr, "메모리가 부족합니다.\n");
		exit(1);
	}
}

void PreOrder(TreeNode* root)
{
	if (root != NULL)
	{
		if (root->data > 40)
		{
			printf("%c ", root->data);
		}
		else
		{
			printf("%d ", root->data);
		}
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

void InOrder(TreeNode* root)
{
	if (root != NULL)
	{
		InOrder(root->left);
		if (root->data > 40)
		{
			printf("%c ", root->data);
		}
		else
		{
			printf("%d ", root->data);
		}
		InOrder(root->right);
	}
}

void PostOrder(TreeNode* root)
{
	if (root != NULL)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		if (root->data > 40)
		{
			printf("%c ", root->data);
		}
		else
		{
			printf("%d ", root->data);
		}
	}
}

int EvaluationTree(TreeNode* root)
{
	if (root == NULL) return 0;
	if (root->left == NULL && root->right == NULL)
	{
		return root->data;
	}
	else
	{
		int numLeft, numRight;
		numLeft = EvaluationTree(root->left);
		numRight = EvaluationTree(root->right);
		printf("Calculate %d %c %d\n", numLeft, root->data, numRight);
		switch (root->data)
		{
		case '+':
			return numLeft + numRight;
		case '-':
			return numLeft - numRight;
		case '*':
			return numLeft * numRight;
		case '/':
			return numLeft / numRight;
		case '<':
			return (numLeft < numRight) ? 1 : 0;
		case '>':
			return (numLeft > numRight) ? 1 : 0;
		case '|':
			return numLeft || numRight;
		}
	}
	return 0;
}

int main(void)
{
	TreeNode* root1, * x1, * x2;
	TreeNode* root2, * y1, * y2, * y3, * y4;
	TreeNode* root3, * z1, * z2, * z3, * z4, * z5, * z6;

	InitTree(&root1);               //         root1('+')
	InitTree(&x1);                  //        /       |
	InitTree(&x2);                  //    x1(10)     x2(20)

	InitTree(&root2);               //         root2('-')
	InitTree(&y1);                  //        /       |
	InitTree(&y2);                  //    y1(10)     y2('*')      
	InitTree(&y3);                  //              /     |
	InitTree(&y4);                  //           y3(20)   y4(30)

	InitTree(&root3);
	InitTree(&z1);                  //          root3('or')                    
 	InitTree(&z2);                  //        /           |           
	InitTree(&z3);                  //     z1('<')       z2('>')                   
	InitTree(&z4);                  //     /     |       /     |       
	InitTree(&z5);                  //  z3(10)  z4(20) z5(30)  z6(40)                               
	InitTree(&z6);                                               

	root1->data = '+';
	root1->left = x1;
	root1->right = x2;
	x1->data = 10;
	x1->left = NULL;
	x1->right = NULL;
	x2->data = 20;
	x2->left = NULL;
	x2->right = NULL;

	root2->data = '-';
	root2->left = y1;
	root2->right = y2;
	y1->data = 10;
	y1->left = NULL;
	y1->right = NULL;
	y2->data = '*';
	y2->left = y3;
	y2->right = y4;
	y3->data = 20;
	y3->left = NULL;
	y3->right = NULL;
	y4->data = 30;
	y4->left = NULL;
	y4->right = NULL;

	root3->data = '|';
	root3->left = z1;
	root3->right = z2;
	z1->data = '<';
	z1->left = z3;
	z1->right = z4;
	z2->data = '>';
	z2->left = z5;
	z2->right = z6;
	z3->data = 10;
	z3->left = NULL;
	z3->right = NULL;
	z4->data = 20;
	z4->left = NULL;
	z4->right = NULL;
	z5->data = 30;
	z5->left = NULL;
	z5->right = NULL;
	z6->data = 40;
	z6->left = NULL;
	z6->right = NULL;

	printf("root1 전위순회 : ");
	PreOrder(root1);
	printf("\n");
	printf("root1 중위순회 : ");
	InOrder(root1);
	printf("\n");
	printf("root1 후위순회 : ");
	PostOrder(root1);
	printf("\n");
	printf("\n");

	printf("root2 전위순회 : ");
	PreOrder(root2);
	printf("\n");
	printf("root2 중위순회 : ");
	InOrder(root2);
	printf("\n");
	printf("root2 후위순회 : ");
	PostOrder(root2);
	printf("\n");
	printf("\n");

	printf("root3 전위순회 : ");
	PreOrder(root3);
	printf("\n");
	printf("root3 중위순회 : ");
	InOrder(root3);
	printf("\n");
	printf("root3 후위순회 : ");
	PostOrder(root3);
	printf("\n");
	printf("\n");

	printf("root1 : %d\n", EvaluationTree(root1));
	printf("root2 : %d\n", EvaluationTree(root2));
	if (EvaluationTree(root3))
	{
		printf("root3 : %s\n", "True");
	}
	else
	{
		printf("root3 : %s\n", "False");
	}

	free(root1);
	free(x1);
	free(x2);
	free(root2);
	free(y1);
	free(y2);
	free(y3);
	free(y4);
	free(root3);
	free(z1);
	free(z2);
	free(z3);
	free(z4);
	free(z5);
	free(z6);

	return 0;
}