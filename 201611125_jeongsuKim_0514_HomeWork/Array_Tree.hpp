//
//  Array_Tree.hpp
//  data_struct
//
//  Created by 쩡수 on 2021/05/13.
//

#ifndef Array_Tree_hpp
#define Array_Tree_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

#define max_size_at 20


//int array_tree[max_size_at];

typedef struct TreeNode {
    int data;
    struct TreeNode * left;
    struct TreeNode * right;
} TreeNode;

// 전위 순회 (preorder traversal) - VLR
// 자손 노드보다 루트 노드를 먼저 방문
void PreOrder(TreeNode * t);

// 중위 순회 (inorder traversal) :LVR
// 왼쪽 자손, 루트, 오른쪽 자손 순으로 방문
void InOrder(TreeNode * t);

// 후위 순회 (postorder traversal) :LRV
// 루트 노드보다 자손 노드를 먼저 방문
void PostOrder(TreeNode * t);

int PrintData(TreeNode * t);

int CalculateTree(TreeNode * t);

void PushTree(TreeNode * t, int item);
TreeNode * PopTree(TreeNode * t);
TreeNode * InsertTree(TreeNode * t, int key);
TreeNode * NewTree(int key);
TreeNode * DeleteTree(TreeNode * t, int key);
TreeNode * MinValueTree(TreeNode * t);
TreeNode * SearchTree(TreeNode * t, int key);


#endif /* Array_Tree_hpp */
