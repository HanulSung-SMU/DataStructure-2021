#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
    int key;
    struct TreeNode* left, * right;
} TreeNode;

//중위 순회
int inorder(TreeNode* root) {
    if (root) {
        inorder(root->left);
        printf("[%d]", root->key);
        inorder(root->right);
    }
}

TreeNode* new_node(int item)
{
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode* min_value_node(TreeNode* node)
{
    TreeNode* current = node;
    while (current->left != NULL)
        current = current->left;

    return current;
}

//탐색 함수
TreeNode* search(TreeNode* node, int key)
{
    if (node == NULL)
        return NULL;
    if (key == node->key)
        return node;
    else if (key < node->key)
        return search(node->left, key);
    else
        return search(node->right, key);
}

//삽입 연산
TreeNode* insert_node(TreeNode* node, int key)
{
    if (node == NULL)
        return new_node(key);
    if (key < node->key)
        node->left = insert_node(node->left, key);
    else if (key > node->key)
        node->right = insert_node(node->right, key);
    return node;
}

//삭제 연산
TreeNode* delete_node(TreeNode* root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = delete_node(root->left, key);
    else if (key > root->key)
        root->right = delete_node(root->right, key);
    else {
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        TreeNode* temp = min_value_node(root->right);

        root->key = temp->key;
        root->right = delete_node(root->right, temp->key);
    }
    return root;
}

int main(void)
{
    TreeNode* root = NULL;
    TreeNode* tmp = NULL;

    root = insert_node(root, 27);
    root = insert_node(root, 18);
    root = insert_node(root, 9);
    root = insert_node(root, 10);
    root = insert_node(root, 19);
    root = insert_node(root, 32);
    root = insert_node(root, 44);
    root = insert_node(root, 21);
    root = delete_node(root, 33);

    printf("이진 탐색 트리 중위 순회 결과 \n");
    inorder(root);
    printf("\n\n");

    if (search(root, 28) != NULL)
        printf("이진 탐색 트리에서 33을 발견함 \n");
    else
        printf("이진 탐색 트리에서 33을 발견못함 \n");
    return 0;
}
