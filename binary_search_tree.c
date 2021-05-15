#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode {
    element key;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode* search (TreeNode* node, int key) {
    if(node == NULL)
        return NULL;
    if(key == node->key)
        return node;
    else if(key < node->key)
        return search(node->left, key);
    else
        return search(node->right, key);
}

TreeNode* newNode(int item) {
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode* insertNode(TreeNode* node, int key) {
    if(node == NULL)
        return newNode(key);
    if(key < node->key)
        node->left = insertNode(node->left, key);
    else if(key > node->key)
        node->right = insertNode(node->right, key);
    
    return node;
}

TreeNode* minValueNode(TreeNode* node) {
    TreeNode* current = node;
    
    while(current->left != NULL)
        current = current->left;
    
    return current;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if(root == NULL)
        return root;
    if(key < root->key)
        root->left = deleteNode(root->left, key);
    else if(key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if(root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        TreeNode* temp = minValueNode(root->right);
        
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
//중위순회
void inorder(TreeNode* root) {
    if(root){
        inorder(root->left);
        printf("[%d] ", root->key);
        inorder(root->right);
    }
}

int main(void) {
    TreeNode* root = NULL;
    
    root = insertNode(root, 27);
    root = insertNode(root, 18);
    root = insertNode(root, 9);
    root = insertNode(root, 10);
    root = insertNode(root, 18);
    root = insertNode(root, 32);
    root = insertNode(root, 44);
    
    printf("이진 탐색 트리 중위 순회 결과 \n");
    inorder(root);
    printf("\n\n");
    
    printf("28을 넣기\n");
    root = insertNode(root, 28);
    inorder(root);
    printf("\n\n");
    
    if(search(root, 18) != NULL)
        printf("이진 탐색 트리에서 18을 발견함.\n\n");
    else
        printf("이진 탐색 트리에서 18을 발견 못함.\n\n");
    
    printf("18을 지우기\n");
    root = deleteNode(root, 18);
    inorder(root);
    printf("\n\n");
    
    if(search(root, 18) != NULL)
        printf("이진 탐색 트리에서 18을 발견함.\n");
    else
        printf("이진 탐색 트리에서 18을 발견 못함.\n");
    return 0;
}

