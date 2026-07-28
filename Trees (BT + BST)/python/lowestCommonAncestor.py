# Problem Statement: Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

# Problem Link: https://www.codingninjas.com/studio/problems/lca-of-binary-tree_920541?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

class TreeNode:
    def __init__(self, data=None):
        self.data = data
        self.left = None
        self.right = None

def lca(root, x, y):
    if not root or root.data == x or root.data == y:
        return root
        
    left = lca(root.left, x, y)
    right = lca(root.right, x, y)
    
    if not left:
        return right
    elif not right:
        return left
    else:
        return root

def lowest_common_ancestor(root, x, y):
    res = lca(root, x, y)
    return res.data if res else None
