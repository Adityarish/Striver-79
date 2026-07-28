// Problem Statement: Write a program to find the maximum sum path in a binary tree. A path in a binary tree is a sequence of nodes where every adjacent pair of nodes are connected by an edge. A node can only appear in the sequence at most once. A path need not pass from the root. We need to find the path with the maximum sum in the binary tree.

// Problem Link: https://www.codingninjas.com/studio/problems/maximum-sum-path-of-a-binary-tree._1214968?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

int maxPathS(BinaryTreeNode<int>* node, int& maxValue) {
    if (node == NULL) {
        return 0;
    }

    int left = max(0, maxPathS(node->left, maxValue));
    int right = max(0, maxPathS(node->right, maxValue));

    maxValue = max(maxValue, left + right + node->data);

    return max(left, right) + node->data;
}

int maxPathSum(BinaryTreeNode<int>* root) {
    int maxValue = -1e9; // Assuming max path sum can be negative
    if (root != NULL) {
        maxPathS(root, maxValue);
    }
    return maxValue;
}
