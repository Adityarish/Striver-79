# Problem Statement: Given the root of a binary tree, return the preorder traversal of its nodes' values.

# Problem Link: https://www.codingninjas.com/studio/problems/preorder-binary-tree_5948?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

class BinaryTreeNode:
    def __init__(self, data=None):
        self.data = data
        self.left = None
        self.right = None

def pre_order(root):
    if root is None:
        return
        
    print(root.data, end=" ")
    pre_order(root.left)
    pre_order(root.right)
