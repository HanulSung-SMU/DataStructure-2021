//
//  Array_Tree.cpp
//  data_struct
//
//  Created by 쩡수 on 2021/05/13.
//

#include "Array_Tree.hpp"


int PrintData(TreeNode * t) {
    if (t != NULL) {
        return t -> data;
    } else {
        return -1;
    }
}


// 전위 순회 (preorder traversal) - VLR
// 자손 노드보다 루트 노드를 먼저 방문
void PreOrder(TreeNode * t) {
    if (t != NULL) {
        cout << PrintData(t) << " | ";
        PreOrder(t -> left);
        PreOrder(t -> right);
    }
}

// 중위 순회 (inorder traversal) :LVR
// 왼쪽 자손, 루트, 오른쪽 자손 순으로 방문
void InOrder(TreeNode * t) {
    if (t != NULL) {
        InOrder(t -> left);
        cout << PrintData(t) << " | ";
        InOrder(t -> right);
    }
}

// 후위 순회 (postorder traversal) :LRV
// 루트 노드보다 자손 노드를 먼저 방문
void PostOrder(TreeNode * t) {
    if (t != NULL) {
        PostOrder(t -> left);
        PostOrder(t -> right);
        cout << PrintData(t) << " | ";
    }
}

// 후위 순회 사용
// 서브트리의 값을 순환 호출로 계산
// 비단말 노드를 방문할때 양쪽 서브 트리의 값을 계산
int CalculateTree(TreeNode * t) {
    
    if (t == NULL) {
        return -1;
    }
    
    if (t -> left == NULL && t -> right == NULL) {
        return t -> data;
    } else {
        int x = CalculateTree(t -> left);
        int y = CalculateTree(t -> right);
        cout << x << " 와 " << y << " 를 계산합니다.\n";
        switch (t -> data) {
            case '+':
                return x + y;
            case '-':
                return x - y;
            case '*':
                return x * y;
            case '/':
                return x / y;
            case '<':
                return x < y;
            case '>':
                return x > y;
            case '|':
                return x || y;
            default:
                break;
        }
    }
    
    return 0;
}

TreeNode * InsertTree(TreeNode * t, int key) {
    if (t == NULL) {
        return NewTree(key);
    } else {
        if (key < t -> data) {
            t -> left = InsertTree(t -> left, key);
        } else if (key > t -> data) {
            t -> right = InsertTree(t -> right, key);
        }
    }
    return t;
}

TreeNode * NewTree(int key) {
    TreeNode * temp = new TreeNode;
    temp -> data = key;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

TreeNode * DeleteTree(TreeNode * t, int key) {
    if (t == NULL) {
        return t;
    } else {
        if (key < t -> data) {
            t -> left = DeleteTree(t -> left, key);
        } else if (key > t -> data) {
            t -> right = DeleteTree(t -> right, key);
        } else {
            if (t  -> left == NULL) {
                TreeNode * temp = t -> right;
                delete t;
                return temp;
            } else if (t -> right == NULL) {
                TreeNode * temp = t -> left;
                delete t;
                return temp;
            }
            
            TreeNode * temp = MinValueTree(t -> right);
            t -> data = temp -> data;
            t -> right = DeleteTree(t -> right, temp -> data);
        }
        return t;
    }
}

TreeNode * MinValueTree(TreeNode * t) {
    TreeNode * current = t;
    while (current -> left != NULL) {
        current = current -> left;
    }
    return current;
}

TreeNode * SearchTree(TreeNode * t, int key) {
    if (t == NULL) {
        return t;
    } else {
        if (key == t -> data) {
            return t;
        } else if (key < t -> data) {
            return SearchTree(t -> left, key);
        } else {
            return SearchTree(t -> right, key);
        }
    }
}
