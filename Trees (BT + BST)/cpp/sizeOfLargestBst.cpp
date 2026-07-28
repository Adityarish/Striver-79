// Problem Statement: Find the size of largest BST in a binary tree.

// Problem Link: https://www.codingninjas.com/studio/problems/size-of-largest-bst-in-binary-tree_893103?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode() {
        this->data = 0;
        this->left = NULL;
        this->right = NULL;
    }

    TreeNode(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    TreeNode(int data, TreeNode* left, TreeNode* right) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

class BSTInfo {
public:
    int size;
    int min;
    int max;
    bool isBST;

    BSTInfo(int size, int min, int max, bool isBST) {
        this->size = size;
        this->min = min;
        this->max = max;
        this->isBST = isBST;
    }
};

BSTInfo findLargestBST(TreeNode* node) {
    if (node == NULL) {
        return BSTInfo(0, INT_MAX, INT_MIN, true);
    }
    
    BSTInfo leftInfo = findLargestBST(node->left);
    BSTInfo rightInfo = findLargestBST(node->right);
    
    bool isBST = false;
    if (leftInfo.isBST && rightInfo.isBST && node->data > leftInfo.max && node->data < rightInfo.min) {
        isBST = true;
    }
    
    int size = isBST ? leftInfo.size + rightInfo.size + 1 : max(leftInfo.size, rightInfo.size);
    
    int minVal = min(node->data, min(leftInfo.min, rightInfo.min));
    int maxVal = max(node->data, max(leftInfo.max, rightInfo.max));
    
    return BSTInfo(size, minVal, maxVal, isBST);
}

int largestBST(TreeNode* root) {
    BSTInfo result = findLargestBST(root);
    return result.size;
}
