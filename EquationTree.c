#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
	int data;
	char data_ch;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode n1 = {10, NULL, NULL, NULL};
TreeNode n2 = {20, NULL, NULL, NULL};
TreeNode n3 = {30, NULL, NULL, NULL};
TreeNode n4 = {40, NULL, NULL, NULL};
TreeNode n5 = {NULL, '+', &n1, &n2};
TreeNode n6 = {NULL, '*', &n2, &n3 };
TreeNode n7 = {NULL, '-', &n1, &n6};
TreeNode n8 = {NULL, '<', &n1, &n2 };
TreeNode n9 = {NULL, '<', &n3, &n4 };
TreeNode n10 = {NULL, '|', &n8, &n9 };

TreeNode* root1 = &n5;
TreeNode* root2 = &n7;
TreeNode* root3 = &n10;


void inorder(TreeNode *root){
    if (root != NULL){
        inorder(root->left);
        if (root->data != NULL)
        {
        	printf("%d ", root->data);
        }
        else
        	printf("%c ", root->data_ch);
        inorder(root->right);
    }
}

void preorder(TreeNode *root){
    if(root != NULL){
        if (root->data != NULL)
        {
        	printf("%d ", root->data);
        }
        else
        	printf("%c ", root->data_ch);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(TreeNode *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        if (root->data != NULL)
        {
        	printf("%d ", root->data);
        }
        else
        	printf("%c ", root->data_ch);
    }
}


// 중위 순회로 계산
int evaluate(TreeNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
	{
		return root->data;
	}
	else
	{
		int op1 = evaluate(root->left);
		int op2= evaluate(root->right);
		printf("%d %c %d을 계산\n", op1, root->data_ch, op2);

		switch (root->data_ch)
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
		case '>':
			return op1 < op2;
		case '|':
			return op1 || op2;
		}
	}
	return 0;
}


int main(void)
{
	printf("전위 순회= ");
	preorder(root1);
	printf("\n");

	printf("중위 순회= ");
	inorder(root1);
	printf("\n");

	printf("후위 순회= ");
	postorder(root1);
	printf("\n");

	printf("1번 수식 결과 값은 %d\n", evaluate(root1));
	printf("\n\n");
	
	printf("전위 순회= ");
	preorder(root2);
	printf("\n");

	printf("중위 순회= ");
	inorder(root2);
	printf("\n");

	printf("후위 순회= ");
	postorder(root2);
	printf("\n");

	printf("2번 수식 결과 값은 %d\n", evaluate(root2));
	printf("\n\n");

	printf("전위 순회= ");
	preorder(root3);
	printf("\n");

	printf("중위 순회= ");
	inorder(root3);
	printf("\n");

	printf("후위 순회= ");
	postorder(root3);
	printf("\n");


	printf("3번 수식 결과 값은 %d\n", evaluate(root3));
	printf("\n\n");

	return 0;
}