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
        cout << PrintData(t) << "\n";
        PreOrder(t -> left);
        PreOrder(t -> right);
    }
}

// 중위 순회 (inorder traversal) :LVR
// 왼쪽 자손, 루트, 오른쪽 자손 순으로 방문
void InOrder(TreeNode * t) {
    if (t != NULL) {
        InOrder(t -> left);
        cout << PrintData(t) << "\n";
        InOrder(t -> right);
    }
}

// 후위 순회 (postorder traversal) :LRV
// 루트 노드보다 자손 노드를 먼저 방문
void PostOrder(TreeNode * t) {
    if (t != NULL) {
        PostOrder(t -> left);
        PostOrder(t -> right);
        cout << PrintData(t) << "\n";
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
