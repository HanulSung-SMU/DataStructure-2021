#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode
{
  element key;
  struct TreeNode *left, *right;
} TreeNode;

TreeNode * search(TreeNode * node, int key)
{
  while(node != NULL)
  {
    if(key == node->key)
    {
      return node;
    }
    else if(key < node->key)
    {
      node = node->left;
    }
    else
    {
      node = node->right;
    }
  }
  return NULL;
}

TreeNode * new_node(int item)
{
  TreeNode * temp = (TreeNode *)malloc(sizeof(TreeNode));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

TreeNode * insert_node(TreeNode * node, int key)
{
  if(node == NULL)
  {
    return new_node(key);
  }
  if(key < node->key)
  {
    node->left = insert_node(node->left, key);
  }
  else if(key > node->key)
  {
    node->right = insert_node(node->right, key);
  }
  return node;
}

TreeNode * delete_replace_right(TreeNode * node)
{
  TreeNode * current = node;
  while(current->left != NULL)
  {
    current = current->left;
  }
  return current;
}

TreeNode * delete_replace_left(TreeNode * node)
{
  TreeNode * current = node;
  while(current->right != NULL)
  {
    current = current->right;
  }
  return current;
}

TreeNode * delete_node(TreeNode * root, int key)
{
  if(root == NULL)
  {
    return root;
  }
  if(key < root->key)
  {
    root->left = delete_node(root->left, key);
  }
  else if(key > root->key)
  {
    root->right = delete_node(root->right, key);
  }
  else
  {
    if(root->left == NULL)
    {
      TreeNode * temp = root->right;
      free(root);
      return temp;
    }
    else if(root->right == NULL)
    {
      TreeNode *temp = root->left;
      free(root);
      return temp;
    }
    TreeNode * temp1 = delete_replace_right(root->right);
    TreeNode * temp2 = delete_replace_left(root->left);
    if((root->key - temp2->key) < (temp1->key - root->key))
    {
      root->key = temp2->key;
      root->left = delete_node(root->left, temp2->key);
    }
    else
    {
      root->key = temp1->key;
      root->right = delete_node(root->right, temp1->key);
    }
  }
  return root;
}

void inorder(TreeNode * root)
{
  if(root)
  {
    inorder(root->left);
    printf("[%2d] ", root->key);
    inorder(root->right);
  }
}

int main(void)
{
  TreeNode * root = NULL;
  TreeNode * tmp = NULL;

  root = insert_node(root, 27);
  root = insert_node(root, 18);
  root = insert_node(root, 9);
  root = insert_node(root, 10);
  root = insert_node(root, 19);
  root = insert_node(root, 32);
  root = insert_node(root, 44);
  inorder(root);
  printf("\n");
  root = insert_node(root, 28);
  inorder(root);
  printf("\n");
  delete_node(root, 18);
  inorder(root);
  return 0;
}