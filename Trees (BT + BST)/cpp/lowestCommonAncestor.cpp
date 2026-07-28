// Problem Statement: Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

// Problem Link: https://www.codingninjas.com/studio/problems/lca-of-binary-tree_920541?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
using namespace std;

template <typename T>
class TreeNode {
public:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode<int>* lca(TreeNode<int>* root, int x, int y) {
    if (root == NULL || root->data == x || root->data == y) {
        return root;
    }
    
    TreeNode<int>* left = lca(root->left, x, y);
    TreeNode<int>* right = lca(root->right, x, y);
    
    if (left == NULL) {
        return right;
    } else if (right == NULL) {
        return left;
    } else {
        return root;
    }
}

int lowestCommonAncestor(TreeNode<int>* root, int x, int y) {
    TreeNode<int>* res = lca(root, x, y);
    return res->data;
}
