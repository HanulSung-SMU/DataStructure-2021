#include <stdio.h>
#include <stdlib.h>


typedef struct TreeNode {
    int data;
    struct TreeNode* left, * right;
} TreeNode;

TreeNode m1_n1 = { 10,NULL,NULL };
TreeNode m1_n2 = { 50,NULL,NULL };
TreeNode m1_n3 = { '-',&m1_n1,&m1_n2 };
TreeNode* Exp1 = &m1_n3;

TreeNode m2_n1 = { 10,NULL,NULL };
TreeNode m2_n2 = { 45,NULL,NULL };
TreeNode m2_n3 = { 55,NULL,NULL };
TreeNode m2_n4 = { '+',&m2_n2,&m2_n3 };
TreeNode m2_n5 = { '*',&m2_n1,&m2_n4 };
TreeNode* Exp2 = &m2_n5;

TreeNode m3_n1 = { 10,NULL,NULL };
TreeNode m3_n2 = { 40,NULL,NULL };
TreeNode m3_n3 = { '<',&m3_n1,&m3_n2 };
TreeNode m3_n4 = { 30,NULL,NULL };
TreeNode m3_n5 = { 70,NULL,NULL };
TreeNode m3_n6 = { '>',&m3_n4,&m3_n5 };
TreeNode m3_n7 = { '|',&m3_n3,&m3_n6 };
TreeNode* Exp3 = &m3_n7;


void Inorder(TreeNode* root) {
    if (root) {
        Inorder(root->left);
        if (root->left == NULL && root->right == NULL)
            printf("%d ", root->data);
        else
            printf("%c ", root->data);
        Inorder(root->right);
    }
}

void Preorder(TreeNode* root) {
    if (root) {
        if (root->left == NULL && root->right == NULL)
            printf("%d ", root->data);
        else
            printf("%c ", root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(TreeNode* root) {
    if (root) {
        Postorder(root->left);
        Postorder(root->right);
        if (root->left == NULL && root->right == NULL)
            printf("%d ", root->data);
        else
            printf("%c ", root->data);
    }
}

int evaluate(TreeNode* root)
{
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return root->data;
    else {
        int op1 = evaluate(root->left);
        int op2 = evaluate(root->right);
        printf("%d %c %d 계산...\n", op1, root->data, op2);
        switch (root->data) {
        case '+': 
            return op1 + op2;
        case '-': 
            return op1 - op2;
        case '*': 
            return op1 * op2;
        case '/': 
            return op1 / op2;
        case '>': 
            return op1 > op2;
        case '<': 
            return op1 < op2;
        case '|': 
            return op1 | op2;
        }
    }
    return 0;
}

int main(void)
{
    printf("중위 순회:");
    printf("\n");
    Inorder(Exp1);
    printf("\n");
    Inorder(Exp2);
    printf("\n");
    Inorder(Exp3);
    printf("\n");

    printf("전위 순회:");
    printf("\n");
    Preorder(Exp1);
    printf("\n");
    Preorder(Exp2);
    printf("\n");
    Preorder(Exp3);
    printf("\n");

    printf("후위 순회:");
    printf("\n");
    Postorder(Exp1);
    printf("\n");
    Postorder(Exp2);
    printf("\n");
    Postorder(Exp3);
    printf("\n");
    printf("\n");

    printf("1번째 수식: ");
    Inorder(Exp1);
    printf("\n");
    printf("= %d\n", evaluate(Exp1));

    printf("2번째 수식: ");
    Inorder(Exp2);
    printf("\n");
    printf("= %d\n", evaluate(Exp2));

    printf("3번째 수식: ");
    Inorder(Exp3);
    printf("\n");
    printf("= %d\n", evaluate(Exp3));
    return 0;
}
