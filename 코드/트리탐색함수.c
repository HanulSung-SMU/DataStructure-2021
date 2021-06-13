#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
    int key;
    struct TreeNode* left, * right;
} TreeNode;

//���� ��ȸ
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

//Ž�� �Լ�
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

//���� ����
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

//���� ����
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

    printf("���� Ž�� Ʈ�� ���� ��ȸ ��� \n");
    inorder(root);
    printf("\n\n");

    if (search(root, 28) != NULL)
        printf("���� Ž�� Ʈ������ 33�� �߰��� \n");
    else
        printf("���� Ž�� Ʈ������ 33�� �߰߸��� \n");
    return 0;
}
