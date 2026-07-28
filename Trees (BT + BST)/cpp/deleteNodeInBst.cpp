// Problem Statement: Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
// Basically, the deletion can be divided into two stages:
// Search for a node to remove.
// If the node is found, delete the node.

// Problem Link: https://www.codingninjas.com/studio/problems/delete-node-in-bst_920381?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode() {
        this->left = NULL;
        this->right = NULL;
    }

    BinaryTreeNode(T data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    BinaryTreeNode(T data, BinaryTreeNode<T>* left, BinaryTreeNode<T>* right) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

BinaryTreeNode<int>* solve(BinaryTreeNode<int>* root) {
    if (root->left == NULL) {
        return root->right;
    }
    
    if (root->right == NULL) {
        return root->left;
    }
    
    BinaryTreeNode<int>* lefty = root->left;
    BinaryTreeNode<int>* righty = root->right;
    
    while (righty->left != NULL) {
        righty = righty->left;
    }
    
    righty->left = lefty;
    return root->right;
}

BinaryTreeNode<int>* deleteNode(BinaryTreeNode<int>* root, int key) {
    if (root == NULL) return NULL;
    
    if (root->data == key) return solve(root);
    
    BinaryTreeNode<int>* curr = root;
    while (curr != NULL) {
        if (key < curr->data) {
            if (curr->left != NULL && curr->left->data == key) {
                curr->left = solve(curr->left);
                break;
            } else {
                curr = curr->left;
            }
        } else {
            if (curr->right != NULL && curr->right->data == key) {
                curr->right = solve(curr->right);
                break;
            } else {
                curr = curr->right;
            }
        }
    }
    
    return root;
}
