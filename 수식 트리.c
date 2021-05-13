#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <ctype.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left, * right;
} TreeNode;

TreeNode x1 = { 10, NULL, NULL };
TreeNode x2 = { 20, NULL, NULL };
TreeNode x3 = { '+', &x1, &x2 };
TreeNode* root1 = &x3;

TreeNode y1 = { 10, NULL, NULL };
TreeNode y2 = { 0, NULL, NULL };
TreeNode y3 = { 0, NULL, NULL };
TreeNode y4 = { '+', &y2, &y3 };
TreeNode y5 = { 30, NULL, NULL };
TreeNode y6 = { 20, NULL, NULL };
TreeNode y7 = { '*', &y6, &y5 };
TreeNode y8 = { '-', &y1, &y7 };
TreeNode* root2 = &y8;

TreeNode z1 = { 10, NULL, NULL };
TreeNode z2 = { 20, NULL, NULL };
TreeNode z3 = { '<', &z1, &z2 };
TreeNode z4 = { 30, NULL, NULL };
TreeNode z5 = { 40, NULL, NULL };
TreeNode z6 = { '<', &z4, &z5 };
TreeNode z7 = { '|', &z3, &z6 };
TreeNode* root3 = &z7;

// 전위 순회
void preorder(TreeNode *root) {
	if (root != NULL) {
		switch(root->data)
    {
      case '+':case '-':case '*':case '/':case '|':case '<':case '>':
        printf("[ %c ] ", root->data);
        break;
      default :
        printf("[ %d ] ", root->data);
        break;
    }
		preorder(root->left);// 왼쪽서브트리 순회
		preorder(root->right);// 오른쪽서브트리 순회
	}
}

// 중위 순회
void inorder(TreeNode *root) {
	if (root != NULL) {
		inorder(root->left);// 왼쪽서브트리 순회
		switch(root->data)
    {
      case '+':case '-':case '*':case '/':case '|':case '<':case '>':
        printf("[ %c ] ", root->data);
        break;
      default :
        printf("[ %d ] ", root->data);
        break;
    }
		inorder(root->right);// 오른쪽서브트리 순회
	}
}

// 후위 순회
void postorder(TreeNode *root) {
	if (root != NULL) 
  {
		postorder(root->left);// 왼쪽서브트리 순회
		postorder(root->right);// 오른쪽서브트리순회
		switch(root->data)
    {
      case '+':case '-':case '*':case '/':case '|':case '<':case '>':
        printf("[ %c ] ", root->data);
        break;
      default :
        printf("[ %d ] ", root->data);
        break; 
    }
	}
}

int calc(TreeNode* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return root->data;
    else 
    {
        int LP = calc(root->left);
        int RP = calc(root->right);

        //printf("%d %c %d을 계산합니다.\n", LP, root->data, RP);
        
        switch (root->data) {
        case '+':
            return LP + RP;
        case '-':
            return LP - RP;
        case '*':
            return LP * RP;
        case '/':
            return LP / RP;
        case '|':
            return LP || RP;
        case '<':
            return (LP < RP) ? 1 : 0;
        case '>':
            return (LP > RP) ? 1 : 0;
        }
    }
    return 0;
}

int main(void) {
    printf("================== 첫 번째 수식 ==================\n");
    printf("중위 순회 : \n");
	  inorder(root1);
    printf("\n");
    printf("전위 순회 : \n");
	  preorder(root1);
    printf("\n");
    printf("후위 순회 : \n");
	  postorder(root1);
    printf("\n\n");
    printf("두 번째 수식의 값 : %d \n", calc(root1));
    printf("================== 첫 번째 수식 ==================\n\n");
    printf("================== 두 번째 수식 ==================\n");
    printf("중위 순회 : \n");
	  inorder(root2);
    printf("\n");
    printf("전위 순회 : \n");
	  preorder(root2);
    printf("\n");
    printf("후위 순회 : \n");
	  postorder(root2);
    printf("\n\n");
    printf("두 번째 수식의 값 : %d \n", calc(root2));
    printf("================== 두 번째 수식 ==================\n\n");
    printf("================== 세 번째 수식 ==================\n");
    printf("중위 순회 : \n");
	  inorder(root3);
    printf("\n");
    printf("전위 순회 : \n");
	  preorder(root3);
    printf("\n");
    printf("후위 순회 : \n");
	  postorder(root3);
    printf("\n\n");
    printf("세번째 수식의 값 : %d \n", calc(root3));
    printf("================== 세 번째 수식 ==================\n\n");
    return 0;
}
