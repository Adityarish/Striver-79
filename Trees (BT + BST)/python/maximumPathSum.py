# Problem Statement: Write a program to find the maximum sum path in a binary tree. A path in a binary tree is a sequence of nodes where every adjacent pair of nodes are connected by an edge. A node can only appear in the sequence at most once. A path need not pass from the root. We need to find the path with the maximum sum in the binary tree.

# Problem Link: https://www.codingninjas.com/studio/problems/maximum-sum-path-of-a-binary-tree._1214968?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

class BinaryTreeNode:
    def __init__(self, data=None):
        self.data = data
        self.left = None
        self.right = None

class Solution:
    def maxPathSum(self, root):
        self.max_value = float('-inf')
        if root:
            self.max_path_s(root)
        return self.max_value
        
    def max_path_s(self, node):
        if not node:
            return 0
            
        left = max(0, self.max_path_s(node.left))
        right = max(0, self.max_path_s(node.right))
        
        self.max_value = max(self.max_value, left + right + node.data)
        
        return max(left, right) + node.data

def max_path_sum(root):
    sol = Solution()
    return sol.maxPathSum(root)
