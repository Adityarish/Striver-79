# Problem Statement: Find the size of largest BST in a binary tree.

# Problem Link: https://www.codingninjas.com/studio/problems/size-of-largest-bst-in-binary-tree_893103?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

class TreeNode:
    def __init__(self, data=0, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

class BSTInfo:
    def __init__(self, size, min_val, max_val, is_bst):
        self.size = size
        self.min = min_val
        self.max = max_val
        self.is_bst = is_bst

def find_largest_bst(node):
    if node is None:
        return BSTInfo(0, float('inf'), float('-inf'), True)
        
    left_info = find_largest_bst(node.left)
    right_info = find_largest_bst(node.right)
    
    is_bst = False
    if left_info.is_bst and right_info.is_bst and node.data > left_info.max and node.data < right_info.min:
        is_bst = True
        
    size = left_info.size + right_info.size + 1 if is_bst else max(left_info.size, right_info.size)
    
    min_val = min(node.data, min(left_info.min, right_info.min))
    max_val = max(node.data, max(left_info.max, right_info.max))
    
    return BSTInfo(size, min_val, max_val, is_bst)

def largest_bst(root):
    result = find_largest_bst(root)
    return result.size
