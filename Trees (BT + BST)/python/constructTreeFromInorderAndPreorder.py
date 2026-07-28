# Problem Statement: Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

# Problem Link: https://www.codingninjas.com/studio/problems/construct-binary-tree-from-inorder-and-preorder-traversal_920539?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

class TreeNode:
    def __init__(self, data=0, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

def build_tree_helper(preorder, pre_start, pre_end, inorder, in_start, in_end, in_map):
    if pre_start > pre_end or in_start > in_end:
        return None
        
    root = TreeNode(preorder[pre_start])
    in_root = in_map[root.data]
    nums_left = in_root - in_start
    
    root.left = build_tree_helper(preorder, pre_start + 1, pre_start + nums_left, inorder, in_start, in_root - 1, in_map)
    root.right = build_tree_helper(preorder, pre_start + nums_left + 1, pre_end, inorder, in_root + 1, in_end, in_map)
    
    return root

def build_binary_tree(inorder, preorder):
    in_map = {}
    for i in range(len(inorder)):
        in_map[inorder[i]] = i
        
    return build_tree_helper(preorder, 0, len(preorder) - 1, inorder, 0, len(inorder) - 1, in_map)
