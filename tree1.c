#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef int ele;
typedef struct TreeNode {
    ele data;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode n1={1,NULL,NULL};
TreeNode n2={4,&n1,NULL};
TreeNode n3={16,NULL,NULL};
TreeNode n4={25,NULL,NULL};
TreeNode n5={20,&n3,&n4};
TreeNode n6={15,&n2,&n5};
TreeNode *root=&n6;

void Inorder(TreeNode *root) {
    if (root) {
        Inorder(root->left);
        printf("[%d]",root->data);
        Inorder(root->right);
    }
}

void Preorder(TreeNode *root) {
    if (root) {
        printf("[%d]",root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(TreeNode *root) {
    if (root) {
        Postorder(root->left);
        Postorder(root->right);
        printf("[%d]",root->data);
    }
}

int main(void)
{
    printf("중위 순회=");
    Inorder(root);
    putchar('\n');
    
    printf("전위 순회=");
    Preorder(root);
    putchar('\n');
    
    printf("후위 순회=");
    Postorder(root);
    putchar('\n');
    return 0;
}
