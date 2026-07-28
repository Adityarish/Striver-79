# Problem Statement: Find the Diameter of a Binary Tree. Diameter is the length of the longest path between any 2 nodes in the tree and this path may or may not pass from the root.

# Problem Link: https://leetcode.com/problems/diameter-of-binary-tree/

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def diameterOfBinaryTree(self, root):
        self.diameter = 0
        self.height(root)
        return self.diameter
        
    def height(self, root):
        if not root:
            return 0
            
        left_height = self.height(root.left)
        right_height = self.height(root.right)
        
        self.diameter = max(self.diameter, left_height + right_height)
        
        return 1 + max(left_height, right_height)
