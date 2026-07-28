# Problem Statement: Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

# Problem Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        return self.lca(root, p, q)
        
    def lca(self, root, p, q):
        if root is None or root == p or root == q:
            return root
            
        left = self.lca(root.left, p, q)
        right = self.lca(root.right, p, q)
        
        if left is None:
            return right
        elif right is None:
            return left
        else:
            return root
