// Problem Statement: Given a binary tree, print the bottom view from left to right. A node is included in the bottom view if it can be seen when we look at the tree from the bottom.

// Problem Link: https://www.codingninjas.com/studio/problems/bottom-view-of-binary-tree_893110?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class Pair {
public:
    int hd;
    TreeNode* root;

    Pair(int hd, TreeNode* root) {
        this->hd = hd;
        this->root = root;
    }
};

vector<int> bottomView(TreeNode* root) {
    vector<int> ans;
    if (root == NULL) return ans;
    
    queue<Pair> q;
    map<int, int> m;
    
    q.push(Pair(0, root));
    
    while (!q.empty()) {
        Pair temp = q.front();
        q.pop();
        
        m[temp.hd] = temp.root->val;
        
        if (temp.root->left != NULL) {
            q.push(Pair(temp.hd - 1, temp.root->left));
        }
        
        if (temp.root->right != NULL) {
            q.push(Pair(temp.hd + 1, temp.root->right));
        }
    }
    
    for (auto it : m) {
        ans.push_back(it.second);
    }
    
    return ans;
}
