// Problem Statement: You are given a binary tree with distinct node values and a starting node 'start'. The tree is on fire, and it takes 1 unit of time for the fire to spread from a node to any of its neighboring nodes (parent, left child, or right child).
// Your task is to calculate the minimum time required for the entire tree to be engulfed in flames, starting from the node with value 'start'. Write a function 'timeToBurnTree' that takes the root of the binary tree and the starting node value 'start' as input and returns the minimum time needed for the entire tree to burn.

// Problem Link: https://www.codingninjas.com/studio/problems/time-to-burn-tree_1469067?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <unordered_map>
#include <queue>
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

void findParent(BinaryTreeNode<int>* target, unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*>& par) {
    if (target == NULL) return;

    if (target->left != NULL) {
        par[target->left] = target;
    }
    
    if (target->right != NULL) {
        par[target->right] = target;
    }
    
    findParent(target->left, par);
    findParent(target->right, par);
}

BinaryTreeNode<int>* findStart(BinaryTreeNode<int>* target, int start) {
    if (target == NULL) return NULL;
    
    if (target->data == start) return target;
    
    BinaryTreeNode<int>* leftResult = findStart(target->left, start);
    if (leftResult == NULL) {
        return findStart(target->right, start);
    }
    return leftResult;
}

int timeToBurnTree(BinaryTreeNode<int>* root, int start) {
    unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> par;
    findParent(root, par);
    
    unordered_map<BinaryTreeNode<int>*, bool> vis;
    BinaryTreeNode<int>* target = findStart(root, start);
    
    if (target == NULL) return 0;
    
    queue<BinaryTreeNode<int>*> q;
    q.push(target);
    vis[target] = true;
    int ans = 0;
    
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            BinaryTreeNode<int>* temp = q.front();
            q.pop();
            
            if (par.find(temp) != par.end() && !vis[par[temp]]) {
                vis[par[temp]] = true;
                q.push(par[temp]);
            }
            if (temp->left != NULL && !vis[temp->left]) {
                vis[temp->left] = true;
                q.push(temp->left);
            }
            if (temp->right != NULL && !vis[temp->right]) {
                vis[temp->right] = true;
                q.push(temp->right);
            }
        }
        ans++;
    }
    
    return ans - 1;
}
