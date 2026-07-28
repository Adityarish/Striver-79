// Problem Statement: Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

// Problem Link: https://www.codingninjas.com/studio/problems/pair-sum-in-bst._920493?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <stack>
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

bool pairSumBstUsingStacks(TreeNode* root, int k) {
    if (root == NULL) {
        return false;
    }
    
    stack<TreeNode*> leftStack;
    stack<TreeNode*> rightStack;
    TreeNode* leftCurr = root;
    TreeNode* rightCurr = root;
    
    while (!leftStack.empty() || !rightStack.empty() || leftCurr != NULL || rightCurr != NULL) {
        while (leftCurr != NULL) {
            leftStack.push(leftCurr);
            leftCurr = leftCurr->left;
        }
        
        while (rightCurr != NULL) {
            rightStack.push(rightCurr);
            rightCurr = rightCurr->right;
        }
        
        if (leftStack.empty() || rightStack.empty()) {
            break;
        }
        
        TreeNode* leftNode = leftStack.top();
        TreeNode* rightNode = rightStack.top();
        if (leftNode == rightNode) {
            break;
        }
        
        int sum = leftNode->data + rightNode->data;
        if (sum == k) {
            return true;
        } else if (sum < k) {
            leftStack.pop();
            leftCurr = leftNode->right;
        } else {
            rightStack.pop();
            rightCurr = rightNode->left;
        }
    }
    return false;
}

void inorder(TreeNode* root, vector<int>& in) {
    if (root == NULL) return;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

bool pairSumBstUsingTwoPointer(TreeNode* root, int k) {
    vector<int> in;
    inorder(root, in);
    
    int start = 0;
    int end = in.size() - 1;
    
    while (start <= end) {
        int sum = in[start] + in[end];
        if (sum == k) {
            return true;
        } else if (sum > k) {
            end--;
        } else {
            start++;
        }
    }
    return false;
}
