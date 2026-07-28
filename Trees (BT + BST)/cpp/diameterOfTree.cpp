// Problem Statement: Find the Diameter of a Binary Tree. Diameter is the length of the longest path between any 2 nodes in the tree and this path may or may not pass from the root.

// Problem Link: https://leetcode.com/problems/diameter-of-binary-tree/

#include <iostream>
#include <algorithm>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() {
        this->val = 0;
        this->left = NULL;
        this->right = NULL;
    }

    TreeNode(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }

    TreeNode(int val, TreeNode* left, TreeNode* right) {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

class Solution {
private:
    int height(TreeNode* root, int& diameter) {
        if (root == NULL) {
            return 0;
        }

        int leftHeight = height(root->left, diameter);
        int rightHeight = height(root->right, diameter);

        diameter = max(diameter, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};
