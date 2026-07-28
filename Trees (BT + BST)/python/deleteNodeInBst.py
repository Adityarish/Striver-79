# Problem Statement: Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
# Basically, the deletion can be divided into two stages:
# Search for a node to remove.
# If the node is found, delete the node.

# Problem Link: https://www.codingninjas.com/studio/problems/delete-node-in-bst_920381?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

class BinaryTreeNode:
    def __init__(self, data=None, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

def solve(root):
    if root.left is None:
        return root.right
        
    if root.right is None:
        return root.left
        
    lefty = root.left
    righty = root.right
    
    while righty.left is not None:
        righty = righty.left
        
    righty.left = lefty
    return root.right

def delete_node(root, key):
    if root is None:
        return None
        
    if root.data == key:
        return solve(root)
        
    curr = root
    while curr is not None:
        if key < curr.data:
            if curr.left is not None and curr.left.data == key:
                curr.left = solve(curr.left)
                break
            else:
                curr = curr.left
        else:
            if curr.right is not None and curr.right.data == key:
                curr.right = solve(curr.right)
                break
            else:
                curr = curr.right
                
    return root
