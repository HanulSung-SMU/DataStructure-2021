#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

int a = 10; int b = 20; int c = 30; int d = 40;
TreeNode n1 = {10, NULL, NULL};
TreeNode n2 = {20, NULL, NULL};
TreeNode n3 = {'*', &n1, &n2};
TreeNode *re1 = &n3;

TreeNode r1 = {10, NULL, NULL};
TreeNode r2 = {0, NULL, NULL};
TreeNode r3 = {0, NULL, NULL};
TreeNode r4 = {'+', &r2, &r3};
TreeNode r5 = {20, NULL, NULL};
TreeNode r6 = {30, NULL, NULL};
TreeNode r7 = {'*', &r5, &r6};
TreeNode r8 = {'-', &r1, &r7};
TreeNode *re2 = &r8;

TreeNode a1 = {10, NULL, NULL};
TreeNode a2 = {20, NULL, NULL};
TreeNode a3 = {'<', &a1, &a2};
TreeNode a4 = {30, NULL, NULL};
TreeNode a5 = {40, NULL, NULL};
TreeNode a6 = {'>', &a4, &a5};
TreeNode a7 = {'|', &a3, &a6};
TreeNode *re3 = &a7;

int evaluate(TreeNode *root) {
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return root->data;
    else {
        int nn1 = evaluate(root->left);
        int nn2 = evaluate(root->right);
        printf("%d %c %d을 계산합니다. ", nn1, root->data, nn2);
        switch (root->data) {
            case '+':
                return nn1 + nn2;
            case '-':
                return nn1 - nn2;
            case '*':
                return nn1 * nn2;
            case '<':
                return (((nn1) < (nn2)) ? (nn2) : 0);
            case '>':
                return (((nn1) > (nn2)) ? (nn1) : 0);
            case '|':
                return nn1 && nn2;
        }
    }
    return 0;
}

int main(void) {
    printf("수식의 값은 %d입니다. \n", evaluate(re1));
    printf("수식의 값은 %d입니다. \n", evaluate(re2));
    printf("수식의 값은 %d입니다. \n", evaluate(re3));
    return 0;
}

